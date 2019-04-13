// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_RECTANGLE_SWAP_HPP
#define CYNODELIC_TESELA_TEST_CORE_RECTANGLE_SWAP_HPP


CYNODELIC_TESTER_TEST_CASE(rectangle_swap);

CYNODELIC_TESTER_SECTION(rectangle_swap,member_function)
{
	tsl::rectangle rect1(244, 98,103,  2);
	tsl::rectangle rect2( 45,123,  0,111);

	tsl::rectangle rect1_new = rect1;
	tsl::rectangle rect2_new = rect2;

	CYNODELIC_TESTER_MESSAGE
		<< "*** Before swapping ***" << tst::newline
		<< "Values for rect1_new:" << tst::newline
		<< "    rect1_new.width = " << rect1_new.width << tst::newline
		<< "    rect1_new.height = " << rect1_new.height << tst::newline
		<< "    rect1_new.x = " << rect1_new.x << tst::newline
		<< "    rect1_new.y = " << rect1_new.y << tst::newline
		<< "Values for rect2_new:" << tst::newline
		<< "    rect2_new.width = " << rect2_new.width << tst::newline
		<< "    rect2_new.height = " << rect2_new.height << tst::newline
		<< "    rect2_new.x = " << rect2_new.x << tst::newline
		<< "    rect2_new.y = " << rect2_new.y;

	rect1_new.swap(rect2_new);

	CYNODELIC_TESTER_MESSAGE
		<< "*** After swapping ***" << tst::newline
		<< "Values for rect1_new:" << tst::newline
		<< "    rect1_new.width = " << rect1_new.width << tst::newline
		<< "    rect1_new.height = " << rect1_new.height << tst::newline
		<< "    rect1_new.x = " << rect1_new.x << tst::newline
		<< "    rect1_new.y = " << rect1_new.y << tst::newline
		<< "Values for rect2_new:" << tst::newline
		<< "    rect2_new.width = " << rect2_new.width << tst::newline
		<< "    rect2_new.height = " << rect2_new.height << tst::newline
		<< "    rect2_new.x = " << rect2_new.x << tst::newline
		<< "    rect2_new.y = " << rect2_new.y;

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(rect1_new.width,rect2_new.width);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(rect1_new.height,rect2_new.height);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(rect1_new.x,rect2_new.x);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(rect1_new.y,rect2_new.y);

	CYNODELIC_TESTER_ASSERT_EQUALS(rect1_new.width,rect2.width);
	CYNODELIC_TESTER_ASSERT_EQUALS(rect1_new.height,rect2.height);
	CYNODELIC_TESTER_ASSERT_EQUALS(rect1_new.x,rect2.x);
	CYNODELIC_TESTER_ASSERT_EQUALS(rect1_new.y,rect2.y);

	CYNODELIC_TESTER_ASSERT_EQUALS(rect2_new.width,rect1.width);
	CYNODELIC_TESTER_ASSERT_EQUALS(rect2_new.height,rect1.height);
	CYNODELIC_TESTER_ASSERT_EQUALS(rect2_new.x,rect1.x);
	CYNODELIC_TESTER_ASSERT_EQUALS(rect2_new.y,rect1.y);
}

CYNODELIC_TESTER_SECTION(rectangle_swap,std_swap_function)
{
	tsl::rectangle rect1(244, 98,103,  2);
	tsl::rectangle rect2( 45,123,  0,111);

	tsl::rectangle rect1_new = rect1;
	tsl::rectangle rect2_new = rect2;

	CYNODELIC_TESTER_MESSAGE
		<< "*** Before swapping ***" << tst::newline
		<< "Values for rect1_new:" << tst::newline
		<< "    rect1_new.width = " << rect1_new.width << tst::newline
		<< "    rect1_new.height = " << rect1_new.height << tst::newline
		<< "    rect1_new.x = " << rect1_new.x << tst::newline
		<< "    rect1_new.y = " << rect1_new.y << tst::newline
		<< "Values for rect2_new:" << tst::newline
		<< "    rect2_new.width = " << rect2_new.width << tst::newline
		<< "    rect2_new.height = " << rect2_new.height << tst::newline
		<< "    rect2_new.x = " << rect2_new.x << tst::newline
		<< "    rect2_new.y = " << rect2_new.y;

	std::swap(rect1_new,rect2_new);

	CYNODELIC_TESTER_MESSAGE
		<< "*** After swapping ***" << tst::newline
		<< "Values for rect1_new:" << tst::newline
		<< "    rect1_new.width = " << rect1_new.width << tst::newline
		<< "    rect1_new.height = " << rect1_new.height << tst::newline
		<< "    rect1_new.x = " << rect1_new.x << tst::newline
		<< "    rect1_new.y = " << rect1_new.y << tst::newline
		<< "Values for rect2_new:" << tst::newline
		<< "    rect2_new.width = " << rect2_new.width << tst::newline
		<< "    rect2_new.height = " << rect2_new.height << tst::newline
		<< "    rect2_new.x = " << rect2_new.x << tst::newline
		<< "    rect2_new.y = " << rect2_new.y;

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(rect1_new.width,rect2_new.width);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(rect1_new.height,rect2_new.height);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(rect1_new.x,rect2_new.x);
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(rect1_new.y,rect2_new.y);

	CYNODELIC_TESTER_ASSERT_EQUALS(rect1_new.width,rect2.width);
	CYNODELIC_TESTER_ASSERT_EQUALS(rect1_new.height,rect2.height);
	CYNODELIC_TESTER_ASSERT_EQUALS(rect1_new.x,rect2.x);
	CYNODELIC_TESTER_ASSERT_EQUALS(rect1_new.y,rect2.y);

	CYNODELIC_TESTER_ASSERT_EQUALS(rect2_new.width,rect1.width);
	CYNODELIC_TESTER_ASSERT_EQUALS(rect2_new.height,rect1.height);
	CYNODELIC_TESTER_ASSERT_EQUALS(rect2_new.x,rect1.x);
	CYNODELIC_TESTER_ASSERT_EQUALS(rect2_new.y,rect1.y);
}


#endif // CYNODELIC_TESELA_TEST_CORE_RECTANGLE_SWAP_HPP
