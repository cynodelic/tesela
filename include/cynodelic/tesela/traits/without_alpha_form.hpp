// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file without_alpha_form.hpp
 *
 * @brief Defines the `without_alpha_form` type transformation.
 */

#ifndef CYNODELIC_TESELA_TRAITS_WITHOUT_ALPHA_FORM_HPP
#define CYNODELIC_TESELA_TRAITS_WITHOUT_ALPHA_FORM_HPP


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
 * @brief Helper for `without_alpha_form`
 */
template <typename>
struct without_alpha_form_impl;


/**
 * @brief Helper for `without_alpha_form`
 */
template <>
struct without_alpha_form_impl<rgb_t> : rgb_t
{};


/**
 * @brief Helper for `without_alpha_form`
 */
template <>
struct without_alpha_form_impl<rgba_t> : rgb_t
{};


/**
 * @brief Helper for `without_alpha_form`
 */
template <>
struct without_alpha_form_impl<gray_t> : gray_t
{};


/**
 * @brief Helper for `without_alpha_form`
 */
template <>
struct without_alpha_form_impl<ga_t> : gray_t
{};


/**
 * @brief Helper for `without_alpha_form`
 */
template <>
struct without_alpha_form_impl<nrgb_t> : nrgb_t
{};


/**
 * @brief Helper for `without_alpha_form`
 */
template <>
struct without_alpha_form_impl<nrgba_t> : nrgb_t
{};


/**
 * @brief Helper for `without_alpha_form`
 */
template <>
struct without_alpha_form_impl<ngray_t> : ngray_t
{};


/**
 * @brief Helper for `without_alpha_form`
 */
template <>
struct without_alpha_form_impl<nga_t> : ngray_t
{};

#endif // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @ingroup typetraits
 * @brief Non-alpha form of a pixel type
 *
 * Returns a non-alpha _version_ of a pixel type, i.e., without the `alpha`
 * member variable and component.
 *
 * @param T The type to transform.
 */
template <typename T>
using without_alpha_form = typename without_alpha_form_impl<T>::type;


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_TRAITS_WITHOUT_ALPHA_FORM_HPP
