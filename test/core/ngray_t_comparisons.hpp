// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_NGRAY_T_COMPARISONS_HPP
#define CYNODELIC_TESELA_TEST_CORE_NGRAY_T_COMPARISONS_HPP


CYNODELIC_TESTER_TEST_CASE(ngray_t_equals);

CYNODELIC_TESTER_SECTION(ngray_t_equals,main)
{
	tsl::ngray_t value_1(249.0/255.0);
	tsl::ngray_t value_2(249.0/255.0);
	tsl::ngray_t value_3( 35.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.gray = " << value_1.gray << " (gray)"; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.gray = " << value_2.gray << " (gray)" << tst::newline; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_3" << tst::newline
		<< "value_3.gray = " << value_3.gray << " (gray)" << tst::newline;

	CYNODELIC_TESTER_CHECK_EQUALS(value_1.gray,value_2.gray);
	CYNODELIC_TESTER_CHECK_TRUE(value_1 == value_2);

	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.gray,value_3.gray);
	CYNODELIC_TESTER_CHECK_FALSE(value_1 == value_3);
}


CYNODELIC_TESTER_TEST_CASE(ngray_t_not_equals);

CYNODELIC_TESTER_SECTION(ngray_t_not_equals,main)
{
	tsl::ngray_t value_1(145.0/255.0);
	tsl::ngray_t value_2(1.0);
	tsl::ngray_t value_3(145.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.gray = " << value_1.gray << " (gray)"; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.gray = " << value_2.gray << " (gray)" << tst::newline; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_3" << tst::newline
		<< "value_3.gray = " << value_3.gray << " (gray)" << tst::newline;

	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.gray,value_2.gray);
	CYNODELIC_TESTER_CHECK_TRUE(value_1 != value_2);

	CYNODELIC_TESTER_CHECK_EQUALS(value_1.gray,value_3.gray);
	CYNODELIC_TESTER_CHECK_FALSE(value_1 != value_3);
}


#endif // CYNODELIC_TESELA_TEST_CORE_NGRAY_T_COMPARISONS_HPP
