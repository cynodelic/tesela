// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file with_alpha_form.hpp
 *
 * @brief Defines the `with_alpha_form` type transformation.
 */

#ifndef CYNODELIC_TESELA_TRAITS_WITH_ALPHA_FORM_HPP
#define CYNODELIC_TESELA_TRAITS_WITH_ALPHA_FORM_HPP


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
 * @brief Helper for `with_alpha_form`
 */
template <typename>
struct with_alpha_form_impl;


/**
 * @brief Helper for `with_alpha_form`
 */
template <>
struct with_alpha_form_impl<rgb_t> : rgba_t
{};


/**
 * @brief Helper for `with_alpha_form`
 */
template <>
struct with_alpha_form_impl<rgba_t> : rgba_t
{};


/**
 * @brief Helper for `with_alpha_form`
 */
template <>
struct with_alpha_form_impl<gray_t> : ga_t
{};


/**
 * @brief Helper for `with_alpha_form`
 */
template <>
struct with_alpha_form_impl<ga_t> : ga_t
{};


/**
 * @brief Helper for `with_alpha_form`
 */
template <>
struct with_alpha_form_impl<nrgb_t> : nrgba_t
{};


/**
 * @brief Helper for `with_alpha_form`
 */
template <>
struct with_alpha_form_impl<nrgba_t> : nrgba_t
{};


/**
 * @brief Helper for `with_alpha_form`
 */
template <>
struct with_alpha_form_impl<ngray_t> : nga_t
{};


/**
 * @brief Helper for `with_alpha_form`
 */
template <>
struct with_alpha_form_impl<nga_t> : nga_t
{};

#endif // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @ingroup typetraits
 * @brief _With-alpha-channel_ form of a pixel type
 *
 * Returns the _version_ of a given pixel type with an `alpha` member variable,
 * corresponding to the alpha channel.
 *
 * @param T The type to transform.
 */
template <typename T>
using with_alpha_form = typename with_alpha_form_impl<T>::type;


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_TRAITS_WITH_ALPHA_FORM_HPP
