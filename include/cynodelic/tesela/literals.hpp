// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file literals.hpp
 *
 * @brief Defines literals for some types.
 */

#ifndef CYNODELIC_TESELA_LITERALS_HPP
#define CYNODELIC_TESELA_LITERALS_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/rgb_types.hpp>
#include <cynodelic/tesela/rgba_types.hpp>
#include <cynodelic/tesela/gray_types.hpp>
#include <cynodelic/tesela/ga_types.hpp>
#include <cynodelic/tesela/tdouble.hpp>
#include <cynodelic/tesela/detail/literals_helpers.hpp>


namespace cynodelic { namespace tesela {


/**
 * @ingroup literals
 * @brief Namespace for literals
 */
namespace literals
{
	/**
	 * @ingroup literals
	 * @brief Literal for `tdouble`
	 *
	 * Creates an instance of @ref tdouble from a floating-point value.
	 */
	constexpr tdouble operator""_td(long double x)
	{
		return tdouble(x);
	}


	/**
	 * @ingroup literals
	 * @brief Literal for `rgb_t`
	 *
	 * Creates an instance of @ref rgb_t using hexadecimal notation, from `0x000000`
	 * to `0xffffff`.
	 *
	 * The values are represented, in hexadecimal, as `0xRRGGBB`, being `R`, `G` and
	 * `B` the values for the red, green and blue channels, respectively.
	 */
	template <char... Chars>
	constexpr rgb_t operator""_hrgb()
	{
		static_assert(
			detail::is_valid_hexadecimal_literal<Chars...>::value,
			"[cynodelic::tesela_literals::operator\"\"_hrgb()] A hexadecimal value must be used."
		);

		static_assert(
			sizeof...(Chars) == 8,
			"[cynodelic::tesela_literals::operator\"\"_hrgb()] The value must be represented as 0xRRGGBB."
		);

		return rgb_t(
			detail::parse_rgb<Chars...>::red,
			detail::parse_rgb<Chars...>::green,
			detail::parse_rgb<Chars...>::blue
		);
	}


	/**
	 * @ingroup literals
	 * @brief Literal for `nrgb_t`
	 *
	 * Creates an instance of @ref nrgb_t using hexadecimal notation, from `0x000000`
	 * to `0xffffff`.
	 *
	 * The values are represented, in hexadecimal, as `0xRRGGBB`, being `R`, `G` and
	 * `B` the values for the red, green and blue channels, respectively.
	 */
	template <char... Chars>
	constexpr nrgb_t operator""_hnrgb()
	{
		static_assert(
			detail::is_valid_hexadecimal_literal<Chars...>::value,
			"[cynodelic::tesela_literals::operator\"\"_hnrgb()] A hexadecimal value must be used."
		);

		static_assert(
			sizeof...(Chars) == 8,
			"[cynodelic::tesela_literals::operator\"\"_hnrgb()] The value must be represented as 0xRRGGBB."
		);

		return nrgb_t(
			detail::u8_to_dbl(detail::parse_rgb<Chars...>::red),
			detail::u8_to_dbl(detail::parse_rgb<Chars...>::green),
			detail::u8_to_dbl(detail::parse_rgb<Chars...>::blue)
		);
	}


	/**
	 * @ingroup literals
	 * @brief Literal for `rgba_t`
	 *
	 * Creates an instance of @ref rgba_t using hexadecimal notation, from `0x00000000`
	 * to `0xffffffff`.
	 *
	 * The values are represented, in hexadecimal, as `0xRRGGBBAA`, being `R`, `G`,
	 * `B` and `A` the values for the red, green and blue channels, respectively.
	 */
	template <char... Chars>
	constexpr rgba_t operator""_hrgba()
	{
		static_assert(
			detail::is_valid_hexadecimal_literal<Chars...>::value,
			"[cynodelic::tesela_literals::operator\"\"_hrgba()] A hexadecimal value must be used."
		);

		static_assert(
			sizeof...(Chars) == 10,
			"[cynodelic::tesela_literals::operator\"\"_hrgba()] The value must be represented as 0xRRGGBBAA."
		);

		return rgba_t(
			detail::parse_rgba<Chars...>::red,
			detail::parse_rgba<Chars...>::green,
			detail::parse_rgba<Chars...>::blue,
			detail::parse_rgba<Chars...>::alpha
		);
	}


