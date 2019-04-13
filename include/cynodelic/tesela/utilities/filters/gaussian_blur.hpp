// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file gaussian_blur.hpp
 *
 * @brief Defines the `gaussian_blur` function.
 */

#ifndef CYNODELIC_TESELA_UTILITIES_FILTERS_GAUSSIAN_BLUR_HPP
#define CYNODELIC_TESELA_UTILITIES_FILTERS_GAUSSIAN_BLUR_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <cmath>
#include <type_traits>
#include <utility>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/detail/utils.hpp>
#include <cynodelic/tesela/image_types.hpp>
#include <cynodelic/tesela/traits/is_normalized.hpp>
#include <cynodelic/tesela/traits/has_rgb_components.hpp>
#include <cynodelic/tesela/traits/is_grayscale.hpp>


namespace cynodelic { namespace tesela {


#ifndef DOXYGEN_SHOULD_SKIP_THIS

void gaussian_blur(rgb_image& img,const std::size_t& r,double sigma = 1.0)
{
	rgb_image tmp(img);
	
	const std::size_t ksiz = r*2 + 1;
	double **kernel = new double*[ksiz];

	for (std::size_t i = 0; i < ksiz; i++)
		kernel[i] = new double[ksiz];
	
	double ksum = 0;
	std::size_t jx, jy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(jy,jx) schedule(dynamic)
#endif
	for (jy = 0; jy < ksiz; jy++)
	{
		for (jx = 0; jx < ksiz; jx++)
		{
			kernel[jy][jx] = detail::gaussian_2d(
				(static_cast<double>(jx) - static_cast<double>(r))/r,
				(static_cast<double>(jy) - static_cast<double>(r))/r,
				sigma
			);

			ksum += kernel[jy][jx];
		}
	}
	
	// Normalize kernel
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(jy,jx) schedule(dynamic)
#endif
	for (jy = 0; jy < ksiz; jy++)
	{
		for (jx = 0; jx < ksiz; jx++)
		{
			kernel[jy][jx] /= ksum;
		}
	}
	
	std::size_t ix, iy;
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix,jy,jx) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			double rs = 0.0, gs = 0.0, bs = 0.0;
			for (jy = 0; jy < ksiz; jy++)
			{
				for (jx = 0; jx < ksiz; jx++)
				{
					std::size_t loc_x = detail::clip(ix + jx - r,static_cast<std::size_t>(0u),img.width() - 1);
					std::size_t loc_y = detail::clip(iy + jy - r,static_cast<std::size_t>(0u),img.height() - 1);
					rs += detail::u8_to_dbl(img(loc_x,loc_y).red)*kernel[jy][jx];
					gs += detail::u8_to_dbl(img(loc_x,loc_y).green)*kernel[jy][jx];
					bs += detail::u8_to_dbl(img(loc_x,loc_y).blue)*kernel[jy][jx];
				}
			}
			
			tmp(ix,iy) = rgb_t(
				detail::dbl_to_u8(rs),
				detail::dbl_to_u8(gs),
				detail::dbl_to_u8(bs)
			);
		}
	}

	for (std::size_t i = 0; i < ksiz; i++)
		delete [] kernel[i];

	delete [] kernel;

	img = std::move(tmp);
}


void gaussian_blur(rgba_image& img,const std::size_t& r,double sigma = 1.0)
{
	rgba_image tmp(img);
	
	const std::size_t ksiz = r*2 + 1;
	double **kernel = new double*[ksiz];

	for (std::size_t i = 0; i < ksiz; i++)
		kernel[i] = new double[ksiz];
	
	double ksum = 0;
	std::size_t jx, jy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(jy,jx) schedule(dynamic)
#endif
	for (jy = 0; jy < ksiz; jy++)
	{
		for (jx = 0; jx < ksiz; jx++)
		{
			kernel[jy][jx] = detail::gaussian_2d(
				(static_cast<double>(jx) - static_cast<double>(r))/r,
				(static_cast<double>(jy) - static_cast<double>(r))/r,
				sigma
			);

			ksum += kernel[jy][jx];
		}
	}
	
	// Normalize kernel
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(jy,jx) schedule(dynamic)
#endif
	for (jy = 0; jy < ksiz; jy++)
	{
		for (jx = 0; jx < ksiz; jx++)
		{
			kernel[jy][jx] /= ksum;
		}
	}
	
	std::size_t ix, iy;
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix,jy,jx) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			double rs = 0.0, gs = 0.0, bs = 0.0, as = 0.0;
			for (jy = 0; jy < ksiz; jy++)
			{
				for (jx = 0; jx < ksiz; jx++)
				{
					std::size_t loc_x = detail::clip(ix + jx - r,static_cast<std::size_t>(0u),img.width() - 1);
					std::size_t loc_y = detail::clip(iy + jy - r,static_cast<std::size_t>(0u),img.height() - 1);
					rs += detail::u8_to_dbl(img(loc_x,loc_y).red)*kernel[jy][jx];
					gs += detail::u8_to_dbl(img(loc_x,loc_y).green)*kernel[jy][jx];
					bs += detail::u8_to_dbl(img(loc_x,loc_y).blue)*kernel[jy][jx];
					as += detail::u8_to_dbl(img(loc_x,loc_y).alpha)*kernel[jy][jx];
				}
			}
			
			tmp(ix,iy) = rgba_t(
				detail::dbl_to_u8(rs),
				detail::dbl_to_u8(gs),
				detail::dbl_to_u8(bs),
				detail::dbl_to_u8(as)
			);
		}
	}

	for (std::size_t i = 0; i < ksiz; i++)
		delete [] kernel[i];

	delete [] kernel;

	img = std::move(tmp);
}


