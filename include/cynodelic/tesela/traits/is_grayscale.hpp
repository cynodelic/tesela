// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file is_grayscale.hpp
 *
 * @brief Defines the `is_grayscale` type trait.
 */

#ifndef CYNODELIC_TESELA_TRAITS_IS_GRAYSCALE_HPP
#define CYNODELIC_TESELA_TRAITS_IS_GRAYSCALE_HPP


#include <cstdlib>
#include <type_traits>
#include <utility>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/detail/void_t.hpp>


namespace cynodelic { namespace tesela {


#ifndef DOXYGEN_SHOULD_SKIP_THIS

/**
 * @brief Helper for `is_grayscale`
 */
template <typename,typename = void>
struct is_grayscale_impl : std::false_type
{};


/**
 * @brief Helper for `is_grayscale`
 */
template <typename T>
struct is_grayscale_impl<
	T,
	detail::void_t<decltype(std::declval<T>().gray)>
> : std::is_same<typename T::component_type,decltype(std::declval<T>().gray)>
{};

#endif // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @ingroup typetraits
 * @brief Checks if a type is a grayscale pixel type
 *
 * Checks if a type is a grayscale pixel type, i.e., it has a `gray` member
 * variable, corresponding to the gray channel.
 *
 * If this is accomplished, the resulting type will be `std::true_type`,
 * otherwise, it will be `std::false_type`.
 *
 * @param T The type to check.
 */
template <typename T>
using is_grayscale = typename is_grayscale_impl<T>::type;


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_TRAITS_IS_GRAYSCALE_HPP
