// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_POINT_INITIALIZATION_HPP
#define CYNODELIC_TESELA_TEST_CORE_POINT_INITIALIZATION_HPP


CYNODELIC_TESTER_TEST_CASE(point_initialization);

CYNODELIC_TESTER_SECTION(point_initialization,empty_constructor)
{
	tsl::point pt;

	CYNODELIC_TESTER_CHECK_EQUALS(pt.x,0);
	CYNODELIC_TESTER_CHECK_EQUALS(pt.y,0);
}

CYNODELIC_TESTER_SECTION(point_initialization,xy_constructor)
{
	tsl::point pt(15,51);

	CYNODELIC_TESTER_CHECK_EQUALS(pt.x,15);
	CYNODELIC_TESTER_CHECK_EQUALS(pt.y,51);
}

CYNODELIC_TESTER_SECTION(point_initialization,assignment)
{
	tsl::point pt = tsl::point(32,19);

	CYNODELIC_TESTER_CHECK_EQUALS(pt.x,32);
	CYNODELIC_TESTER_CHECK_EQUALS(pt.y,19);
}


#endif // CYNODELIC_TESELA_TEST_CORE_POINT_INITIALIZATION_HPP
