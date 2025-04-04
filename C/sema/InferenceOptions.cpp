// Copyright (c) 2025 Leandro T. C. Melo <ltcmelo@gmail.com>
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

#include "InferenceOptions.h"

using namespace psy;
using namespace C;

InferenceOptions::InferenceOptions()
    : BD_(0)
{
    F_.DeclarationAndTypeInference_ = 0;
}

#define DEFINE_ENABLE_ISENABLED(FLAG) \
    InferenceOptions& InferenceOptions::enable_##FLAG(bool enable) \
        { F_.FLAG##_ = enable; return *this; } \
    bool InferenceOptions::isEnabled_##FLAG() const \
        { return F_.FLAG##_; }

DEFINE_ENABLE_ISENABLED(DeclarationAndTypeInference)

#undef DEFINE_ENABLE_ISENABLED
