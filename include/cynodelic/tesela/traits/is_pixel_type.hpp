// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file is_pixel_type.hpp
 *
 * @brief Defines the `is_pixel_type` type trait.
 */

#ifndef CYNODELIC_TESELA_TRAITS_IS_PIXEL_TYPE_HPP
#define CYNODELIC_TESELA_TRAITS_IS_PIXEL_TYPE_HPP


#include <cstdlib>
#include <type_traits>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/rgb_types.hpp>
#include <cynodelic/tesela/rgba_types.hpp>
#include <cynodelic/tesela/gray_types.hpp>
#include <cynodelic/tesela/ga_types.hpp>


namespace cynodelic { namespace tesela {


#ifndef DOXYGEN_SHOULD_SKIP_THIS

/**
 * @brief Helper for `is_pixel_type`
 */
template <typename T>
struct is_pixel_type_impl : std::false_type
{};

/**
 * @brief Helper for `is_pixel_type`
 */
template <>
struct is_pixel_type_impl<rgb_t> : std::true_type
{};


/**
 * @brief Helper for `is_pixel_type`
 */
template <>
struct is_pixel_type_impl<rgba_t> : std::true_type
{};


/**
 * @brief Helper for `is_pixel_type`
 */
template <>
struct is_pixel_type_impl<gray_t> : std::true_type
{};


/**
 * @brief Helper for `is_pixel_type`
 */
template <>
struct is_pixel_type_impl<ga_t> : std::true_type
{};

/**
 * @brief Helper for `is_pixel_type`
 */
template <>
struct is_pixel_type_impl<nrgb_t> : std::true_type
{};


/**
 * @brief Helper for `is_pixel_type`
 */
template <>
struct is_pixel_type_impl<nrgba_t> : std::true_type
{};


/**
 * @brief Helper for `is_pixel_type`
 */
template <>
struct is_pixel_type_impl<ngray_t> : std::true_type
{};


/**
 * @brief Helper for `is_pixel_type`
 */
template <>
struct is_pixel_type_impl<nga_t> : std::true_type
{};

#endif


/**
 * @ingroup typetraits
 * @brief Checks if a type is a valid pixel type
 *
 * Checks if a type `T` is a valid pixel type.
 *
 * If this is accomplished, the resulting type will be `std::true_type`,
 * otherwise, it will be `std::false_type`.
 *
 * @param T The type to check.
 */
template <typename T>
using is_pixel_type = typename is_pixel_type_impl<T>::type;


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_TRAITS_IS_PIXEL_TYPE_HPP
