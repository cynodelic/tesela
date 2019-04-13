// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_PIXEL_CAST_HPP
#define CYNODELIC_TESELA_TEST_CORE_PIXEL_CAST_HPP


CYNODELIC_TESTER_TEST_CASE(pixel_cast);

CYNODELIC_TESTER_SECTION(pixel_cast,from_rgb)
{
	tsl::rgb_t input(134,255,31);

	tsl::tdouble expected_ngray{0.2126*(134.0/255.0) + 0.7152*1.0 + 0.0722*(31.0/255.0)};
	std::uint8_t expected_gray  = static_cast<std::uint8_t>(expected_ngray*255.0);

	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::rgb_t>(input),tsl::rgb_t(134,255,31));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::rgba_t>(input),tsl::rgba_t(134,255,31,255));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::gray_t>(input),tsl::gray_t(expected_gray));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::ga_t>(input),tsl::ga_t(expected_gray,255));

	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nrgb_t>(input),tsl::nrgb_t(134.0/255.0,1.0,31.0/255.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nrgba_t>(input),tsl::nrgba_t(134.0/255.0,1.0,31.0/255.0,1.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::ngray_t>(input),tsl::ngray_t(expected_ngray));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nga_t>(input),tsl::nga_t(expected_ngray,1.0));
}

CYNODELIC_TESTER_SECTION(pixel_cast,from_rgba)
{
	tsl::rgba_t input(244,100,123,99);

	tsl::tdouble expected_ngray{0.2126*(244.0/255.0) + 0.7152*(100.0/255.0) + 0.0722*(123.0/255.0)};
	std::uint8_t expected_gray  = static_cast<std::uint8_t>(expected_ngray*255.0);

	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::rgb_t>(input),tsl::rgb_t(244,100,123));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::rgba_t>(input),tsl::rgba_t(244,100,123,99));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::gray_t>(input),tsl::gray_t(expected_gray));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::ga_t>(input),tsl::ga_t(expected_gray,99));

	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nrgb_t>(input),tsl::nrgb_t(244.0/255.0,100.0/255.0,123.0/255.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nrgba_t>(input),tsl::nrgba_t(244.0/255.0,100.0/255.0,123.0/255.0,99.0/255.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::ngray_t>(input),tsl::ngray_t(expected_ngray));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nga_t>(input),tsl::nga_t(expected_ngray,99.0/255.0));
}

CYNODELIC_TESTER_SECTION(pixel_cast,from_gray)
{
	tsl::gray_t input(150);

	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::rgb_t>(input),tsl::rgb_t(150,150,150));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::rgba_t>(input),tsl::rgba_t(150,150,150,255));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::gray_t>(input),tsl::gray_t(150));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::ga_t>(input),tsl::ga_t(150,255));

	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nrgb_t>(input),tsl::nrgb_t(150.0/255.0,150.0/255.0,150.0/255.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nrgba_t>(input),tsl::nrgba_t(150.0/255.0,150.0/255.0,150.0/255.0,1.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::ngray_t>(input),tsl::ngray_t(150.0/255.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nga_t>(input),tsl::nga_t(150.0/255.0,1.0));
}

CYNODELIC_TESTER_SECTION(pixel_cast,from_ga)
{
	tsl::ga_t input(87,199);

	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::rgb_t>(input),tsl::rgb_t(87,87,87));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::rgba_t>(input),tsl::rgba_t(87,87,87,199));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::gray_t>(input),tsl::gray_t(87));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::ga_t>(input),tsl::ga_t(87,199));

	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nrgb_t>(input),tsl::nrgb_t(87.0/255.0,87.0/255.0,87.0/255.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nrgba_t>(input),tsl::nrgba_t(87.0/255.0,87.0/255.0,87.0/255.0,199.0/255.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::ngray_t>(input),tsl::ngray_t(87.0/255.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nga_t>(input),tsl::nga_t(87.0/255.0,199.0/255.0));
}

CYNODELIC_TESTER_SECTION(pixel_cast,from_nrgb)
{
	tsl::nrgb_t input(134.0/255.0,1.0,31.0/255.0);

	tsl::tdouble expected_ngray{0.2126*(134.0/255.0) + 0.7152*1.0 + 0.0722*(31.0/255.0)};
	std::uint8_t expected_gray  = static_cast<std::uint8_t>(expected_ngray*255.0);

	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::rgb_t>(input),tsl::rgb_t(134,255,31));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::rgba_t>(input),tsl::rgba_t(134,255,31,255));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::gray_t>(input),tsl::gray_t(expected_gray));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::ga_t>(input),tsl::ga_t(expected_gray,255));

	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nrgb_t>(input),tsl::nrgb_t(134.0/255.0,1.0,31.0/255.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nrgba_t>(input),tsl::nrgba_t(134.0/255.0,1.0,31.0/255.0,1.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::ngray_t>(input),tsl::ngray_t(expected_ngray));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nga_t>(input),tsl::nga_t(expected_ngray,1.0));
}

