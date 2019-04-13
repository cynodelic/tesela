// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file has_rgb_components.hpp
 *
 * @brief Defines the `has_rgb_components` type trait.
 */

#ifndef CYNODELIC_TESELA_TRAITS_HAS_RGB_COMPONENTS_HPP
#define CYNODELIC_TESELA_TRAITS_HAS_RGB_COMPONENTS_HPP


#include <cstdlib>
#include <type_traits>
#include <utility>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/detail/void_t.hpp>


namespace cynodelic { namespace tesela {


#ifndef DOXYGEN_SHOULD_SKIP_THIS

/**
 * @brief Helper for `has_rgb_components`
 */
template <typename,typename = void>
struct has_rgb_components_impl : std::false_type
{};


/**
 * @brief Helper for `has_rgb_components`
 */
template <typename T>
struct has_rgb_components_impl<
	T,
	detail::void_t<
		decltype(std::declval<T>().red),
		decltype(std::declval<T>().green),
		decltype(std::declval<T>().blue)
	>
> : std::integral_constant<
	bool,
	std::is_same<typename T::component_type,decltype(std::declval<T>().red)>::value &&
	std::is_same<typename T::component_type,decltype(std::declval<T>().green)>::value &&
	std::is_same<typename T::component_type,decltype(std::declval<T>().blue)>::value
>
{};

#endif // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @ingroup typetraits
 * @brief Checks if a pixel type has RGB components
 *
 * Checks if a pixel type has the `red`, `green` and `blue` member variables
 * corresponding to the respective channels.
 *
 * If this is accomplished, the resulting type will be `std::true_type`,
 * otherwise, it will be `std::false_type`.
 *
 * @param T The type to check.
 */
template <typename T>
using has_rgb_components = typename has_rgb_components_impl<T>::type;


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_TRAITS_HAS_RGB_COMPONENTS_HPP
