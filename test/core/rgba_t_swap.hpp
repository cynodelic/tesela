// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_RGBA_T_SWAP_HPP
#define CYNODELIC_TESELA_TEST_CORE_RGBA_T_SWAP_HPP


CYNODELIC_TESTER_TEST_CASE(rgba_t_swap);

CYNODELIC_TESTER_SECTION(rgba_t_swap,member_function)
{
	tsl::rgba_t pix1( 99,176,  0,206);
	tsl::rgba_t pix2(225, 21, 32, 87);

	tsl::rgba_t pix1_new = pix1;
	tsl::rgba_t pix2_new = pix2;

	CYNODELIC_TESTER_MESSAGE
		<< "*** Before swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.red   = " << static_cast<unsigned>(pix1_new.red) << tst::newline
		<< "    pix1_new.green = " << static_cast<unsigned>(pix1_new.green) << tst::newline
		<< "    pix1_new.blue  = " << static_cast<unsigned>(pix1_new.blue) << tst::newline
		<< "    pix1_new.alpha = " << static_cast<unsigned>(pix1_new.alpha) << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.red   = " << static_cast<unsigned>(pix2_new.red) << tst::newline
		<< "    pix2_new.green = " << static_cast<unsigned>(pix2_new.green) << tst::newline
		<< "    pix2_new.blue  = " << static_cast<unsigned>(pix2_new.blue) << tst::newline
		<< "    pix2_new.alpha = " << static_cast<unsigned>(pix2_new.alpha);

	pix1_new.swap(pix2_new);

	CYNODELIC_TESTER_MESSAGE
		<< "*** After swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.red   = " << static_cast<unsigned>(pix1_new.red) << tst::newline
		<< "    pix1_new.green = " << static_cast<unsigned>(pix1_new.green) << tst::newline
		<< "    pix1_new.blue  = " << static_cast<unsigned>(pix1_new.blue) << tst::newline
		<< "    pix1_new.alpha = " << static_cast<unsigned>(pix1_new.alpha) << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.red   = " << static_cast<unsigned>(pix2_new.red) << tst::newline
		<< "    pix2_new.green = " << static_cast<unsigned>(pix2_new.green) << tst::newline
		<< "    pix2_new.blue  = " << static_cast<unsigned>(pix2_new.blue) << tst::newline
		<< "    pix2_new.alpha = " << static_cast<unsigned>(pix2_new.alpha);

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.red,pix2_new.red);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.green,pix2_new.green);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.blue,pix2_new.blue);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.alpha,pix2_new.alpha);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.red,pix2.red);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.green,pix2.green);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.blue,pix2.blue);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.alpha,pix2.alpha);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.red,pix1.red);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.green,pix1.green);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.blue,pix1.blue);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.alpha,pix1.alpha);
}

CYNODELIC_TESTER_SECTION(rgba_t_swap,std_swap_function)
{
	tsl::rgba_t pix1( 99,176,  0,206);
	tsl::rgba_t pix2(225, 21, 32, 87);

	tsl::rgba_t pix1_new = pix1;
	tsl::rgba_t pix2_new = pix2;

	CYNODELIC_TESTER_MESSAGE
		<< "*** Before swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.red   = " << static_cast<unsigned>(pix1_new.red) << tst::newline
		<< "    pix1_new.green = " << static_cast<unsigned>(pix1_new.green) << tst::newline
		<< "    pix1_new.blue  = " << static_cast<unsigned>(pix1_new.blue) << tst::newline
		<< "    pix1_new.alpha = " << static_cast<unsigned>(pix1_new.alpha) << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.red   = " << static_cast<unsigned>(pix2_new.red) << tst::newline
		<< "    pix2_new.green = " << static_cast<unsigned>(pix2_new.green) << tst::newline
		<< "    pix2_new.blue  = " << static_cast<unsigned>(pix2_new.blue) << tst::newline
		<< "    pix2_new.alpha = " << static_cast<unsigned>(pix2_new.alpha);

	std::swap(pix1_new,pix2_new);

	CYNODELIC_TESTER_MESSAGE
		<< "*** After swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.red   = " << static_cast<unsigned>(pix1_new.red) << tst::newline
		<< "    pix1_new.green = " << static_cast<unsigned>(pix1_new.green) << tst::newline
		<< "    pix1_new.blue  = " << static_cast<unsigned>(pix1_new.blue) << tst::newline
		<< "    pix1_new.alpha = " << static_cast<unsigned>(pix1_new.alpha) << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.red   = " << static_cast<unsigned>(pix2_new.red) << tst::newline
		<< "    pix2_new.green = " << static_cast<unsigned>(pix2_new.green) << tst::newline
		<< "    pix2_new.blue  = " << static_cast<unsigned>(pix2_new.blue) << tst::newline
		<< "    pix2_new.alpha = " << static_cast<unsigned>(pix2_new.alpha);

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.red,pix2_new.red);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.green,pix2_new.green);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.blue,pix2_new.blue);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pix1_new.alpha,pix2_new.alpha);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.red,pix2.red);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.green,pix2.green);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.blue,pix2.blue);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1_new.alpha,pix2.alpha);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.red,pix1.red);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.green,pix1.green);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.blue,pix1.blue);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix2_new.alpha,pix1.alpha);
}


#endif // CYNODELIC_TESELA_TEST_CORE_RGBA_T_SWAP_HPP
