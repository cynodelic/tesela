// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_BASIC_IMAGE_NOT_EQUALS_HPP
#define CYNODELIC_TESELA_TEST_CORE_BASIC_IMAGE_NOT_EQUALS_HPP


CYNODELIC_TESTER_TEST_CASE(basic_image_not_equals);

CYNODELIC_TESTER_SECTION(basic_image_not_equals,image_same_parameters)
{
	tsl::rgba_image img1(8,8,tsl::color_space::rgb);
	tsl::rgba_image img2(8,8,tsl::color_space::rgb);
	tsl::rgba_image img3(8,8,tsl::color_space::rgb);

	for (std::size_t iy = 0; iy < img1.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img1.width(); ix++)
		{
			img1(ix,iy) = ((ix + iy)%2   == 0) ? tsl::rgba_t(128,128,204) : tsl::rgba_t(255,64,21);
			img2(ix,iy) = ((ix/2 + iy)%2 == 0) ? tsl::rgba_t(255,0,127)   : tsl::rgba_t(30,21,0);
			img3(ix,iy) = ((ix + iy)%2   == 0) ? tsl::rgba_t(128,128,204) : tsl::rgba_t(255,64,21);
		}
	}


	CYNODELIC_TESTER_ASSERT_EQUALS(img1.width(),img2.width());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.height(),img2.height());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.size(),img2.size());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.get_color_space(),img2.get_color_space());

	for (std::size_t iy = 0; iy < img1.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img1.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For ix = " << ix << ", iy = " << iy << ":";
			CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1(ix,iy),img2(ix,iy));
		}
	}

	CYNODELIC_TESTER_CHECK_TRUE(img1 != img2);


	CYNODELIC_TESTER_ASSERT_EQUALS(img1.width(),img3.width());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.height(),img3.height());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.size(),img3.size());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.get_color_space(),img3.get_color_space());

	for (std::size_t iy = 0; iy < img1.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img1.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For ix = " << ix << ", iy = " << iy << ":";
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy),img3(ix,iy));
		}
	}

	CYNODELIC_TESTER_CHECK_FALSE(img1 != img3);
}

CYNODELIC_TESTER_SECTION(basic_image_not_equals,image_different_parameters)
{
	tsl::rgba_image img1(10,5,tsl::color_space::ga);
	tsl::rgba_image img2(9,6,tsl::color_space::rgb);
	tsl::rgba_image img3(10,5,tsl::color_space::ga);

	for (std::size_t iy = 0; iy < img1.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img1.width(); ix++)
		{
			img1(ix,iy) = ((ix + iy)%2   == 0) ? tsl::rgba_t(160,99) : tsl::rgba_t(240,255);
			img3(ix,iy) = ((ix + iy)%2   == 0) ? tsl::rgba_t(160,99) : tsl::rgba_t(240,255);
		}
	}

	for (std::size_t iy = 0; iy < img3.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img3.width(); ix++)
		{
			img2(ix,iy) = ((ix + iy)%2 == 0) ? tsl::rgba_t(255,255,127) : tsl::rgba_t(0,66,100);
		}
	}


	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.width(),img2.width());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.height(),img2.height());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.size(),img2.size());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.get_color_space(),img2.get_color_space());

	std::size_t min_size = (img1.size() < img3.size()) ? img1.size() : img3.size();

	for (std::size_t i = 0; i < min_size; i++)
	{
		std::size_t ix1 = i%img1.width();
		std::size_t iy1 = i/img1.width();

		std::size_t ix2 = i%img2.width();
		std::size_t iy2 = i/img2.width();

		CYNODELIC_TESTER_MESSAGE
			<< "ix1 = " << ix1 << ", iy1 = " << iy1 << tst::newline
			<< "ix2 = " << ix2 << ", iy2 = " << iy2;

		CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1(ix1,iy1),img2(ix2,iy2));
	}

	CYNODELIC_TESTER_CHECK_TRUE(img1 != img2);


	CYNODELIC_TESTER_ASSERT_EQUALS(img1.width(),img3.width());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.height(),img3.height());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.size(),img3.size());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.get_color_space(),img3.get_color_space());

	for (std::size_t iy = 0; iy < img1.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img1.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For ix = " << ix << ", iy = " << iy << ":";
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy),img3(ix,iy));
		}
	}

	CYNODELIC_TESTER_CHECK_FALSE(img1 != img3);
}

