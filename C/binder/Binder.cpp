// Copyright (c) 2021/22 Leandro T. C. Melo <ltcmelo@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "Binder.h"
#include "Binder__MACROS__.inc"

#include "SyntaxTree.h"
#include "binder/Scope.h"
#include "compilation/Compilation.h"
#include "symbols/Symbol_ALL.h"
#include "syntax/SyntaxFacts.h"
#include "syntax/Lexeme_ALL.h"
#include "syntax/SyntaxNodes.h"
#include "syntax/SyntaxUtilities.h"
#include "types/Type_ALL.h"

#include "../common/infra/Assertions.h"

#include <iostream>

using namespace psy;
using namespace C;

Binder::Binder(SemanticModel* semaModel, const SyntaxTree* tree)
    : SyntaxVisitor(tree)
    , semaModel_(semaModel)
    , stashedScope_(nullptr)
    , BD_(0)
    , ptrdiff_t_(tree->findIdentifier("ptrdiff_t", 9))
    , size_t_(tree->findIdentifier("size_t", 6))
    , max_align_t_(tree->findIdentifier("max_align_t", 11))
    , wchar_t_(tree->findIdentifier("wchar_t", 7))
    , char16_t_(tree->findIdentifier("char16_t", 8))
    , char32_t_(tree->findIdentifier("char32_t", 8))
    , diagReporter_(this)
{}

Binder::~Binder()
{
}

void Binder::bind()
{
    syms_.push(nullptr);

    visit(tree_->root());

    PSY_ASSERT_3(syms_.size() == 1, return, "expected 1 symbol");
    PSY_ASSERT_3(syms_.top() == nullptr, return, "expected sentinel symbol");
    syms_.pop();
}

void Binder::pushNewScope(const SyntaxNode* node,
                          ScopeKind scopeK,
                          bool encloseInOuterScope)
{
    PSY_ASSERT_2(scopeK == ScopeKind::File
                   || scopeK == ScopeKind::Block
                   || scopeK == ScopeKind::Function
                   || scopeK == ScopeKind::FunctionPrototype,
               return);

    std::unique_ptr<Scope> scope(new Scope(scopeK));
    auto rawScope = semaModel_->mapAndKeepScope(node, std::move(scope));
    if (!encloseInOuterScope)
        scopes_.push(rawScope);
    else {
        PSY_ASSERT_2(!scopes_.empty(), return);
        auto outerScope = scopes_.top();
        scopes_.push(rawScope);
        outerScope->encloseScope(rawScope);
    }
}

void Binder::pushStashedScope()
{
    PSY_ASSERT_2(stashedScope_, return);
    scopes_.push(stashedScope_);
}

void Binder::popScope()
{
    scopes_.pop();
}

void Binder::popAndStashScope()
{
    stashedScope_ = scopes_.top();
    scopes_.pop();
}

void Binder::pushSymbol(Symbol* sym)
{
    DBG_SYM_STACK(sym);
    syms_.push(sym);
}

Symbol* Binder::popSymbol()
{
    PSY_ASSERT_2(!syms_.empty(), return nullptr);
    DBG_SYM_STACK(syms_.top());
    auto sym = syms_.top();
    syms_.pop();
    return sym;
}

Declaration* Binder::popSymbolAsDeclaration()
{
    auto sym = popSymbol();
    PSY_ASSERT_2(sym && sym->kind() == SymbolKind::Declaration, return nullptr);
    return sym->asDeclaration();
}

void Binder::pushType(Type* ty)
{
    DBG_TY_STACK(ty);
    tys_.push(ty);
}

Type* Binder::popType()
{
    PSY_ASSERT_2(!tys_.empty(), return nullptr);
    DBG_TY_STACK(tys_.top());
    auto ty = tys_.top();
    tys_.pop();
    return ty;
}

const Identifier* Binder::identifier(const SyntaxToken& tk) const
{
    return tk.lexeme()
            ? tk.lexeme()->asIdentifier()
            : tree_->findIdentifier("", 0);
}

//--------------//
// Declarations //
//--------------//

SyntaxVisitor::Action Binder::visitTranslationUnit(const TranslationUnitSyntax* node)
{
    std::unique_ptr<TranslationUnit> unit(
                new TranslationUnit(
                    semaModel_->compilation()->program(),
                    tree_));
    auto rawUnit = semaModel_->keepTranslationUnit(std::move(unit));
    pushSymbol(rawUnit);

    pushNewScope(node, ScopeKind::File, false);
    for (auto declIt = node->declarations(); declIt; declIt = declIt->next)
        visit(declIt->value);
    PSY_ASSERT_2(scopes_.size() == 1, return Action::Quit);
    PSY_ASSERT_2(scopes_.top()->kind() == ScopeKind::File, return Action::Quit);
    popScope();

    popSymbol();

    return Action::Skip;
}

SyntaxVisitor::Action Binder::visitIncompleteDeclaration(const IncompleteDeclarationSyntax* node)
{
    diagReporter_.UselessDeclaration(node->lastToken());

    return Action::Skip;
}

SyntaxVisitor::Action Binder::visitStructOrUnionDeclaration(const StructOrUnionDeclarationSyntax* node)
{
    return visitStructOrUnionDeclaration_AtSpecifier(node);
}

SyntaxVisitor::Action Binder::visitEnumDeclaration(const EnumDeclarationSyntax* node)
{
    return visitEnumDeclaration_AtSpecifier(node);
}

SyntaxVisitor::Action Binder::visitTypedefDeclaration(const TypedefDeclarationSyntax* node)
{
    return visitTypedefDeclaration_AtSpecifier(node);
}

SyntaxVisitor::Action Binder::visitVariableAndOrFunctionDeclaration(
        const VariableAndOrFunctionDeclarationSyntax* node)
{
    return visitVariableAndOrFunctionDeclaration_AtSpecifiers(node);
}

SyntaxVisitor::Action Binder::visitFieldDeclaration(const FieldDeclarationSyntax* node)
{
    return visitFieldDeclaration_AtSpecifiers(node);
}

SyntaxVisitor::Action Binder::visitEnumeratorDeclaration(const EnumeratorDeclarationSyntax* node)
{
    return visitEnumeratorDeclaration_AtImplicitSpecifier(node);
}

SyntaxVisitor::Action Binder::visitParameterDeclaration(const ParameterDeclarationSyntax* node)
{
    return visitParameterDeclaration_AtSpecifiers(node);
}

SyntaxVisitor::Action Binder::visitStaticAssertDeclaration(const StaticAssertDeclarationSyntax*)
{
    return Action::Skip;
}

SyntaxVisitor::Action Binder::visitFunctionDefinition(const FunctionDefinitionSyntax* node)
{
    return visitFunctionDefinition_AtSpecifiers(node);
}

//------------//
// Statements //
//------------//

SyntaxVisitor::Action Binder::visitCompoundStatement(const CompoundStatementSyntax* node)
{
    pushNewScope(node, ScopeKind::Block, true);
    for (auto stmtIt = node->statements(); stmtIt; stmtIt = stmtIt->next)
        visit(stmtIt->value);
    popScope();

    return Action::Skip;
}

//--------//
// Common //
//--------//

SyntaxVisitor::Action Binder::visitTypeName(const TypeNameSyntax* node)
{
    TyContT tys;
    std::swap(tys_, tys);
    auto action = visitTypeName_AtSpecifier(node);
    std::swap(tys_, tys);
    return action;
}
