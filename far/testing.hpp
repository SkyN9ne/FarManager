﻿#ifndef TESTING_HPP_DF49B287_DB16_4C12_AB55_9D6F14D3A409
#define TESTING_HPP_DF49B287_DB16_4C12_AB55_9D6F14D3A409
#pragma once

/*
testing.hpp

Testing framework wrapper

*/
/*
Copyright © 2019 Far Group
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The name of the authors may not be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifdef ENABLE_TESTS

#ifndef TESTS_ENTRYPOINT_ONLY

#include "disable_warnings_in_std_begin.hpp"

WARNING_PUSH()

WARNING_DISABLE_MSC(5204) // 'class': class has virtual functions, but its trivial destructor is not virtual; instances of objects derived from this class may not be destructed correctly
WARNING_DISABLE_CLANG("-Weverything")

#define CATCH_CONFIG_ENABLE_ALL_STRINGMAKERS
// It's rubbish
#define CATCH_CONFIG_NO_WINDOWS_SEH

#include "thirdparty/catch2/catch.hpp"

WARNING_POP()

#include "disable_warnings_in_std_end.hpp"

class generic_exception_matcher: public Catch::MatcherBase<std::any>
{
public:
	explicit generic_exception_matcher(std::function<bool(std::any const&)> Matcher);

	bool match(std::any const& e) const override;
	std::string describe() const override;

private:
	std::function<bool(std::any const&)> m_Matcher;
};

#endif

std::optional<int> testing_main(int Argc, wchar_t const* const Argv[]);

#endif

#endif // TESTING_HPP_DF49B287_DB16_4C12_AB55_9D6F14D3A409
