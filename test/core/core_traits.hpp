// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_CORE_TRAITS_HPP
#define CYNODELIC_TESELA_TEST_CORE_CORE_TRAITS_HPP


CYNODELIC_TESTER_TEST_CASE(core_traits);

CYNODELIC_TESTER_SECTION(core_traits,is_pixel_type)
{
	CYNODELIC_TESTER_ASSERT_TRUE((tsl::is_pixel_type<tsl::rgb_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((tsl::is_pixel_type<tsl::rgba_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((tsl::is_pixel_type<tsl::gray_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((tsl::is_pixel_type<tsl::ga_t>::value));

	CYNODELIC_TESTER_ASSERT_TRUE((tsl::is_pixel_type<tsl::nrgb_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((tsl::is_pixel_type<tsl::nrgba_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((tsl::is_pixel_type<tsl::ngray_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((tsl::is_pixel_type<tsl::nga_t>::value));

	CYNODELIC_TESTER_ASSERT_FALSE((tsl::is_pixel_type<tsl::rectangle>::value));
	CYNODELIC_TESTER_ASSERT_FALSE((tsl::is_pixel_type<float>::value));
}

CYNODELIC_TESTER_SECTION(core_traits,has_alpha)
{
	CYNODELIC_TESTER_ASSERT_FALSE((tsl::has_alpha<tsl::rgb_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((tsl::has_alpha<tsl::rgba_t>::value));
	CYNODELIC_TESTER_ASSERT_FALSE((tsl::has_alpha<tsl::gray_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((tsl::has_alpha<tsl::ga_t>::value));

	CYNODELIC_TESTER_ASSERT_FALSE((tsl::has_alpha<tsl::nrgb_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((tsl::has_alpha<tsl::nrgba_t>::value));
	CYNODELIC_TESTER_ASSERT_FALSE((tsl::has_alpha<tsl::ngray_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((tsl::has_alpha<tsl::nga_t>::value));
}

CYNODELIC_TESTER_SECTION(core_traits,is_grayscale)
{
	CYNODELIC_TESTER_ASSERT_FALSE((tsl::is_grayscale<tsl::rgb_t>::value));
	CYNODELIC_TESTER_ASSERT_FALSE((tsl::is_grayscale<tsl::rgba_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((tsl::is_grayscale<tsl::gray_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((tsl::is_grayscale<tsl::ga_t>::value));

	CYNODELIC_TESTER_ASSERT_FALSE((tsl::is_grayscale<tsl::nrgb_t>::value));
	CYNODELIC_TESTER_ASSERT_FALSE((tsl::is_grayscale<tsl::nrgba_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((tsl::is_grayscale<tsl::ngray_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((tsl::is_grayscale<tsl::nga_t>::value));
}

CYNODELIC_TESTER_SECTION(core_traits,has_rgb_components)
{
	CYNODELIC_TESTER_ASSERT_TRUE((tsl::has_rgb_components<tsl::rgb_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((tsl::has_rgb_components<tsl::rgba_t>::value));
	CYNODELIC_TESTER_ASSERT_FALSE((tsl::has_rgb_components<tsl::gray_t>::value));
	CYNODELIC_TESTER_ASSERT_FALSE((tsl::has_rgb_components<tsl::ga_t>::value));

	CYNODELIC_TESTER_ASSERT_TRUE((tsl::has_rgb_components<tsl::nrgb_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((tsl::has_rgb_components<tsl::nrgba_t>::value));
	CYNODELIC_TESTER_ASSERT_FALSE((tsl::has_rgb_components<tsl::ngray_t>::value));
	CYNODELIC_TESTER_ASSERT_FALSE((tsl::has_rgb_components<tsl::nga_t>::value));
}


CYNODELIC_TESTER_TEST_CASE(type_transformations);

CYNODELIC_TESTER_SECTION(type_transformations,integral_form_of)
{
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::integral_form_of<tsl::rgb_t>,tsl::rgb_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::integral_form_of<tsl::rgba_t>,tsl::rgba_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::integral_form_of<tsl::gray_t>,tsl::gray_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::integral_form_of<tsl::ga_t>,tsl::ga_t>::value));

	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::integral_form_of<tsl::nrgb_t>,tsl::rgb_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::integral_form_of<tsl::nrgba_t>,tsl::rgba_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::integral_form_of<tsl::ngray_t>,tsl::gray_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::integral_form_of<tsl::nga_t>,tsl::ga_t>::value));
}

CYNODELIC_TESTER_SECTION(type_transformations,normalized_form_of)
{
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::normalized_form_of<tsl::rgb_t>,tsl::nrgb_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::normalized_form_of<tsl::rgba_t>,tsl::nrgba_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::normalized_form_of<tsl::gray_t>,tsl::ngray_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::normalized_form_of<tsl::ga_t>,tsl::nga_t>::value));

	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::normalized_form_of<tsl::nrgb_t>,tsl::nrgb_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::normalized_form_of<tsl::nrgba_t>,tsl::nrgba_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::normalized_form_of<tsl::ngray_t>,tsl::ngray_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::normalized_form_of<tsl::nga_t>,tsl::nga_t>::value));
}

CYNODELIC_TESTER_SECTION(type_transformations,with_alpha_form)
{
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::with_alpha_form<tsl::rgb_t>,tsl::rgba_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::with_alpha_form<tsl::rgba_t>,tsl::rgba_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::with_alpha_form<tsl::gray_t>,tsl::ga_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::with_alpha_form<tsl::ga_t>,tsl::ga_t>::value));

	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::with_alpha_form<tsl::nrgb_t>,tsl::nrgba_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::with_alpha_form<tsl::nrgba_t>,tsl::nrgba_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::with_alpha_form<tsl::ngray_t>,tsl::nga_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::with_alpha_form<tsl::nga_t>,tsl::nga_t>::value));
}

CYNODELIC_TESTER_SECTION(type_transformations,without_alpha_form)
{
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::without_alpha_form<tsl::rgb_t>,tsl::rgb_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::without_alpha_form<tsl::rgba_t>,tsl::rgb_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::without_alpha_form<tsl::gray_t>,tsl::gray_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::without_alpha_form<tsl::ga_t>,tsl::gray_t>::value));

	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::without_alpha_form<tsl::nrgb_t>,tsl::nrgb_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::without_alpha_form<tsl::nrgba_t>,tsl::nrgb_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::without_alpha_form<tsl::ngray_t>,tsl::ngray_t>::value));
	CYNODELIC_TESTER_ASSERT_TRUE((std::is_same<tsl::without_alpha_form<tsl::nga_t>,tsl::ngray_t>::value));
}


#endif // CYNODELIC_TESELA_TEST_CORE_CORE_TRAITS_HPP
