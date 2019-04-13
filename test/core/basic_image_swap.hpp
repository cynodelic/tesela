// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_BASIC_IMAGE_SWAP_HPP
#define CYNODELIC_TESELA_TEST_CORE_BASIC_IMAGE_SWAP_HPP


CYNODELIC_TESTER_TEST_CASE(basic_image_swap);

CYNODELIC_TESTER_SECTION(basic_image_swap,image_member_function)
{
	tsl::rgba_image img1_old(5,4,tsl::color_space::rgba);
	tsl::rgba_image img2_old(3,7,tsl::color_space::ga);

	for (std::size_t iy = 0; iy < img1_old.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img1_old.width(); ix++)
		{
			img1_old(ix,iy) = tsl::rgba_t(127,255,32,127);
		}
	}

	for (std::size_t iy = 0; iy < img2_old.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img2_old.width(); ix++)
		{
			img2_old(ix,iy) = tsl::rgba_t(255,127);
		}
	}

	tsl::rgba_image img1(img1_old);
	tsl::rgba_image img2(img2_old);

	img1.swap(img2);

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.width(),img2.width());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.height(),img2.height());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.size(),img2.size());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.get_color_space(),img2.get_color_space());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(std::distance(img1.begin(),img1.end()),std::distance(img2.begin(),img2.end()));

	CYNODELIC_TESTER_ASSERT_EQUALS(img1.width(),img2_old.width());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.height(),img2_old.height());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.size(),img2_old.size());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.get_color_space(),img2_old.get_color_space());
	CYNODELIC_TESTER_ASSERT_EQUALS(std::distance(img1.begin(),img1.end()),std::distance(img2_old.begin(),img2_old.end()));

	CYNODELIC_TESTER_ASSERT_EQUALS(img2.width(),img1_old.width());
	CYNODELIC_TESTER_ASSERT_EQUALS(img2.height(),img1_old.height());
	CYNODELIC_TESTER_ASSERT_EQUALS(img2.size(),img1_old.size());
	CYNODELIC_TESTER_ASSERT_EQUALS(img2.get_color_space(),img1_old.get_color_space());
	CYNODELIC_TESTER_ASSERT_EQUALS(std::distance(img2.begin(),img2.end()),std::distance(img1_old.begin(),img1_old.end()));

	for (std::size_t iy = 0; iy < img1.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img1.width(); ix++)
		{
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy),img2_old(ix,iy));
		}
	}

	for (std::size_t iy = 0; iy < img2.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img2.width(); ix++)
		{
			CYNODELIC_TESTER_ASSERT_EQUALS(img2(ix,iy),img1_old(ix,iy));
		}
	}
}

CYNODELIC_TESTER_SECTION(basic_image_swap,image_std_swap_function)
{
	tsl::rgba_image img1_old(5,4,tsl::color_space::rgba);
	tsl::rgba_image img2_old(3,7,tsl::color_space::ga);

	for (std::size_t iy = 0; iy < img1_old.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img1_old.width(); ix++)
		{
			img1_old(ix,iy) = tsl::rgba_t(127,255,32,127);
		}
	}

	for (std::size_t iy = 0; iy < img2_old.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img2_old.width(); ix++)
		{
			img2_old(ix,iy) = tsl::rgba_t(255,127);
		}
	}

	tsl::rgba_image img1(img1_old);
	tsl::rgba_image img2(img2_old);

	std::swap(img1,img2);

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.width(),img2.width());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.height(),img2.height());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.size(),img2.size());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.get_color_space(),img2.get_color_space());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(std::distance(img1.begin(),img1.end()),std::distance(img2.begin(),img2.end()));

	CYNODELIC_TESTER_ASSERT_EQUALS(img1.width(),img2_old.width());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.height(),img2_old.height());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.size(),img2_old.size());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.get_color_space(),img2_old.get_color_space());
	CYNODELIC_TESTER_ASSERT_EQUALS(std::distance(img1.begin(),img1.end()),std::distance(img2_old.begin(),img2_old.end()));

	CYNODELIC_TESTER_ASSERT_EQUALS(img2.width(),img1_old.width());
	CYNODELIC_TESTER_ASSERT_EQUALS(img2.height(),img1_old.height());
	CYNODELIC_TESTER_ASSERT_EQUALS(img2.size(),img1_old.size());
	CYNODELIC_TESTER_ASSERT_EQUALS(img2.get_color_space(),img1_old.get_color_space());
	CYNODELIC_TESTER_ASSERT_EQUALS(std::distance(img2.begin(),img2.end()),std::distance(img1_old.begin(),img1_old.end()));

	for (std::size_t iy = 0; iy < img1.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img1.width(); ix++)
		{
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy),img2_old(ix,iy));
		}
	}

	for (std::size_t iy = 0; iy < img2.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img2.width(); ix++)
		{
			CYNODELIC_TESTER_ASSERT_EQUALS(img2(ix,iy),img1_old(ix,iy));
		}
	}
}

