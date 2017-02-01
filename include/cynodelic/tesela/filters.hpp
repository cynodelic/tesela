// Copyright (c) 2017 Alvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_FILTERS_HPP
#define CYNODELIC_TESELA_FILTERS_HPP

/* - filters.hpp:
 * Some filters and effects for images.
 */

#include "internal.hpp"
#include "types.hpp"
#include "image_io.hpp"

namespace cynodelic { namespace tesela {

// Inverts image colors
void invert(image& img,bool inv_r = true,bool inv_g = true,bool inv_b = true)
{
	std::size_t ix, iy;
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			if (inv_r) img(ix,iy).r = 255 - img(ix,iy).r;
			if (inv_g) img(ix,iy).g = 255 - img(ix,iy).g;
			if (inv_b) img(ix,iy).b = 255 - img(ix,iy).b;
		}
	}
}

void invert(norm_image& img,bool inv_r = true,bool inv_g = true,bool inv_b = true)
{
	std::size_t ix, iy;
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			if (inv_r) img(ix,iy).r = 1.0 - img(ix,iy).r;
			if (inv_g) img(ix,iy).g = 1.0 - img(ix,iy).g;
			if (inv_b) img(ix,iy).b = 1.0 - img(ix,iy).b;
		}
	}
}

// Grayscale
void monochrome(image& img)
{
	double nr, ng, nb, ny;
	std::size_t ix, iy;
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
			ny = 0.2126*nr+0.7152*ng+0.0722*nb;
			img(ix,iy) = rgba_t(internal::dbl_to_u8(ny));
		}
	}
}

void monochrome(norm_image& img)
{
	double nr, ng, nb, ny;
	std::size_t ix, iy;
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			ny = 0.2126*img(ix,iy).r+0.7152*img(ix,iy).g+0.0722*img(ix,iy).b;
			img(ix,iy) = nrgba_t(ny);
		}
	}
}

// Duotone
void duotone(image& img,const rgba_t& high,const rgba_t& low)
{
	double nr, ng, nb, ny;
	double tr, tg, tb;
	std::size_t ix, iy;
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
			ny = 0.2126*nr+0.7152*ng+0.0722*nb;
			tr = internal::u8_to_dbl(high.r)*ny+internal::u8_to_dbl(low.r)*(1.0-ny);
			tg = internal::u8_to_dbl(high.g)*ny+internal::u8_to_dbl(low.g)*(1.0-ny);
			tb = internal::u8_to_dbl(high.b)*ny+internal::u8_to_dbl(low.b)*(1.0-ny);
			img(ix,iy) = rgba_t(
				internal::dbl_to_u8(tr),
				internal::dbl_to_u8(tg),
				internal::dbl_to_u8(tb)
			);
		}
	}
}

void duotone(norm_image& img,const nrgba_t& high,const nrgba_t& low)
{
	double ny;
	double tr, tg, tb;
	std::size_t ix, iy;
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			ny = 0.2126*img(ix,iy).r+0.7152*img(ix,iy).g+0.0722*img(ix,iy).b;
			tr = high.r*ny+low.r*(1.0-ny);
			tg = high.g*ny+low.g*(1.0-ny);
			tb = high.b*ny+low.b*(1.0-ny);
			img(ix,iy) = nrgba_t(tr,tg,tb);
		}
	}
}

// Brightness
void brightness(image& img,const double& value)
{
	std::uint8_t tr, tg, tb;
	std::size_t ix, iy;
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			tr = std::uint8_t(internal::clip(double(img(ix,iy).r) + 255.0*value,0.0,255.0));
			tg = std::uint8_t(internal::clip(double(img(ix,iy).g) + 255.0*value,0.0,255.0));
			tb = std::uint8_t(internal::clip(double(img(ix,iy).b) + 255.0*value,0.0,255.0));
			img(ix,iy) = rgba_t(tr,tg,tb);
		}
	}
}

void brightness(norm_image& img,const double& value)
{
	double tr, tg, tb;
	std::size_t ix, iy;
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			tr = internal::clip(img(ix,iy).r + value,0.0,1.0);
			tg = internal::clip(img(ix,iy).g + value,0.0,1.0);
			tb = internal::clip(img(ix,iy).b + value,0.0,1.0);
			img(ix,iy) = nrgba_t(tr,tg,tb);
		}
	}
}

// Contrast
void contrast(image& img,const double& value)
{
	double cf = (259.0*(255.0*value+255.0))/(255.0*(259.0-255.0*value));
	std::uint8_t tr, tg, tb;
	std::size_t ix, iy;
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			tr = std::uint8_t(internal::clip( cf*(double(img(ix,iy).r)-128.0)+128.0 ,0.0,255.0));
			tg = std::uint8_t(internal::clip( cf*(double(img(ix,iy).g)-128.0)+128.0 ,0.0,255.0));
			tb = std::uint8_t(internal::clip( cf*(double(img(ix,iy).b)-128.0)+128.0 ,0.0,255.0));
			img(ix,iy) = rgba_t(tr,tg,tb);
		}
	}
}

