// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_NRGB_T_INITIALIZATION_HPP
#define CYNODELIC_TESELA_TEST_CORE_NRGB_T_INITIALIZATION_HPP


CYNODELIC_TESTER_TEST_CASE(nrgb_t_initialization);

CYNODELIC_TESTER_SECTION(nrgb_t_initialization,empty_constructor)
{
	tsl::nrgb_t value_0;

	CYNODELIC_TESTER_CHECK_EQUALS(value_0.red,0.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_0.green,0.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_0.blue,0.0);
}

CYNODELIC_TESTER_SECTION(nrgb_t_initialization,constructor)
{
	tsl::nrgb_t value_1(241.0/255.0);
	tsl::nrgb_t value_2(176.0/255.0,1.0,200.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.red   = " << value_1.red << " (red)" << tst::newline
		<< "value_1.green = " << value_1.green << " (green)" << tst::newline
		<< "value_1.blue  = " << value_1.blue << " (blue)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.red,241.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.green,241.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.blue,241.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.red   = " << value_2.red << " (red)" << tst::newline
		<< "value_2.green = " << value_2.green << " (green)" << tst::newline
		<< "value_2.blue  = " << value_2.blue << " (blue)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.red,176.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.green,1.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.blue,200.0/255.0);
}

CYNODELIC_TESTER_SECTION(nrgb_t_initialization,assignment)
{
	tsl::nrgb_t value_1 = tsl::nrgb_t{241.0/255.0};
	tsl::nrgb_t value_2 = tsl::nrgb_t{176.0/255.0,1.0,200.0/255.0};

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.red   = " << value_1.red << " (red)" << tst::newline
		<< "value_1.green = " << value_1.green << " (green)" << tst::newline
		<< "value_1.blue  = " << value_1.blue << " (blue)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.red,241.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.green,241.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.blue,241.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.red   = " << value_2.red << " (red)" << tst::newline
		<< "value_2.green = " << value_2.green << " (green)" << tst::newline
		<< "value_2.blue  = " << value_2.blue << " (blue)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.red,176.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.green,1.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.blue,200.0/255.0);
}


#endif // CYNODELIC_TESELA_TEST_CORE_NRGB_T_INITIALIZATION_HPP
