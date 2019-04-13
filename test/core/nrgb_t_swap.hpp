// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_NRGB_T_SWAP_HPP
#define CYNODELIC_TESELA_TEST_CORE_NRGB_T_SWAP_HPP


CYNODELIC_TESTER_TEST_CASE(nrgb_t_swap);

CYNODELIC_TESTER_SECTION(nrgb_t_swap,member_function)
{
	tsl::nrgb_t pix1( 56.0/255.0,244.0/255.0,251.0/255.0);
	tsl::nrgb_t pix2(134.0/255.0,233.0/255.0,  1.0/255.0);

	tsl::nrgb_t pix1_new = pix1;
	tsl::nrgb_t pix2_new = pix2;

	CYNODELIC_TESTER_MESSAGE
		<< "*** Before swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.red = " << pix1_new.red << tst::newline
		<< "    pix1_new.green = " << pix1_new.green << tst::newline
		<< "    pix1_new.blue = " << pix1_new.blue << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.red = " << pix2_new.red << tst::newline
		<< "    pix2_new.green = " << pix2_new.green << tst::newline
		<< "    pix2_new.blue = " << pix2_new.blue;

	pix1_new.swap(pix2_new);

	CYNODELIC_TESTER_MESSAGE
		<< "*** After swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.red = " << pix1_new.red << tst::newline
		<< "    pix1_new.green = " << pix1_new.green << tst::newline
		<< "    pix1_new.blue = " << pix1_new.blue << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.red = " << pix2_new.red << tst::newline
		<< "    pix2_new.green = " << pix2_new.green << tst::newline
		<< "    pix2_new.blue = " << pix2_new.blue;

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

CYNODELIC_TESTER_SECTION(nrgb_t_swap,std_swap_function)
{
	tsl::nrgb_t pix1( 56.0/255.0,244.0/255.0,251.0/255.0);
	tsl::nrgb_t pix2(134.0/255.0,233.0/255.0,  1.0/255.0);

	tsl::nrgb_t pix1_new = pix1;
	tsl::nrgb_t pix2_new = pix2;

	CYNODELIC_TESTER_MESSAGE
		<< "*** Before swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.red = " << pix1_new.red << tst::newline
		<< "    pix1_new.green = " << pix1_new.green << tst::newline
		<< "    pix1_new.blue = " << pix1_new.blue << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.red = " << pix2_new.red << tst::newline
		<< "    pix2_new.green = " << pix2_new.green << tst::newline
		<< "    pix2_new.blue = " << pix2_new.blue;

	std::swap(pix1_new,pix2_new);

	CYNODELIC_TESTER_MESSAGE
		<< "*** After swapping ***" << tst::newline
		<< "Values for pix1_new:" << tst::newline
		<< "    pix1_new.red = " << pix1_new.red << tst::newline
		<< "    pix1_new.green = " << pix1_new.green << tst::newline
		<< "    pix1_new.blue = " << pix1_new.blue << tst::newline
		<< "Values for pix2_new:" << tst::newline
		<< "    pix2_new.red = " << pix2_new.red << tst::newline
		<< "    pix2_new.green = " << pix2_new.green << tst::newline
		<< "    pix2_new.blue = " << pix2_new.blue;

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


#endif // CYNODELIC_TESELA_TEST_CORE_NRGB_T_SWAP_HPP