CYNODELIC_TESTER_SECTION(basic_image_swap,norm_image_member_function)
{
	tsl::nrgba_image img1_old(5,4,tsl::color_space::rgba);
	tsl::nrgba_image img2_old(3,7,tsl::color_space::ga);

	for (std::size_t iy = 0; iy < img1_old.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img1_old.width(); ix++)
		{
			img1_old(ix,iy) = tsl::nrgba_t(241.0/255.0,22.0/255.0,1.0,190.0/255.0);
		}
	}

	for (std::size_t iy = 0; iy < img2_old.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img2_old.width(); ix++)
		{
			img2_old(ix,iy) = tsl::nrgba_t(64.0/255.0,200.0/255.0);
		}
	}

	tsl::nrgba_image img1(img1_old);
	tsl::nrgba_image img2(img2_old);

	img1.swap(img2);

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.width(),img2.width());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.height(),img2.height());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.size(),img2.size());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.get_color_space(),img2.get_color_space());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(std::distance(img1.begin(),img1.end()),std::distance(img2.begin(),img2.end()));

	CYNODELIC_TESTER_ASSERT_EQUALS(img1.width(),img2_old.width());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.height(),img2_old.height());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.size(),img2_old.size());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.get_color_space(),img2_old.get_color_space());
	CYNODELIC_TESTER_ASSERT_EQUALS(std::distance(img1.begin(),img1.end()),std::distance(img2_old.begin(),img2_old.end()));

	CYNODELIC_TESTER_ASSERT_EQUALS(img2.width(),img1_old.width());
	CYNODELIC_TESTER_ASSERT_EQUALS(img2.height(),img1_old.height());
	CYNODELIC_TESTER_ASSERT_EQUALS(img2.size(),img1_old.size());
	CYNODELIC_TESTER_ASSERT_EQUALS(img2.get_color_space(),img1_old.get_color_space());
	CYNODELIC_TESTER_ASSERT_EQUALS(std::distance(img2.begin(),img2.end()),std::distance(img1_old.begin(),img1_old.end()));

	for (std::size_t iy = 0; iy < img1.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img1.width(); ix++)
		{
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy),img2_old(ix,iy));
		}
	}

	for (std::size_t iy = 0; iy < img2.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img2.width(); ix++)
		{
			CYNODELIC_TESTER_ASSERT_EQUALS(img2(ix,iy),img1_old(ix,iy));
		}
	}
}

CYNODELIC_TESTER_SECTION(basic_image_swap,norm_image_std_swap_function)
{
	tsl::nrgba_image img1_old(5,4,tsl::color_space::rgba);
	tsl::nrgba_image img2_old(3,7,tsl::color_space::ga);

	for (std::size_t iy = 0; iy < img1_old.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img1_old.width(); ix++)
		{
			img1_old(ix,iy) = tsl::nrgba_t(241.0/255.0,22.0/255.0,1.0,190.0/255.0);
		}
	}

	for (std::size_t iy = 0; iy < img2_old.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img2_old.width(); ix++)
		{
			img2_old(ix,iy) = tsl::nrgba_t(64.0/255.0,200.0/255.0);
		}
	}

	tsl::nrgba_image img1(img1_old);
	tsl::nrgba_image img2(img2_old);

	std::swap(img1,img2);

	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.width(),img2.width());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.height(),img2.height());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.size(),img2.size());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(img1.get_color_space(),img2.get_color_space());
	CYNODELIC_TESTER_ASSERT_NOT_EQUALS(std::distance(img1.begin(),img1.end()),std::distance(img2.begin(),img2.end()));

	CYNODELIC_TESTER_ASSERT_EQUALS(img1.width(),img2_old.width());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.height(),img2_old.height());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.size(),img2_old.size());
	CYNODELIC_TESTER_ASSERT_EQUALS(img1.get_color_space(),img2_old.get_color_space());
	CYNODELIC_TESTER_ASSERT_EQUALS(std::distance(img1.begin(),img1.end()),std::distance(img2_old.begin(),img2_old.end()));

	CYNODELIC_TESTER_ASSERT_EQUALS(img2.width(),img1_old.width());
	CYNODELIC_TESTER_ASSERT_EQUALS(img2.height(),img1_old.height());
	CYNODELIC_TESTER_ASSERT_EQUALS(img2.size(),img1_old.size());
	CYNODELIC_TESTER_ASSERT_EQUALS(img2.get_color_space(),img1_old.get_color_space());
	CYNODELIC_TESTER_ASSERT_EQUALS(std::distance(img2.begin(),img2.end()),std::distance(img1_old.begin(),img1_old.end()));

	for (std::size_t iy = 0; iy < img1.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img1.width(); ix++)
		{
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy),img2_old(ix,iy));
		}
	}

	for (std::size_t iy = 0; iy < img2.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img2.width(); ix++)
		{
			CYNODELIC_TESTER_ASSERT_EQUALS(img2(ix,iy),img1_old(ix,iy));
		}
	}
}


#endif // CYNODELIC_TESELA_TEST_CORE_BASIC_IMAGE_SWAP_HPP
