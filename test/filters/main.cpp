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
#include <cynodelic/tesela/utilities/filters/invert.hpp>


namespace tst = cynodelic::tester;
namespace tsl = cynodelic::tesela;

using namespace tsl::literals;

#include "invert.hpp"
#include "invert_selective.hpp"
