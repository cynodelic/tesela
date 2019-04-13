// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file normalized_form_of.hpp
 *
 * @brief Defines the `normalized_form_of` type transformation.
 */

#ifndef CYNODELIC_TESELA_TRAITS_NORMALIZED_FORM_OF_HPP
#define CYNODELIC_TESELA_TRAITS_NORMALIZED_FORM_OF_HPP


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
 * @brief Helper for `normalized_form_of`
 */
template <typename>
struct normalized_form_of_impl;


/**
 * @brief Helper for `normalized_form_of`
 */
template <>
struct normalized_form_of_impl<rgb_t> : nrgb_t
{};


/**
 * @brief Helper for `normalized_form_of`
 */
template <>
struct normalized_form_of_impl<rgba_t> : nrgba_t
{};


/**
 * @brief Helper for `normalized_form_of`
 */
template <>
struct normalized_form_of_impl<gray_t> : ngray_t
{};


/**
 * @brief Helper for `normalized_form_of`
 */
template <>
struct normalized_form_of_impl<ga_t> : nga_t
{};


/**
 * @brief Helper for `normalized_form_of`
 */
template <>
struct normalized_form_of_impl<nrgb_t> : nrgb_t
{};


/**
 * @brief Helper for `normalized_form_of`
 */
template <>
struct normalized_form_of_impl<nrgba_t> : nrgba_t
{};


/**
 * @brief Helper for `normalized_form_of`
 */
template <>
struct normalized_form_of_impl<ngray_t> : ngray_t
{};


/**
 * @brief Helper for `normalized_form_of`
 */
template <>
struct normalized_form_of_impl<nga_t> : nga_t
{};

#endif // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @ingroup typetraits
 * @brief Normalized form of a pixel type
 *
 * Returns the type corresponding to the normalized form of a pixel type, i.e.,
 * with components that take quantized values between 0.0 and 1.0.
 *
 * @param T The type to transform.
 */
template <typename T>
using normalized_form_of = typename normalized_form_of_impl<T>::type;


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_TRAITS_NORMALIZED_FORM_OF_HPP
