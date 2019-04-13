// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_RGBA_T_INITIALIZATION_HPP
#define CYNODELIC_TESELA_TEST_CORE_RGBA_T_INITIALIZATION_HPP


CYNODELIC_TESTER_TEST_CASE(rgba_t_initialization);

CYNODELIC_TESTER_SECTION(rgba_t_initialization,empty_constructor)
{
	tsl::rgba_t value_0;

	CYNODELIC_TESTER_CHECK_EQUALS(value_0.red,0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_0.green,0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_0.blue,0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_0.alpha,0);
}

CYNODELIC_TESTER_SECTION(rgba_t_initialization,constructor)
{
	tsl::rgba_t value_1(192);
	tsl::rgba_t value_2(255,127);
	tsl::rgba_t value_3(240,100,63);
	tsl::rgba_t value_4(10,255,201,190);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.red   = " << static_cast<unsigned>(value_1.red) << " (red)" << tst::newline
		<< "value_1.green = " << static_cast<unsigned>(value_1.green) << " (green)" << tst::newline
		<< "value_1.blue  = " << static_cast<unsigned>(value_1.blue) << " (blue)" << tst::newline
		<< "value_1.alpha = " << static_cast<unsigned>(value_1.alpha) << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.red,192);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.green,192);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.blue,192);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.alpha,255);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.red   = " << static_cast<unsigned>(value_2.red) << " (red)" << tst::newline
		<< "value_2.green = " << static_cast<unsigned>(value_2.green) << " (green)" << tst::newline
		<< "value_2.blue  = " << static_cast<unsigned>(value_2.blue) << " (blue)" << tst::newline
		<< "value_2.alpha = " << static_cast<unsigned>(value_2.alpha) << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.red,255);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.green,255);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.blue,255);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.alpha,127);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_3" << tst::newline
		<< "value_3.red   = " << static_cast<unsigned>(value_3.red) << " (red)" << tst::newline
		<< "value_3.green = " << static_cast<unsigned>(value_3.green) << " (green)" << tst::newline
		<< "value_3.blue  = " << static_cast<unsigned>(value_3.blue) << " (blue)" << tst::newline
		<< "value_3.alpha = " << static_cast<unsigned>(value_3.alpha) << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_3.red,240);
	CYNODELIC_TESTER_CHECK_EQUALS(value_3.green,100);
	CYNODELIC_TESTER_CHECK_EQUALS(value_3.blue,63);
	CYNODELIC_TESTER_CHECK_EQUALS(value_3.alpha,255);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_4" << tst::newline
		<< "value_4.red   = " << static_cast<unsigned>(value_4.red) << " (red)" << tst::newline
		<< "value_4.green = " << static_cast<unsigned>(value_4.green) << " (green)" << tst::newline
		<< "value_4.blue  = " << static_cast<unsigned>(value_4.blue) << " (blue)" << tst::newline
		<< "value_4.alpha = " << static_cast<unsigned>(value_4.alpha) << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_4.red,10);
	CYNODELIC_TESTER_CHECK_EQUALS(value_4.green,255);
	CYNODELIC_TESTER_CHECK_EQUALS(value_4.blue,201);
	CYNODELIC_TESTER_CHECK_EQUALS(value_4.alpha,190);
}

CYNODELIC_TESTER_SECTION(rgba_t_initialization,assignment)
{
	tsl::rgba_t value_1 = tsl::rgba_t{192};
	tsl::rgba_t value_2 = tsl::rgba_t{255,127};
	tsl::rgba_t value_3 = tsl::rgba_t{240,100,63};
	tsl::rgba_t value_4 = tsl::rgba_t{10,255,201,190};

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.red   = " << static_cast<unsigned>(value_1.red) << " (red)" << tst::newline
		<< "value_1.green = " << static_cast<unsigned>(value_1.green) << " (green)" << tst::newline
		<< "value_1.blue  = " << static_cast<unsigned>(value_1.blue) << " (blue)" << tst::newline
		<< "value_1.alpha = " << static_cast<unsigned>(value_1.alpha) << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.red,192);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.green,192);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.blue,192);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.alpha,255);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.red   = " << static_cast<unsigned>(value_2.red) << " (red)" << tst::newline
		<< "value_2.green = " << static_cast<unsigned>(value_2.green) << " (green)" << tst::newline
		<< "value_2.blue  = " << static_cast<unsigned>(value_2.blue) << " (blue)" << tst::newline
		<< "value_2.alpha = " << static_cast<unsigned>(value_2.alpha) << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.red,255);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.green,255);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.blue,255);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.alpha,127);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_3" << tst::newline
		<< "value_3.red   = " << static_cast<unsigned>(value_3.red) << " (red)" << tst::newline
		<< "value_3.green = " << static_cast<unsigned>(value_3.green) << " (green)" << tst::newline
		<< "value_3.blue  = " << static_cast<unsigned>(value_3.blue) << " (blue)" << tst::newline
		<< "value_3.alpha = " << static_cast<unsigned>(value_3.alpha) << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_3.red,240);
	CYNODELIC_TESTER_CHECK_EQUALS(value_3.green,100);
	CYNODELIC_TESTER_CHECK_EQUALS(value_3.blue,63);
	CYNODELIC_TESTER_CHECK_EQUALS(value_3.alpha,255);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_4" << tst::newline
		<< "value_4.red   = " << static_cast<unsigned>(value_4.red) << " (red)" << tst::newline
		<< "value_4.green = " << static_cast<unsigned>(value_4.green) << " (green)" << tst::newline
		<< "value_4.blue  = " << static_cast<unsigned>(value_4.blue) << " (blue)" << tst::newline
		<< "value_4.alpha = " << static_cast<unsigned>(value_4.alpha) << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_4.red,10);
	CYNODELIC_TESTER_CHECK_EQUALS(value_4.green,255);
	CYNODELIC_TESTER_CHECK_EQUALS(value_4.blue,201);
	CYNODELIC_TESTER_CHECK_EQUALS(value_4.alpha,190);
}


#endif // CYNODELIC_TESELA_TEST_CORE_RGBA_T_INITIALIZATION_HPP
