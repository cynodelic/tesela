// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file has_alpha.hpp
 *
 * @brief Defines the `has_alpha` type trait.
 */

#ifndef CYNODELIC_TESELA_TRAITS_HAS_ALPHA_HPP
#define CYNODELIC_TESELA_TRAITS_HAS_ALPHA_HPP


#include <cstdlib>
#include <type_traits>
#include <utility>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/detail/void_t.hpp>


namespace cynodelic { namespace tesela {


#ifndef DOXYGEN_SHOULD_SKIP_THIS

/**
 * @brief Helper for `has_alpha`
 */
template <typename,typename = void>
struct has_alpha_impl : std::false_type
{};


/**
 * @brief Helper for `has_alpha`
 */
template <typename T>
struct has_alpha_impl<
	T,
	detail::void_t<decltype(std::declval<T>().alpha)>
> : std::is_same<typename T::component_type,decltype(std::declval<T>().alpha)>
{};

#endif // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @ingroup typetraits
 * @brief Checks if a pixel type has an alpha channel
 *
 * Checks if a pixel type has an `alpha` member variable, corresponding to the
 * alpha channel.
 *
 * If this is accomplished, the resulting type will be `std::true_type`,
 * otherwise, it will be `std::false_type`.
 *
 * @param T The type to check.
 */
template <typename T>
using has_alpha = typename has_alpha_impl<T>::type;


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_TRAITS_HAS_ALPHA_HPP
