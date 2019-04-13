// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_NGRAY_T_STREAM_HPP
#define CYNODELIC_TESELA_TEST_CORE_NGRAY_T_STREAM_HPP


CYNODELIC_TESTER_TEST_CASE(ngray_t_stream);

CYNODELIC_TESTER_SECTION(ngray_t_stream,input)
{
	CYNODELIC_TESTER_MESSAGE
		<< "NOTE: the stringstream used here was set for the maximum precision possible for" << tst::newline
		<< "the ngray_t's component base type (double), and the strings used here are generated" << tst::newline
		<< "using such stream types." << tst::newline;

	std::stringstream ss;
	ss.precision(std::numeric_limits<typename tsl::ngray_t::component_base_type>::max_digits10 + 1);

	double input_y = 115.0/255.0;

	ss << input_y;

	std::string input_str = ss.str();

	CYNODELIC_TESTER_MESSAGE << "String to insert into stream: " << input_str;

	tsl::ngray_t test_val;
	ss >> test_val;

	CYNODELIC_TESTER_MESSAGE
		<< "Values for test_val:" << tst::newline
		<< "test_val.gray = " << test_val.gray;

	CYNODELIC_TESTER_CHECK_EQUALS(test_val.gray,input_y);
}

CYNODELIC_TESTER_SECTION(ngray_t_stream,output)
{
	CYNODELIC_TESTER_MESSAGE
		<< "NOTE: the stringstream used here was set for the maximum precision possible for" << tst::newline
		<< "the ngray_t's component base type (double), and the strings used here are generated" << tst::newline
		<< "using such stream types." << tst::newline;

	std::stringstream ss;
	ss.precision(std::numeric_limits<typename tsl::ngray_t::component_base_type>::max_digits10 + 1);

	double output_y = 31.0/255.0;

	tsl::ngray_t test_val(output_y);

	ss << test_val;

	std::string result = ss.str();

	ss.str(std::string{});

	ss << output_y;

	std::string expected_str = ss.str();

	CYNODELIC_TESTER_MESSAGE << "Stream output: " << result << tst::newline
	                         << "Expected:      " << expected_str;

	CYNODELIC_TESTER_CHECK_EQUALS(result,expected_str);
}


#endif // CYNODELIC_TESELA_TEST_CORE_NGRAY_T_STREAM_HPP
