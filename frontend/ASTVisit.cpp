// Copyright (c) 2008 Roberto Raggi <roberto.raggi@gmail.com>
// Copyright (c) 2016 Leandro T. C. Melo <ltcmelo@gmail.com>
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

#include "AST.h"
#include "ASTVisitor.h"

using namespace psyche;

void SimpleSpecifierAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void AlignmentSpecifierAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(typeIdExprOrAlignmentExpr, visitor);
    }
    visitor->endVisit(this);
}

void GenericsDeclarationAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(declaration, visitor);
    }
    visitor->endVisit(this);
}

void GnuAttributeSpecifierAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(attribute_list, visitor);
    }
    visitor->endVisit(this);
}

void GnuAttributeAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression_list, visitor);
    }
    visitor->endVisit(this);
}

void TypeofSpecifierAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void DecltypeSpecifierAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void DeclaratorAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(attribute_list, visitor);
        accept(ptr_operator_list, visitor);
        accept(core_declarator, visitor);
        accept(postfix_declarator_list, visitor);
        accept(post_attribute_list, visitor);
        accept(initializer, visitor);
    }
    visitor->endVisit(this);
}

void SimpleDeclarationAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(decl_specifier_list, visitor);
        accept(declarator_list, visitor);
    }
    visitor->endVisit(this);
}

void EmptyDeclarationAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void AccessDeclarationAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void AsmDefinitionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void BaseSpecifierAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
    }
    visitor->endVisit(this);
}

void IdExpressionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
    }
    visitor->endVisit(this);
}

void CompoundExpressionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}

void CompoundLiteralAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(type_id, visitor);
        accept(initializer, visitor);
    }
    visitor->endVisit(this);
}

void BinaryExpressionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(left_expression, visitor);
        accept(right_expression, visitor);
    }
    visitor->endVisit(this);
}

void CastExpressionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(type_id, visitor);
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void ClassSpecifierAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(attribute_list, visitor);
        accept(name, visitor);
        accept(base_clause_list, visitor);
        accept(member_specifier_list, visitor);
    }
    visitor->endVisit(this);
}

void CaseStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}

void CompoundStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(statement_list, visitor);
    }
    visitor->endVisit(this);
}

void ConditionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(type_specifier_list, visitor);
        accept(declarator, visitor);
    }
    visitor->endVisit(this);
}

void ConditionalExpressionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(condition, visitor);
        accept(left_expression, visitor);
        accept(right_expression, visitor);
    }
    visitor->endVisit(this);
}

void CppCastExpressionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(type_id, visitor);
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void CtorInitializerAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(member_initializer_list, visitor);
    }
    visitor->endVisit(this);
}

void DeclarationStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(declaration, visitor);
    }
    visitor->endVisit(this);
}

void DeclaratorIdAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
    }
    visitor->endVisit(this);
}

void NestedDeclaratorAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(declarator, visitor);
    }
    visitor->endVisit(this);
}

void FunctionDeclaratorAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(parameter_declaration_clause, visitor);
        accept(cv_qualifier_list, visitor);
        accept(exception_specification, visitor);
        accept(trailing_return_type, visitor);
        accept(as_cpp_initializer, visitor);
    }
    visitor->endVisit(this);
}

void ArrayDeclaratorAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void DeleteExpressionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void DoStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(statement, visitor);
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void NamedTypeSpecifierAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
    }
    visitor->endVisit(this);
}

void ElaboratedTypeSpecifierAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(attribute_list, visitor);
        accept(name, visitor);
    }
    visitor->endVisit(this);
}

void EnumSpecifierAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
        accept(type_specifier_list, visitor);
        accept(enumerator_list, visitor);
    }
    visitor->endVisit(this);
}

void EnumeratorAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void ExceptionDeclarationAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(type_specifier_list, visitor);
        accept(declarator, visitor);
    }
    visitor->endVisit(this);
}

void DynamicExceptionSpecificationAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(type_id_list, visitor);
    }
    visitor->endVisit(this);
}

void NoExceptSpecificationAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void ExpressionOrDeclarationStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
        accept(declaration, visitor);
    }
    visitor->endVisit(this);
}

void ExpressionStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void AmbiguousStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(declarationStmt, visitor);
        accept(expressionStmt, visitor);
    }
    visitor->endVisit(this);
}

void FunctionDefinitionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(decl_specifier_list, visitor);
        accept(declarator, visitor);
        accept(ctor_initializer, visitor);
        accept(function_body, visitor);
    }
    visitor->endVisit(this);
}

void ForeachStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(type_specifier_list, visitor);
        accept(declarator, visitor);
        accept(initializer, visitor);
        accept(expression, visitor);
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}

void RangeBasedForStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(type_specifier_list, visitor);
        accept(declarator, visitor);
        accept(expression, visitor);
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}

void ForStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(initializer, visitor);
        accept(condition, visitor);
        accept(expression, visitor);
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}

void IfStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(condition, visitor);
        accept(statement, visitor);
        accept(else_statement, visitor);
    }
    visitor->endVisit(this);
}

void ArrayInitializerAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression_list, visitor);
    }
    visitor->endVisit(this);
}

void LabeledStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}

void LinkageBodyAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(declaration_list, visitor);
    }
    visitor->endVisit(this);
}

void LinkageSpecificationAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(declaration, visitor);
    }
    visitor->endVisit(this);
}

void MemInitializerAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void NestedNameSpecifierAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(class_or_namespace_name, visitor);
    }
    visitor->endVisit(this);
}

void QualifiedNameAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(nested_name_specifier_list, visitor);
        accept(unqualified_name, visitor);
    }
    visitor->endVisit(this);
}

void QuantifiedTypeSpecifierAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
    }
    visitor->endVisit(this);
}

void OperatorFunctionIdAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(op, visitor);
    }
    visitor->endVisit(this);
}

void ConversionFunctionIdAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(type_specifier_list, visitor);
        accept(ptr_operator_list, visitor);
    }
    visitor->endVisit(this);
}

void AnonymousNameAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void SimpleNameAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void TaggedNameAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(core_name, visitor);
    }
    visitor->endVisit(this);
}

void DestructorNameAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(unqualified_name, visitor);
    }
    visitor->endVisit(this);
}

void TemplateIdAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(template_argument_list, visitor);
    }
    visitor->endVisit(this);
}

void NamespaceAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(attribute_list, visitor);
        accept(linkage_body, visitor);
    }
    visitor->endVisit(this);
}

void NamespaceAliasDefinitionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
    }
    visitor->endVisit(this);
}

void AliasDeclarationAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
        accept(typeId, visitor);
    }
    visitor->endVisit(this);
}

void ExpressionListParenAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression_list, visitor);
    }
    visitor->endVisit(this);
}

void NewArrayDeclaratorAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void NewExpressionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(new_placement, visitor);
        accept(type_id, visitor);
        accept(new_type_id, visitor);
        accept(new_initializer, visitor);
    }
    visitor->endVisit(this);
}

void NewTypeIdAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(type_specifier_list, visitor);
        accept(ptr_operator_list, visitor);
        accept(new_array_declarator_list, visitor);
    }
    visitor->endVisit(this);
}

void OperatorAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void ParameterDeclarationAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(type_specifier_list, visitor);
        accept(declarator, visitor);
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void ParameterDeclarationClauseAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(parameter_declaration_list, visitor);
    }
    visitor->endVisit(this);
}

void CallAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(base_expression, visitor);
        accept(expression_list, visitor);
    }
    visitor->endVisit(this);
}

void ArrayAccessAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(base_expression, visitor);
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void PostIncrDecrAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(base_expression, visitor);
    }
    visitor->endVisit(this);
}

void MemberAccessAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(base_expression, visitor);
        accept(member_name, visitor);
    }
    visitor->endVisit(this);
}

void TypeidExpressionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void TypenameCallExpressionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void TypeConstructorCallAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(type_specifier_list, visitor);
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void PointerToMemberAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(nested_name_specifier_list, visitor);
        accept(cv_qualifier_list, visitor);
    }
    visitor->endVisit(this);
}

void PointerAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(cv_qualifier_list, visitor);
    }
    visitor->endVisit(this);
}

void ReferenceAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void BreakStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void ContinueStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void GotoStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void ReturnStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void SizeofExpressionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void AlignofExpressionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(typeId, visitor);
    }
    visitor->endVisit(this);
}

void PointerLiteralAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void NumericLiteralAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void BoolLiteralAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void ThisExpressionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void NestedExpressionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void StaticAssertDeclarationAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
        accept(string_literal, visitor);
    }
    visitor->endVisit(this);
}

void StringLiteralAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void SwitchStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(condition, visitor);
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}

void TemplateDeclarationAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(template_parameter_list, visitor);
        accept(declaration, visitor);
    }
    visitor->endVisit(this);
}

void ThrowExpressionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void NoExceptOperatorExpressionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void TranslationUnitAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(declaration_list, visitor);
    }
    visitor->endVisit(this);
}

void TryBlockStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(statement, visitor);
        accept(catch_clause_list, visitor);
    }
    visitor->endVisit(this);
}

void CatchClauseAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(exception_declaration, visitor);
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}

void TypeIdAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(type_specifier_list, visitor);
        accept(declarator, visitor);
    }
    visitor->endVisit(this);
}

void TypenameTypeParameterAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
        accept(type_id, visitor);
    }
    visitor->endVisit(this);
}

void TemplateTypeParameterAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(template_parameter_list, visitor);
        accept(name, visitor);
        accept(type_id, visitor);
    }
    visitor->endVisit(this);
}

void UnaryExpressionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void UsingAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
    }
    visitor->endVisit(this);
}

void UsingDirectiveAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
    }
    visitor->endVisit(this);
}

void WhileStatementAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(condition, visitor);
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}

void LambdaExpressionAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(lambda_introducer, visitor);
        accept(lambda_declarator, visitor);
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}

void LambdaIntroducerAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(lambda_capture, visitor);
    }
    visitor->endVisit(this);
}

void LambdaCaptureAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(capture_list, visitor);
    }
    visitor->endVisit(this);
}

void CaptureAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(identifier, visitor);
    }
    visitor->endVisit(this);
}

void LambdaDeclaratorAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(parameter_declaration_clause, visitor);
        accept(attributes, visitor);
        accept(exception_specification, visitor);
        accept(trailing_return_type, visitor);
    }
    visitor->endVisit(this);
}

void TrailingReturnTypeAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(attributes, visitor);
        accept(type_specifier_list, visitor);
        accept(declarator, visitor);
    }
    visitor->endVisit(this);
}

void BracedInitializerAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression_list, visitor);
    }
    visitor->endVisit(this);
}

void DotDesignatorAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void BracketDesignatorAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void DesignatedInitializerAST::accept0(ASTVisitor* visitor)
{
    if (visitor->visit(this)) {
        accept(designator_list, visitor);
        accept(initializer, visitor);
    }
    visitor->endVisit(this);
}

