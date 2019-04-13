// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_TRANSFORMATIONS_FLIP_HPP
#define CYNODELIC_TESELA_TEST_TRANSFORMATIONS_FLIP_HPP


CYNODELIC_TESTER_TEST_CASE(flip);

CYNODELIC_TESTER_SECTION(flip,horizontal)
{
	tsl::rgb_image img(4,3);

	img(0,0) = 0x0f0f0f_hrgb;
	img(1,0) = 0x0f0f0f_hrgb;
	img(2,0) = 0x000000_hrgb;
	img(3,0) = 0x000000_hrgb;

	img(0,1) = 0xff00ff_hrgb;
	img(1,1) = 0xff00ff_hrgb;
	img(2,1) = 0x00ff00_hrgb;
	img(3,1) = 0x00ff00_hrgb;

	img(0,2) = 0xff00ff_hrgb;
	img(1,2) = 0xff00ff_hrgb;
	img(2,2) = 0x00ff00_hrgb;
	img(3,2) = 0x00ff00_hrgb;

	tsl::rgb_image expected(4,3);

	expected(0,0) = 0x000000_hrgb;
	expected(1,0) = 0x000000_hrgb;
	expected(2,0) = 0x0f0f0f_hrgb;
	expected(3,0) = 0x0f0f0f_hrgb;

	expected(0,1) = 0x00ff00_hrgb;
	expected(1,1) = 0x00ff00_hrgb;
	expected(2,1) = 0xff00ff_hrgb;
	expected(3,1) = 0xff00ff_hrgb;

	expected(0,2) = 0x00ff00_hrgb;
	expected(1,2) = 0x00ff00_hrgb;
	expected(2,2) = 0xff00ff_hrgb;
	expected(3,2) = 0xff00ff_hrgb;

	tsl::flip(img,true,false);

	CYNODELIC_TESTER_CHECK_EQUALS(img,expected);
}

CYNODELIC_TESTER_SECTION(flip,vertical)
{
	tsl::rgb_image img(4,3);

	img(0,0) = 0x0f0f0f_hrgb;
	img(1,0) = 0x0f0f0f_hrgb;
	img(2,0) = 0x000000_hrgb;
	img(3,0) = 0x000000_hrgb;

	img(0,1) = 0xff00ff_hrgb;
	img(1,1) = 0xff00ff_hrgb;
	img(2,1) = 0x00ff00_hrgb;
	img(3,1) = 0x00ff00_hrgb;

	img(0,2) = 0xff00ff_hrgb;
	img(1,2) = 0xff00ff_hrgb;
	img(2,2) = 0x00ff00_hrgb;
	img(3,2) = 0x00ff00_hrgb;

	tsl::rgb_image expected(4,3);

	expected(0,0) = 0xff00ff_hrgb;
	expected(1,0) = 0xff00ff_hrgb;
	expected(2,0) = 0x00ff00_hrgb;
	expected(3,0) = 0x00ff00_hrgb;

	expected(0,1) = 0xff00ff_hrgb;
	expected(1,1) = 0xff00ff_hrgb;
	expected(2,1) = 0x00ff00_hrgb;
	expected(3,1) = 0x00ff00_hrgb;

	expected(0,2) = 0x0f0f0f_hrgb;
	expected(1,2) = 0x0f0f0f_hrgb;
	expected(2,2) = 0x000000_hrgb;
	expected(3,2) = 0x000000_hrgb;

	tsl::flip(img,false,true);

	CYNODELIC_TESTER_CHECK_EQUALS(img,expected);
}

CYNODELIC_TESTER_SECTION(flip,both)
{
	tsl::rgb_image img(4,3);

	img(0,0) = 0x0f0f0f_hrgb;
	img(1,0) = 0x0f0f0f_hrgb;
	img(2,0) = 0x000000_hrgb;
	img(3,0) = 0x000000_hrgb;

	img(0,1) = 0xff00ff_hrgb;
	img(1,1) = 0xff00ff_hrgb;
	img(2,1) = 0x00ff00_hrgb;
	img(3,1) = 0x00ff00_hrgb;

	img(0,2) = 0xff00ff_hrgb;
	img(1,2) = 0xff00ff_hrgb;
	img(2,2) = 0x00ff00_hrgb;
	img(3,2) = 0x00ff00_hrgb;

	tsl::rgb_image expected(4,3);

	expected(0,0) = 0x00ff00_hrgb;
	expected(1,0) = 0x00ff00_hrgb;
	expected(2,0) = 0xff00ff_hrgb;
	expected(3,0) = 0xff00ff_hrgb;

	expected(0,1) = 0x00ff00_hrgb;
	expected(1,1) = 0x00ff00_hrgb;
	expected(2,1) = 0xff00ff_hrgb;
	expected(3,1) = 0xff00ff_hrgb;

	expected(0,2) = 0x000000_hrgb;
	expected(1,2) = 0x000000_hrgb;
	expected(2,2) = 0x0f0f0f_hrgb;
	expected(3,2) = 0x0f0f0f_hrgb;

	tsl::flip(img,true,true);

	CYNODELIC_TESTER_CHECK_EQUALS(img,expected);
}

CYNODELIC_TESTER_SECTION(flip,none)
{
	tsl::rgb_image img(4,3);

	img(0,0) = 0x0f0f0f_hrgb;
	img(1,0) = 0x0f0f0f_hrgb;
	img(2,0) = 0x000000_hrgb;
	img(3,0) = 0x000000_hrgb;

	img(0,1) = 0xff00ff_hrgb;
	img(1,1) = 0xff00ff_hrgb;
	img(2,1) = 0x00ff00_hrgb;
	img(3,1) = 0x00ff00_hrgb;

	img(0,2) = 0xff00ff_hrgb;
	img(1,2) = 0xff00ff_hrgb;
	img(2,2) = 0x00ff00_hrgb;
	img(3,2) = 0x00ff00_hrgb;

	tsl::rgb_image expected(4,3);

	expected(0,0) = 0x0f0f0f_hrgb;
	expected(1,0) = 0x0f0f0f_hrgb;
	expected(2,0) = 0x000000_hrgb;
	expected(3,0) = 0x000000_hrgb;

	expected(0,1) = 0xff00ff_hrgb;
	expected(1,1) = 0xff00ff_hrgb;
	expected(2,1) = 0x00ff00_hrgb;
	expected(3,1) = 0x00ff00_hrgb;

	expected(0,2) = 0xff00ff_hrgb;
	expected(1,2) = 0xff00ff_hrgb;
	expected(2,2) = 0x00ff00_hrgb;
	expected(3,2) = 0x00ff00_hrgb;

	tsl::flip(img,false,false);

	CYNODELIC_TESTER_CHECK_EQUALS(img,expected);
}


#endif // CYNODELIC_TESELA_TEST_TRANSFORMATIONS_FLIP_HPP
