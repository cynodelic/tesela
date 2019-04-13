// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file tesela_all.hpp
 *
 * @brief All headers.
 */

#ifndef CYNODELIC_TESELA_TESELA_ALL_HPP
#define CYNODELIC_TESELA_TESELA_ALL_HPP


#include <cynodelic/tesela/config.hpp>

// Types
#include <cynodelic/tesela/tdouble.hpp>
#include <cynodelic/tesela/rgb_types.hpp>
#include <cynodelic/tesela/rgba_types.hpp>
#include <cynodelic/tesela/gray_types.hpp>
#include <cynodelic/tesela/ga_types.hpp>
#include <cynodelic/tesela/point.hpp>
#include <cynodelic/tesela/rectangle.hpp>
#include <cynodelic/tesela/image_types.hpp>

// Type operations
#include <cynodelic/tesela/literals.hpp>
#include <cynodelic/tesela/type_casts.hpp>

// Image I/O
#include <cynodelic/tesela/image_io.hpp>

// Image formats
#include <cynodelic/tesela/formats/jpeg_io.hpp>
#include <cynodelic/tesela/formats/png_io.hpp>
#include <cynodelic/tesela/formats/tiff_io.hpp>

// Utilities
#include <cynodelic/tesela/utilities/convert/convert_to_grayscale.hpp>
#include <cynodelic/tesela/utilities/convert/remove_alpha.hpp>

#include <cynodelic/tesela/utilities/filters/brightness.hpp>
#include <cynodelic/tesela/utilities/filters/contrast.hpp>
#include <cynodelic/tesela/utilities/filters/duotone.hpp>
#include <cynodelic/tesela/utilities/filters/gamma.hpp>
#include <cynodelic/tesela/utilities/filters/gaussian_blur.hpp>
#include <cynodelic/tesela/utilities/filters/invert.hpp>
#include <cynodelic/tesela/utilities/filters/monochrome.hpp>
#include <cynodelic/tesela/utilities/filters/scatter.hpp>

#include <cynodelic/tesela/utilities/transformations/crop.hpp>
#include <cynodelic/tesela/utilities/transformations/flip.hpp>
#include <cynodelic/tesela/utilities/transformations/scale.hpp>

// Type traits
#include <cynodelic/tesela/traits/has_alpha.hpp>
#include <cynodelic/tesela/traits/has_rgb_components.hpp>
#include <cynodelic/tesela/traits/integral_form_of.hpp>
#include <cynodelic/tesela/traits/is_grayscale.hpp>
#include <cynodelic/tesela/traits/is_image_format_io.hpp>
#include <cynodelic/tesela/traits/is_normalized.hpp>
#include <cynodelic/tesela/traits/is_pixel_type.hpp>
#include <cynodelic/tesela/traits/normalized_form_of.hpp>
#include <cynodelic/tesela/traits/without_alpha_form.hpp>
#include <cynodelic/tesela/traits/with_alpha_form.hpp>


#endif // CYNODELIC_TESELA_TESELA_ALL_HPP

