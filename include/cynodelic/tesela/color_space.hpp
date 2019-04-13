// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file color_space.hpp
 *
 * @brief Defines the `color_space` ennumerator.
 */

#ifndef CYNODELIC_TESELA_COLOR_SPACE_HPP
#define CYNODELIC_TESELA_COLOR_SPACE_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <cynodelic/tesela/config.hpp>


namespace cynodelic { namespace tesela {


/**
 * @ingroup types
 * @brief Color space
 *
 * Determines in which color space was the image file read and, also, in which
 * color space will the image file be written.
 *
 * Used as a parameter in @ref basic_image.
 */
enum class color_space : std::uint8_t
{
	gray, /**< Grayscale. */
	ga,   /**< Grayscale and alpha. */
	rgb,  /**< RGB (red, green and blue). */
	rgba  /**< RGBA (red, green, blue and alpha). */
};


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_COLOR_SPACE_HPP