void gaussian_blur(gray_image& img,const std::size_t& r,double sigma = 1.0)
{
	gray_image tmp(img);
	
	const std::size_t ksiz = r*2 + 1;
	double **kernel = new double*[ksiz];

	for (std::size_t i = 0; i < ksiz; i++)
		kernel[i] = new double[ksiz];
	
	double ksum = 0;
	std::size_t jx, jy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(jy,jx) schedule(dynamic)
#endif
	for (jy = 0; jy < ksiz; jy++)
	{
		for (jx = 0; jx < ksiz; jx++)
		{
			kernel[jy][jx] = detail::gaussian_2d(
				(static_cast<double>(jx) - static_cast<double>(r))/r,
				(static_cast<double>(jy) - static_cast<double>(r))/r,
				sigma
			);

			ksum += kernel[jy][jx];
		}
	}
	
	// Normalize kernel
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(jy,jx) schedule(dynamic)
#endif
	for (jy = 0; jy < ksiz; jy++)
	{
		for (jx = 0; jx < ksiz; jx++)
		{
			kernel[jy][jx] /= ksum;
		}
	}
	
	std::size_t ix, iy;
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix,jy,jx) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			double ys = 0.0;
			for (jy = 0; jy < ksiz; jy++)
			{
				for (jx = 0; jx < ksiz; jx++)
				{
					std::size_t loc_x = detail::clip(ix + jx - r,static_cast<std::size_t>(0u),img.width() - 1);
					std::size_t loc_y = detail::clip(iy + jy - r,static_cast<std::size_t>(0u),img.height() - 1);
					ys += detail::u8_to_dbl(img(loc_x,loc_y).gray)*kernel[jy][jx];
				}
			}
			
			tmp(ix,iy) = gray_t(
				detail::dbl_to_u8(ys)
			);
		}
	}

	for (std::size_t i = 0; i < ksiz; i++)
		delete [] kernel[i];

	delete [] kernel;

	img = std::move(tmp);
}


void gaussian_blur(ga_image& img,const std::size_t& r,double sigma = 1.0)
{
	ga_image tmp(img);
	
	const std::size_t ksiz = r*2 + 1;
	double **kernel = new double*[ksiz];

	for (std::size_t i = 0; i < ksiz; i++)
		kernel[i] = new double[ksiz];
	
	double ksum = 0;
	std::size_t jx, jy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(jy,jx) schedule(dynamic)
#endif
	for (jy = 0; jy < ksiz; jy++)
	{
		for (jx = 0; jx < ksiz; jx++)
		{
			kernel[jy][jx] = detail::gaussian_2d(
				(static_cast<double>(jx) - static_cast<double>(r))/r,
				(static_cast<double>(jy) - static_cast<double>(r))/r,
				sigma
			);

			ksum += kernel[jy][jx];
		}
	}
	
	// Normalize kernel
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(jy,jx) schedule(dynamic)
#endif
	for (jy = 0; jy < ksiz; jy++)
	{
		for (jx = 0; jx < ksiz; jx++)
		{
			kernel[jy][jx] /= ksum;
		}
	}
	
	std::size_t ix, iy;
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix,jy,jx) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			double ys = 0.0, as = 0.0;
			for (jy = 0; jy < ksiz; jy++)
			{
				for (jx = 0; jx < ksiz; jx++)
				{
					std::size_t loc_x = detail::clip(ix + jx - r,static_cast<std::size_t>(0u),img.width() - 1);
					std::size_t loc_y = detail::clip(iy + jy - r,static_cast<std::size_t>(0u),img.height() - 1);
					ys += detail::u8_to_dbl(img(loc_x,loc_y).gray)*kernel[jy][jx];
					as += detail::u8_to_dbl(img(loc_x,loc_y).alpha)*kernel[jy][jx];
				}
			}
			
			tmp(ix,iy) = ga_t(
				detail::dbl_to_u8(ys),
				detail::dbl_to_u8(as)
			);
		}
	}

	for (std::size_t i = 0; i < ksiz; i++)
		delete [] kernel[i];

	delete [] kernel;

	img = std::move(tmp);
}


