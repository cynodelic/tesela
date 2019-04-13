// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_NGRAY_T_SWAP_HPP
#define CYNODELIC_TESELA_TEST_CORE_NGRAY_T_SWAP_HPP


CYNODELIC_TESTER_TEST_CASE(ngray_t_swap);

CYNODELIC_TESTER_SECTION(ngray_t_swap,member_function)
{
	tsl::ngray_t pix1(211.0/255.0);
	tsl::ngray_t pix2( 44.0/255.0);

	tsl::ngray_t pix1_new = pix1;
	tsl::ngray_t pix2_new = pix2;

	CYNODELIC_TESTER_MESSAGE
		<< "*** Before swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.gray = " << pix1_new.gray << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.gray = " << pix2_new.gray;

	pix1_new.swap(pix2_new);

	CYNODELIC_TESTER_MESSAGE
		<< "*** After swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.gray = " << pix1_new.gray << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.gray = " << pix2_new.gray;

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.gray,pix2_new.gray);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.gray,pix2.gray);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.gray,pix1.gray);
}

CYNODELIC_TESTER_SECTION(ngray_t_swap,std_swap_function)
{
	tsl::ngray_t pix1(211.0/255.0);
	tsl::ngray_t pix2( 44.0/255.0);

	tsl::ngray_t pix1_new = pix1;
	tsl::ngray_t pix2_new = pix2;

	CYNODELIC_TESTER_MESSAGE
		<< "*** Before swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.gray = " << pix1_new.gray << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.gray = " << pix2_new.gray;

	std::swap(pix1_new,pix2_new);

	CYNODELIC_TESTER_MESSAGE
		<< "*** After swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.gray = " << pix1_new.gray << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.gray = " << pix2_new.gray;

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.gray,pix2_new.gray);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.gray,pix2.gray);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.gray,pix1.gray);
}


#endif // CYNODELIC_TESELA_TEST_CORE_NGRAY_T_SWAP_HPP
