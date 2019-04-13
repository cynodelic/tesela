// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_GA_T_COMPARISONS_HPP
#define CYNODELIC_TESELA_TEST_CORE_GA_T_COMPARISONS_HPP


CYNODELIC_TESTER_TEST_CASE(ga_t_equals);

CYNODELIC_TESTER_SECTION(ga_t_equals,main)
{
	tsl::ga_t value_1(253,41);
	tsl::ga_t value_2(253,41);
	tsl::ga_t value_3(5,255);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.gray  = " << static_cast<unsigned>(value_1.gray) << " (gray)" << tst::newline
		<< "value_1.alpha = " << static_cast<unsigned>(value_1.alpha) << " (alpha)"; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.gray  = " << static_cast<unsigned>(value_2.gray) << " (gray)" << tst::newline
		<< "value_2.alpha = " << static_cast<unsigned>(value_2.alpha) << " (alpha)"; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_3" << tst::newline
		<< "value_3.gray  = " << static_cast<unsigned>(value_3.gray) << " (gray)" << tst::newline
		<< "value_3.alpha = " << static_cast<unsigned>(value_3.alpha) << " (alpha)";

	CYNODELIC_TESTER_CHECK_EQUALS(value_1.gray,value_2.gray);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.alpha,value_2.alpha);
	CYNODELIC_TESTER_CHECK_TRUE(value_1 == value_2);

	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.gray,value_3.gray);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.alpha,value_3.alpha);
	CYNODELIC_TESTER_CHECK_FALSE(value_1 == value_3);
}


CYNODELIC_TESTER_TEST_CASE(ga_t_not_equals);

CYNODELIC_TESTER_SECTION(ga_t_not_equals,main)
{
	tsl::ga_t value_1(200,1);
	tsl::ga_t value_2(45,193);
	tsl::ga_t value_3(200,1);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.gray  = " << static_cast<unsigned>(value_1.gray) << " (gray)" << tst::newline
		<< "value_1.alpha = " << static_cast<unsigned>(value_1.alpha) << " (alpha)"; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.gray  = " << static_cast<unsigned>(value_2.gray) << " (gray)" << tst::newline
		<< "value_2.alpha = " << static_cast<unsigned>(value_2.alpha) << " (alpha)"; 

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_3" << tst::newline
		<< "value_3.gray  = " << static_cast<unsigned>(value_3.gray) << " (gray)" << tst::newline
		<< "value_3.alpha = " << static_cast<unsigned>(value_3.alpha) << " (alpha)";

	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.gray,value_2.gray);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.alpha,value_2.alpha);
	CYNODELIC_TESTER_CHECK_TRUE(value_1 != value_2);

	CYNODELIC_TESTER_CHECK_EQUALS(value_1.gray,value_3.gray);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.alpha,value_3.alpha);
	CYNODELIC_TESTER_CHECK_FALSE(value_1 != value_3);
}


#endif // CYNODELIC_TESELA_TEST_CORE_GA_T_COMPARISONS_HPP
