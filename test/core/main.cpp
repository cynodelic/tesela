// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <limits>
#include <iterator>
#include <string>
#include <sstream>

#include "../tester.hpp"

#include <cynodelic/tesela/tdouble.hpp>
#include <cynodelic/tesela/point.hpp>
#include <cynodelic/tesela/rectangle.hpp>
#include <cynodelic/tesela/rgb_types.hpp>
#include <cynodelic/tesela/rgba_types.hpp>
#include <cynodelic/tesela/gray_types.hpp>
#include <cynodelic/tesela/ga_types.hpp>
#include <cynodelic/tesela/image_types.hpp>
#include <cynodelic/tesela/literals.hpp>
#include <cynodelic/tesela/traits/has_alpha.hpp>
#include <cynodelic/tesela/traits/has_rgb_components.hpp>
#include <cynodelic/tesela/traits/integral_form_of.hpp>
#include <cynodelic/tesela/traits/is_grayscale.hpp>
#include <cynodelic/tesela/traits/is_pixel_type.hpp>
#include <cynodelic/tesela/traits/normalized_form_of.hpp>
#include <cynodelic/tesela/traits/without_alpha_form.hpp>
#include <cynodelic/tesela/traits/with_alpha_form.hpp>
#include <cynodelic/tesela/type_casts.hpp>


namespace tst = cynodelic::tester;
namespace tsl = cynodelic::tesela;

using namespace tsl::literals;


#include "tdouble_initialization.hpp"
#include "tdouble_copy.hpp"
#include "tdouble_swap.hpp"
#include "tdouble_unary_operators.hpp"
#include "tdouble_arithmetic.hpp"
#include "tdouble_comparisons.hpp"
#include "tdouble_stream.hpp"

#include "rgb_t_initialization.hpp"
#include "rgb_t_copy.hpp"
#include "rgb_t_swap.hpp"
#include "rgb_t_comparisons.hpp"
#include "rgb_t_stream.hpp"

#include "rgba_t_initialization.hpp"
#include "rgba_t_copy.hpp"
#include "rgba_t_swap.hpp"
#include "rgba_t_comparisons.hpp"
#include "rgba_t_stream.hpp"

#include "gray_t_initialization.hpp"
#include "gray_t_copy.hpp"
#include "gray_t_swap.hpp"
#include "gray_t_comparisons.hpp"
#include "gray_t_stream.hpp"

#include "ga_t_initialization.hpp"
#include "ga_t_copy.hpp"
#include "ga_t_swap.hpp"
#include "ga_t_comparisons.hpp"
#include "ga_t_stream.hpp"

#include "nrgb_t_initialization.hpp"
#include "nrgb_t_copy.hpp"
#include "nrgb_t_swap.hpp"
#include "nrgb_t_comparisons.hpp"
#include "nrgb_t_stream.hpp"

#include "nrgba_t_initialization.hpp"
#include "nrgba_t_copy.hpp"
#include "nrgba_t_swap.hpp"
#include "nrgba_t_comparisons.hpp"
#include "nrgba_t_stream.hpp"

#include "ngray_t_initialization.hpp"
#include "ngray_t_copy.hpp"
#include "ngray_t_swap.hpp"
#include "ngray_t_comparisons.hpp"
#include "ngray_t_stream.hpp"

#include "nga_t_initialization.hpp"
#include "nga_t_copy.hpp"
#include "nga_t_swap.hpp"
#include "nga_t_comparisons.hpp"
#include "nga_t_stream.hpp"

#include "point_initialization.hpp"
#include "point_copy.hpp"
#include "point_swap.hpp"
#include "point_comparisons.hpp"
#include "point_stream.hpp"

#include "rectangle_initialization.hpp"
#include "rectangle_copy.hpp"
#include "rectangle_swap.hpp"
#include "rectangle_comparisons.hpp"
#include "rectangle_stream.hpp"

#include "basic_image_initialization.hpp"
#include "basic_image_copy.hpp"
#include "basic_image_move.hpp"
#include "basic_image_swap.hpp"
#include "basic_image_iterator.hpp"
#include "basic_image_reverse_iterator.hpp"
#include "basic_image_equals.hpp"
#include "basic_image_not_equals.hpp"

#include "literals.hpp"

#include "core_traits.hpp"

#include "pixel_cast.hpp"
#include "image_cast.hpp"
