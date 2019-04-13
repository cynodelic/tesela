// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_BASIC_IMAGE_ITERATOR_HPP
#define CYNODELIC_TESELA_TEST_CORE_BASIC_IMAGE_ITERATOR_HPP


CYNODELIC_TESTER_TEST_CASE(basic_image_iterator);

CYNODELIC_TESTER_SECTION(basic_image_iterator,image)
{
	tsl::rgba_t pixels[16] = {
		tsl::rgba_t(  0,255,240, 15),tsl::rgba_t( 63,255,240, 15),tsl::rgba_t(127,255,240,127),tsl::rgba_t(255,255,240,127),
		tsl::rgba_t(  0,192,128, 15),tsl::rgba_t( 63,192,128, 15),tsl::rgba_t(127,192,128,127),tsl::rgba_t(255,192,128,127),
		tsl::rgba_t(  0,128, 64,255),tsl::rgba_t( 63,128, 64,255),tsl::rgba_t(127,128, 64,  0),tsl::rgba_t(255,128, 64,  0),
		tsl::rgba_t(  0, 64, 32,255),tsl::rgba_t( 63, 64, 32,255),tsl::rgba_t(127, 64, 32,  0),tsl::rgba_t(255, 64, 32,  0)
	};

	tsl::rgba_image img(4,4);

	for (std::size_t i = 0; i < 16; i++)
	{
		std::size_t iy = i/4;
		std::size_t ix = i%4;
		img(ix,iy) = pixels[i];
	}


	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img.begin(),img.end());

	std::size_t idx = 0;
	for (auto iter = img.begin(); iter != img.end(); iter++)
	{
		CYNODELIC_TESTER_MESSAGE << "For idx = " << idx << ", *iter = " << *iter << ", pixels[idx] = " << pixels[idx] << ":";

		CYNODELIC_TESTER_ASSERT_EQUALS(*iter,pixels[idx]);
		idx++;
	}
}

CYNODELIC_TESTER_SECTION(basic_image_iterator,norm_image)
{
	tsl::nrgba_t pixels[16] = {
		tsl::nrgba_t(  0.0/255.0,        1.0,240.0/255.0, 15.0/255.0),tsl::nrgba_t( 63.0/255.0,        1.0,240.0/255.0, 15.0/255.0),tsl::nrgba_t(127.0/255.0,        1.0,240.0/255.0,127.0/255.0),tsl::nrgba_t(        1.0,        1.0,240.0/255.0,127.0/255.0),
		tsl::nrgba_t(  0.0/255.0,192.0/255.0,128.0/255.0, 15.0/255.0),tsl::nrgba_t( 63.0/255.0,192.0/255.0,128.0/255.0, 15.0/255.0),tsl::nrgba_t(127.0/255.0,192.0/255.0,128.0/255.0,127.0/255.0),tsl::nrgba_t(        1.0,192.0/255.0,128.0/255.0,127.0/255.0),
		tsl::nrgba_t(  0.0/255.0,128.0/255.0, 64.0/255.0,        1.0),tsl::nrgba_t( 63.0/255.0,128.0/255.0, 64.0/255.0,        1.0),tsl::nrgba_t(127.0/255.0,128.0/255.0, 64.0/255.0,  0.0/255.0),tsl::nrgba_t(        1.0,128.0/255.0, 64.0/255.0,  0.0/255.0),
		tsl::nrgba_t(  0.0/255.0, 64.0/255.0, 32.0/255.0,        1.0),tsl::nrgba_t( 63.0/255.0, 64.0/255.0, 32.0/255.0,        1.0),tsl::nrgba_t(127.0/255.0, 64.0/255.0, 32.0/255.0,  0.0/255.0),tsl::nrgba_t(        1.0, 64.0/255.0, 32.0/255.0,  0.0/255.0)
	};

	tsl::nrgba_image img(4,4);

	for (std::size_t i = 0; i < 16; i++)
	{
		std::size_t iy = i/4;
		std::size_t ix = i%4;
		img(ix,iy) = pixels[i];
	}


	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img.begin(),img.end());

	std::size_t idx = 0;
	for (auto iter = img.begin(); iter != img.end(); iter++)
	{
		CYNODELIC_TESTER_MESSAGE << "For idx = " << idx << ", *iter = " << *iter << ", pixels[idx] = " << pixels[idx] << ":";

		CYNODELIC_TESTER_ASSERT_EQUALS(*iter,pixels[idx]);
		idx++;
	}
}


