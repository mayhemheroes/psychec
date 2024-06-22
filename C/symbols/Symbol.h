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

#ifndef PSYCHE_C_SYMBOL_H__
#define PSYCHE_C_SYMBOL_H__

#include "API.h"
#include "Fwds.h"

#include "SymbolKind.h"

#include "syntax/SyntaxReference.h"

#include "../common/location/Location.h"
#include "../common/infra/Pimpl.h"

#include <memory>
#include <vector>

namespace psy {
namespace C {

/**
 * \brief The Symbol class.
 *
 * \note
 * This API is inspired by that of \c Microsoft.CodeAnalysis.ISymbol
 * from Roslyn, the .NET Compiler Platform.
 */
class PSY_C_API Symbol
{
public:
    virtual ~Symbol();

    /**
     * The SymbolKind of \c this Symbol.
     */
    SymbolKind kind() const;

    virtual Program* asProgram() { return nullptr; }
    virtual const Program* asProgram() const { return nullptr; }
    virtual TranslationUnit* asTranslationUnit() { return nullptr; }
    virtual const TranslationUnit* asTranslationUnit() const { return nullptr; }
    virtual DeclarationSymbol* asDeclarationSymbol() { return nullptr; }
    virtual const DeclarationSymbol* asDeclarationSymbol() const { return nullptr; }

    /**
     * The Symbol that contains \c this Symbol.
     */
    const Symbol* containingSymbol() const;

    /**
     * Compute a displayable string for \c this Symbol.
     */
    virtual std::string toDisplayString() const = 0;

protected:
    DECL_PIMPL(Symbol);
    Symbol(SymbolImpl* p);
    Symbol(const Symbol&) = delete;
    Symbol& operator=(const Symbol&) = delete;
};

std::string PSY_C_API to_string(const Symbol& sym);

} // C
} // psy

#endif
