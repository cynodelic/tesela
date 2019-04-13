// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_POINT_SWAP_HPP
#define CYNODELIC_TESELA_TEST_CORE_POINT_SWAP_HPP


CYNODELIC_TESTER_TEST_CASE(point_swap);

CYNODELIC_TESTER_SECTION(point_swap,member_function)
{
	tsl::point pt1(37,98);
	tsl::point pt2(11,90);

	tsl::point pt1_new = pt1;
	tsl::point pt2_new = pt2;

	CYNODELIC_TESTER_MESSAGE
		<< "**** Before swapping ****" << tst::newline
		<< "    pt1_new.x = " << pt1_new.x << tst::newline
		<< "    pt1_new.y = " << pt1_new.y << tst::newline
		<< "    pt2_new.x = " << pt2_new.x << tst::newline
		<< "    pt2_new.y = " << pt2_new.y;

	pt1_new.swap(pt2_new);

	CYNODELIC_TESTER_MESSAGE
		<< "**** After swapping ****" << tst::newline
		<< "    pt1_new.x = " << pt1_new.x << tst::newline
		<< "    pt1_new.y = " << pt1_new.y << tst::newline
		<< "    pt2_new.x = " << pt2_new.x << tst::newline
		<< "    pt2_new.y = " << pt2_new.y;

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pt1_new.x,pt2_new.x);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pt1_new.y,pt2_new.y);
	CYNODELIC_TESTER_ASSERT_EQUALS(pt1.x,pt2_new.x);
	CYNODELIC_TESTER_ASSERT_EQUALS(pt1.y,pt2_new.y);
	CYNODELIC_TESTER_ASSERT_EQUALS(pt2.x,pt1_new.x);
	CYNODELIC_TESTER_ASSERT_EQUALS(pt2.y,pt1_new.y);
}

CYNODELIC_TESTER_SECTION(point_swap,std_swap_function)
{
	tsl::point pt1(37,98);
	tsl::point pt2(11,90);

	tsl::point pt1_new = pt1;
	tsl::point pt2_new = pt2;

	CYNODELIC_TESTER_MESSAGE
		<< "**** Before swapping ****" << tst::newline
		<< "    pt1_new.x = " << pt1_new.x << tst::newline
		<< "    pt1_new.y = " << pt1_new.y << tst::newline
		<< "    pt2_new.x = " << pt2_new.x << tst::newline
		<< "    pt2_new.y = " << pt2_new.y;

	std::swap(pt1_new,pt2_new);

	CYNODELIC_TESTER_MESSAGE
		<< "**** After swapping ****" << tst::newline
		<< "    pt1_new.x = " << pt1_new.x << tst::newline
		<< "    pt1_new.y = " << pt1_new.y << tst::newline
		<< "    pt2_new.x = " << pt2_new.x << tst::newline
		<< "    pt2_new.y = " << pt2_new.y;

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pt1_new.x,pt2_new.x);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(pt1_new.y,pt2_new.y);
	CYNODELIC_TESTER_ASSERT_EQUALS(pt1.x,pt2_new.x);
	CYNODELIC_TESTER_ASSERT_EQUALS(pt1.y,pt2_new.y);
	CYNODELIC_TESTER_ASSERT_EQUALS(pt2.x,pt1_new.x);
	CYNODELIC_TESTER_ASSERT_EQUALS(pt2.y,pt1_new.y);
}


#endif // CYNODELIC_TESELA_TEST_CORE_POINT_SWAP_HPP
