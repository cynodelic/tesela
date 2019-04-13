// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_RGB_T_COPY_HPP
#define CYNODELIC_TESELA_TEST_CORE_RGB_T_COPY_HPP


CYNODELIC_TESTER_TEST_CASE(rgb_t_copy);

CYNODELIC_TESTER_SECTION(rgb_t_copy,copy_constructor)
{
	tsl::rgb_t pix1(241,98,102);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for pix1:" << tst::newline
		<< "    Red (pix1.red):     " << static_cast<unsigned>(pix1.red) << tst::newline
		<< "    Green (pix1.green): " << static_cast<unsigned>(pix1.green) << tst::newline
		<< "    Blue (pix1.blue):   " << static_cast<unsigned>(pix1.blue);

	tsl::rgb_t pix2(pix1);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.red,pix2.red);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.green,pix2.green);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.blue,pix2.blue);
}


CYNODELIC_TESTER_SECTION(rgb_t_copy,copy_assignment)
{
	tsl::rgb_t pix1(241,98,102);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for pix1:" << tst::newline
		<< "    Red (pix1.red):     " << static_cast<unsigned>(pix1.red) << tst::newline
		<< "    Green (pix1.green): " << static_cast<unsigned>(pix1.green) << tst::newline
		<< "    Blue (pix1.blue):   " << static_cast<unsigned>(pix1.blue);

	
	tsl::rgb_t pix2;
	pix2 = pix1;

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.red,pix2.red);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.green,pix2.green);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.blue,pix2.blue);
}


#endif // CYNODELIC_TESELA_TEST_CORE_RGB_T_COPY_HPP