CYNODELIC_TESTER_TEST_CASE(basic_image_const_iterator);

CYNODELIC_TESTER_SECTION(basic_image_const_iterator,image)
{
	tsl::rgba_t pixels[16] = {
		tsl::rgba_t(  0,255,240, 15),tsl::rgba_t( 63,255,240, 15),tsl::rgba_t(127,255,240,127),tsl::rgba_t(255,255,240,127),
		tsl::rgba_t(  0,192,128, 15),tsl::rgba_t( 63,192,128, 15),tsl::rgba_t(127,192,128,127),tsl::rgba_t(255,192,128,127),
		tsl::rgba_t(  0,128, 64,255),tsl::rgba_t( 63,128, 64,255),tsl::rgba_t(127,128, 64,  0),tsl::rgba_t(255,128, 64,  0),
		tsl::rgba_t(  0, 64, 32,255),tsl::rgba_t( 63, 64, 32,255),tsl::rgba_t(127, 64, 32,  0),tsl::rgba_t(255, 64, 32,  0)
	};

	tsl::rgba_image img(4,4);

	for (std::size_t i = 0; i < 16; i++)
	{
		std::size_t iy = i/4;
		std::size_t ix = i%4;
		img(ix,iy) = pixels[i];
	}


	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img.cbegin(),img.cend());

	std::size_t idx = 0;
	for (auto iter = img.cbegin(); iter != img.cend(); iter++)
	{
		CYNODELIC_TESTER_MESSAGE << "For idx = " << idx << ", *iter = " << *iter << ", pixels[idx] = " << pixels[idx] << ":";

		CYNODELIC_TESTER_ASSERT_EQUALS(*iter,pixels[idx]);
		idx++;
	}
}

CYNODELIC_TESTER_SECTION(basic_image_const_iterator,norm_image)
{
	tsl::nrgba_t pixels[16] = {
		tsl::nrgba_t(  0.0/255.0,        1.0,240.0/255.0, 15.0/255.0),tsl::nrgba_t( 63.0/255.0,        1.0,240.0/255.0, 15.0/255.0),tsl::nrgba_t(127.0/255.0,        1.0,240.0/255.0,127.0/255.0),tsl::nrgba_t(        1.0,        1.0,240.0/255.0,127.0/255.0),
		tsl::nrgba_t(  0.0/255.0,192.0/255.0,128.0/255.0, 15.0/255.0),tsl::nrgba_t( 63.0/255.0,192.0/255.0,128.0/255.0, 15.0/255.0),tsl::nrgba_t(127.0/255.0,192.0/255.0,128.0/255.0,127.0/255.0),tsl::nrgba_t(        1.0,192.0/255.0,128.0/255.0,127.0/255.0),
		tsl::nrgba_t(  0.0/255.0,128.0/255.0, 64.0/255.0,        1.0),tsl::nrgba_t( 63.0/255.0,128.0/255.0, 64.0/255.0,        1.0),tsl::nrgba_t(127.0/255.0,128.0/255.0, 64.0/255.0,  0.0/255.0),tsl::nrgba_t(        1.0,128.0/255.0, 64.0/255.0,  0.0/255.0),
		tsl::nrgba_t(  0.0/255.0, 64.0/255.0, 32.0/255.0,        1.0),tsl::nrgba_t( 63.0/255.0, 64.0/255.0, 32.0/255.0,        1.0),tsl::nrgba_t(127.0/255.0, 64.0/255.0, 32.0/255.0,  0.0/255.0),tsl::nrgba_t(        1.0, 64.0/255.0, 32.0/255.0,  0.0/255.0)
	};

	tsl::nrgba_image img(4,4);

	for (std::size_t i = 0; i < 16; i++)
	{
		std::size_t iy = i/4;
		std::size_t ix = i%4;
		img(ix,iy) = pixels[i];
	}


	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img.cbegin(),img.cend());

	std::size_t idx = 0;
	for (auto iter = img.cbegin(); iter != img.cend(); iter++)
	{
		CYNODELIC_TESTER_MESSAGE << "For idx = " << idx << ", *iter = " << *iter << ", pixels[idx] = " << pixels[idx] << ":";

		CYNODELIC_TESTER_ASSERT_EQUALS(*iter,pixels[idx]);
		idx++;
	}
}


#endif // CYNODELIC_TESELA_TEST_CORE_BASIC_IMAGE_ITERATOR_HPP
