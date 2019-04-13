// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_IO_TIFF_INPUT_HPP
#define CYNODELIC_TESELA_TEST_IO_TIFF_INPUT_HPP


CYNODELIC_TESTER_TEST_CASE(tiff_input);

CYNODELIC_TESTER_SECTION(tiff_input,rgb)
{
	tsl::rgba_image img;

	try
	{
		tsl::tiff_io::read("data/tiff_rgb_test.tif",img);
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
			
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).red,tiff_rgb_test_pixels[iy][ix][0]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).green,tiff_rgb_test_pixels[iy][ix][1]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).blue,tiff_rgb_test_pixels[iy][ix][2]);
		}
	}
}

CYNODELIC_TESTER_SECTION(tiff_input,rgba)
{
	tsl::rgba_image img;

	try
	{
		tsl::tiff_io::read("data/tiff_rgba_test.tif",img);
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
			
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).red,tiff_rgba_test_pixels[iy][ix][0]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).green,tiff_rgba_test_pixels[iy][ix][1]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).blue,tiff_rgba_test_pixels[iy][ix][2]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).alpha,tiff_rgba_test_pixels[iy][ix][3]);
		}
	}
}

CYNODELIC_TESTER_SECTION(tiff_input,gray)
{
	tsl::rgba_image img;

	try
	{
		tsl::tiff_io::read("data/tiff_gray_test.tif",img);
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
			
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).red,tiff_gray_test_pixels[iy][ix][0]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).green,tiff_gray_test_pixels[iy][ix][0]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).blue,tiff_gray_test_pixels[iy][ix][0]);
		}
	}
}

CYNODELIC_TESTER_SECTION(tiff_input,ga)
{
	tsl::rgba_image img;

	try
	{
		tsl::tiff_io::read("data/tiff_ga_test.tif",img);
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
			
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).red,tiff_ga_test_pixels[iy][ix][0]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).green,tiff_ga_test_pixels[iy][ix][0]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).blue,tiff_ga_test_pixels[iy][ix][0]);
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy).alpha,tiff_ga_test_pixels[iy][ix][1]);
		}
	}
}


#endif // CYNODELIC_TESELA_TEST_IO_TIFF_INPUT_HPP