	/**
	 * @ingroup literals
	 * @brief Literal for `nrgba_t`
	 *
	 * Creates an instance of @ref nrgba_t using hexadecimal notation, from `0x00000000`
	 * to `0xffffffff`.
	 *
	 * The values are represented, in hexadecimal, as `0xRRGGBBAA`, being `R`, `G`,
	 * `B` and `A` the values for the red, green and blue channels, respectively.
	 */
	template <char... Chars>
	constexpr nrgba_t operator""_hnrgba()
	{
		static_assert(
			detail::is_valid_hexadecimal_literal<Chars...>::value,
			"[cynodelic::tesela_literals::operator\"\"_hnrgba()] A hexadecimal value must be used."
		);

		static_assert(
			sizeof...(Chars) == 10,
			"[cynodelic::tesela_literals::operator\"\"_hnrgba()] The value must be represented as 0xRRGGBBAA."
		);

		return nrgba_t(
			detail::u8_to_dbl(detail::parse_rgba<Chars...>::red),
			detail::u8_to_dbl(detail::parse_rgba<Chars...>::green),
			detail::u8_to_dbl(detail::parse_rgba<Chars...>::blue),
			detail::u8_to_dbl(detail::parse_rgba<Chars...>::alpha)
		);
	}


	/**
	 * @ingroup literals
	 * @brief Literal for `gray_t`
	 *
	 * Creates an instance of @ref gray_t using hexadecimal notation, from `0x00` to
	 * `0xff`.
	 */
	template <char... Chars>
	constexpr gray_t operator""_hgray()
	{
		static_assert(
			detail::is_valid_hexadecimal_literal<Chars...>::value,
			"[cynodelic::tesela_literals::operator\"\"_hgray()] A hexadecimal value must be used."
		);

		static_assert(
			sizeof...(Chars) == 4,
			"[cynodelic::tesela_literals::operator\"\"_hgray()] The value must be represented as 0xYY."
		);

		return gray_t(detail::parse_gray<Chars...>::gray);
	}


	/**
	 * @ingroup literals
	 * @brief Literal for `ngray_t`
	 *
	 * Creates an instance of @ref ngray_t using hexadecimal notation, from `0x00` to
	 * `0xff`.
	 */
	template <char... Chars>
	constexpr ngray_t operator""_hngray()
	{
		static_assert(
			detail::is_valid_hexadecimal_literal<Chars...>::value,
			"[cynodelic::tesela_literals::operator\"\"_hngray()] A hexadecimal value must be used."
		);

		static_assert(
			sizeof...(Chars) == 4,
			"[cynodelic::tesela_literals::operator\"\"_hngray()] The value must be represented as 0xYY."
		);

		return ngray_t(detail::u8_to_dbl(detail::parse_gray<Chars...>::gray));
	}


	/**
	 * @ingroup literals
	 * @brief Literal for `ga_t`
	 *
	 * Creates an instance of @ref ga_t using hexadecimal notation, from `0x0000` to
	 * `0xffff`.
	 *
	 * The values are represented, in hexadecimal, as `0xYYAA`, being `Y` and `A`
	 * the values for the gray and alpha channels, respectively.
	 */
	template <char... Chars>
	constexpr ga_t operator""_hga()
	{
		static_assert(
			detail::is_valid_hexadecimal_literal<Chars...>::value,
			"[cynodelic::tesela_literals::operator\"\"_hga()] A hexadecimal value must be used."
		);

		static_assert(
			sizeof...(Chars) == 6,
			"[cynodelic::tesela_literals::operator\"\"_hga()] The value must be represented as 0xYYAA."
		);

		return ga_t(
			detail::parse_ga<Chars...>::gray,
			detail::parse_ga<Chars...>::alpha
		);
	}


	/**
	 * @ingroup literals
	 * @brief Literal for `nga_t`
	 *
	 * Creates an instance of @ref nga_t using hexadecimal notation, from `0x0000` to
	 * `0xffff`.
	 *
	 * The values are represented, in hexadecimal, as `0xYYAA`, being `Y` and `A`
	 * the values for the gray and alpha channels, respectively.
	 */
	template <char... Chars>
	constexpr nga_t operator""_hnga()
	{
		static_assert(
			detail::is_valid_hexadecimal_literal<Chars...>::value,
			"[cynodelic::tesela_literals::operator\"\"_hnga()] A hexadecimal value must be used."
		);

		static_assert(
			sizeof...(Chars) == 6,
			"[cynodelic::tesela_literals::operator\"\"_hnga()] The value must be represented as 0xYYAA."
		);

		return nga_t(
			detail::u8_to_dbl(detail::parse_ga<Chars...>::gray),
			detail::u8_to_dbl(detail::parse_ga<Chars...>::alpha)
		);
	}
} // end of "literals" namespace

}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_LITERALS_HPP