CYNODELIC_TESTER_SECTION(pixel_cast,from_nrgba)
{
	tsl::nrgba_t input(244.0/255.0,100.0/255.0,123.0/255.0,99.0/255.0);

	tsl::tdouble expected_ngray{0.2126*(244.0/255.0) + 0.7152*(100.0/255.0) + 0.0722*(123.0/255.0)};
	std::uint8_t expected_gray  = static_cast<std::uint8_t>(expected_ngray*255.0);

	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::rgb_t>(input),tsl::rgb_t(244,100,123));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::rgba_t>(input),tsl::rgba_t(244,100,123,99));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::gray_t>(input),tsl::gray_t(expected_gray));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::ga_t>(input),tsl::ga_t(expected_gray,99));

	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nrgb_t>(input),tsl::nrgb_t(244.0/255.0,100.0/255.0,123.0/255.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nrgba_t>(input),tsl::nrgba_t(244.0/255.0,100.0/255.0,123.0/255.0,99.0/255.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::ngray_t>(input),tsl::ngray_t(expected_ngray));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nga_t>(input),tsl::nga_t(expected_ngray,99.0/255.0));
}

CYNODELIC_TESTER_SECTION(pixel_cast,from_ngray)
{
	tsl::ngray_t input(150.0/255.0);

	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::rgb_t>(input),tsl::rgb_t(150,150,150));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::rgba_t>(input),tsl::rgba_t(150,150,150,255));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::gray_t>(input),tsl::gray_t(150));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::ga_t>(input),tsl::ga_t(150,255));

	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nrgb_t>(input),tsl::nrgb_t(150.0/255.0,150.0/255.0,150.0/255.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nrgba_t>(input),tsl::nrgba_t(150.0/255.0,150.0/255.0,150.0/255.0,1.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::ngray_t>(input),tsl::ngray_t(150.0/255.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nga_t>(input),tsl::nga_t(150.0/255.0,1.0));
}

CYNODELIC_TESTER_SECTION(pixel_cast,from_nga)
{
	tsl::nga_t input(87.0/255.0,199.0/255.0);

	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::rgb_t>(input),tsl::rgb_t(87,87,87));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::rgba_t>(input),tsl::rgba_t(87,87,87,199));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::gray_t>(input),tsl::gray_t(87));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::ga_t>(input),tsl::ga_t(87,199));

	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nrgb_t>(input),tsl::nrgb_t(87.0/255.0,87.0/255.0,87.0/255.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nrgba_t>(input),tsl::nrgba_t(87.0/255.0,87.0/255.0,87.0/255.0,199.0/255.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::ngray_t>(input),tsl::ngray_t(87.0/255.0));
	CYNODELIC_TESTER_CHECK_EQUALS(tsl::pixel_cast<tsl::nga_t>(input),tsl::nga_t(87.0/255.0,199.0/255.0));
}


#endif // CYNODELIC_TESELA_TEST_CORE_PIXEL_CAST_HPP
