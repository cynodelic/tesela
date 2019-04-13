// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_TDOUBLE_COMPARISONS_HPP
#define CYNODELIC_TESELA_TEST_CORE_TDOUBLE_COMPARISONS_HPP


CYNODELIC_TESTER_TEST_CASE(tdouble_equals);

CYNODELIC_TESTER_SECTION(tdouble_equals,main)
{
	tsl::tdouble value_1(149.0/255.0);
	tsl::tdouble value_2(149.0/255.0);
	tsl::tdouble value_3(245.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values used:" << tst::newline
		<< "value_1 = " << value_1 << tst::newline
		<< "value_2 = " << value_2 << tst::newline
		<< "value_3 = " << value_3;

	CYNODELIC_TESTER_CHECK_TRUE(value_1 == value_2);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.get(),value_2.get());

	CYNODELIC_TESTER_CHECK_FALSE(value_1 == value_3);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.get(),value_3.get());
}


CYNODELIC_TESTER_TEST_CASE(tdouble_not_equals);

CYNODELIC_TESTER_SECTION(tdouble_not_equals,main)
{
	tsl::tdouble value_1(221.0/255.0);
	tsl::tdouble value_2(301.0/255.0);
	tsl::tdouble value_3(221.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values used:" << tst::newline
		<< "value_1 = " << value_1 << tst::newline
		<< "value_2 = " << value_2 << tst::newline
		<< "value_3 = " << value_3;

	CYNODELIC_TESTER_CHECK_TRUE(value_1 != value_2);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(value_1.get(),value_2.get());

	CYNODELIC_TESTER_CHECK_FALSE(value_1 != value_3);
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.get(),value_3.get());
}


CYNODELIC_TESTER_TEST_CASE(tdouble_greater);

CYNODELIC_TESTER_SECTION(tdouble_greater,main)
{
	tsl::tdouble value_1(199.0/255.0);
	tsl::tdouble value_2(56.0/255.0);
	tsl::tdouble value_3(200.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values used:" << tst::newline
		<< "value_1 = " << value_1 << tst::newline
		<< "value_2 = " << value_2 << tst::newline
		<< "value_3 = " << value_3;

	CYNODELIC_TESTER_CHECK_TRUE(value_1 > value_2);
	CYNODELIC_TESTER_CHECK_GREATER(value_1.get(),value_2.get());

	CYNODELIC_TESTER_CHECK_FALSE(value_1 > value_3);
	CYNODELIC_TESTER_CHECK_LEQ(value_1.get(),value_3.get());
}


CYNODELIC_TESTER_TEST_CASE(tdouble_less);

CYNODELIC_TESTER_SECTION(tdouble_less,main)
{
	tsl::tdouble value_1(401.0/255.0);
	tsl::tdouble value_2(441.0/255.0);
	tsl::tdouble value_3(1.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values used:" << tst::newline
		<< "value_1 = " << value_1 << tst::newline
		<< "value_2 = " << value_2 << tst::newline
		<< "value_3 = " << value_3;

	CYNODELIC_TESTER_CHECK_TRUE(value_1 < value_2);
	CYNODELIC_TESTER_CHECK_LESS(value_1.get(),value_2.get());

	CYNODELIC_TESTER_CHECK_FALSE(value_1 < value_3);
	CYNODELIC_TESTER_CHECK_GEQ(value_1.get(),value_3.get());
}


CYNODELIC_TESTER_TEST_CASE(tdouble_greater_equals);

CYNODELIC_TESTER_SECTION(tdouble_greater_equals,main)
{
	tsl::tdouble value_1(100.0/255.0);
	tsl::tdouble value_2(25.0/255.0);
	tsl::tdouble value_3(143.0/255.0);
	tsl::tdouble value_4(100.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values used:" << tst::newline
		<< "value_1 = " << value_1 << tst::newline
		<< "value_2 = " << value_2 << tst::newline
		<< "value_3 = " << value_3 << tst::newline
		<< "value_4 = " << value_4;

	CYNODELIC_TESTER_CHECK_TRUE(value_1 >= value_2);
	CYNODELIC_TESTER_CHECK_GEQ(value_1.get(),value_2.get());

	CYNODELIC_TESTER_CHECK_FALSE(value_2 >= value_3);
	CYNODELIC_TESTER_CHECK_LESS(value_2.get(),value_3.get());

	CYNODELIC_TESTER_CHECK_TRUE(value_1 >= value_4);
	CYNODELIC_TESTER_CHECK_GEQ(value_1.get(),value_4.get());
}


CYNODELIC_TESTER_TEST_CASE(tdouble_less_equals);

CYNODELIC_TESTER_SECTION(tdouble_less_equals,main)
{
	tsl::tdouble value_1(121.0/255.0);
	tsl::tdouble value_2(666.0/255.0);
	tsl::tdouble value_3(98.0/255.0);
	tsl::tdouble value_4(121.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values used:" << tst::newline
		<< "value_1 = " << value_1 << tst::newline
		<< "value_2 = " << value_2 << tst::newline
		<< "value_3 = " << value_3 << tst::newline
		<< "value_4 = " << value_4;

	CYNODELIC_TESTER_CHECK_TRUE(value_1 <= value_2);
	CYNODELIC_TESTER_CHECK_LEQ(value_1.get(),value_2.get());

	CYNODELIC_TESTER_CHECK_FALSE(value_2 <= value_3);
	CYNODELIC_TESTER_CHECK_GREATER(value_2.get(),value_3.get());

	CYNODELIC_TESTER_CHECK_TRUE(value_1 <= value_4);
	CYNODELIC_TESTER_CHECK_LEQ(value_1.get(),value_4.get());
}


#endif // CYNODELIC_TESELA_TEST_CORE_TDOUBLE_COMPARISONS_HPP
