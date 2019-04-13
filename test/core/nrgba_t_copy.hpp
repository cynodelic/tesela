// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_NRGBA_T_COPY_HPP
#define CYNODELIC_TESELA_TEST_CORE_NRGBA_T_COPY_HPP


CYNODELIC_TESTER_TEST_CASE(nrgba_t_copy);

CYNODELIC_TESTER_SECTION(nrgba_t_copy,copy_constructor)
{
	tsl::nrgba_t pix1(127.0/255.0,33.0/255.0,240.0/255.0,63.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for pix1:" << tst::newline
		<< "    Red (pix1.red):     " << pix1.red << tst::newline
		<< "    Green (pix1.green): " << pix1.green << tst::newline
		<< "    Blue (pix1.blue):   " << pix1.blue << tst::newline
		<< "    Alpha (pix1.alpha): " << pix1.alpha;

	tsl::nrgba_t pix2(pix1);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.red,pix2.red);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.green,pix2.green);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.blue,pix2.blue);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.alpha,pix2.alpha);
}


CYNODELIC_TESTER_SECTION(nrgba_t_copy,copy_assignment)
{
	tsl::nrgba_t pix1(127.0/255.0,33.0/255.0,240.0/255.0,63.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for pix1:" << tst::newline
		<< "    Red (pix1.red):     " << pix1.red << tst::newline
		<< "    Green (pix1.green): " << pix1.green << tst::newline
		<< "    Blue (pix1.blue):   " << pix1.blue << tst::newline
		<< "    Alpha (pix1.alpha): " << pix1.alpha;

	tsl::nrgba_t pix2;
	pix2 = pix1;

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.red,pix2.red);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.green,pix2.green);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.blue,pix2.blue);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.alpha,pix2.alpha);
}


#endif // CYNODELIC_TESELA_TEST_CORE_NRGBA_T_COPY_HPP
