// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_NRGB_T_COMPARISONS_HPP
#define CYNODELIC_TESELA_TEST_CORE_NRGB_T_COMPARISONS_HPP


CYNODELIC_TESTER_TEST_CASE(nrgb_t_equals);

CYNODELIC_TESTER_SECTION(nrgb_t_equals,main)
{
	tsl::nrgb_t value_1(204.0/255.0,59.0/255.0,111.0/255.0);
	tsl::nrgb_t value_2(204.0/255.0,59.0/255.0,111.0/255.0);
	tsl::nrgb_t value_3(13.0/255.0,70.0/255.0,229.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.red   = " << value_1.red << " (red)" << tst::newline
		<< "value_1.green = " << value_1.green << " (green)" << tst::newline
		<< "value_1.blue  = " << value_1.blue << " (blue)"; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.red   = " << value_2.red << " (red)" << tst::newline
		<< "value_2.green = " << value_2.green << " (green)" << tst::newline
		<< "value_2.blue  = " << value_2.blue << " (blue)"; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_3" << tst::newline
		<< "value_3.red   = " << value_3.red << " (red)" << tst::newline
		<< "value_3.green = " << value_3.green << " (green)" << tst::newline
		<< "value_3.blue  = " << value_3.blue << " (blue)";

	CYNODELIC_TESTER_CHECK_EQUALS(value_1.red,value_2.red);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.green,value_2.green);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.blue,value_2.blue);
	CYNODELIC_TESTER_CHECK_TRUE(value_1 == value_2);

	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.red,value_3.red);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.green,value_3.green);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.blue,value_3.blue);
	CYNODELIC_TESTER_CHECK_FALSE(value_1 == value_3);
}


CYNODELIC_TESTER_TEST_CASE(nrgb_t_not_equals);

CYNODELIC_TESTER_SECTION(nrgb_t_not_equals,main)
{
	tsl::nrgb_t value_1(31.0/255.0,103.0/255.0,250.0/255.0);
	tsl::nrgb_t value_2(133.0/255.0,67.0/255.0,222.0/255.0);
	tsl::nrgb_t value_3(31.0/255.0,103.0/255.0,250.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.red   = " << value_1.red << " (red)" << tst::newline
		<< "value_1.green = " << value_1.green << " (green)" << tst::newline
		<< "value_1.blue  = " << value_1.blue << " (blue)"; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.red   = " << value_2.red << " (red)" << tst::newline
		<< "value_2.green = " << value_2.green << " (green)" << tst::newline
		<< "value_2.blue  = " << value_2.blue << " (blue)"; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_3" << tst::newline
		<< "value_3.red   = " << value_3.red << " (red)" << tst::newline
		<< "value_3.green = " << value_3.green << " (green)" << tst::newline
		<< "value_3.blue  = " << value_3.blue << " (blue)";

	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.red,value_2.red);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.green,value_2.green);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.blue,value_2.blue);
	CYNODELIC_TESTER_CHECK_TRUE(value_1 != value_2);

	CYNODELIC_TESTER_CHECK_EQUALS(value_1.red,value_3.red);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.green,value_3.green);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.blue,value_3.blue);
	CYNODELIC_TESTER_CHECK_FALSE(value_1 != value_3);
}


#endif // CYNODELIC_TESELA_TEST_CORE_NRGB_T_COMPARISONS_HPP
