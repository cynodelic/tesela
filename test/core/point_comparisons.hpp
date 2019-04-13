// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_POINT_COMPARISONS_HPP
#define CYNODELIC_TESELA_TEST_CORE_POINT_COMPARISONS_HPP


CYNODELIC_TESTER_TEST_CASE(point_equals);

CYNODELIC_TESTER_SECTION(point_equals,main)
{
	tsl::point pt1(439,115);
	tsl::point pt2(439,115);
	tsl::point pt3(600,412);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for pt1:" << tst::newline
		<< "    pt1.x = " << pt1.x << tst::newline
		<< "    pt1.y = " << pt1.y;

	CYNODELIC_TESTER_MESSAGE
		<< "Values for pt2:" << tst::newline
		<< "    pt2.x = " << pt2.x << tst::newline
		<< "    pt2.y = " << pt2.y;

	CYNODELIC_TESTER_MESSAGE
		<< "Values for pt3:" << tst::newline
		<< "    pt3.x = " << pt3.x << tst::newline
		<< "    pt3.y = " << pt3.y;

	CYNODELIC_TESTER_CHECK_EQUALS(pt1.x,pt2.x);
	CYNODELIC_TESTER_CHECK_EQUALS(pt1.y,pt2.y);
	CYNODELIC_TESTER_CHECK_TRUE(pt1 == pt2);

	CYNODELIC_TESTER_CHECK_NOT_EQUALS(pt1.x,pt3.x);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(pt1.y,pt3.y);
	CYNODELIC_TESTER_CHECK_FALSE(pt1 == pt3);
}


CYNODELIC_TESTER_TEST_CASE(point_not_equals);

CYNODELIC_TESTER_SECTION(point_not_equals,main)
{
	tsl::point pt1(556,120);
	tsl::point pt2(901,396);
	tsl::point pt3(556,120);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for pt1:" << tst::newline
		<< "    pt1.x = " << pt1.x << tst::newline
		<< "    pt1.y = " << pt1.y;

	CYNODELIC_TESTER_MESSAGE
		<< "Values for pt2:" << tst::newline
		<< "    pt2.x = " << pt2.x << tst::newline
		<< "    pt2.y = " << pt2.y;

	CYNODELIC_TESTER_MESSAGE
		<< "Values for pt3:" << tst::newline
		<< "    pt3.x = " << pt3.x << tst::newline
		<< "    pt3.y = " << pt3.y;

	CYNODELIC_TESTER_CHECK_NOT_EQUALS(pt1.x,pt2.x);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(pt1.y,pt2.y);
	CYNODELIC_TESTER_CHECK_TRUE(pt1 != pt2);

	CYNODELIC_TESTER_CHECK_EQUALS(pt1.x,pt3.x);
	CYNODELIC_TESTER_CHECK_EQUALS(pt1.y,pt3.y);
	CYNODELIC_TESTER_CHECK_FALSE(pt1 != pt3);
}


#endif // CYNODELIC_TESELA_TEST_CORE_POINT_COMPARISONS_HPP