void gaussian_blur(nrgb_image& img,const std::size_t& r,double sigma = 1.0)
{
	nrgb_image tmp(img);
	
	const std::size_t ksiz = r*2 + 1;
	double **kernel = new double*[ksiz];
	for (std::size_t i=0; i < ksiz; i++)
		kernel[i] = new double[ksiz];
	
	double ksum = 0;
	std::size_t jx, jy;
	
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(jy,jx) schedule(dynamic)
#endif
	for (jy = 0; jy < ksiz; jy++)
	{
		for (jx = 0; jx < ksiz; jx++)
		{
			kernel[jy][jx] = detail::gaussian_2d(
				(static_cast<double>(jx) - static_cast<double>(r))/r,
				(static_cast<double>(jy) - static_cast<double>(r))/r,
				sigma
			);

			ksum += kernel[jy][jx];
		}
	}
	
	// Normalize kernel
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(jy,jx) schedule(dynamic)
#endif
	for (jy = 0; jy < ksiz; jy++)
	{
		for (jx = 0; jx < ksiz; jx++)
		{
			kernel[jy][jx] /= ksum;
		}
	}
	
	std::size_t ix, iy;
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix,jy,jx) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			double rs = 0.0, gs = 0.0, bs = 0.0;
			for (jy = 0; jy < ksiz; jy++)
			{
				for (jx = 0; jx < ksiz; jx++)
				{
					std::size_t loc_x = detail::clip(ix + jx - r,static_cast<std::size_t>(0u),img.width() - 1);
					std::size_t loc_y = detail::clip(iy + jy - r,static_cast<std::size_t>(0u),img.height() - 1);
					rs += img(loc_x,loc_y).red.get()*kernel[jy][jx];
					gs += img(loc_x,loc_y).green.get()*kernel[jy][jx];
					bs += img(loc_x,loc_y).blue.get()*kernel[jy][jx];
				}
			}
			tmp(ix,iy) = nrgb_t(rs,gs,bs);
		}
	}


	for (std::size_t i = 0; i < ksiz; i++)
		delete [] kernel[i];

	delete [] kernel;
	
	img = std::move(tmp);
}


void gaussian_blur(nrgba_image& img,const std::size_t& r,double sigma = 1.0)
{
	nrgba_image tmp(img);
	
	const std::size_t ksiz = r*2 + 1;
	double **kernel = new double*[ksiz];
	for (std::size_t i=0; i < ksiz; i++)
		kernel[i] = new double[ksiz];
	
	double ksum = 0;
	std::size_t jx, jy;
	
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(jy,jx) schedule(dynamic)
#endif
	for (jy = 0; jy < ksiz; jy++)
	{
		for (jx = 0; jx < ksiz; jx++)
		{
			kernel[jy][jx] = detail::gaussian_2d(
				(static_cast<double>(jx) - static_cast<double>(r))/r,
				(static_cast<double>(jy) - static_cast<double>(r))/r,
				sigma
			);

			ksum += kernel[jy][jx];
		}
	}
	
	// Normalize kernel
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(jy,jx) schedule(dynamic)
#endif
	for (jy = 0; jy < ksiz; jy++)
	{
		for (jx = 0; jx < ksiz; jx++)
		{
			kernel[jy][jx] /= ksum;
		}
	}
	
	std::size_t ix, iy;
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix,jy,jx) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			double rs = 0.0, gs = 0.0, bs = 0.0, as = 0.0;
			for (jy = 0; jy < ksiz; jy++)
			{
				for (jx = 0; jx < ksiz; jx++)
				{
					std::size_t loc_x = detail::clip(ix + jx - r,static_cast<std::size_t>(0u),img.width() - 1);
					std::size_t loc_y = detail::clip(iy + jy - r,static_cast<std::size_t>(0u),img.height() - 1);
					rs += img(loc_x,loc_y).red.get()*kernel[jy][jx];
					gs += img(loc_x,loc_y).green.get()*kernel[jy][jx];
					bs += img(loc_x,loc_y).blue.get()*kernel[jy][jx];
					as += img(loc_x,loc_y).alpha.get()*kernel[jy][jx];
				}
			}
			tmp(ix,iy) = nrgba_t(rs,gs,bs,as);
		}
	}


	for (std::size_t i = 0; i < ksiz; i++)
		delete [] kernel[i];

	delete [] kernel;
	
	img = std::move(tmp);
}


