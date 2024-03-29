/*

Copyright (C) 2016 Apple Inc. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1.  Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
2.  Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#pragma once

#include "ExceptionCode.h"
#include <wtf/text/WTFString.h>

namespace WebCore {

class Exception {
public:
    explicit Exception(ExceptionCode, String = { });

    ExceptionCode code() const { return m_code; }
    const String& message() const { return m_message; }
    String&& releaseMessage() { return WTFMove(m_message); }

    Exception isolatedCopy() const & { return Exception { m_code, m_message.isolatedCopy() }; }
    Exception isolatedCopy() && { return Exception { m_code, WTFMove(m_message).isolatedCopy() }; }

    template<class Encoder> void encode(Encoder&) const;
    template<class Decoder> static std::optional<Exception> decode(Decoder&);
private:
    ExceptionCode m_code;
    String m_message;
};

inline Exception::Exception(ExceptionCode code, String message)
    : m_code { code }
    , m_message { WTFMove(message) }
{
}

template<class Encoder>
void Exception::encode(Encoder& encoder) const
{
    encoder << m_code << m_message;
}

template<class Decoder>
std::optional<Exception> Exception::decode(Decoder& decoder)
{
    std::optional<ExceptionCode> code;
    decoder >> code;
    if (!code)
        return std::nullopt;

    std::optional<String> message;
    decoder >> message;
    if (!message)
        return std::nullopt;

    return Exception {
        *code,
        WTFMove(*message)
    };
}

} // namespace WebCore
