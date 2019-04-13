// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file literals_helpers.hpp
 *
 * @brief Helpers for literals.
 */

#ifndef CYNODELIC_TESELA_DETAIL_LITERALS_HELPERS_HPP
#define CYNODELIC_TESELA_DETAIL_LITERALS_HELPERS_HPP


#include <type_traits>

#include <cynodelic/tesela/config.hpp>


namespace cynodelic { namespace tesela {


namespace detail
{
	/**
	 * @brief Checks if a character represents a valid hexadecimal value
	 */
	inline constexpr bool check_valid_hex_chars(const char& chr)
	{
		return (
			(chr >= '0' && chr <= '9') ||
			(chr >= 'A' && chr <= 'F') ||
			(chr >= 'a' && chr <= 'f')
		);
	}

	/**
	 * @brief Checks if a character represents a valid hexadecimal value
	 */
	template <typename... Others>
	inline constexpr bool check_valid_hex_chars(const char& chr,Others... others)
	{
		return (
			(chr >= '0' && chr <= '9') ||
			(chr >= 'A' && chr <= 'F') ||
			(chr >= 'a' && chr <= 'f')
		) && check_valid_hex_chars(others...);
	}


	/**
	 * @brief Checks if a hexadecimal literal is valid.
	 */
	template <char... Chars>
	struct is_valid_hexadecimal_literal : std::false_type
	{};

	/**
	 * @brief Checks if a hexadecimal literal is valid.
	 */
	template <char... Others>
	struct is_valid_hexadecimal_literal<'0','x',Others...> : std::integral_constant<bool,check_valid_hex_chars(Others...)>
	{};


	template <char,typename = void>
	struct char_to_hex_value {};

	template <char Chr>
	struct char_to_hex_value<Chr,std::enable_if_t<(Chr >= '0') && (Chr <= '9')>>
	{
		static inline constexpr std::uint8_t call()
		{
			return static_cast<std::uint8_t>(Chr - '0');
		}
	};

	template <char Chr>
	struct char_to_hex_value<Chr,std::enable_if_t<(Chr >= 'a') && (Chr <= 'f')>>
	{
		static inline constexpr std::uint8_t call()
		{
			return static_cast<std::uint8_t>(Chr - 'a' + static_cast<char>(10));
		}
	};

	template <char Chr>
	struct char_to_hex_value<Chr,std::enable_if_t<(Chr >= 'A') && (Chr <= 'F')>>
	{
		static inline constexpr std::uint8_t call()
		{
			return static_cast<std::uint8_t>(Chr - 'A' + static_cast<char>(10));
		}
	};


	/**
	 * @brief Helper for the literals for `(n)rgb_t`
	 */
	template <char,char,char,char,char,char,char,char>
	struct parse_rgb;

	/**
	 * @brief Helper for the literals for `(n)rgb_t`
	 */
	template <char Red1,char Red0,char Green1,char Green0,char Blue1,char Blue0>
	struct parse_rgb<'0','x',Red1,Red0,Green1,Green0,Blue1,Blue0>
	{
		static constexpr std::uint8_t red   = (char_to_hex_value<Red1>::call() << 4) | char_to_hex_value<Red0>::call();
		static constexpr std::uint8_t green = (char_to_hex_value<Green1>::call() << 4) | char_to_hex_value<Green0>::call();
		static constexpr std::uint8_t blue  = (char_to_hex_value<Blue1>::call() << 4) | char_to_hex_value<Blue0>::call();
	};

	template <char Red1,char Red0,char Green1,char Green0,char Blue1,char Blue0>
	constexpr std::uint8_t parse_rgb<'0','x',Red1,Red0,Green1,Green0,Blue1,Blue0>::red;

	template <char Red1,char Red0,char Green1,char Green0,char Blue1,char Blue0>
	constexpr std::uint8_t parse_rgb<'0','x',Red1,Red0,Green1,Green0,Blue1,Blue0>::green;

	template <char Red1,char Red0,char Green1,char Green0,char Blue1,char Blue0>
	constexpr std::uint8_t parse_rgb<'0','x',Red1,Red0,Green1,Green0,Blue1,Blue0>::blue;


