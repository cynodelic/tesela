// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_TDOUBLE_SWAP_HPP
#define CYNODELIC_TESELA_TEST_CORE_TDOUBLE_SWAP_HPP


CYNODELIC_TESTER_TEST_CASE(tdouble_swap);

CYNODELIC_TESTER_SECTION(tdouble_swap,member_function)
{
	tsl::tdouble val1(130.0/255.0);
	tsl::tdouble val2(222.0/255.0);

	tsl::tdouble val1_new = val1;
	tsl::tdouble val2_new = val2;

	CYNODELIC_TESTER_MESSAGE
		<< "*** Before swapping ***" << tst::newline
		<< "Value for val1_new:" << val1_new.get() << tst::newline
		<< "Value for val2_new:" << val2_new.get();

	val1_new.swap(val2_new);

	CYNODELIC_TESTER_MESSAGE
		<< "*** After swapping ***" << tst::newline
		<< "Value for val1_new:" << val1_new.get() << tst::newline
		<< "Value for val2_new:" << val2_new.get();

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(val1_new.get(),val2_new.get());
	CYNODELIC_TESTER_ASSERT_EQUALS(val1_new.get(),val2.get());
	CYNODELIC_TESTER_ASSERT_EQUALS(val2_new.get(),val1.get());
}

CYNODELIC_TESTER_SECTION(tdouble_swap,std_swap_function)
{
	tsl::tdouble val1(130.0/255.0);
	tsl::tdouble val2(222.0/255.0);

	tsl::tdouble val1_new = val1;
	tsl::tdouble val2_new = val2;

	CYNODELIC_TESTER_MESSAGE
		<< "*** Before swapping ***" << tst::newline
		<< "Value for val1_new:" << val1_new.get() << tst::newline
		<< "Value for val2_new:" << val2_new.get();

	std::swap(val1_new,val2_new);

	CYNODELIC_TESTER_MESSAGE
		<< "*** After swapping ***" << tst::newline
		<< "Value for val1_new:" << val1_new.get() << tst::newline
		<< "Value for val2_new:" << val2_new.get();

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(val1_new.get(),val2_new.get());
	CYNODELIC_TESTER_ASSERT_EQUALS(val1_new.get(),val2.get());
	CYNODELIC_TESTER_ASSERT_EQUALS(val2_new.get(),val1.get());
}


#endif // CYNODELIC_TESELA_TEST_CORE_TDOUBLE_SWAP_HPP
