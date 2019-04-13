// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_GA_T_STREAM_HPP
#define CYNODELIC_TESELA_TEST_CORE_GA_T_STREAM_HPP


CYNODELIC_TESTER_TEST_CASE(ga_t_stream);

CYNODELIC_TESTER_SECTION(ga_t_stream,input)
{
	std::stringstream ss;

	std::string input_str = "46 144";
	ss << input_str;

	CYNODELIC_TESTER_MESSAGE << "String to insert into stream: " << input_str;

	tsl::ga_t test_val;
	ss >> test_val;

	CYNODELIC_TESTER_MESSAGE
		<< "Values for test_val:" << tst::newline
		<< "test_val.gray  = " << static_cast<unsigned>(test_val.gray) << tst::newline
		<< "test_val.alpha = " << static_cast<unsigned>(test_val.alpha);

	CYNODELIC_TESTER_CHECK_EQUALS(test_val.gray,46);
	CYNODELIC_TESTER_CHECK_EQUALS(test_val.alpha,144);
}

CYNODELIC_TESTER_SECTION(ga_t_stream,output)
{
	std::stringstream ss;

	tsl::ga_t test_val(145,200);

	ss << test_val;

	std::string result = ss.str();
	std::string expected_str = "145 200";

	CYNODELIC_TESTER_MESSAGE << "Stream output: " << result << tst::newline
	                         << "Expected:      " << expected_str;

	CYNODELIC_TESTER_CHECK_EQUALS(result,expected_str);
}


#endif // CYNODELIC_TESELA_TEST_CORE_GA_T_STREAM_HPP
