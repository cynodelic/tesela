// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_GRAY_T_INITIALIZATION_HPP
#define CYNODELIC_TESELA_TEST_CORE_GRAY_T_INITIALIZATION_HPP


CYNODELIC_TESTER_TEST_CASE(gray_t_initialization);

CYNODELIC_TESTER_SECTION(gray_t_initialization,empty_constructor)
{
	tsl::gray_t value_0;

	CYNODELIC_TESTER_CHECK_EQUALS(value_0.gray,0);
}

CYNODELIC_TESTER_SECTION(gray_t_initialization,constructor)
{
	tsl::gray_t value_1(99);
	tsl::gray_t value_2(188);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.gray = " << static_cast<unsigned>(value_1.gray) << " (gray)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.gray,99);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.gray = " << static_cast<unsigned>(value_2.gray) << " (gray)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.gray,188);
}

CYNODELIC_TESTER_SECTION(gray_t_initialization,assignment)
{
	tsl::gray_t value_1 = tsl::gray_t{99};
	tsl::gray_t value_2 = tsl::gray_t{188};

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.gray = " << static_cast<unsigned>(value_1.gray) << " (gray)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.gray,99);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_2" << tst::newline
		<< "value_2.gray = " << static_cast<unsigned>(value_2.gray) << " (gray)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_2.gray,188);
}


#endif // CYNODELIC_TESELA_TEST_CORE_GRAY_T_INITIALIZATION_HPP
