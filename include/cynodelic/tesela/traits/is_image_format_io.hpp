// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file is_image_format_io.hpp
 *
 * @brief Defines the `is_image_format_io` type trait.
 */

#ifndef CYNODELIC_TESELA_TRAITS_IS_IMAGE_FORMAT_IO_HPP
#define CYNODELIC_TESELA_TRAITS_IS_IMAGE_FORMAT_IO_HPP


#include <cstdlib>
#include <type_traits>
#include <utility>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/detail/void_t.hpp>
#include <cynodelic/tesela/traits/detail/has_valid_read_write.hpp>
#include <cynodelic/tesela/image_types.hpp>


namespace cynodelic { namespace tesela {


#ifndef DOXYGEN_SHOULD_SKIP_THIS


/**
 * @brief Helper for `is_image_format_io`
 */
template <typename T,typename = void>
struct is_image_format_io_impl : std::false_type {};


/**
 * @brief Helper for `is_image_format_io`
 */
template <typename Type>
struct is_image_format_io_impl<
	Type,
	detail::void_t<
		decltype(Type::file_extension_regex),
		decltype(Type::regex_syntax)
	>
> : std::integral_constant<
	bool,
	detail::has_valid_read<Type>::value &&
	detail::has_valid_write<Type>::value
>
{};

#endif


/**
 * @ingroup typetraits
 * @brief Checks if a type is a valid image format I/O type
 *
 * Checks if a type `T` is a valid image format I/O type, which can be used in
 * the @ref image_io helper class.
 *
 * If `T` is such a type, its member `value` will be `true`, otherwise, it will
 * be `false`.
 *
 * @param T The type to check. 
 */
template <typename T>
using is_image_format_io = typename is_image_format_io_impl<T>::type;


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_TRAITS_IS_IMAGE_FORMAT_IO_HPP
