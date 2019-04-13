// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_RECTANGLE_STREAM_HPP
#define CYNODELIC_TESELA_TEST_CORE_RECTANGLE_STREAM_HPP


CYNODELIC_TESTER_TEST_CASE(rectangle_stream);

CYNODELIC_TESTER_SECTION(rectangle_stream,input)
{
	std::stringstream ss;

	std::string input_str = "240 240 35 411";
	ss << input_str;

	CYNODELIC_TESTER_MESSAGE << "String to insert into stream: " << input_str;

	tsl::rectangle test_val;
	ss >> test_val;

	CYNODELIC_TESTER_MESSAGE
		<< "Values for test_val:" << tst::newline
		<< "test_val.width = " << test_val.width << tst::newline
		<< "test_val.height = " << test_val.height << tst::newline
		<< "test_val.x = " << test_val.x << tst::newline
		<< "test_val.y = " << test_val.y;

	CYNODELIC_TESTER_CHECK_EQUALS(test_val.width,240);
	CYNODELIC_TESTER_CHECK_EQUALS(test_val.height,240);
	CYNODELIC_TESTER_CHECK_EQUALS(test_val.x,35);
	CYNODELIC_TESTER_CHECK_EQUALS(test_val.y,411);
}

CYNODELIC_TESTER_SECTION(rectangle_stream,output)
{
	std::stringstream ss;

	tsl::rectangle test_val(200,121,59,54);

	ss << test_val;

	std::string result = ss.str();
	std::string expected_str = "200 121 59 54";

	CYNODELIC_TESTER_MESSAGE << "Stream output: " << result << tst::newline
	                         << "Expected:      " << expected_str;

	CYNODELIC_TESTER_CHECK_EQUALS(result,expected_str);
}


#endif // CYNODELIC_TESELA_TEST_CORE_RECTANGLE_STREAM_HPP
