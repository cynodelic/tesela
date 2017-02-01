// Copyright (c) 2017 Alvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_INTERNAL_HPP
#define CYNODELIC_TESELA_INTERNAL_HPP

/* - __internal__.hpp:
 * Includes the necessary libraries (standard and OpenMP)
 * and, also, declares some useful constants.
 */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <cmath>
#include <csetjmp>
#include <string>
#include <regex>
#include <random>
#include <utility>
#ifdef __OPENMP
  #include <omp.h>
#endif

extern "C"
{
#include <jpeglib.h>

#define PNG_SKIP_SETJMP_CHECK // This is necessary, so that "__pngconf.h__ in libpng..." thing does not appear.
#define PNG_DEBUG 3
#include <png.h>

#include <tiff.h>
#include <tiffio.h>
#include <tiffconf.h>
}

#ifndef CYNODELIC_TESELA_NRGBA_T_COUT_PRECISION
#define CYNODELIC_TESELA_NRGBA_T_COUT_PRECISION 10
#endif
#ifndef CYNODELIC_TESELA_DEFAULT_JPEG_QUALITY
#define CYNODELIC_TESELA_DEFAULT_JPEG_QUALITY 95
#endif
#define CYNODELIC_TESELA_DEFAULT_ALPHA_FILL 0xFF
#define CYNODELIC_TESELA_IMAGE_EXTENSIONS_REGEX "(.*)\\.(([J|j][P|p][E|e]?[G|g])|([P|p][N|n][G|g])|([T|t][I|i][F|f][F|f]?))"
#define CYNODELIC_TESELA_JPEG_EXTENSION_REGEX "(.*)\\.([J|j][P|p][E|e]?[G|g])"
#define CYNODELIC_TESELA_PNG_EXTENSION_REGEX  "(.*)\\.([P|p][N|n][G|g])"
#define CYNODELIC_TESELA_TIFF_EXTENSION_REGEX "(.*)\\.([T|t][I|i][F|f][F|f]?)"

namespace cynodelic { namespace tesela {

namespace internal
{

static constexpr double PI = 3.1415926535897932384626433832795;

// Internal random number generator
std::random_device internal_rs;
std::mt19937 irand(internal_rs());

inline double quantize(double x)
{
	return std::floor(x*255.0)/255.0;
};

// Loosless [0,1] double to uint8_t
inline std::uint8_t dbl_to_u8(double x)
{
	return static_cast<std::uint8_t>(quantize(x)*255.0);
}

// uint8_t to double between [0,1]
inline double u8_to_dbl(std::uint8_t x)
{
	return static_cast<double>(x)/255.0;
}

std::int32_t urnd(std::int32_t min,std::int32_t max)
{
	return std::uniform_int_distribution<std::int32_t>(min,max)(irand);
}

std::uint8_t brnd(std::uint8_t min,std::uint8_t max)
{
	return std::uniform_int_distribution<std::uint8_t>(min,max)(irand);
}

template <typename T> T clip(T x,T a,T b)
{
	return (x < a) ? a : ((x > b) ? b : x);
}

// Gaussian (f:R^2 -> R) function for Gaussian blur
double gaussian_2d(double x,double y)
{
	return (1/std::sqrt(2*PI))*std::exp(-(x*x+y*y)/2);
}

}

}} // end of "cynodelic::tesela" namespace

#endif
