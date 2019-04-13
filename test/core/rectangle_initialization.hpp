// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_RECTANGLE_INITIALIZATION_HPP
#define CYNODELIC_TESELA_TEST_CORE_RECTANGLE_INITIALIZATION_HPP


CYNODELIC_TESTER_TEST_CASE(rectangle_initialization);

CYNODELIC_TESTER_SECTION(rectangle_initialization,empty_constructor)
{
	tsl::rectangle rect;

	CYNODELIC_TESTER_CHECK_EQUALS(rect.width,0);
	CYNODELIC_TESTER_CHECK_EQUALS(rect.height,0);
	CYNODELIC_TESTER_CHECK_EQUALS(rect.x,0);
	CYNODELIC_TESTER_CHECK_EQUALS(rect.y,0);
}

CYNODELIC_TESTER_SECTION(rectangle_initialization,width_height_constructor)
{
	tsl::rectangle rect(156,40);

	CYNODELIC_TESTER_CHECK_EQUALS(rect.width,156);
	CYNODELIC_TESTER_CHECK_EQUALS(rect.height,40);
	CYNODELIC_TESTER_CHECK_EQUALS(rect.x,0);
	CYNODELIC_TESTER_CHECK_EQUALS(rect.y,0);
}

CYNODELIC_TESTER_SECTION(rectangle_initialization,width_height_xy_constructor)
{
	tsl::rectangle rect(128,128,40,11);

	CYNODELIC_TESTER_CHECK_EQUALS(rect.width,128);
	CYNODELIC_TESTER_CHECK_EQUALS(rect.height,128);
	CYNODELIC_TESTER_CHECK_EQUALS(rect.x,40);
	CYNODELIC_TESTER_CHECK_EQUALS(rect.y,11);
}

CYNODELIC_TESTER_SECTION(rectangle_initialization,two_points_constructor)
{
	tsl::rectangle rect(tsl::point(35,40),tsl::point(89,55));

	CYNODELIC_TESTER_CHECK_EQUALS(rect.width,54);
	CYNODELIC_TESTER_CHECK_EQUALS(rect.height,15);
	CYNODELIC_TESTER_CHECK_EQUALS(rect.x,35);
	CYNODELIC_TESTER_CHECK_EQUALS(rect.y,40);
}

CYNODELIC_TESTER_SECTION(rectangle_initialization,width_height_assignment)
{
	tsl::rectangle rect = tsl::rectangle{156,40};

	CYNODELIC_TESTER_CHECK_EQUALS(rect.width,156);
	CYNODELIC_TESTER_CHECK_EQUALS(rect.height,40);
	CYNODELIC_TESTER_CHECK_EQUALS(rect.x,0);
	CYNODELIC_TESTER_CHECK_EQUALS(rect.y,0);
}

CYNODELIC_TESTER_SECTION(rectangle_initialization,width_height_xy_assignment)
{
	tsl::rectangle rect = tsl::rectangle{128,128,40,11};

	CYNODELIC_TESTER_CHECK_EQUALS(rect.width,128);
	CYNODELIC_TESTER_CHECK_EQUALS(rect.height,128);
	CYNODELIC_TESTER_CHECK_EQUALS(rect.x,40);
	CYNODELIC_TESTER_CHECK_EQUALS(rect.y,11);
}


#endif // CYNODELIC_TESELA_TEST_CORE_RECTANGLE_INITIALIZATION_HPP
