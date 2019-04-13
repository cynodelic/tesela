// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_GRAY_T_SWAP_HPP
#define CYNODELIC_TESELA_TEST_CORE_GRAY_T_SWAP_HPP


CYNODELIC_TESTER_TEST_CASE(gray_t_swap);

CYNODELIC_TESTER_SECTION(gray_t_swap,member_function)
{
	tsl::gray_t pix1( 49);
	tsl::gray_t pix2(200);

	tsl::gray_t pix1_new = pix1;
	tsl::gray_t pix2_new = pix2;

	CYNODELIC_TESTER_MESSAGE
		<< "*** Before swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.gray   = " << static_cast<unsigned>(pix1_new.gray) << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.gray   = " << static_cast<unsigned>(pix2_new.gray);

	pix1_new.swap(pix2_new);

	CYNODELIC_TESTER_MESSAGE
		<< "*** After swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.gray   = " << static_cast<unsigned>(pix1_new.gray) << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.gray   = " << static_cast<unsigned>(pix2_new.gray);

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.gray,pix2_new.gray);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.gray,pix2.gray);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.gray,pix1.gray);
}

CYNODELIC_TESTER_SECTION(gray_t_swap,std_swap_function)
{
	tsl::gray_t pix1( 49);
	tsl::gray_t pix2(200);

	tsl::gray_t pix1_new = pix1;
	tsl::gray_t pix2_new = pix2;

	CYNODELIC_TESTER_MESSAGE
		<< "*** Before swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.gray   = " << static_cast<unsigned>(pix1_new.gray) << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.gray   = " << static_cast<unsigned>(pix2_new.gray);

	std::swap(pix1_new,pix2_new);

	CYNODELIC_TESTER_MESSAGE
		<< "*** After swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.gray   = " << static_cast<unsigned>(pix1_new.gray) << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.gray   = " << static_cast<unsigned>(pix2_new.gray);

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.gray,pix2_new.gray);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.gray,pix2.gray);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.gray,pix1.gray);
}


#endif // CYNODELIC_TESELA_TEST_CORE_GRAY_T_SWAP_HPP
