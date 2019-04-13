// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file config.hpp
 *
 * @brief Header for configurations.
 */

#ifndef CYNODELIC_TESELA_CONFIG_HPP
#define CYNODELIC_TESELA_CONFIG_HPP


#ifndef DOXYGEN_SHOULD_SKIP_THIS

#define CYNODELIC_TESELA_STRINGIZE_IMPL(x) #x
#define CYNODELIC_TESELA_STRINGIZE(x) CYNODELIC_TESELA_STRINGIZE_IMPL(x)

#endif // DOXYGEN_SHOULD_SKIP_THIS


#define CYNODELIC_TESELA_VERSION_MAJOR 2 /**< @brief Major version of this library. */
#define CYNODELIC_TESELA_VERSION_MINOR 0 /**< @brief Minor version of this library. */
#define CYNODELIC_TESELA_VERSION_PATCH 0 /**< @brief Patch version of this library. */


/// @brief The version of this library
#define CYNODELIC_TESELA_VERSION CYNODELIC_TESELA_STRINGIZE(CYNODELIC_TESELA_VERSION_MAJOR) "." CYNODELIC_TESELA_STRINGIZE(CYNODELIC_TESELA_VERSION_MINOR) "." CYNODELIC_TESELA_STRINGIZE(CYNODELIC_TESELA_VERSION_PATCH)


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#if defined(_OPENMP) && defined(CYNODELIC_TESELA_USE_OPENMP)

#define CYNODELIC_TESELA_OPENMP_ENABLED

#include <omp.h>

#endif // defined(_OPENMP) && defined(CYNODELIC_TESELA_USE_OPENMP)

#else // DOXYGEN_SHOULD_SKIP_THIS

/**
 * @brief Checks if this library uses OpenMP
 *
 * This macro is defined if this library is allowed to use OpenMP (if
 * available), when such utility is used. It can be allowed by defining the
 * `CYNODELIC_TESELA_USE_OPENMP` macro before the library's first header file.
 */
#define CYNODELIC_TESELA_OPENMP_ENABLED

#endif // DOXYGEN_SHOULD_SKIP_THIS


#endif // CYNODELIC_TESELA_CONFIG_HPP
