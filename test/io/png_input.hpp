// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_IO_PNG_INPUT_HPP
#define CYNODELIC_TESELA_TEST_IO_PNG_INPUT_HPP


CYNODELIC_TESTER_TEST_CASE(png_input);

CYNODELIC_TESTER_SECTION(png_input,rgb)
{
	tsl::rgba_image img;

	try
	{
		tsl::png_io::read("data/png_rgb_test.png",img);
	}
	catch (const tsl::io_error& e)
	{
		CYNODELIC_TESTER_FAILURE() << "Error during image reading: " << e.what();
	}

	CYNODELIC_TESTER_ASSERT_EQUALS(img.width(),16);
	CYNODELIC_TESTER_ASSERT_EQUALS(img.height(),16);

	for (std::size_t iy = 0; iy < img.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "ix = " << ix << "; iy = " << iy;
			
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).red,png_rgb_test_pixels[iy][ix][0]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).green,png_rgb_test_pixels[iy][ix][1]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).blue,png_rgb_test_pixels[iy][ix][2]);
		}
	}
}

CYNODELIC_TESTER_SECTION(png_input,rgba)
{
	tsl::rgba_image img;

	try
	{
		tsl::png_io::read("data/png_rgba_test.png",img);
	}
	catch (const tsl::io_error& e)
	{
		CYNODELIC_TESTER_FAILURE() << "Error during image reading: " << e.what();
	}

	CYNODELIC_TESTER_ASSERT_EQUALS(img.width(),16);
	CYNODELIC_TESTER_ASSERT_EQUALS(img.height(),16);

	for (std::size_t iy = 0; iy < img.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "ix = " << ix << "; iy = " << iy;
			
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).red,png_rgba_test_pixels[iy][ix][0]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).green,png_rgba_test_pixels[iy][ix][1]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).blue,png_rgba_test_pixels[iy][ix][2]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).alpha,png_rgba_test_pixels[iy][ix][3]);
		}
	}
}

CYNODELIC_TESTER_SECTION(png_input,gray)
{
	tsl::rgba_image img;

	try
	{
		tsl::png_io::read("data/png_gray_test.png",img);
	}
	catch (const tsl::io_error& e)
	{
		CYNODELIC_TESTER_FAILURE() << "Error during image reading: " << e.what();
	}

	CYNODELIC_TESTER_ASSERT_EQUALS(img.width(),16);
	CYNODELIC_TESTER_ASSERT_EQUALS(img.height(),16);

	for (std::size_t iy = 0; iy < img.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "ix = " << ix << "; iy = " << iy;
			
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).red,png_gray_test_pixels[iy][ix][0]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).green,png_gray_test_pixels[iy][ix][0]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).blue,png_gray_test_pixels[iy][ix][0]);
		}
	}
}

CYNODELIC_TESTER_SECTION(png_input,ga)
{
	tsl::rgba_image img;

	try
	{
		tsl::png_io::read("data/png_ga_test.png",img);
	}
	catch (const tsl::io_error& e)
	{
		CYNODELIC_TESTER_FAILURE() << "Error during image reading: " << e.what();
	}

	CYNODELIC_TESTER_ASSERT_EQUALS(img.width(),16);
	CYNODELIC_TESTER_ASSERT_EQUALS(img.height(),16);

	for (std::size_t iy = 0; iy < img.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "ix = " << ix << "; iy = " << iy;
			
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).red,png_ga_test_pixels[iy][ix][0]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).green,png_ga_test_pixels[iy][ix][0]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).blue,png_ga_test_pixels[iy][ix][0]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).alpha,png_ga_test_pixels[iy][ix][1]);
		}
	}
}


#endif // CYNODELIC_TESELA_TEST_IO_PNG_INPUT_HPP
