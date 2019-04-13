// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_TDOUBLE_COPY_HPP
#define CYNODELIC_TESELA_TEST_CORE_TDOUBLE_COPY_HPP


CYNODELIC_TESTER_TEST_CASE(tdouble_copy);

CYNODELIC_TESTER_SECTION(tdouble_copy,copy_constructor)
{
	tsl::tdouble tdbl1(45.0/255.0);

	CYNODELIC_TESTER_MESSAGE << "Value of tdbl1: " << tdbl1;

	tsl::tdouble tdbl2(tdbl1);

	CYNODELIC_TESTER_ASSERT_EQUALS(tdbl1.get(),tdbl2.get());
}

CYNODELIC_TESTER_SECTION(tdouble_copy,copy_assignment)
{
	tsl::tdouble tdbl1(50.0/255.0);

	CYNODELIC_TESTER_MESSAGE << "Value of tdbl1: " << tdbl1;

	tsl::tdouble tdbl2;
	tdbl2 = tdbl1;

	CYNODELIC_TESTER_ASSERT_EQUALS(tdbl1.get(),tdbl2.get());
}



#endif // CYNODELIC_TESELA_TEST_CORE_TDOUBLE_COPY_HPP
