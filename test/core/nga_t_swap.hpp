// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_NGA_T_SWAP_HPP
#define CYNODELIC_TESELA_TEST_CORE_NGA_T_SWAP_HPP


CYNODELIC_TESTER_TEST_CASE(nga_t_swap);

CYNODELIC_TESTER_SECTION(nga_t_swap,member_function)
{
	tsl::nga_t pix1( 25.0/255.0,        1.0);
	tsl::nga_t pix2(156.0/255.0, 40.0/255.0);

	tsl::nga_t pix1_new = pix1;
	tsl::nga_t pix2_new = pix2;

	CYNODELIC_TESTER_MESSAGE
		<< "*** Before swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.gray = " << pix1_new.gray << tst::newline
		<< "    pix1_new.alpha = " << pix1_new.alpha << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.gray = " << pix2_new.gray << tst::newline
		<< "    pix2_new.alpha = " << pix2_new.alpha;

	pix1_new.swap(pix2_new);

	CYNODELIC_TESTER_MESSAGE
		<< "*** After swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.gray = " << pix1_new.gray << tst::newline
		<< "    pix1_new.alpha = " << pix1_new.alpha << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.gray = " << pix2_new.gray << tst::newline
		<< "    pix2_new.alpha = " << pix2_new.alpha;

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.gray,pix2_new.gray);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.alpha,pix2_new.alpha);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.gray,pix2.gray);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.alpha,pix2.alpha);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.gray,pix1.gray);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.alpha,pix1.alpha);
}

CYNODELIC_TESTER_SECTION(nga_t_swap,std_swap_function)
{
	tsl::nga_t pix1( 25.0/255.0,        1.0);
	tsl::nga_t pix2(156.0/255.0, 40.0/255.0);

	tsl::nga_t pix1_new = pix1;
	tsl::nga_t pix2_new = pix2;

	CYNODELIC_TESTER_MESSAGE
		<< "*** Before swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.gray = " << pix1_new.gray << tst::newline
		<< "    pix1_new.alpha = " << pix1_new.alpha << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.gray = " << pix2_new.gray << tst::newline
		<< "    pix2_new.alpha = " << pix2_new.alpha;

	std::swap(pix1_new,pix2_new);

	CYNODELIC_TESTER_MESSAGE
		<< "*** After swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.gray = " << pix1_new.gray << tst::newline
		<< "    pix1_new.alpha = " << pix1_new.alpha << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.gray = " << pix2_new.gray << tst::newline
		<< "    pix2_new.alpha = " << pix2_new.alpha;

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.gray,pix2_new.gray);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.alpha,pix2_new.alpha);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.gray,pix2.gray);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.alpha,pix2.alpha);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.gray,pix1.gray);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.alpha,pix1.alpha);
}


#endif // CYNODELIC_TESELA_TEST_CORE_NGA_T_SWAP_HPP
