# Copyright (c) 2019 Álvaro Ceballos
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt


add_test(NAME transformations COMMAND test_transformations --run-all)

add_executable(test_transformations main.cpp)
target_include_directories(test_transformations PUBLIC ${PROJECT_SOURCE_DIR}/include ${PROJECT_BINARY_DIR}/include)
