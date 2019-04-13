// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_NGRAY_T_COPY_HPP
#define CYNODELIC_TESELA_TEST_CORE_NGRAY_T_COPY_HPP


CYNODELIC_TESTER_TEST_CASE(ngray_t_copy);

CYNODELIC_TESTER_SECTION(ngray_t_copy,copy_constructor)
{
	tsl::ngray_t pix1(69.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for pix1:" << tst::newline
		<< "    Gray (pix1.gray): " << pix1.gray;

	tsl::ngray_t pix2(pix1);

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.gray,pix2.gray);
}


CYNODELIC_TESTER_SECTION(ngray_t_copy,copy_assignment)
{
	tsl::ngray_t pix1(69.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for pix1:" << tst::newline
		<< "    Gray (pix1.gray): " << pix1.gray;

	tsl::ngray_t pix2;
	pix2 = pix1;

	CYNODELIC_TESTER_ASSERT_EQUALS(pix1.gray,pix2.gray);
}


#endif // CYNODELIC_TESELA_TEST_CORE_NGRAY_T_COPY_HPP
