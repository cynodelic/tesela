// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_BASIC_IMAGE_INITIALIZATION_HPP
#define CYNODELIC_TESELA_TEST_CORE_BASIC_IMAGE_INITIALIZATION_HPP


CYNODELIC_TESTER_TEST_CASE(basic_image_initialization);

CYNODELIC_TESTER_SECTION(basic_image_initialization,image_empty_constructor)
{
	tsl::rgba_image img;

	CYNODELIC_TESTER_CHECK_EQUALS(img.width(),0);
	CYNODELIC_TESTER_CHECK_EQUALS(img.height(),0);
	CYNODELIC_TESTER_CHECK_EQUALS(img.size(),0);
	CYNODELIC_TESTER_CHECK_EQUALS(img.get_color_space(),tsl::color_space::rgba);
	CYNODELIC_TESTER_CHECK_EQUALS(img.data(),nullptr);
	CYNODELIC_TESTER_CHECK_EQUALS(img.cbegin(),img.cend());
	CYNODELIC_TESTER_CHECK_TRUE(img.empty());
}

CYNODELIC_TESTER_SECTION(basic_image_initialization,image_constructor)
{
	tsl::rgba_image img(3,2,tsl::color_space::rgba);

	CYNODELIC_TESTER_CHECK_EQUALS(img.width(),3);
	CYNODELIC_TESTER_CHECK_EQUALS(img.height(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(img.size(),6);
	CYNODELIC_TESTER_CHECK_EQUALS(img.get_color_space(),tsl::color_space::rgba);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(img.data(),nullptr);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(img.cbegin(),img.cend());
	CYNODELIC_TESTER_CHECK_FALSE(img.empty());

	for (std::size_t iy = 0; iy < img.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For ix = " << ix << ", iy = " << iy;
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy),tsl::rgba_t{});
		}
	}
}

CYNODELIC_TESTER_SECTION(basic_image_initialization,image_rectangle_constructor)
{
	tsl::rectangle rct(3,2);

	tsl::rgba_image img(rct,tsl::color_space::rgba);

	CYNODELIC_TESTER_CHECK_EQUALS(img.width(),3);
	CYNODELIC_TESTER_CHECK_EQUALS(img.height(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(img.size(),6);
	CYNODELIC_TESTER_CHECK_EQUALS(img.get_color_space(),tsl::color_space::rgba);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(img.data(),nullptr);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(img.cbegin(),img.cend());

	for (std::size_t iy = 0; iy < img.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For ix = " << ix << ", iy = " << iy;
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy),tsl::rgba_t{});
		}
	}
}

CYNODELIC_TESTER_SECTION(basic_image_initialization,image_assignment)
{
	tsl::rgba_image img = tsl::rgba_image{3,2,tsl::color_space::rgba};

	CYNODELIC_TESTER_CHECK_EQUALS(img.width(),3);
	CYNODELIC_TESTER_CHECK_EQUALS(img.height(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(img.size(),6);
	CYNODELIC_TESTER_CHECK_EQUALS(img.get_color_space(),tsl::color_space::rgba);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(img.data(),nullptr);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(img.cbegin(),img.cend());
	CYNODELIC_TESTER_CHECK_FALSE(img.empty());

	for (std::size_t iy = 0; iy < img.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For ix = " << ix << ", iy = " << iy;
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy),tsl::rgba_t{});
		}
	}
}

CYNODELIC_TESTER_SECTION(basic_image_initialization,norm_image_empty_constructor)
{
	tsl::norm_image img;

	CYNODELIC_TESTER_CHECK_EQUALS(img.width(),0);
	CYNODELIC_TESTER_CHECK_EQUALS(img.height(),0);
	CYNODELIC_TESTER_CHECK_EQUALS(img.size(),0);
	CYNODELIC_TESTER_CHECK_EQUALS(img.get_color_space(),tsl::color_space::rgba);
	CYNODELIC_TESTER_CHECK_EQUALS(img.data(),nullptr);
	CYNODELIC_TESTER_CHECK_EQUALS(img.cbegin(),img.cend());
	CYNODELIC_TESTER_CHECK_TRUE(img.empty());
}

CYNODELIC_TESTER_SECTION(basic_image_initialization,norm_image_constructor)
{
	tsl::norm_image img(2,4,tsl::color_space::gray);

	CYNODELIC_TESTER_CHECK_EQUALS(img.width(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(img.height(),4);
	CYNODELIC_TESTER_CHECK_EQUALS(img.size(),8);
	CYNODELIC_TESTER_CHECK_EQUALS(img.get_color_space(),tsl::color_space::gray);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(img.data(),nullptr);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(img.cbegin(),img.cend());
	CYNODELIC_TESTER_CHECK_FALSE(img.empty());

	for (std::size_t iy = 0; iy < img.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For ix = " << ix << ", iy = " << iy;
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy),tsl::nrgba_t{});
		}
	}
}

CYNODELIC_TESTER_SECTION(basic_image_initialization,norm_image_rectangle_constructor)
{
	tsl::rectangle rct(2,4);

	tsl::norm_image img(rct,tsl::color_space::gray);

	CYNODELIC_TESTER_CHECK_EQUALS(img.width(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(img.height(),4);
	CYNODELIC_TESTER_CHECK_EQUALS(img.size(),8);
	CYNODELIC_TESTER_CHECK_EQUALS(img.get_color_space(),tsl::color_space::gray);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(img.data(),nullptr);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(img.cbegin(),img.cend());
	CYNODELIC_TESTER_CHECK_FALSE(img.empty());

	for (std::size_t iy = 0; iy < img.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For ix = " << ix << ", iy = " << iy;
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy),tsl::nrgba_t{});
		}
	}
}

CYNODELIC_TESTER_SECTION(basic_image_initialization,norm_image_assignment)
{
	tsl::norm_image img = tsl::norm_image{2,4,tsl::color_space::gray};

	CYNODELIC_TESTER_CHECK_EQUALS(img.width(),2);
	CYNODELIC_TESTER_CHECK_EQUALS(img.height(),4);
	CYNODELIC_TESTER_CHECK_EQUALS(img.size(),8);
	CYNODELIC_TESTER_CHECK_EQUALS(img.get_color_space(),tsl::color_space::gray);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(img.data(),nullptr);
	CYNODELIC_TESTER_CHECK_NOT_EQUALS(img.cbegin(),img.cend());
	CYNODELIC_TESTER_CHECK_FALSE(img.empty());

	for (std::size_t iy = 0; iy < img.height(); iy++)
	{
		for (std::size_t ix = 0; ix < img.width(); ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For ix = " << ix << ", iy = " << iy << ":";
			CYNODELIC_TESTER_ASSERT_EQUALS(img(ix,iy),tsl::nrgba_t{});
		}
	}
}


#endif // CYNODELIC_TESELA_TEST_CORE_BASIC_IMAGE_INITIALIZATION_HPP
