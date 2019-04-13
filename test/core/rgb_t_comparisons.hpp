// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_RGB_T_COMPARISONS_HPP
#define CYNODELIC_TESELA_TEST_CORE_RGB_T_COMPARISONS_HPP


CYNODELIC_TESTER_TEST_CASE(rgb_t_equals);

CYNODELIC_TESTER_SECTION(rgb_t_equals,main)
{
	tsl::rgb_t value_1(50,114,202);
	tsl::rgb_t value_2(50,114,202);
	tsl::rgb_t value_3(255,68,10);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.red   = " << static_cast<unsigned>(value_1.red) << " (red)" << tst::newline
		<< "value_1.green = " << static_cast<unsigned>(value_1.green) << " (green)" << tst::newline
		<< "value_1.blue  = " << static_cast<unsigned>(value_1.blue) << " (blue)"; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.red   = " << static_cast<unsigned>(value_2.red) << " (red)" << tst::newline
		<< "value_2.green = " << static_cast<unsigned>(value_2.green) << " (green)" << tst::newline
		<< "value_2.blue  = " << static_cast<unsigned>(value_2.blue) << " (blue)"; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_3" << tst::newline
		<< "value_3.red   = " << static_cast<unsigned>(value_3.red) << " (red)" << tst::newline
		<< "value_3.green = " << static_cast<unsigned>(value_3.green) << " (green)" << tst::newline
		<< "value_3.blue  = " << static_cast<unsigned>(value_3.blue) << " (blue)";

	CYNODELIC_TESTER_CHECK_EQUALS(value_1.red,value_2.red);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.green,value_2.green);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.blue,value_2.blue);
	CYNODELIC_TESTER_CHECK_TRUE(value_1 == value_2);

	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.red,value_3.red);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.green,value_3.green);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.blue,value_3.blue);
	CYNODELIC_TESTER_CHECK_FALSE(value_1 == value_3);
}


CYNODELIC_TESTER_TEST_CASE(rgb_t_not_equals);

CYNODELIC_TESTER_SECTION(rgb_t_not_equals,main)
{
	tsl::rgb_t value_1(100,200,32);
	tsl::rgb_t value_2(41,140,42);
	tsl::rgb_t value_3(100,200,32);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.red   = " << static_cast<unsigned>(value_1.red) << " (red)" << tst::newline
		<< "value_1.green = " << static_cast<unsigned>(value_1.green) << " (green)" << tst::newline
		<< "value_1.blue  = " << static_cast<unsigned>(value_1.blue) << " (blue)"; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.red   = " << static_cast<unsigned>(value_2.red) << " (red)" << tst::newline
		<< "value_2.green = " << static_cast<unsigned>(value_2.green) << " (green)" << tst::newline
		<< "value_2.blue  = " << static_cast<unsigned>(value_2.blue) << " (blue)"; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_3" << tst::newline
		<< "value_3.red   = " << static_cast<unsigned>(value_3.red) << " (red)" << tst::newline
		<< "value_3.green = " << static_cast<unsigned>(value_3.green) << " (green)" << tst::newline
		<< "value_3.blue  = " << static_cast<unsigned>(value_3.blue) << " (blue)";

	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.red,value_2.red);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.green,value_2.green);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.blue,value_2.blue);
	CYNODELIC_TESTER_CHECK_TRUE(value_1 != value_2);

	CYNODELIC_TESTER_CHECK_EQUALS(value_1.red,value_3.red);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.green,value_3.green);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.blue,value_3.blue);
	CYNODELIC_TESTER_CHECK_FALSE(value_1 != value_3);
}


#endif // CYNODELIC_TESELA_TEST_CORE_RGB_T_COMPARISONS_HPP
