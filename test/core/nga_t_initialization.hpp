// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_NGA_T_INITIALIZATION_HPP
#define CYNODELIC_TESELA_TEST_CORE_NGA_T_INITIALIZATION_HPP


CYNODELIC_TESTER_TEST_CASE(nga_t_initialization);

CYNODELIC_TESTER_SECTION(nga_t_initialization,empty_constructor)
{
	tsl::nga_t value_0;

	CYNODELIC_TESTER_CHECK_EQUALS(value_0.gray,0.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_0.alpha,0.0);
}

CYNODELIC_TESTER_SECTION(nga_t_initialization,constructor)
{
	tsl::nga_t value_1(241.0/255.0);
	tsl::nga_t value_2(120.0/255.0,61.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.gray  = " << value_1.gray << " (gray)" << tst::newline
		<< "value_1.alpha = " << value_1.alpha << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.gray,241.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.alpha,1.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.gray  = " << value_2.gray << " (gray)" << tst::newline
		<< "value_2.alpha = " << value_2.alpha << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.gray,120.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.alpha,61.0/255.0);
}

CYNODELIC_TESTER_SECTION(nga_t_initialization,assignment)
{
	tsl::nga_t value_1 = tsl::nga_t{241.0/255.0};
	tsl::nga_t value_2 = tsl::nga_t{120.0/255.0,61.0/255.0};

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.gray  = " << value_1.gray << " (gray)" << tst::newline
		<< "value_1.alpha = " << value_1.alpha << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.gray,241.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.alpha,1.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.gray  = " << value_2.gray << " (gray)" << tst::newline
		<< "value_2.alpha = " << value_2.alpha << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.gray,120.0/255.0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.alpha,61.0/255.0);
}


#endif // CYNODELIC_TESELA_TEST_CORE_NGA_T_INITIALIZATION_HPP
