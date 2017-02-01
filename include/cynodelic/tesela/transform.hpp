// Copyright (c) 2017 Alvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TRANSFORM_HPP
#define CYNODELIC_TESELA_TRANSFORM_HPP

/* - transform.hpp:
 * Methods for flipping and cropping images.
 */

#include "internal.hpp"
#include "types.hpp"
#include "image_io.hpp"

namespace cynodelic { namespace tesela {

// Flips image (image, left/right, up/down)
void flip(image& img,bool hor = false,bool ver = false)
{
	image out(img);
	std::size_t ix, iy;
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			if (hor)
			{
				if (ver) out(ix,iy) = img(img.width()-1-ix,img.height()-1-iy);
				else     out(ix,iy) = img(img.width()-1-ix,iy);
			}
			else
			{
				if (ver) out(ix,iy) = img(ix,img.height()-1-iy);
				else     out(ix,iy) = img(ix,iy);
			}
		}
	}
	
	img = out;
}

void flip(norm_image& img,bool hor = false,bool ver = false)
{
	norm_image out(img);
	std::size_t ix, iy;
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			if (hor)
			{
				if (ver) out(ix,iy) = img(img.width()-1-ix,img.height()-1-iy);
				else     out(ix,iy) = img(img.width()-1-ix,iy);
			}
			else
			{
				if (ver) out(ix,iy) = img(ix,img.height()-1-iy);
				else     out(ix,iy) = img(ix,iy);
			}
		}
	}
	
	img = out;
}

// Crop image according to rectangle
void crop(image& img,const rectangle& rect)
{
	std::size_t ix, iy;
	std::size_t ow = internal::clip(rect.w,0u,img.width()), oh = internal::clip(rect.h,0u,img.height());
	image out(ow,oh,img.color);
	
	if ((rect.x+ow < 0) || (rect.y+oh < 0) || (rect.x+ow > img.width()) || (rect.y+oh > img.height()))
	{
		std::cerr << "[cynodelic::tesela::crop] ERROR: Rectangle is outside image's bounds.\n";
		std::exit(EXIT_FAILURE);
	}
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<oh;iy++)
		for (ix=0;ix<ow;ix++)
			out(ix,iy) = img(rect.x+ix,rect.y+iy);
	
	img = out;
}

void crop(norm_image& img,const rectangle& rect)
{
	std::size_t ix, iy;
	std::size_t ow = internal::clip(rect.w,0u,img.width()), oh = internal::clip(rect.h,0u,img.height());
	norm_image out(ow,oh,img.color);
	
	if ((rect.x+ow < 0) || (rect.y+oh < 0) || (rect.x+ow >= img.width()) || (rect.y+oh >= img.height()))
	{
		std::cerr << "[cynodelic::tesela::crop] ERROR: Rectangle is outside image's bounds.\n";
		std::exit(EXIT_FAILURE);
	}
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<oh;iy++)
		for (ix=0;ix<ow;ix++)
			out(ix,iy) = img(rect.x+ix,rect.y+iy);
	
	img = out;
}

}} // end of "cynodelic::tesela" namespace

#endif

