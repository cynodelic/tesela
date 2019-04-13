// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_BASIC_IMAGE_MOVE_HPP
#define CYNODELIC_TESELA_TEST_CORE_BASIC_IMAGE_MOVE_HPP


CYNODELIC_TESTER_TEST_CASE(basic_image_move);

CYNODELIC_TESTER_SECTION(basic_image_move,image_move_constructor)
{
	tsl::rgba_image img1_old(160,120,tsl::color_space::rgba);
	tsl::rgba_image img1 = img1_old;
	tsl::rgba_image img2(std::move(img1));

	CYNODELIC_TESTER_ASSERT_EQUALS(img2.width(),img1_old.width());
	CYNODELIC_TESTER_ASSERT_EQUALS(img2.height(),img1_old.height());
	CYNODELIC_TESTER_ASSERT_EQUALS(img2.size(),img1_old.size());

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img2.width(),img1.width());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img2.height(),img1.height());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img2.size(),img1.size());

	CYNODELIC_TESTER_ASSERT_EQUALS(img1.width(),0);
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.height(),0);
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.size(),0);
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.get_color_space(),tsl::color_space::rgba);
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.data(),nullptr);
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.cbegin(),img1.cend());
	CYNODELIC_TESTER_ASSERT_TRUE(img1.empty());
}

CYNODELIC_TESTER_SECTION(basic_image_move,image_move_assignment)
{
	tsl::rgba_image img1_old(160,120,tsl::color_space::rgba);
	tsl::rgba_image img1 = img1_old;
	tsl::rgba_image img2;
	img2 = std::move(img1);

	CYNODELIC_TESTER_ASSERT_EQUALS(img2.width(),img1_old.width());
	CYNODELIC_TESTER_ASSERT_EQUALS(img2.height(),img1_old.height());
	CYNODELIC_TESTER_ASSERT_EQUALS(img2.size(),img1_old.size());

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img2.width(),img1.width());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img2.height(),img1.height());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img2.size(),img1.size());

	CYNODELIC_TESTER_ASSERT_EQUALS(img1.width(),0);
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.height(),0);
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.size(),0);
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.get_color_space(),tsl::color_space::rgba);
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.data(),nullptr);
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.cbegin(),img1.cend());
	CYNODELIC_TESTER_ASSERT_TRUE(img1.empty());
}


#endif // CYNODELIC_TESELA_TEST_CORE_BASIC_IMAGE_MOVE_HPP
