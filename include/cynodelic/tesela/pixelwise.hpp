// Copyright (c) 2017 Alvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_PIXELWISE_HPP
#define CYNODELIC_TESELA_PIXELWISE_HPP

#include "internal.hpp"
#include "types.hpp"

namespace cynodelic { namespace tesela {

// Pixel brightness
std::uint8_t pix_brightness(const rgba_t& x)
{
	return internal::dbl_to_u8(
		0.2126*internal::u8_to_dbl(x.r)+
		0.7152*internal::u8_to_dbl(x.g)+
		0.0722*internal::u8_to_dbl(x.b)
	);
}

double pix_brightness(const nrgba_t& x)
{
	return 0.2126*x.r+0.7152*x.g+0.0722*x.b;
}

// Random RGB
rgba_t rand_rgb()
{
	return rgba_t(
		internal::brnd(0,255),
		internal::brnd(0,255),
		internal::brnd(0,255)
	);
}

nrgba_t rand_nrgb()
{
	return nrgba_t(
		internal::u8_to_dbl(internal::brnd(0,255)),
		internal::u8_to_dbl(internal::brnd(0,255)),
		internal::u8_to_dbl(internal::brnd(0,255))
	);
}

// Random RGBA
rgba_t rand_rgba()
{
	return rgba_t(
		internal::brnd(0,255),
		internal::brnd(0,255),
		internal::brnd(0,255),
		internal::brnd(0,255)
	);
}

nrgba_t rand_nrgba()
{
	return nrgba_t(
		internal::u8_to_dbl(internal::brnd(0,255)),
		internal::u8_to_dbl(internal::brnd(0,255)),
		internal::u8_to_dbl(internal::brnd(0,255)),
		internal::u8_to_dbl(internal::brnd(0,255))
	);
}

}} // end of "cynodelic::tesela" namespace

#endif

