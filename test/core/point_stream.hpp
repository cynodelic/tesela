// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_POINT_STREAM_HPP
#define CYNODELIC_TESELA_TEST_CORE_POINT_STREAM_HPP


CYNODELIC_TESTER_TEST_CASE(point_stream);

CYNODELIC_TESTER_SECTION(point_stream,input)
{
	std::stringstream ss;

	std::string input_str = "30 683";
	ss << input_str;

	CYNODELIC_TESTER_MESSAGE << "String to insert into stream: " << input_str;

	tsl::point test_val;
	ss >> test_val;

	CYNODELIC_TESTER_MESSAGE
		<< "Values for test_val:" << tst::newline
		<< "test_val.x = " << static_cast<unsigned>(test_val.x) << tst::newline
		<< "test_val.y = " << static_cast<unsigned>(test_val.y);

	CYNODELIC_TESTER_CHECK_EQUALS(test_val.x,30);
	CYNODELIC_TESTER_CHECK_EQUALS(test_val.y,683);
}

CYNODELIC_TESTER_SECTION(point_stream,output)
{
	std::stringstream ss;

	tsl::point test_val(77,2);

	ss << test_val;

	std::string result = ss.str();
	std::string expected_str = "77 2";

	CYNODELIC_TESTER_MESSAGE << "Stream output: " << result << tst::newline
	                         << "Expected:      " << expected_str;

	CYNODELIC_TESTER_CHECK_EQUALS(result,expected_str);
}


#endif // CYNODELIC_TESELA_TEST_CORE_POINT_STREAM_HPP
