// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_NRGBA_T_INITIALIZATION_HPP
#define CYNODELIC_TESELA_TEST_CORE_NRGBA_T_INITIALIZATION_HPP


CYNODELIC_TESTER_TEST_CASE(nrgba_t_initialization);

CYNODELIC_TESTER_SECTION(nrgba_t_initialization,empty_constructor)
{
	tsl::nrgba_t value_0;

	CYNODELIC_TESTER_CHECK_EQUALS(value_0.red,0.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_0.green,0.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_0.blue,0.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_0.alpha,0.0);
}

CYNODELIC_TESTER_SECTION(nrgba_t_initialization,constructor)
{
	tsl::nrgba_t value_1(241.0/255.0);
	tsl::nrgba_t value_2(120.0/255.0,61.0/255.0);
	tsl::nrgba_t value_3(176.0/255.0,1.0,200.0/255.0);
	tsl::nrgba_t value_4(74.0/255.0,123.0/255.0,40.0/255.0,219.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.red   = " << value_1.red << " (red)" << tst::newline
		<< "value_1.green = " << value_1.green << " (green)" << tst::newline
		<< "value_1.blue  = " << value_1.blue << " (blue)" << tst::newline
		<< "value_1.alpha = " << value_1.alpha << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.red,241.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.green,241.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.blue,241.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.alpha,1.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.red   = " << value_2.red << " (red)" << tst::newline
		<< "value_2.green = " << value_2.green << " (green)" << tst::newline
		<< "value_2.blue  = " << value_2.blue << " (blue)" << tst::newline
		<< "value_2.alpha = " << value_2.alpha << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.red,120.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.green,120.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.blue,120.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.alpha,61.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_3" << tst::newline
		<< "value_3.red   = " << value_3.red << " (red)" << tst::newline
		<< "value_3.green = " << value_3.green << " (green)" << tst::newline
		<< "value_3.blue  = " << value_3.blue << " (blue)" << tst::newline
		<< "value_3.alpha = " << value_3.alpha << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_3.red,176.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_3.green,1.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_3.blue,200.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_3.alpha,1.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_4" << tst::newline
		<< "value_4.red   = " << value_4.red << " (red)" << tst::newline
		<< "value_4.green = " << value_4.green << " (green)" << tst::newline
		<< "value_4.blue  = " << value_4.blue << " (blue)" << tst::newline
		<< "value_4.alpha = " << value_4.alpha << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_4.red,74.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_4.green,123.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_4.blue,40.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_4.alpha,219.0/255.0);
}

CYNODELIC_TESTER_SECTION(nrgba_t_initialization,assignment)
{
	tsl::nrgba_t value_1 = tsl::nrgba_t{241.0/255.0};
	tsl::nrgba_t value_2 = tsl::nrgba_t{120.0/255.0,61.0/255.0};
	tsl::nrgba_t value_3 = tsl::nrgba_t{176.0/255.0,1.0,200.0/255.0};
	tsl::nrgba_t value_4 = tsl::nrgba_t{74.0/255.0,123.0/255.0,40.0/255.0,219.0/255.0};

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.red   = " << value_1.red << " (red)" << tst::newline
		<< "value_1.green = " << value_1.green << " (green)" << tst::newline
		<< "value_1.blue  = " << value_1.blue << " (blue)" << tst::newline
		<< "value_1.alpha = " << value_1.alpha << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.red,241.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.green,241.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.blue,241.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.alpha,1.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.red   = " << value_2.red << " (red)" << tst::newline
		<< "value_2.green = " << value_2.green << " (green)" << tst::newline
		<< "value_2.blue  = " << value_2.blue << " (blue)" << tst::newline
		<< "value_2.alpha = " << value_2.alpha << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.red,120.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.green,120.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.blue,120.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.alpha,61.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_3" << tst::newline
		<< "value_3.red   = " << value_3.red << " (red)" << tst::newline
		<< "value_3.green = " << value_3.green << " (green)" << tst::newline
		<< "value_3.blue  = " << value_3.blue << " (blue)" << tst::newline
		<< "value_3.alpha = " << value_3.alpha << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_3.red,176.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_3.green,1.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_3.blue,200.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_3.alpha,1.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_4" << tst::newline
		<< "value_4.red   = " << value_4.red << " (red)" << tst::newline
		<< "value_4.green = " << value_4.green << " (green)" << tst::newline
		<< "value_4.blue  = " << value_4.blue << " (blue)" << tst::newline
		<< "value_4.alpha = " << value_4.alpha << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_4.red,74.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_4.green,123.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_4.blue,40.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_4.alpha,219.0/255.0);
}


#endif // CYNODELIC_TESELA_TEST_CORE_NRGBA_T_INITIALIZATION_HPP