void contrast(norm_image& img,const double& value)
{
	double cf = (259.0*(255.0*value+255.0))/(255.0*(259.0-255.0*value));
	double tr, tg, tb;
	std::size_t ix, iy;
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			tr = internal::clip( cf*(img(ix,iy).r-0.5)+0.5 ,0.0,1.0);
			tg = internal::clip( cf*(img(ix,iy).g-0.5)+0.5 ,0.0,1.0);
			tb = internal::clip( cf*(img(ix,iy).b-0.5)+0.5 ,0.0,1.0);
			img(ix,iy) = nrgba_t(tr,tg,tb);
		}
	}
}

// Gamma
void gamma(image& img,const double& value)
{
	if (value == 0.0)
	{
		std::cerr << "[cynodelic::tesela::gamma] ERROR: Divisions by zero are impossible.\n";
		std::exit(EXIT_FAILURE);
	}
	std::uint8_t tr, tg, tb;
	std::size_t ix, iy;
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			tr = internal::dbl_to_u8(std::pow(internal::u8_to_dbl(img(ix,iy).r),1.0/value));
			tg = internal::dbl_to_u8(std::pow(internal::u8_to_dbl(img(ix,iy).g),1.0/value));
			tb = internal::dbl_to_u8(std::pow(internal::u8_to_dbl(img(ix,iy).b),1.0/value));
			img(ix,iy) = rgba_t(tr,tg,tb);
		}
	}
}

void gamma(norm_image& img,const double& value)
{
	if (value == 0.0)
	{
		std::cerr << "[cynodelic::tesela::gamma] ERROR: Divisions by zero are impossible.\n";
		std::exit(EXIT_FAILURE);
	}
	double tr, tg, tb;
	std::size_t ix, iy;
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			tr = std::pow(img(ix,iy).r,1.0/value);
			tg = std::pow(img(ix,iy).g,1.0/value);
			tb = std::pow(img(ix,iy).b,1.0/value);
			img(ix,iy) = nrgba_t(tr,tg,tb);
		}
	}
}

// Gaussian blur
// Note: It has a complexity of O(n^4)
void gaussian_blur(image& img,const std::size_t& r)
{
	image tmp(img.width(),img.height());
	tmp.color = img.color;
	
#ifdef CYNODELIC_TESELA_VERBOSE
	std::cout << "[cynodelic::tesela::gaussian_blur] Generating convolution matrix...\n";
#endif
	std::size_t ksiz = r*2+1;
	double **kernel = new double*[ksiz];
	for (std::size_t i=0;i<ksiz;i++)
		kernel[i] = new double[ksiz];
	
	double ksum = 0;
	std::size_t jx, jy;
	for (jy=0;jy<ksiz;jy++)
	{
		for (jx=0;jx<ksiz;jx++)
		{
			kernel[jy][jx] = internal::gaussian_2d((double(jx)-double(r))/r,(double(jy)-double(r))/r);
			ksum += kernel[jy][jx];
		}
	}
	
	// Normalize kernel
	for (jy=0;jy<ksiz;jy++)
		for (jx=0;jx<ksiz;jx++)
			kernel[jy][jx] /= ksum;
	
#ifdef CYNODELIC_TESELA_VERBOSE
	std::cout << "[cynodelic::tesela::gaussian_blur] Applying blur effect...\n";
#endif
	
	std::size_t ix, iy;
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix,jy,jx) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			double rs = 0.0, gs = 0.0, bs = 0.0, as = 0.0;
			for (jy=0;jy<ksiz;jy++)
			{
				for (jx=0;jx<ksiz;jx++)
				{
					std::size_t loc_x = internal::clip(ix+jx-r,0u,img.width()-1);
					std::size_t loc_y = internal::clip(iy+jy-r,0u,img.height()-1);
					rs += internal::u8_to_dbl(img(loc_x,loc_y).r)*kernel[jy][jx];
					gs += internal::u8_to_dbl(img(loc_x,loc_y).g)*kernel[jy][jx];
					bs += internal::u8_to_dbl(img(loc_x,loc_y).b)*kernel[jy][jx];
					
					if (img.color == color_mode::RGBA || img.color == color_mode::GA)
						as += internal::u8_to_dbl(img(loc_x,loc_y).a)*kernel[jy][jx];
				}
			}
			
			tmp(ix,iy) = rgba_t(
				internal::dbl_to_u8(rs),
				internal::dbl_to_u8(gs),
				internal::dbl_to_u8(bs),
				(img.color == color_mode::RGBA || img.color == color_mode::GA) ?
					internal::dbl_to_u8(as) :
					img(ix,iy).a
			);
		}
	}
	
