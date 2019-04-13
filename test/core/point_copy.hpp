// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_POINT_COPY_HPP
#define CYNODELIC_TESELA_TEST_CORE_POINT_COPY_HPP


CYNODELIC_TESTER_TEST_CASE(point_copy);

CYNODELIC_TESTER_SECTION(point_copy,copy_constructor)
{
	tsl::point pt1(934,712);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for pt1:" << tst::newline
		<< "    X (pt1.x): " << pt1.x << tst::newline
		<< "    Y (pt1.y): " << pt1.y;

	tsl::point pt2(pt1);

	CYNODELIC_TESTER_CHECK_EQUALS(pt2.x,pt1.x);
	CYNODELIC_TESTER_CHECK_EQUALS(pt2.y,pt1.y);
}

CYNODELIC_TESTER_SECTION(point_copy,copy_assignment)
{
	tsl::point pt1(934,712);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for pt1:" << tst::newline
		<< "    X (pt1.x): " << pt1.x << tst::newline
		<< "    Y (pt1.y): " << pt1.y;

	tsl::point pt2 = pt1;

	CYNODELIC_TESTER_CHECK_EQUALS(pt2.x,pt1.x);
	CYNODELIC_TESTER_CHECK_EQUALS(pt2.y,pt1.y);
}


#endif // CYNODELIC_TESELA_TEST_CORE_POINT_COPY_HPP
