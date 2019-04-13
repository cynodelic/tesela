// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_GA_T_COPY_HPP
#define CYNODELIC_TESELA_TEST_CORE_GA_T_COPY_HPP


CYNODELIC_TESTER_TEST_CASE(ga_t_copy);

CYNODELIC_TESTER_SECTION(ga_t_copy,copy_constructor)
{
	tsl::ga_t pix1(251,101);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for pix1:" << tst::newline
		<< "    Gray (pix1.gray):   " << static_cast<unsigned>(pix1.gray) << tst::newline
		<< "    Alpha (pix1.alpha): " << static_cast<unsigned>(pix1.alpha);

	tsl::ga_t pix2(pix1);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.gray,pix2.gray);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.alpha,pix2.alpha);
}


CYNODELIC_TESTER_SECTION(ga_t_copy,copy_assignment)
{
	tsl::ga_t pix1(251,101);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for pix1:" << tst::newline
		<< "    Gray (pix1.gray):   " << static_cast<unsigned>(pix1.gray) << tst::newline
		<< "    Alpha (pix1.alpha): " << static_cast<unsigned>(pix1.alpha);

	
	tsl::ga_t pix2;
	pix2 = pix1;

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.gray,pix2.gray);
	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.alpha,pix2.alpha);
}


#endif // CYNODELIC_TESELA_TEST_CORE_GA_T_COPY_HPP
