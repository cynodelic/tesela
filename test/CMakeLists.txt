# Copyright (c) 2019 Álvaro Ceballos
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt


add_subdirectory(core)
add_subdirectory(transformations)
add_subdirectory(filters)

if (CYNODELIC_TESELA_ALLOW_IO AND has_image_libs)
	add_subdirectory(io)
endif()
