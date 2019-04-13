// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_RGBA_T_STREAM_HPP
#define CYNODELIC_TESELA_TEST_CORE_RGBA_T_STREAM_HPP


CYNODELIC_TESTER_TEST_CASE(rgba_t_stream);

CYNODELIC_TESTER_SECTION(rgba_t_stream,input)
{
	std::stringstream ss;

	std::string input_str = "250 125 39 101";
	ss << input_str;

	CYNODELIC_TESTER_MESSAGE << "String to insert into stream: " << input_str;

	tsl::rgba_t test_val;
	ss >> test_val;

	CYNODELIC_TESTER_MESSAGE
		<< "Values for test_val:" << tst::newline
		<< "test_val.red = " << static_cast<unsigned>(test_val.red) << tst::newline
		<< "test_val.green = " << static_cast<unsigned>(test_val.green) << tst::newline
		<< "test_val.blue = " << static_cast<unsigned>(test_val.blue) << tst::newline
		<< "test_val.alpha = " << static_cast<unsigned>(test_val.alpha);

	CYNODELIC_TESTER_CHECK_EQUALS(test_val.red,250);
	CYNODELIC_TESTER_CHECK_EQUALS(test_val.green,125);
	CYNODELIC_TESTER_CHECK_EQUALS(test_val.blue,39);
	CYNODELIC_TESTER_CHECK_EQUALS(test_val.alpha,101);
}

CYNODELIC_TESTER_SECTION(rgba_t_stream,output)
{
	std::stringstream ss;

	tsl::rgba_t test_val(30,255,100,99);

	ss << test_val;

	std::string result = ss.str();
	std::string expected_str = "30 255 100 99";

	CYNODELIC_TESTER_MESSAGE << "Stream output: " << result << tst::newline
	                         << "Expected:      " << expected_str;

	CYNODELIC_TESTER_CHECK_EQUALS(result,expected_str);
}


#endif // CYNODELIC_TESELA_TEST_CORE_RGBA_T_STREAM_HPP