#ifdef CYNODELIC_TESELA_VERBOSE
	std::cout << "[cynodelic::tesela::gaussian_blur] Copying blurred image into original...\n";
#endif
	
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
		for (ix=0;ix<img.width();ix++)
			img(ix,iy) = tmp(ix,iy);
}

void gaussian_blur(norm_image& img,const std::size_t& r)
{
	norm_image tmp(img.width(),img.height());
	tmp.color = img.color;
	
#ifdef CYNODELIC_TESELA_VERBOSE
	std::cout << "[cynodelic::tesela::gaussian_blur] Generating convolution matrix...\n";
#endif
	std::size_t ksiz = r*2+1;
	double **kernel = new double*[ksiz];
	for (std::size_t i=0;i<ksiz;i++)
		kernel[i] = new double[ksiz];
	
	double ksum = 0;
	std::size_t jx, jy;
	for (jy=0;jy<ksiz;jy++)
	{
		for (jx=0;jx<ksiz;jx++)
		{
			kernel[jy][jx] = internal::gaussian_2d((double(jx)-double(r))/r,(double(jy)-double(r))/r);
			ksum += kernel[jy][jx];
		}
	}
	
	// Normalize kernel
	for (jy=0;jy<ksiz;jy++)
		for (jx=0;jx<ksiz;jx++)
			kernel[jy][jx] /= ksum;
	
#ifdef CYNODELIC_TESELA_VERBOSE
	std::cout << "[cynodelic::tesela::gaussian_blur] Applying blur effect...\n";
#endif
	
	std::size_t ix, iy;
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix,jy,jx) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			double rs = 0.0, gs = 0.0, bs = 0.0, as = 0.0;
			for (jy=0;jy<ksiz;jy++)
			{
				for (jx=0;jx<ksiz;jx++)
				{
					std::size_t loc_x = internal::clip(ix+jx-r,0u,img.width()-1);
					std::size_t loc_y = internal::clip(iy+jy-r,0u,img.height()-1);
					rs += img(loc_x,loc_y).r*kernel[jy][jx];
					gs += img(loc_x,loc_y).g*kernel[jy][jx];
					bs += img(loc_x,loc_y).b*kernel[jy][jx];
					
					if (img.color == color_mode::RGBA || img.color == color_mode::GA)
						as += img(loc_x,loc_y).a*kernel[jy][jx];
				}
			}
			tmp(ix,iy) = nrgba_t(
				rs,gs,bs,
				(img.color == color_mode::RGBA || img.color == color_mode::GA) ? as : img(ix,iy).a
			);
		}
	}
	
#ifdef CYNODELIC_TESELA_VERBOSE
	std::cout << "[cynodelic::tesela::gaussian_blur] Copying blurred image into original...\n";
#endif
	
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
		for (ix=0;ix<img.width();ix++)
			img(ix,iy) = tmp(ix,iy);
}

// Scatter
void scatter(image& img,const double& r = 1)
{
	image tmp(img.width(),img.height());
	tmp.color = img.color;
	
	std::size_t ix, iy;
	std::int32_t xp, yp;
	double ang;
	
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			ang = double(internal::irand())/double(0x7FFFFFFF);
			xp = std::int32_t(double(ix)+r*std::cos(internal::PI*ang));
			yp = std::int32_t(double(iy)+r*std::sin(internal::PI*ang));
			xp = internal::clip(xp,0,std::int32_t(img.width()-1));
			yp = internal::clip(yp,0,std::int32_t(img.height()-1));
			tmp(ix,iy) = img(std::size_t(xp),std::size_t(yp));
		}
	}
	
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
		for (ix=0;ix<img.width();ix++)
			img(ix,iy) = tmp(ix,iy);
}

void scatter(norm_image& img,const double& r = 1)
{
	norm_image tmp(img.width(),img.height());
	tmp.color = img.color;
	
	std::size_t ix, iy;
	std::int32_t xp, yp;
	double ang;
	
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
	{
		for (ix=0;ix<img.width();ix++)
		{
			ang = double(internal::irand())/double(0x7FFFFFFF);
			xp = std::int32_t(double(ix)+r*std::cos(internal::PI*ang));
			yp = std::int32_t(double(iy)+r*std::sin(internal::PI*ang));
			xp = internal::clip(xp,0,std::int32_t(img.width()-1));
			yp = internal::clip(yp,0,std::int32_t(img.height()-1));
			tmp(ix,iy) = img(std::size_t(xp),std::size_t(yp));
		}
	}
	
#ifndef CYNODELIC_TESELA_DISABLE_OPENMP
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy=0;iy<img.height();iy++)
		for (ix=0;ix<img.width();ix++)
			img(ix,iy) = tmp(ix,iy);
}

}} // end of "cynodelic::tesela" namespace

#endif
