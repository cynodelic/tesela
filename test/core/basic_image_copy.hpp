// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_BASIC_IMAGE_COPY_HPP
#define CYNODELIC_TESELA_TEST_CORE_BASIC_IMAGE_COPY_HPP


CYNODELIC_TESTER_TEST_CASE(basic_image_copy);

CYNODELIC_TESTER_SECTION(basic_image_copy,image_copy_constructor)
{
	std::size_t sizex = 4;
	std::size_t sizey = 3;

	CYNODELIC_TESTER_MESSAGE << "X size: " << sizex << ", Y size: " << sizey;

	tsl::rgba_image img1(4,3);

	for (std::size_t iy = 0; iy < sizey; iy++)
	{
		for (std::size_t ix = 0; ix < sizex; ix++)
		{
			switch ((ix + iy)%4)
			{
				case 0:
					img1(ix,iy) = tsl::rgba_t(0,255);
					break;
				case 1:
					img1(ix,iy) = tsl::rgba_t(127,64);
					break;
				case 2:
					img1(ix,iy) = tsl::rgba_t(255,127);
					break;
				case 3:
					img1(ix,iy) = tsl::rgba_t(255,0,0,32);
					break;
			}
		}
	}

	tsl::rgba_image img2(img1);


	for (std::size_t iy = 0; iy < sizey; iy++)
	{
		for (std::size_t ix = 0; ix < sizex; ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For img1(" << ix << "," << iy << ") and img2(" << ix << "," << iy << "):";
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy).red,img2(ix,iy).red);
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy).green,img2(ix,iy).green);
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy).blue,img2(ix,iy).blue);
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy).alpha,img2(ix,iy).alpha);
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy),img2(ix,iy));
		}
	}
}

CYNODELIC_TESTER_SECTION(basic_image_copy,image_copy_assignment)
{
	std::size_t sizex = 4;
	std::size_t sizey = 3;

	CYNODELIC_TESTER_MESSAGE << "X size: " << sizex << ", Y size: " << sizey;

	tsl::rgba_image img1(4,3);

	for (std::size_t iy = 0; iy < sizey; iy++)
	{
		for (std::size_t ix = 0; ix < sizex; ix++)
		{
			switch ((ix + iy)%4)
			{
				case 0:
					img1(ix,iy) = tsl::rgba_t(0,255);
					break;
				case 1:
					img1(ix,iy) = tsl::rgba_t(127,64);
					break;
				case 2:
					img1(ix,iy) = tsl::rgba_t(255,127);
					break;
				case 3:
					img1(ix,iy) = tsl::rgba_t(255,0,0,32);
					break;
			}
		}
	}

	tsl::rgba_image img2;
	img2 = img1;


	for (std::size_t iy = 0; iy < sizey; iy++)
	{
		for (std::size_t ix = 0; ix < sizex; ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For img1(" << ix << "," << iy << ") and img2(" << ix << "," << iy << "):";
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy).red,img2(ix,iy).red);
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy).green,img2(ix,iy).green);
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy).blue,img2(ix,iy).blue);
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy).alpha,img2(ix,iy).alpha);
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy),img2(ix,iy));
		}
	}
}

CYNODELIC_TESTER_SECTION(basic_image_copy,norm_image_copy_constructor)
{
	std::size_t sizex = 4;
	std::size_t sizey = 3;

	CYNODELIC_TESTER_MESSAGE << "X size: " << sizex << ", Y size: " << sizey;

	tsl::nrgba_image img1(4,3);

	for (std::size_t iy = 0; iy < sizey; iy++)
	{
		for (std::size_t ix = 0; ix < sizex; ix++)
		{
			switch ((ix + iy)%4)
			{
				case 0:
					img1(ix,iy) = tsl::nrgba_t(0.0,1.0);
					break;
				case 1:
					img1(ix,iy) = tsl::nrgba_t(127.0/255.0,64.0/255.0);
					break;
				case 2:
					img1(ix,iy) = tsl::nrgba_t(1.0,127.0/255.0);
					break;
				case 3:
					img1(ix,iy) = tsl::nrgba_t(1.0,0,0,32.0/255.0);
					break;
			}
		}
	}

	tsl::nrgba_image img2(img1);


	for (std::size_t iy = 0; iy < sizey; iy++)
	{
		for (std::size_t ix = 0; ix < sizex; ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For img1(" << ix << "," << iy << ") and img2(" << ix << "," << iy << "):";
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy).red,img2(ix,iy).red);
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy).green,img2(ix,iy).green);
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy).blue,img2(ix,iy).blue);
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy).alpha,img2(ix,iy).alpha);
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy),img2(ix,iy));
		}
	}
}

CYNODELIC_TESTER_SECTION(basic_image_copy,norm_image_copy_assignment)
{
	std::size_t sizex = 4;
	std::size_t sizey = 3;

	CYNODELIC_TESTER_MESSAGE << "X size: " << sizex << ", Y size: " << sizey;

	tsl::nrgba_image img1(4,3);

	for (std::size_t iy = 0; iy < sizey; iy++)
	{
		for (std::size_t ix = 0; ix < sizex; ix++)
		{
			switch ((ix + iy)%4)
			{
				case 0:
					img1(ix,iy) = tsl::nrgba_t(0.0,1.0);
					break;
				case 1:
					img1(ix,iy) = tsl::nrgba_t(127.0/255.0,64.0/255.0);
					break;
				case 2:
					img1(ix,iy) = tsl::nrgba_t(1.0,127.0/255.0);
					break;
				case 3:
					img1(ix,iy) = tsl::nrgba_t(1.0,0,0,32.0/255.0);
					break;
			}
		}
	}

	tsl::nrgba_image img2;
	img2 = img1;


	for (std::size_t iy = 0; iy < sizey; iy++)
	{
		for (std::size_t ix = 0; ix < sizex; ix++)
		{
			CYNODELIC_TESTER_MESSAGE << "For img1(" << ix << "," << iy << ") and img2(" << ix << "," << iy << "):";
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy).red,img2(ix,iy).red);
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy).green,img2(ix,iy).green);
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy).blue,img2(ix,iy).blue);
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy).alpha,img2(ix,iy).alpha);
			CYNODELIC_TESTER_ASSERT_EQUALS(img1(ix,iy),img2(ix,iy));
		}
	}
}


#endif // CYNODELIC_TESELA_TEST_CORE_BASIC_IMAGE_COPY_HPP
