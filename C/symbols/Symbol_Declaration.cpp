// Copyright (c) 2024 Leandro T. C. Melo <ltcmelo@gmail.com>
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

#include "Symbol__IMPL__.inc"
#include "Symbol_Declaration.h"

#include "binder/Scope.h"
#include "compilation/Compilation.h"
#include "symbols/Symbol_ALL.h"
#include "syntax/SyntaxNodes.h"
#include "syntax/SyntaxReference.h"

#include "../common/infra/Assertions.h"

#include <algorithm>
#include <sstream>

using namespace psy;
using namespace C;

DeclarationSymbol::DeclarationSymbol(SymbolImpl* p, DeclarationSymbolKind declSymK)
    : Symbol(p)
{
    P->BF_.declSymK_ = static_cast<std::uint32_t>(declSymK);
}

DeclarationSymbolKind DeclarationSymbol::kind() const
{
    return DeclarationSymbolKind(P->BF_.declSymK_);
}

const Scope* DeclarationSymbol::enclosingScope() const
{
    return P->enclosingScope_;
}

SymbolKind Symbol::kind() const
{
    return SymbolKind(P->BF_.symK_);
}

const NameSpace DeclarationSymbol::nameSpace() const
{
    return NameSpace(P->BF_.ns_);
}

Location DeclarationSymbol::location() const
{
    const auto& syntaxRefs = declaringSyntaxReferences();
    std::vector<Location> locs;
    std::transform(syntaxRefs.begin(),
                   syntaxRefs.end(),
                   std::back_inserter(locs),
                   [] (auto& synRef) {
                        return synRef.syntax()->firstToken().location();
                   });

    // TODO
    return locs.front();
}

std::vector<SyntaxReference> DeclarationSymbol::declaringSyntaxReferences() const
{
    return {};
}

namespace psy {
namespace C {

std::string PSY_C_API to_string(const DeclarationSymbol& decl)
{
    switch (decl.kind()) {
        case DeclarationSymbolKind::Function:
            return to_string(*decl.asFunction());
        case DeclarationSymbolKind::Object:
            return to_string(*decl.asObjectDeclarationSymbol());
        case DeclarationSymbolKind::Type:
            return to_string(*decl.asTypeDeclarationSymbol());
    }
}

} // C
} // psy