	/**
	 * @brief Helper for the literals for `(n)rgba_t`
	 */
	template <char,char,char,char,char,char,char,char,char,char>
	struct parse_rgba;

	/**
	 * @brief Helper for the literals for `(n)rgba_t`
	 */
	template <char Red1,char Red0,char Green1,char Green0,char Blue1,char Blue0,char Alpha1,char Alpha0>
	struct parse_rgba<'0','x',Red1,Red0,Green1,Green0,Blue1,Blue0,Alpha1,Alpha0>
	{
		static constexpr std::uint8_t red   = (char_to_hex_value<Red1>::call() << 4) | char_to_hex_value<Red0>::call();
		static constexpr std::uint8_t green = (char_to_hex_value<Green1>::call() << 4) | char_to_hex_value<Green0>::call();
		static constexpr std::uint8_t blue  = (char_to_hex_value<Blue1>::call() << 4) | char_to_hex_value<Blue0>::call();
		static constexpr std::uint8_t alpha = (char_to_hex_value<Alpha1>::call() << 4) | char_to_hex_value<Alpha0>::call();
	};

	template <char Red1,char Red0,char Green1,char Green0,char Blue1,char Blue0,char Alpha1,char Alpha0>
	constexpr std::uint8_t parse_rgba<'0','x',Red1,Red0,Green1,Green0,Blue1,Blue0,Alpha1,Alpha0>::red;

	template <char Red1,char Red0,char Green1,char Green0,char Blue1,char Blue0,char Alpha1,char Alpha0>
	constexpr std::uint8_t parse_rgba<'0','x',Red1,Red0,Green1,Green0,Blue1,Blue0,Alpha1,Alpha0>::green;

	template <char Red1,char Red0,char Green1,char Green0,char Blue1,char Blue0,char Alpha1,char Alpha0>
	constexpr std::uint8_t parse_rgba<'0','x',Red1,Red0,Green1,Green0,Blue1,Blue0,Alpha1,Alpha0>::blue;

	template <char Red1,char Red0,char Green1,char Green0,char Blue1,char Blue0,char Alpha1,char Alpha0>
	constexpr std::uint8_t parse_rgba<'0','x',Red1,Red0,Green1,Green0,Blue1,Blue0,Alpha1,Alpha0>::alpha;


	/**
	 * @brief Helper for the literals for `(n)gray_t`
	 */
	template <char,char,char,char>
	struct parse_gray;

	/**
	 * @brief Helper for the literals for `(n)gray_t`
	 */
	template <char Gray1,char Gray0>
	struct parse_gray<'0','x',Gray1,Gray0>
	{
		static constexpr std::uint8_t gray = (char_to_hex_value<Gray1>::call() << 4) | char_to_hex_value<Gray0>::call();
	};

	template <char Gray1,char Gray0>
	constexpr std::uint8_t parse_gray<'0','x',Gray1,Gray0>::gray;


	/**
	 * @brief Helper for the literals for `(n)ga_t`
	 */
	template <char,char,char,char,char,char>
	struct parse_ga;

	/**
	 * @brief Helper for the literals for `(n)ga_t`
	 */
	template <char Gray1,char Gray0,char Alpha1,char Alpha0>
	struct parse_ga<'0','x',Gray1,Gray0,Alpha1,Alpha0>
	{
		static constexpr std::uint8_t gray  = (char_to_hex_value<Gray1>::call() << 4) | char_to_hex_value<Gray0>::call();
		static constexpr std::uint8_t alpha = (char_to_hex_value<Alpha1>::call() << 4) | char_to_hex_value<Alpha0>::call();
	};

	template <char Gray1,char Gray0,char Alpha1,char Alpha0>
	constexpr std::uint8_t parse_ga<'0','x',Gray1,Gray0,Alpha1,Alpha0>::gray;

	template <char Gray1,char Gray0,char Alpha1,char Alpha0>
	constexpr std::uint8_t parse_ga<'0','x',Gray1,Gray0,Alpha1,Alpha0>::alpha;
} // end of "detail" namespace

}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_DETAIL_LITERALS_HELPERS_HPP
