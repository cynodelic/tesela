// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_TRANSFORMATIONS_SCALE_BILINEAR_HPP
#define CYNODELIC_TESELA_TEST_TRANSFORMATIONS_SCALE_BILINEAR_HPP


CYNODELIC_TESTER_TEST_CASE(scale_bilinear);

CYNODELIC_TESTER_SECTION(scale_bilinear,first)
{
	tsl::rgb_image img(3,3);

	img(0,0) = 0x7fff07_hrgb;
	img(1,0) = 0x00ff0f_hrgb;
	img(2,0) = 0xffffff_hrgb;

	img(0,1) = 0xff7700_hrgb;
	img(1,1) = 0x0ff00f_hrgb;
	img(2,1) = 0xff0000_hrgb;

	img(0,2) = 0x07f707_hrgb;
	img(1,2) = 0x777fff_hrgb;
	img(2,2) = 0xf070f0_hrgb;

	tsl::scale(img,48,48,tsl::bilinear_algorithm);

	for (std::size_t iy = 0; iy < img.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For ix = " << ix << ", iy = " << iy << ":";

			CYNODELIC_TESTER_CHECK_EQUALS(img(ix,iy).red,bilinear_exp_xy[iy][ix][0]);
			CYNODELIC_TESTER_CHECK_EQUALS(img(ix,iy).green,bilinear_exp_xy[iy][ix][1]);
			CYNODELIC_TESTER_CHECK_EQUALS(img(ix,iy).blue,bilinear_exp_xy[iy][ix][2]);
		}
	}
}

CYNODELIC_TESTER_SECTION(scale_bilinear,second)
{
	tsl::rgb_image img(3,3);

	img(0,0) = 0x7fff07_hrgb;
	img(1,0) = 0x00ff0f_hrgb;
	img(2,0) = 0xffffff_hrgb;

	img(0,1) = 0xff7700_hrgb;
	img(1,1) = 0x0ff00f_hrgb;
	img(2,1) = 0xff0000_hrgb;

	img(0,2) = 0x07f707_hrgb;
	img(1,2) = 0x777fff_hrgb;
	img(2,2) = 0xf070f0_hrgb;

	tsl::scale(img,48,3,tsl::bilinear_algorithm);

	for (std::size_t iy = 0; iy < img.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For ix = " << ix << ", iy = " << iy << ":";

			CYNODELIC_TESTER_CHECK_EQUALS(img(ix,iy).red,bilinear_exp_x[iy][ix][0]);
			CYNODELIC_TESTER_CHECK_EQUALS(img(ix,iy).green,bilinear_exp_x[iy][ix][1]);
			CYNODELIC_TESTER_CHECK_EQUALS(img(ix,iy).blue,bilinear_exp_x[iy][ix][2]);
		}
	}
}

CYNODELIC_TESTER_SECTION(scale_bilinear,third)
{
	tsl::rgb_image img(3,3);

	img(0,0) = 0x7fff07_hrgb;
	img(1,0) = 0x00ff0f_hrgb;
	img(2,0) = 0xffffff_hrgb;

	img(0,1) = 0xff7700_hrgb;
	img(1,1) = 0x0ff00f_hrgb;
	img(2,1) = 0xff0000_hrgb;

	img(0,2) = 0x07f707_hrgb;
	img(1,2) = 0x777fff_hrgb;
	img(2,2) = 0xf070f0_hrgb;

	tsl::scale(img,3,48,tsl::bilinear_algorithm);

	for (std::size_t iy = 0; iy < img.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For ix = " << ix << ", iy = " << iy << ":";

			CYNODELIC_TESTER_CHECK_EQUALS(img(ix,iy).red,bilinear_exp_y[iy][ix][0]);
			CYNODELIC_TESTER_CHECK_EQUALS(img(ix,iy).green,bilinear_exp_y[iy][ix][1]);
			CYNODELIC_TESTER_CHECK_EQUALS(img(ix,iy).blue,bilinear_exp_y[iy][ix][2]);
		}
	}
}


#endif // CYNODELIC_TESELA_TEST_TRANSFORMATIONS_SCALE_BILINEAR_HPP
