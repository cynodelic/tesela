// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_NRGB_T_COPY_HPP
#define CYNODELIC_TESELA_TEST_CORE_NRGB_T_COPY_HPP


CYNODELIC_TESTER_TEST_CASE(nrgb_t_copy);

CYNODELIC_TESTER_SECTION(nrgb_t_copy,copy_constructor)
{
	tsl::nrgb_t pix1(144.0/255.0,1.0/255.0,33.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for pix1:" << tst::newline
		<< "    Red (pix1.red):     " << pix1.red << tst::newline
		<< "    Green (pix1.green): " << pix1.green << tst::newline
		<< "    Blue (pix1.blue):   " << pix1.blue;

	tsl::nrgb_t pix2(pix1);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.red,pix2.red);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.green,pix2.green);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.blue,pix2.blue);
}


CYNODELIC_TESTER_SECTION(nrgb_t_copy,copy_assignment)
{
	tsl::nrgb_t pix1(144.0/255.0,1.0/255.0,33.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for pix1:" << tst::newline
		<< "    Red (pix1.red):     " << pix1.red << tst::newline
		<< "    Green (pix1.green): " << pix1.green << tst::newline
		<< "    Blue (pix1.blue):   " << pix1.blue;

	tsl::nrgb_t pix2;
	pix2 = pix1;

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.red,pix2.red);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.green,pix2.green);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.blue,pix2.blue);
}


#endif // CYNODELIC_TESELA_TEST_CORE_NRGB_T_COPY_HPP
