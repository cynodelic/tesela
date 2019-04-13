// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <string>

#include "../tester.hpp"

#include <cynodelic/tesela/rgba_types.hpp>
#include <cynodelic/tesela/image_types.hpp>
#include <cynodelic/tesela/formats/jpeg_io.hpp>
#include <cynodelic/tesela/formats/png_io.hpp>
#include <cynodelic/tesela/formats/tiff_io.hpp>
#include <cynodelic/tesela/traits/is_image_format_io.hpp>


namespace tst = cynodelic::tester;
namespace tsl = cynodelic::tesela;


#include "rgb_test_pixels.hpp"
#include "rgba_test_pixels.hpp"
#include "gray_test_pixels.hpp"
#include "ga_test_pixels.hpp"

#include "jpeg_input.hpp"
#include "png_input.hpp"
#include "tiff_input.hpp"

#include "io_traits.hpp"
