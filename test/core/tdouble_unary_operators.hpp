// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_TDOUBLE_UNARY_OPERATORS_HPP
#define CYNODELIC_TESELA_TEST_CORE_TDOUBLE_UNARY_OPERATORS_HPP


CYNODELIC_TESTER_TEST_CASE(tdouble_unary_operators);

CYNODELIC_TESTER_SECTION(tdouble_unary_operators,plus)
{
	tsl::tdouble value_1(125.0/255.0);
	tsl::tdouble value_2 = +value_1;

	CYNODELIC_TESTER_CHECK_EQUALS(value_1,value_2);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1,+value_1);
}

CYNODELIC_TESTER_SECTION(tdouble_unary_operators,minus)
{
	tsl::tdouble value_1(125.0/255.0);
	tsl::tdouble value_2 = -value_1;

	tsl::tdouble expected(-125.0/255.0);

	CYNODELIC_TESTER_CHECK_EQUALS(value_2,expected);
	CYNODELIC_TESTER_CHECK_EQUALS(expected,-value_1);
}


#endif // CYNODELIC_TESELA_TEST_CORE_TDOUBLE_UNARY_OPERATORS_HPP
