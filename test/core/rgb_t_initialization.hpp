// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_RGB_T_INITIALIZATION_HPP
#define CYNODELIC_TESELA_TEST_CORE_RGB_T_INITIALIZATION_HPP


CYNODELIC_TESTER_TEST_CASE(rgb_t_initialization);

CYNODELIC_TESTER_SECTION(rgb_t_initialization,empty_constructor)
{
	tsl::rgb_t value_0;

	CYNODELIC_TESTER_CHECK_EQUALS(value_0.red,0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_0.green,0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_0.blue,0);
}

CYNODELIC_TESTER_SECTION(rgb_t_initialization,constructor)
{
	tsl::rgb_t value_1(192);
	tsl::rgb_t value_2(240,100,63);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.red   = " << static_cast<unsigned>(value_1.red) << " (red)" << tst::newline
		<< "value_1.green = " << static_cast<unsigned>(value_1.green) << " (green)" << tst::newline
		<< "value_1.blue  = " << static_cast<unsigned>(value_1.blue) << " (blue)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.red,192);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.green,192);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.blue,192);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.red   = " << static_cast<unsigned>(value_2.red) << " (red)" << tst::newline
		<< "value_2.green = " << static_cast<unsigned>(value_2.green) << " (green)" << tst::newline
		<< "value_2.blue  = " << static_cast<unsigned>(value_2.blue) << " (blue)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.red,240);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.green,100);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.blue,63);
}

CYNODELIC_TESTER_SECTION(rgb_t_initialization,assignment)
{
	tsl::rgb_t value_1 = tsl::rgb_t{192};
	tsl::rgb_t value_2 = tsl::rgb_t{240,100,63};

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.red   = " << static_cast<unsigned>(value_1.red) << " (red)" << tst::newline
		<< "value_1.green = " << static_cast<unsigned>(value_1.green) << " (green)" << tst::newline
		<< "value_1.blue  = " << static_cast<unsigned>(value_1.blue) << " (blue)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.red,192);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.green,192);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.blue,192);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.red   = " << static_cast<unsigned>(value_2.red) << " (red)" << tst::newline
		<< "value_2.green = " << static_cast<unsigned>(value_2.green) << " (green)" << tst::newline
		<< "value_2.blue  = " << static_cast<unsigned>(value_2.blue) << " (blue)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.red,240);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.green,100);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.blue,63);
}


#endif // CYNODELIC_TESELA_TEST_CORE_RGB_T_INITIALIZATION_HPP
