// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_RECTANGLE_COPY_HPP
#define CYNODELIC_TESELA_TEST_CORE_RECTANGLE_COPY_HPP


CYNODELIC_TESTER_TEST_CASE(rectangle_copy);

CYNODELIC_TESTER_SECTION(rectangle_copy,copy_constructor)
{
	tsl::rectangle rect1(150,120,10,34);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for rect1:" << tst::newline
		<< "    rect1.width = " << rect1.width << " (width)" << tst::newline
		<< "    rect1.height = " << rect1.height << " (height)" << tst::newline
		<< "    rect1.x = " << rect1.x << " (X position)" << tst::newline
		<< "    rect1.y = " << rect1.y << " (Y position)";

	tsl::rectangle rect2(rect1);

	CYNODELIC_TESTER_ASSERT_EQUALS(rect1.width,rect2.width);
	CYNODELIC_TESTER_ASSERT_EQUALS(rect1.height,rect2.height);
	CYNODELIC_TESTER_ASSERT_EQUALS(rect1.x,rect2.x);
	CYNODELIC_TESTER_ASSERT_EQUALS(rect1.y,rect2.y);
}

CYNODELIC_TESTER_SECTION(rectangle_copy,copy_assignment)
{
	tsl::rectangle rect1(150,120,10,34);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for rect1:" << tst::newline
		<< "    rect1.width = " << rect1.width << " (width)" << tst::newline
		<< "    rect1.height = " << rect1.height << " (height)" << tst::newline
		<< "    rect1.x = " << rect1.x << " (X position)" << tst::newline
		<< "    rect1.y = " << rect1.y << " (Y position)";

	tsl::rectangle rect2;
	rect2 = rect1;

	CYNODELIC_TESTER_ASSERT_EQUALS(rect1.width,rect2.width);
	CYNODELIC_TESTER_ASSERT_EQUALS(rect1.height,rect2.height);
	CYNODELIC_TESTER_ASSERT_EQUALS(rect1.x,rect2.x);
	CYNODELIC_TESTER_ASSERT_EQUALS(rect1.y,rect2.y);
}


#endif // CYNODELIC_TESELA_TEST_CORE_RECTANGLE_COPY_HPP
