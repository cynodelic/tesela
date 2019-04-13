# Copyright (c) 2019 Álvaro Ceballos
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt


add_test(NAME core COMMAND test_core --run-all)

add_executable(test_core main.cpp)
target_include_directories(test_core PUBLIC ${PROJECT_SOURCE_DIR}/include ${PROJECT_BINARY_DIR}/include)
