// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_RGB_T_SWAP_HPP
#define CYNODELIC_TESELA_TEST_CORE_RGB_T_SWAP_HPP


CYNODELIC_TESTER_TEST_CASE(rgb_t_swap);

CYNODELIC_TESTER_SECTION(rgb_t_swap,member_function)
{
	tsl::rgb_t pix1(103,254, 31);
	tsl::rgb_t pix2(  7, 32,199);

	tsl::rgb_t pix1_new = pix1;
	tsl::rgb_t pix2_new = pix2;

	CYNODELIC_TESTER_MESSAGE
		<< "*** Before swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.red   = " << static_cast<unsigned>(pix1_new.red) << tst::newline
		<< "    pix1_new.green = " << static_cast<unsigned>(pix1_new.green) << tst::newline
		<< "    pix1_new.blue  = " << static_cast<unsigned>(pix1_new.blue) << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.red   = " << static_cast<unsigned>(pix2_new.red) << tst::newline
		<< "    pix2_new.green = " << static_cast<unsigned>(pix2_new.green) << tst::newline
		<< "    pix2_new.blue  = " << static_cast<unsigned>(pix2_new.blue);

	pix1_new.swap(pix2_new);

	CYNODELIC_TESTER_MESSAGE
		<< "*** After swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.red   = " << static_cast<unsigned>(pix1_new.red) << tst::newline
		<< "    pix1_new.green = " << static_cast<unsigned>(pix1_new.green) << tst::newline
		<< "    pix1_new.blue  = " << static_cast<unsigned>(pix1_new.blue) << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.red   = " << static_cast<unsigned>(pix2_new.red) << tst::newline
		<< "    pix2_new.green = " << static_cast<unsigned>(pix2_new.green) << tst::newline
		<< "    pix2_new.blue  = " << static_cast<unsigned>(pix2_new.blue);

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.red,pix2_new.red);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.green,pix2_new.green);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.blue,pix2_new.blue);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.red,pix2.red);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.green,pix2.green);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.blue,pix2.blue);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.red,pix1.red);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.green,pix1.green);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.blue,pix1.blue);
}

CYNODELIC_TESTER_SECTION(rgb_t_swap,std_swap_function)
{
	tsl::rgb_t pix1(103,254, 31);
	tsl::rgb_t pix2(  7, 32,199);

	tsl::rgb_t pix1_new = pix1;
	tsl::rgb_t pix2_new = pix2;

	CYNODELIC_TESTER_MESSAGE
		<< "*** Before swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.red   = " << static_cast<unsigned>(pix1_new.red) << tst::newline
		<< "    pix1_new.green = " << static_cast<unsigned>(pix1_new.green) << tst::newline
		<< "    pix1_new.blue  = " << static_cast<unsigned>(pix1_new.blue) << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.red   = " << static_cast<unsigned>(pix2_new.red) << tst::newline
		<< "    pix2_new.green = " << static_cast<unsigned>(pix2_new.green) << tst::newline
		<< "    pix2_new.blue  = " << static_cast<unsigned>(pix2_new.blue);

	std::swap(pix1_new,pix2_new);

	CYNODELIC_TESTER_MESSAGE
		<< "*** After swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.red   = " << static_cast<unsigned>(pix1_new.red) << tst::newline
		<< "    pix1_new.green = " << static_cast<unsigned>(pix1_new.green) << tst::newline
		<< "    pix1_new.blue  = " << static_cast<unsigned>(pix1_new.blue) << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.red   = " << static_cast<unsigned>(pix2_new.red) << tst::newline
		<< "    pix2_new.green = " << static_cast<unsigned>(pix2_new.green) << tst::newline
		<< "    pix2_new.blue  = " << static_cast<unsigned>(pix2_new.blue);

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.red,pix2_new.red);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.green,pix2_new.green);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.blue,pix2_new.blue);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.red,pix2.red);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.green,pix2.green);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.blue,pix2.blue);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.red,pix1.red);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.green,pix1.green);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.blue,pix1.blue);
}


#endif // CYNODELIC_TESELA_TEST_CORE_RGB_T_SWAP_HPP
