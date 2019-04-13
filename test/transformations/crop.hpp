// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_TRANSFORMATIONS_CROP_HPP
#define CYNODELIC_TESELA_TEST_TRANSFORMATIONS_CROP_HPP


CYNODELIC_TESTER_TEST_CASE(crop);

CYNODELIC_TESTER_SECTION(crop,first)
{
	tsl::rgb_image img(4,4);

	tsl::rgb_image out(2,2);

	img(0,0) = out(0,0) = 0xff0000_hrgb;
	img(0,1) = out(0,1) = 0xff0000_hrgb;
	img(1,0) = out(1,0) = 0xff0000_hrgb;
	img(1,1) = out(1,1) = 0xff0000_hrgb;

	img(2,0) = 0x00ff00_hrgb;
	img(2,1) = 0x00ff00_hrgb;
	img(3,0) = 0x00ff00_hrgb;
	img(3,1) = 0x00ff00_hrgb;

	img(0,2) = 0x0ff000_hrgb;
	img(0,3) = 0x0ff000_hrgb;
	img(1,2) = 0x0ff000_hrgb;
	img(1,3) = 0x0ff000_hrgb;

	img(2,2) = 0x000ff0_hrgb;
	img(2,3) = 0x000ff0_hrgb;
	img(3,2) = 0x000ff0_hrgb;
	img(3,3) = 0x000ff0_hrgb;

	tsl::rectangle crop_area(2,2,0,0);

	CYNODELIC_TESTER_MESSAGE
		<< "Source image:" << tst::newline
		<< "    Width:  " << img.width() << tst::newline
		<< "    Height: " << img.height() << tst::newline
		<< "Area to crop:" << tst::newline
		<< "    Width:      " << crop_area.width << tst::newline
		<< "    Height:     " << crop_area.height << tst::newline
		<< "    X position: " << crop_area.x << tst::newline
		<< "    Y position: " << crop_area.y;

	tsl::crop(img,crop_area);

	CYNODELIC_TESTER_CHECK_EQUALS(img,out);
}

CYNODELIC_TESTER_SECTION(crop,second)
{
	tsl::rgb_image img(4,4);

	tsl::rgb_image out(2,2);

	img(0,0) = 0xff0000_hrgb;
	img(0,1) = 0xff0000_hrgb;
	img(1,0) = 0xff0000_hrgb;
	img(1,1) = 0xff0000_hrgb;

	img(2,0) = 0x00ff00_hrgb;
	img(2,1) = 0x00ff00_hrgb;
	img(3,0) = 0x00ff00_hrgb;
	img(3,1) = 0x00ff00_hrgb;

	img(0,2) = out(0,0) = 0x0ff000_hrgb;
	img(0,3) = out(0,1) = 0x0ff000_hrgb;
	img(1,2) = out(1,0) = 0x0ff000_hrgb;
	img(1,3) = out(1,1) = 0x0ff000_hrgb;

	img(2,2) = 0x000ff0_hrgb;
	img(2,3) = 0x000ff0_hrgb;
	img(3,2) = 0x000ff0_hrgb;
	img(3,3) = 0x000ff0_hrgb;

	tsl::rectangle crop_area(2,2,0,2);

	CYNODELIC_TESTER_MESSAGE
		<< "Source image:" << tst::newline
		<< "    Width:  " << img.width() << tst::newline
		<< "    Height: " << img.height() << tst::newline
		<< "Area to crop:" << tst::newline
		<< "    Width:      " << crop_area.width << tst::newline
		<< "    Height:     " << crop_area.height << tst::newline
		<< "    X position: " << crop_area.x << tst::newline
		<< "    Y position: " << crop_area.y;

	tsl::crop(img,crop_area);

	CYNODELIC_TESTER_CHECK_EQUALS(img,out);
}

CYNODELIC_TESTER_SECTION(crop,third)
{
	tsl::rgb_image img(4,4);

	tsl::rgb_image out(2,2);

	img(0,0) = 0xff0000_hrgb;
	img(0,1) = 0xff0000_hrgb;
	img(1,0) = 0xff0000_hrgb;
	img(1,1) = 0xff0000_hrgb;

	img(2,0) = out(0,0) = 0x00ff00_hrgb;
	img(2,1) = out(0,1) = 0x00ff00_hrgb;
	img(3,0) = out(1,0) = 0x00ff00_hrgb;
	img(3,1) = out(1,1) = 0x00ff00_hrgb;

	img(0,2) = 0x0ff000_hrgb;
	img(0,3) = 0x0ff000_hrgb;
	img(1,2) = 0x0ff000_hrgb;
	img(1,3) = 0x0ff000_hrgb;

	img(2,2) = 0x000ff0_hrgb;
	img(2,3) = 0x000ff0_hrgb;
	img(3,2) = 0x000ff0_hrgb;
	img(3,3) = 0x000ff0_hrgb;

	tsl::rectangle crop_area(2,2,2,0);

	CYNODELIC_TESTER_MESSAGE
		<< "Source image:" << tst::newline
		<< "    Width:  " << img.width() << tst::newline
		<< "    Height: " << img.height() << tst::newline
		<< "Area to crop:" << tst::newline
		<< "    Width:      " << crop_area.width << tst::newline
		<< "    Height:     " << crop_area.height << tst::newline
		<< "    X position: " << crop_area.x << tst::newline
		<< "    Y position: " << crop_area.y;

	tsl::crop(img,crop_area);

	CYNODELIC_TESTER_CHECK_EQUALS(img,out);
}

CYNODELIC_TESTER_SECTION(crop,fourth)
{
	tsl::rgb_image img(4,4);

	tsl::rgb_image out(2,2);

	img(0,0) = 0xff0000_hrgb;
	img(0,1) = 0xff0000_hrgb;
	img(1,0) = 0xff0000_hrgb;
	img(1,1) = 0xff0000_hrgb;

	img(2,0) = 0x00ff00_hrgb;
	img(2,1) = 0x00ff00_hrgb;
	img(3,0) = 0x00ff00_hrgb;
	img(3,1) = 0x00ff00_hrgb;

	img(0,2) = 0x0ff000_hrgb;
	img(0,3) = 0x0ff000_hrgb;
	img(1,2) = 0x0ff000_hrgb;
	img(1,3) = 0x0ff000_hrgb;

	img(2,2) = out(0,0) = 0x000ff0_hrgb;
	img(2,3) = out(0,1) = 0x000ff0_hrgb;
	img(3,2) = out(1,0) = 0x000ff0_hrgb;
	img(3,3) = out(1,1) = 0x000ff0_hrgb;

	tsl::rectangle crop_area(2,2,2,2);

	CYNODELIC_TESTER_MESSAGE
		<< "Source image:" << tst::newline
		<< "    Width:  " << img.width() << tst::newline
		<< "    Height: " << img.height() << tst::newline
		<< "Area to crop:" << tst::newline
		<< "    Width:      " << crop_area.width << tst::newline
		<< "    Height:     " << crop_area.height << tst::newline
		<< "    X position: " << crop_area.x << tst::newline
		<< "    Y position: " << crop_area.y;

	tsl::crop(img,crop_area);

	CYNODELIC_TESTER_CHECK_EQUALS(img,out);
}


#endif // CYNODELIC_TESELA_TEST_TRANSFORMATIONS_CROP_HPP
