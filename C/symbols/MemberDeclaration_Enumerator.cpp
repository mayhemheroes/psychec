// Copyright (c) 2022 Leandro T. C. Melo <ltcmelo@gmail.com>
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

#include "MemberDeclaration_Enumerator.h"

#include "symbols/Symbol_ALL.h"
#include "sema/Scope.h"
#include "syntax/Lexeme_Identifier.h"
#include "types/Type_ALL.h"

#include <sstream>

using namespace psy;
using namespace C;

EnumeratorDeclarationSymbol::EnumeratorDeclarationSymbol(
        const Symbol* containingSym,
        const SyntaxTree* tree,
        const Scope* enclosingScope)
    : MemberDeclarationSymbol(SymbolKind::EnumeratorDeclaration,
                              containingSym,
                              tree,
                              enclosingScope)
{}

namespace psy {
namespace C {

std::ostream& operator<<(std::ostream& os, const EnumeratorDeclarationSymbol* enumerator)
{
    if (!enumerator)
        return os << "<Enumerator is null>";
    os << "<Enumerator |";
    os << " name:" << enumerator->name()->valueText();
    os << " type:" << enumerator->type();
    os << ">";
    return os;
}

} // C
} // psi