void gaussian_blur(ngray_image& img,const std::size_t& r,double sigma = 1.0)
{
	ngray_image tmp(img);
	
	const std::size_t ksiz = r*2 + 1;
	double **kernel = new double*[ksiz];
	for (std::size_t i=0; i < ksiz; i++)
		kernel[i] = new double[ksiz];
	
	double ksum = 0;
	std::size_t jx, jy;
	
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(jy,jx) schedule(dynamic)
#endif
	for (jy = 0; jy < ksiz; jy++)
	{
		for (jx = 0; jx < ksiz; jx++)
		{
			kernel[jy][jx] = detail::gaussian_2d(
				(static_cast<double>(jx) - static_cast<double>(r))/r,
				(static_cast<double>(jy) - static_cast<double>(r))/r,
				sigma
			);

			ksum += kernel[jy][jx];
		}
	}
	
	// Normalize kernel
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(jy,jx) schedule(dynamic)
#endif
	for (jy = 0; jy < ksiz; jy++)
	{
		for (jx = 0; jx < ksiz; jx++)
		{
			kernel[jy][jx] /= ksum;
		}
	}
	
	std::size_t ix, iy;
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix,jy,jx) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			double ys = 0.0;
			for (jy = 0; jy < ksiz; jy++)
			{
				for (jx = 0; jx < ksiz; jx++)
				{
					std::size_t loc_x = detail::clip(ix + jx - r,static_cast<std::size_t>(0u),img.width() - 1);
					std::size_t loc_y = detail::clip(iy + jy - r,static_cast<std::size_t>(0u),img.height() - 1);
					ys += img(loc_x,loc_y).gray.get()*kernel[jy][jx];
				}
			}
			tmp(ix,iy) = ngray_t(ys);
		}
	}


	for (std::size_t i = 0; i < ksiz; i++)
		delete [] kernel[i];

	delete [] kernel;
	
	img = std::move(tmp);
}


void gaussian_blur(nga_image& img,const std::size_t& r,double sigma = 1.0)
{
	nga_image tmp(img);
	
	const std::size_t ksiz = r*2 + 1;
	double **kernel = new double*[ksiz];
	for (std::size_t i=0; i < ksiz; i++)
		kernel[i] = new double[ksiz];
	
	double ksum = 0;
	std::size_t jx, jy;
	
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(jy,jx) schedule(dynamic)
#endif
	for (jy = 0; jy < ksiz; jy++)
	{
		for (jx = 0; jx < ksiz; jx++)
		{
			kernel[jy][jx] = detail::gaussian_2d(
				(static_cast<double>(jx) - static_cast<double>(r))/r,
				(static_cast<double>(jy) - static_cast<double>(r))/r,
				sigma
			);

			ksum += kernel[jy][jx];
		}
	}
	
	// Normalize kernel
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(jy,jx) schedule(dynamic)
#endif
	for (jy = 0; jy < ksiz; jy++)
	{
		for (jx = 0; jx < ksiz; jx++)
		{
			kernel[jy][jx] /= ksum;
		}
	}
	
	std::size_t ix, iy;
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix,jy,jx) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			double ys = 0.0, as = 0.0;
			for (jy = 0; jy < ksiz; jy++)
			{
				for (jx = 0; jx < ksiz; jx++)
				{
					std::size_t loc_x = detail::clip(ix + jx - r,static_cast<std::size_t>(0u),img.width() - 1);
					std::size_t loc_y = detail::clip(iy + jy - r,static_cast<std::size_t>(0u),img.height() - 1);
					ys += img(loc_x,loc_y).gray.get()*kernel[jy][jx];
					as += img(loc_x,loc_y).alpha.get()*kernel[jy][jx];
				}
			}
			tmp(ix,iy) = nga_t(ys,as);
		}
	}


	for (std::size_t i = 0; i < ksiz; i++)
		delete [] kernel[i];

	delete [] kernel;
	
	img = std::move(tmp);
}

#else // DOXYGEN_SHOULD_SKIP_THIS

/**
 * @ingroup filters
 * @brief Gaussian blur
 *
 * Applies Gaussian blur to an image.
 *
 * @note The complexity of this filter is O(n^4), so it can be slow with higher radiuses.
 *
 * @param img   The image.
 * @param r     Radius.
 * @param sigma Spreading (standard deviation).
 */
template <typename PixelType>
void gaussian_blur(PixelType& img,const std::size_t& r,double sigma = 1.0);

#endif // DOXYGEN_SHOULD_SKIP_THIS


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_UTILITIES_FILTERS_GAUSSIAN_BLUR_HPP
