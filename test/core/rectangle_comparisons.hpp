// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODLEIC_TESELA_TEST_CORE_RECTANGLE_COMPARISONS_HPP
#define CYNODLEIC_TESELA_TEST_CORE_RECTANGLE_COMPARISONS_HPP


CYNODELIC_TESTER_TEST_CASE(rectangle_equals);

CYNODELIC_TESTER_SECTION(rectangle_equals,main)
{
	tsl::rectangle rect1(130,125,200,515);
	tsl::rectangle rect2(130,125,200,515);
	tsl::rectangle rect3(409,312,5,1);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for rect1:" << tst::newline
		<< "    rect1.width = " << rect1.width << " (width)" << tst::newline
		<< "    rect1.height = " << rect1.height << " (height)" << tst::newline
		<< "    rect1.x = " << rect1.x << " (X position)" << tst::newline
		<< "    rect1.y = " << rect1.y << " (Y position)";

	CYNODELIC_TESTER_MESSAGE
		<< "Values for rect2:" << tst::newline
		<< "    rect2.width = " << rect2.width << " (width)" << tst::newline
		<< "    rect2.height = " << rect2.height << " (height)" << tst::newline
		<< "    rect2.x = " << rect2.x << " (X position)" << tst::newline
		<< "    rect2.y = " << rect2.y << " (Y position)";

	CYNODELIC_TESTER_MESSAGE
		<< "Values for rect3:" << tst::newline
		<< "    rect3.width = " << rect3.width << " (width)" << tst::newline
		<< "    rect3.height = " << rect3.height << " (height)" << tst::newline
		<< "    rect3.x = " << rect3.x << " (X position)" << tst::newline
		<< "    rect3.y = " << rect3.y << " (Y position)";

	CYNODELIC_TESTER_CHECK_EQUALS(rect1.width,rect2.width);
	CYNODELIC_TESTER_CHECK_EQUALS(rect1.height,rect2.height);
	CYNODELIC_TESTER_CHECK_EQUALS(rect1.x,rect2.x);
	CYNODELIC_TESTER_CHECK_EQUALS(rect1.y,rect2.y);
	CYNODELIC_TESTER_CHECK_TRUE(rect1 == rect2);

	CYNODELIC_TESTER_CHECK_NOT_EQUALS(rect1.width,rect3.width);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(rect1.height,rect3.height);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(rect1.x,rect3.x);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(rect1.y,rect3.y);
	CYNODELIC_TESTER_CHECK_FALSE(rect1 == rect3);
}


CYNODELIC_TESTER_TEST_CASE(rectangle_not_equals);

CYNODELIC_TESTER_SECTION(rectangle_not_equals,main)
{
	tsl::rectangle rect1(231,901,333,890);
	tsl::rectangle rect2(356,101,798,320);
	tsl::rectangle rect3(231,901,333,890);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for rect1:" << tst::newline
		<< "    rect1.width = " << rect1.width << " (width)" << tst::newline
		<< "    rect1.height = " << rect1.height << " (height)" << tst::newline
		<< "    rect1.x = " << rect1.x << " (X position)" << tst::newline
		<< "    rect1.y = " << rect1.y << " (Y position)";

	CYNODELIC_TESTER_MESSAGE
		<< "Values for rect2:" << tst::newline
		<< "    rect2.width = " << rect2.width << " (width)" << tst::newline
		<< "    rect2.height = " << rect2.height << " (height)" << tst::newline
		<< "    rect2.x = " << rect2.x << " (X position)" << tst::newline
		<< "    rect2.y = " << rect2.y << " (Y position)";

	CYNODELIC_TESTER_MESSAGE
		<< "Values for rect3:" << tst::newline
		<< "    rect3.width = " << rect3.width << " (width)" << tst::newline
		<< "    rect3.height = " << rect3.height << " (height)" << tst::newline
		<< "    rect3.x = " << rect3.x << " (X position)" << tst::newline
		<< "    rect3.y = " << rect3.y << " (Y position)";

	CYNODELIC_TESTER_CHECK_NOT_EQUALS(rect1.width,rect2.width);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(rect1.height,rect2.height);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(rect1.x,rect2.x);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(rect1.y,rect2.y);
	CYNODELIC_TESTER_CHECK_TRUE(rect1 != rect2);

	CYNODELIC_TESTER_CHECK_EQUALS(rect1.width,rect3.width);
	CYNODELIC_TESTER_CHECK_EQUALS(rect1.height,rect3.height);
	CYNODELIC_TESTER_CHECK_EQUALS(rect1.x,rect3.x);
	CYNODELIC_TESTER_CHECK_EQUALS(rect1.y,rect3.y);
	CYNODELIC_TESTER_CHECK_FALSE(rect1 != rect3);
}


#endif // CYNODLEIC_TESELA_TEST_CORE_RECTANGLE_COMPARISONS_HPP
