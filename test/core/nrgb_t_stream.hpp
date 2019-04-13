// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_NRGB_T_STREAM_HPP
#define CYNODELIC_TESELA_TEST_CORE_NRGB_T_STREAM_HPP


CYNODELIC_TESTER_TEST_CASE(nrgb_t_stream);

CYNODELIC_TESTER_SECTION(nrgb_t_stream,input)
{
	CYNODELIC_TESTER_MESSAGE
		<< "NOTE: the stringstream used here was set for the maximum precision possible for" << tst::newline
		<< "the nrgb_t's component base type (double), and the strings used here are generated" << tst::newline
		<< "using such stream types." << tst::newline;

	std::stringstream ss;
	ss.precision(std::numeric_limits<typename tsl::nrgb_t::component_base_type>::max_digits10 + 1);

	double input_r = 211.0/255.0;
	double input_g = 121.0/255.0;
	double input_b = 2.0/255.0;

	ss << input_r << ' ' << input_g << ' ' << input_b;

	std::string input_str = ss.str();

	CYNODELIC_TESTER_MESSAGE << "String to insert into stream: " << input_str;

	tsl::nrgb_t test_val;
	ss >> test_val;

	CYNODELIC_TESTER_MESSAGE
		<< "Values for test_val:" << tst::newline
		<< "test_val.red   = " << test_val.red << tst::newline
		<< "test_val.green = " << test_val.green << tst::newline
		<< "test_val.blue  = " << test_val.blue;

	CYNODELIC_TESTER_CHECK_EQUALS(test_val.red,input_r);
	CYNODELIC_TESTER_CHECK_EQUALS(test_val.green,input_g);
	CYNODELIC_TESTER_CHECK_EQUALS(test_val.blue,input_b);
}

CYNODELIC_TESTER_SECTION(nrgb_t_stream,output)
{
	CYNODELIC_TESTER_MESSAGE
		<< "NOTE: the stringstream used here was set for the maximum precision possible for" << tst::newline
		<< "the nrgb_t's component base type (double), and the strings used here are generated" << tst::newline
		<< "using such stream types." << tst::newline;

	std::stringstream ss;
	ss.precision(std::numeric_limits<typename tsl::nrgb_t::component_base_type>::max_digits10 + 1);

	double output_r = 31.0/255.0;
	double output_g = 101.0/255.0;
	double output_b = 6.0/255.0;

	tsl::nrgb_t test_val(output_r,output_g,output_b);

	ss << test_val;

	std::string result = ss.str();

	ss.str(std::string{});

	ss << output_r << ' ' << output_g << ' ' << output_b;

	std::string expected_str = ss.str();

	CYNODELIC_TESTER_MESSAGE << "Stream output: " << result << tst::newline
	                         << "Expected:      " << expected_str;

	CYNODELIC_TESTER_CHECK_EQUALS(result,expected_str);
}


#endif // CYNODELIC_TESELA_TEST_CORE_NRGB_T_STREAM_HPP
