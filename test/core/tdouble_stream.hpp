// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_TDOUBLE_STREAM_HPP
#define CYNODELIC_TESELA_TEST_CORE_TDOUBLE_STREAM_HPP


CYNODELIC_TESTER_TEST_CASE(tdouble_stream);

CYNODELIC_TESTER_SECTION(tdouble_stream,input)
{
	CYNODELIC_TESTER_MESSAGE
		<< "NOTE: the stringstream used here was set for the maximum precision possible for" << tst::newline
		<< "the tdouble's base type (double), and the strings used here are generated using" << tst::newline 
		<< "such stream types." << tst::newline;

	std::stringstream ss;
	ss.precision(std::numeric_limits<typename tsl::tdouble::value_type>::max_digits10 + 1);

	double input_dbl = 194.0/255.0;

	ss << input_dbl;

	std::string input_str = ss.str();

	CYNODELIC_TESTER_MESSAGE << "String to insert into stream: " << input_str;

	tsl::tdouble test_val;
	ss >> test_val;

	tsl::tdouble expected(input_dbl);

	CYNODELIC_TESTER_MESSAGE
		<< "Value of test_val: " << test_val << tst::newline
		<< "Expected value:    " << expected;

	CYNODELIC_TESTER_CHECK_EQUALS(test_val,expected);
}

CYNODELIC_TESTER_SECTION(tdouble_stream,output)
{
	CYNODELIC_TESTER_MESSAGE
		<< "NOTE: the stringstream used here was set for the maximum precision possible for" << tst::newline
		<< "the tdouble's base type (double), and the strings used here are generated using" << tst::newline 
		<< "such stream types." << tst::newline;

	std::stringstream ss;
	ss.precision(std::numeric_limits<typename tsl::tdouble::value_type>::max_digits10 + 1);

	double output_dbl = 234.0/255.0;

	tsl::tdouble test_val(output_dbl);

	ss << test_val;

	std::string result = ss.str();

	ss.str(std::string{});

	ss << output_dbl;

	std::string expected = ss.str();

	CYNODELIC_TESTER_MESSAGE << "Stream output: " << result << tst::newline
	                         << "Expected:      " << expected;
	
	CYNODELIC_TESTER_CHECK_EQUALS(result,expected);	                     
}


#endif // CYNODELIC_TESELA_TEST_CORE_TDOUBLE_STREAM_HPP