CYNODELIC_TESTER_SECTION(basic_image_not_equals,norm_image_same_parameters)
{
	tsl::nrgba_image img1(8,8,tsl::color_space::rgb);
	tsl::nrgba_image img2(8,8,tsl::color_space::rgb);
	tsl::nrgba_image img3(8,8,tsl::color_space::rgb);

	for (std::size_t iy = 0; iy < img1.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img1.width(); ix++)
		{
			img1(ix,iy) = ((ix + iy)%2   == 0) ? tsl::nrgba_t(128.0/255.0,180.0/255.0,204.0/255.0) : tsl::nrgba_t(98.0/255.0,1.0,196.0/255.0);
			img2(ix,iy) = ((ix/2 + iy)%2 == 0) ? tsl::nrgba_t(50.0/255.0,240.0/255.0,1.0)   : tsl::nrgba_t(0,1.0,176.0/255.0);
			img3(ix,iy) = ((ix + iy)%2   == 0) ? tsl::nrgba_t(128.0/255.0,180.0/255.0,204.0/255.0) : tsl::nrgba_t(98.0/255.0,1.0,196.0/255.0);
		}
	}


	CYNODELIC_TESTER_ASSERT_EQUALS(img1.width(),img2.width());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.height(),img2.height());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.size(),img2.size());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.get_color_space(),img2.get_color_space());

	for (std::size_t iy = 0; iy < img1.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img1.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For ix = " << ix << ", iy = " << iy << ":";
			CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1(ix,iy),img2(ix,iy));
		}
	}

	CYNODELIC_TESTER_CHECK_TRUE(img1 != img2);


	CYNODELIC_TESTER_ASSERT_EQUALS(img1.width(),img3.width());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.height(),img3.height());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.size(),img3.size());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.get_color_space(),img3.get_color_space());

	for (std::size_t iy = 0; iy < img1.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img1.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For ix = " << ix << ", iy = " << iy << ":";
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy),img3(ix,iy));
		}
	}

	CYNODELIC_TESTER_CHECK_FALSE(img1 != img3);
}


CYNODELIC_TESTER_SECTION(basic_image_not_equals,norm_image_different_parameters)
{
	tsl::nrgba_image img1(10,5,tsl::color_space::ga);
	tsl::nrgba_image img2(9,6,tsl::color_space::rgb);
	tsl::nrgba_image img3(10,5,tsl::color_space::ga);

	for (std::size_t iy = 0; iy < img1.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img1.width(); ix++)
		{
			img1(ix,iy) = ((ix + iy)%2   == 0) ? tsl::nrgba_t(35.0/255.0,1.0) : tsl::nrgba_t(199.0/255.0,101.0/255.0);
			img3(ix,iy) = ((ix + iy)%2   == 0) ? tsl::nrgba_t(35.0/255.0,1.0) : tsl::nrgba_t(199.0/255.0,101.0/255.0);
		}
	}

	for (std::size_t iy = 0; iy < img3.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img3.width(); ix++)
		{
			img2(ix,iy) = ((ix + iy)%2 == 0) ? tsl::nrgba_t(100.0/255.0,1.0,100.0/255.0) : tsl::nrgba_t(209.0/255.0,144.0/255.0,40.0/255.0);
		}
	}


	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.width(),img2.width());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.height(),img2.height());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.size(),img2.size());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.get_color_space(),img2.get_color_space());

	std::size_t min_size = (img1.size() < img3.size()) ? img1.size() : img3.size();

	for (std::size_t i = 0; i < min_size; i++)
	{
		std::size_t ix1 = i%img1.width();
		std::size_t iy1 = i/img1.width();

		std::size_t ix2 = i%img2.width();
		std::size_t iy2 = i/img2.width();

		CYNODELIC_TESTER_MESSAGE
			<< "ix1 = " << ix1 << ", iy1 = " << iy1 << tst::newline
			<< "ix2 = " << ix2 << ", iy2 = " << iy2;

		CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1(ix1,iy1),img2(ix2,iy2));
	}

	CYNODELIC_TESTER_CHECK_TRUE(img1 != img2);


	CYNODELIC_TESTER_ASSERT_EQUALS(img1.width(),img3.width());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.height(),img3.height());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.size(),img3.size());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.get_color_space(),img3.get_color_space());

	for (std::size_t iy = 0; iy < img1.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img1.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For ix = " << ix << ", iy = " << iy << ":";
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy),img3(ix,iy));
		}
	}

	CYNODELIC_TESTER_CHECK_FALSE(img1 != img3);
}

#endif // CYNODELIC_TESELA_TEST_CORE_BASIC_IMAGE_NOT_EQUALS_HPP
