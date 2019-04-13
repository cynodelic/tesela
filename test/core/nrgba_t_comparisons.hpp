// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_NRGBA_T_COMPARISONS_HPP
#define CYNODELIC_TESELA_TEST_CORE_NRGBA_T_COMPARISONS_HPP


CYNODELIC_TESTER_TEST_CASE(nrgba_t_equals);

CYNODELIC_TESTER_SECTION(nrgba_t_equals,main)
{
	tsl::nrgba_t value_1(152.0/255.0,1.0,69.0/255.0,101.0/255.0);
	tsl::nrgba_t value_2(152.0/255.0,1.0,69.0/255.0,101.0/255.0);
	tsl::nrgba_t value_3(200.0/255.0,49.0/255.0,25.0/255.0,140.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.red   = " << value_1.red << " (red)" << tst::newline
		<< "value_1.green = " << value_1.green << " (green)" << tst::newline
		<< "value_1.blue  = " << value_1.blue << " (blue)" << tst::newline
		<< "value_1.alpha = " << value_1.alpha << " (alpha)"; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.red   = " << value_2.red << " (red)" << tst::newline
		<< "value_2.green = " << value_2.green << " (green)" << tst::newline
		<< "value_2.blue  = " << value_2.blue << " (blue)" << tst::newline
		<< "value_2.alpha = " << value_2.alpha << " (alpha)"; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_3" << tst::newline
		<< "value_3.red   = " << value_3.red << " (red)" << tst::newline
		<< "value_3.green = " << value_3.green << " (green)" << tst::newline
		<< "value_3.blue  = " << value_3.blue << " (blue)" << tst::newline
		<< "value_3.alpha = " << value_3.alpha << " (alpha)";

	CYNODELIC_TESTER_CHECK_EQUALS(value_1.red,value_2.red);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.green,value_2.green);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.blue,value_2.blue);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.alpha,value_2.alpha);
	CYNODELIC_TESTER_CHECK_TRUE(value_1 == value_2);

	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.red,value_3.red);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.green,value_3.green);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.blue,value_3.blue);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.alpha,value_3.alpha);
	CYNODELIC_TESTER_CHECK_FALSE(value_1 == value_3);
}


CYNODELIC_TESTER_TEST_CASE(nrgba_t_not_equals);

CYNODELIC_TESTER_SECTION(nrgba_t_not_equals,main)
{
	tsl::nrgba_t value_1(75.0/255.0,204.0/255.0,2.0/255.0,254.0/255.0);
	tsl::nrgba_t value_2(115.0/255.0,1.0/255.0,97.0/255.0,109.0/255.0);
	tsl::nrgba_t value_3(75.0/255.0,204.0/255.0,2.0/255.0,254.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.red   = " << value_1.red << " (red)" << tst::newline
		<< "value_1.green = " << value_1.green << " (green)" << tst::newline
		<< "value_1.blue  = " << value_1.blue << " (blue)" << tst::newline
		<< "value_1.alpha = " << value_1.alpha << " (alpha)"; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.red   = " << value_2.red << " (red)" << tst::newline
		<< "value_2.green = " << value_2.green << " (green)" << tst::newline
		<< "value_2.blue  = " << value_2.blue << " (blue)" << tst::newline
		<< "value_2.alpha = " << value_2.alpha << " (alpha)"; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_3" << tst::newline
		<< "value_3.red   = " << value_3.red << " (red)" << tst::newline
		<< "value_3.green = " << value_3.green << " (green)" << tst::newline
		<< "value_3.blue  = " << value_3.blue << " (blue)" << tst::newline
		<< "value_3.alpha = " << value_3.alpha << " (alpha)";

	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.red,value_2.red);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.green,value_2.green);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.blue,value_2.blue);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.alpha,value_2.alpha);
	CYNODELIC_TESTER_CHECK_TRUE(value_1 != value_2);

	CYNODELIC_TESTER_CHECK_EQUALS(value_1.red,value_3.red);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.green,value_3.green);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.blue,value_3.blue);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.alpha,value_3.alpha);
	CYNODELIC_TESTER_CHECK_FALSE(value_1 != value_3);
}


#endif // CYNODELIC_TESELA_TEST_CORE_NRGBA_T_COMPARISONS_HPP
