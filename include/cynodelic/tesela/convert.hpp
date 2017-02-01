// Copyright (c) 2017 Alvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_CONVERT_HPP
#define CYNODELIC_TESELA_CONVERT_HPP

/* - convert.hpp:
 * Methods for converting images to grayscale, normalizing
 * to a range of 0.0-1.0 (and back to 0-255) and removing alpha
 * channel.
 */

#include "internal.hpp"
#include "types.hpp"
#include "image_io.hpp"

namespace cynodelic { namespace tesela {

void convert_to_grayscale(image& img,bool save_gs = true)
{
	double nr, ng, nb, ny;
	std::size_t iy, ix;
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			nr = internal::u8_to_dbl(img(ix,iy).r)/255.0;
			ng = internal::u8_to_dbl(img(ix,iy).g)/255.0;
			nb = internal::u8_to_dbl(img(ix,iy).b)/255.0;
			ny = 0.2126*nr+0.7152*ng+0.0722*nb;
			img(ix,iy).r = img(ix,iy).g = img(ix,iy).b = std::uint8_t(ny*255.0);
		}
	}
	if (save_gs)
	{
		if (img.color == color_mode::RGB)
			img.color = color_mode::GRAY;
		else if (img.color == color_mode::RGBA)
			img.color = color_mode::GA;
	}
}

void convert_to_grayscale(norm_image& img,bool save_gs = true)
{
	double nr, ng, nb, ny;
	std::size_t iy, ix;
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			nr = img(ix,iy).r;
			ng = img(ix,iy).g;
			nb = img(ix,iy).b;
			ny = 0.2126*nr+0.7152*ng+0.0722*nb;
			img(ix,iy).r = img(ix,iy).g = img(ix,iy).b = ny*255.0;
		}
	}
	if (save_gs)
	{
		if (img.color == color_mode::RGB)
			img.color = color_mode::GRAY;
		else if (img.color == color_mode::RGBA)
			img.color = color_mode::GA;
	}
}

void remove_alpha(image& img,bool save_na = true)
{
	double nr, ng, nb, na, dr, dg, db;
	double nf = double(CYNODELIC_TESELA_DEFAULT_ALPHA_FILL)/255.0;
	std::size_t iy, ix;
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			nr = internal::u8_to_dbl(img(ix,iy).r);
			ng = internal::u8_to_dbl(img(ix,iy).g);
			nb = internal::u8_to_dbl(img(ix,iy).b);
			na = internal::u8_to_dbl(img(ix,iy).a);
			dr = ((1.0-na)*nf) + (na*nr);
			dg = ((1.0-na)*nf) + (na*ng);
			db = ((1.0-na)*nf) + (na*nb);
			img(ix,iy).r = internal::dbl_to_u8(dr);
			img(ix,iy).g = internal::dbl_to_u8(dg);
			img(ix,iy).b = internal::dbl_to_u8(db);
			img(ix,iy).a = std::uint8_t(CYNODELIC_TESELA_DEFAULT_ALPHA_FILL);
		}
	}
	if (save_na)
	{
		if (img.color == color_mode::RGBA)
			img.color = color_mode::RGB;
		else if (img.color == color_mode::GA)
			img.color = color_mode::GRAY;
	}
}

void remove_alpha(norm_image& img,bool save_na = true)
{
	double nr, ng, nb, na, dr, dg, db;
	double nf = internal::u8_to_dbl(CYNODELIC_TESELA_DEFAULT_ALPHA_FILL);
	std::size_t iy, ix;
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			nr = img(ix,iy).r; ng = img(ix,iy).g; nb = img(ix,iy).b; na = img(ix,iy).a;
			dr = ((1.0-na)*nf) + (na*nr);
			dg = ((1.0-na)*nf) + (na*ng);
			db = ((1.0-na)*nf) + (na*nb);
			img(ix,iy) = nrgba_t(dr,dg,db,nf);
		}
	}
	if (save_na)
	{
		if (img.color == color_mode::RGBA)
			img.color = color_mode::RGB;
		else if (img.color == color_mode::GA)
			img.color = color_mode::GRAY;
	}
}

}} // end of "cynodelic::tesela" namespace

#endif
