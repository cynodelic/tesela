// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_GA_T_INITIALIZATION_HPP
#define CYNODELIC_TESELA_TEST_CORE_GA_T_INITIALIZATION_HPP


CYNODELIC_TESTER_TEST_CASE(ga_t_initialization);

CYNODELIC_TESTER_SECTION(ga_t_initialization,empty_constructor)
{
	tsl::ga_t value_0;

	CYNODELIC_TESTER_CHECK_EQUALS(value_0.gray,0);
	CYNODELIC_TESTER_CHECK_EQUALS(value_0.alpha,0);
}

CYNODELIC_TESTER_SECTION(ga_t_initialization,constructor)
{
	tsl::ga_t value_1(64);
	tsl::ga_t value_2(102,249);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.gray  = " << static_cast<unsigned>(value_1.gray) << " (gray)" << tst::newline
		<< "value_1.alpha = " << static_cast<unsigned>(value_1.alpha) << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.gray,64);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.alpha,255);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.gray  = " << static_cast<unsigned>(value_2.gray) << " (gray)" << tst::newline
		<< "value_2.alpha = " << static_cast<unsigned>(value_2.alpha) << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.gray,102);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.alpha,249);
}

CYNODELIC_TESTER_SECTION(ga_t_initialization,assignment)
{
	tsl::ga_t value_1 = tsl::ga_t{64};
	tsl::ga_t value_2 = tsl::ga_t{102,249};

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.gray  = " << static_cast<unsigned>(value_1.gray) << " (gray)" << tst::newline
		<< "value_1.alpha = " << static_cast<unsigned>(value_1.alpha) << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.gray,64);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.alpha,255);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.gray  = " << static_cast<unsigned>(value_2.gray) << " (gray)" << tst::newline
		<< "value_2.alpha = " << static_cast<unsigned>(value_2.alpha) << " (alpha)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.gray,102);
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.alpha,249);
}


#endif // CYNODELIC_TESELA_TEST_CORE_GA_T_INITIALIZATION_HPP
