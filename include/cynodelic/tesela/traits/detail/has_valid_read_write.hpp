// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file has_valid_read_write.hpp
 *
 * @brief Defines the `has_valid_read` and `has_valid_write` helper classes.
 */

#ifndef CYNODELIC_TESELA_TRAITS_DETAIL_HAS_VALID_READ_WRITE_HPP
#define CYNODELIC_TESELA_TRAITS_DETAIL_HAS_VALID_READ_WRITE_HPP


#include <type_traits>
#include <utility>

#include <cynodelic/tesela/config.hpp>


namespace cynodelic { namespace tesela {

namespace detail
{
	/**
	 * @brief Helper for `has_valid_read_write`
	 */
	struct dummy_pixel_t
	{
		static constexpr color_space contained_color_space = color_space::rgb;
	};


	/**
	 * @brief Helper for `has_valid_read_write`
	 */
	template <typename T>
	struct has_valid_read
	{
		struct nothing_t {};

		template <typename U>
		static auto check(U*) -> decltype(U::read(std::declval<std::string>(),std::declval<basic_image<dummy_pixel_t>&>()));

		template <typename U>
		static nothing_t check(...);

		static constexpr bool value = std::is_same<decltype(check<T>(nullptr)),void>::value;
	};

	template <typename T>
	constexpr bool has_valid_read<T>::value;


	/**
	 * @brief Helper for `has_valid_read_write`
	 */
	template <typename T>
	struct has_valid_write
	{
		struct nothing_t {};

		template <typename U>
		static auto check(U*) -> decltype(U::write(std::declval<std::string>(),std::declval<basic_image<dummy_pixel_t>>()));

		template <typename>
		static nothing_t check(...);

		static constexpr bool value = std::is_same<decltype(check<T>(nullptr)),void>::value;
	};

	template <typename T>
	constexpr bool has_valid_write<T>::value;
} // end of "detail" namespace

}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_TRAITS_DETAIL_HAS_VALID_READ_WRITE_HPP
