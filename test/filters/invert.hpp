// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_FILTERS_INVERT_HPP
#define CYNODELIC_TESELA_TEST_FILTERS_INVERT_HPP


CYNODELIC_TESTER_TEST_CASE(invert);

CYNODELIC_TESTER_SECTION(invert,rgb)
{
	tsl::rgb_image img(2,2);

	img(0,0) = tsl::rgb_t(255,0,127);
	img(1,0) = tsl::rgb_t(20,99,200);
	img(0,1) = tsl::rgb_t(50,199,13);
	img(1,1) = tsl::rgb_t(250,5,121);

	tsl::rgb_image expected(2,2);

	expected(0,0) = tsl::rgb_t(0,255,128);
	expected(1,0) = tsl::rgb_t(235,156,55);
	expected(0,1) = tsl::rgb_t(205,56,242);
	expected(1,1) = tsl::rgb_t(5,250,134);

	tsl::invert(img);

	CYNODELIC_TESTER_CHECK_EQUALS(img(0,0),expected(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img(1,0),expected(1,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img(0,1),expected(0,1));
	CYNODELIC_TESTER_CHECK_EQUALS(img(1,1),expected(1,1));
}

CYNODELIC_TESTER_SECTION(invert,rgba)
{
	tsl::rgba_image img(2,2);

	img(0,0) = tsl::rgba_t(255,0,127,55);
	img(1,0) = tsl::rgba_t(20,99,200,102);
	img(0,1) = tsl::rgba_t(50,199,13,208);
	img(1,1) = tsl::rgba_t(250,5,121,191);

	tsl::rgba_image expected(2,2);

	expected(0,0) = tsl::rgba_t(0,255,128,55);
	expected(1,0) = tsl::rgba_t(235,156,55,102);
	expected(0,1) = tsl::rgba_t(205,56,242,208);
	expected(1,1) = tsl::rgba_t(5,250,134,191);

	tsl::invert(img);

	CYNODELIC_TESTER_CHECK_EQUALS(img(0,0),expected(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img(1,0),expected(1,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img(0,1),expected(0,1));
	CYNODELIC_TESTER_CHECK_EQUALS(img(1,1),expected(1,1));
}

CYNODELIC_TESTER_SECTION(invert,gray)
{
	tsl::gray_image img(2,2);

	img(0,0) = tsl::gray_t(130);
	img(1,0) = tsl::gray_t(222);
	img(0,1) = tsl::gray_t(90);
	img(1,1) = tsl::gray_t(201);

	tsl::gray_image expected(2,2);

	expected(0,0) = tsl::gray_t(125);
	expected(1,0) = tsl::gray_t(33);
	expected(0,1) = tsl::gray_t(165);
	expected(1,1) = tsl::gray_t(54);

	tsl::invert(img);

	CYNODELIC_TESTER_CHECK_EQUALS(img(0,0),expected(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img(1,0),expected(1,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img(0,1),expected(0,1));
	CYNODELIC_TESTER_CHECK_EQUALS(img(1,1),expected(1,1));
}

CYNODELIC_TESTER_SECTION(invert,ga)
{
	tsl::ga_image img(2,2);

	img(0,0) = tsl::ga_t(130,33);
	img(1,0) = tsl::ga_t(222,12);
	img(0,1) = tsl::ga_t(90,166);
	img(1,1) = tsl::ga_t(201,250);

	tsl::ga_image expected(2,2);

	expected(0,0) = tsl::ga_t(125,33);
	expected(1,0) = tsl::ga_t(33,12);
	expected(0,1) = tsl::ga_t(165,166);
	expected(1,1) = tsl::ga_t(54,250);

	tsl::invert(img);

	CYNODELIC_TESTER_CHECK_EQUALS(img(0,0),expected(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img(1,0),expected(1,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img(0,1),expected(0,1));
	CYNODELIC_TESTER_CHECK_EQUALS(img(1,1),expected(1,1));
}

CYNODELIC_TESTER_SECTION(invert,nrgb)
{
	tsl::nrgb_image img(2,2);

	img(0,0) = tsl::nrgb_t(1.0,0.0,127.0/255.0);
	img(1,0) = tsl::nrgb_t(20.0/255.0,99.0/255.0,200.0/255.0);
	img(0,1) = tsl::nrgb_t(50.0/255.0,199.0/255.0,13.0/255.0);
	img(1,1) = tsl::nrgb_t(250.0/255.0,5.0/255.0,121.0/255.0);

	tsl::nrgb_image expected(2,2);

	expected(0,0) = tsl::nrgb_t(0.0,1.0,128.0/255.0);
	expected(1,0) = tsl::nrgb_t(235.0/255.0,156.0/255.0,55.0/255.0);
	expected(0,1) = tsl::nrgb_t(205.0/255.0,56.0/255.0,242.0/255.0);
	expected(1,1) = tsl::nrgb_t(5.0/255.0,250.0/255.0,134.0/255.0);

	tsl::invert(img);

	CYNODELIC_TESTER_CHECK_EQUALS(img(0,0),expected(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img(1,0),expected(1,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img(0,1),expected(0,1));
	CYNODELIC_TESTER_CHECK_EQUALS(img(1,1),expected(1,1));
}

CYNODELIC_TESTER_SECTION(invert,nrgba)
{
	tsl::nrgba_image img(2,2);

	img(0,0) = tsl::nrgba_t(1.0,0.0,127.0/255.0,55.0/255.0);
	img(1,0) = tsl::nrgba_t(20.0/255.0,99.0/255.0,200.0/255.0,102.0/255.0);
	img(0,1) = tsl::nrgba_t(50.0/255.0,199.0/255.0,13.0/255.0,208.0/255.0);
	img(1,1) = tsl::nrgba_t(250.0/255.0,5.0/255.0,121.0/255.0,191.0/255.0);

	tsl::nrgba_image expected(2,2);

	expected(0,0) = tsl::nrgba_t(0.0,1.0,128.0/255.0,55.0/255.0);
	expected(1,0) = tsl::nrgba_t(235.0/255.0,156.0/255.0,55.0/255.0,102.0/255.0);
	expected(0,1) = tsl::nrgba_t(205.0/255.0,56.0/255.0,242.0/255.0,208.0/255.0);
	expected(1,1) = tsl::nrgba_t(5.0/255.0,250.0/255.0,134.0/255.0,191.0/255.0);

	tsl::invert(img);

	CYNODELIC_TESTER_CHECK_EQUALS(img(0,0),expected(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img(1,0),expected(1,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img(0,1),expected(0,1));
	CYNODELIC_TESTER_CHECK_EQUALS(img(1,1),expected(1,1));
}

CYNODELIC_TESTER_SECTION(invert,ngray)
{
	tsl::ngray_image img(2,2);

	img(0,0) = tsl::ngray_t(130.0/255.0);
	img(1,0) = tsl::ngray_t(222.0/255.0);
	img(0,1) = tsl::ngray_t(90.0/255.0);
	img(1,1) = tsl::ngray_t(201.0/255.0);

	tsl::ngray_image expected(2,2);

	expected(0,0) = tsl::ngray_t(125.0/255.0);
	expected(1,0) = tsl::ngray_t(33.0/255.0);
	expected(0,1) = tsl::ngray_t(165.0/255.0);
	expected(1,1) = tsl::ngray_t(54.0/255.0);

	tsl::invert(img);

	CYNODELIC_TESTER_CHECK_EQUALS(img(0,0),expected(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img(1,0),expected(1,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img(0,1),expected(0,1));
	CYNODELIC_TESTER_CHECK_EQUALS(img(1,1),expected(1,1));
}

CYNODELIC_TESTER_SECTION(invert,nga)
{
	tsl::nga_image img(2,2);

	img(0,0) = tsl::nga_t(130.0/255.0,33.0/255.0);
	img(1,0) = tsl::nga_t(222.0/255.0,12.0/255.0);
	img(0,1) = tsl::nga_t(90.0/255.0,166.0/255.0);
	img(1,1) = tsl::nga_t(201.0/255.0,250.0/255.0);

	tsl::nga_image expected(2,2);

	expected(0,0) = tsl::nga_t(125.0/255.0,33.0/255.0);
	expected(1,0) = tsl::nga_t(33.0/255.0,12.0/255.0);
	expected(0,1) = tsl::nga_t(165.0/255.0,166.0/255.0);
	expected(1,1) = tsl::nga_t(54.0/255.0,250.0/255.0);

	tsl::invert(img);

	CYNODELIC_TESTER_CHECK_EQUALS(img(0,0),expected(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img(1,0),expected(1,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img(0,1),expected(0,1));
	CYNODELIC_TESTER_CHECK_EQUALS(img(1,1),expected(1,1));
}


#endif // CYNODELIC_TESELA_TEST_FILTERS_INVERT_HPP
