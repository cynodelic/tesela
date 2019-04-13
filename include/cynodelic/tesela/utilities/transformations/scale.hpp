// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/** 
 * @file scale.hpp
 *
 * @brief Defines the `scale` function.
 */

#ifndef CYNODELIC_TESELA_UTILITIES_TRANSFORMATIONS_SCALE_HPP
#define CYNODELIC_TESELA_UTILITIES_TRANSFORMATIONS_SCALE_HPP


#include <cstdlib>
#include <cstddef>
#include <utility>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/detail/utils.hpp>
#include <cynodelic/tesela/image_types.hpp>
#include <cynodelic/tesela/rectangle.hpp>
#include <cynodelic/tesela/utilities/transformations/detail/pix_lerp_2d.hpp>
#include <cynodelic/tesela/utilities/transformations/detail/pix_citp_2d.hpp>


namespace cynodelic { namespace tesela {


/**
 * @ingroup imgscalingtags
 * @brief Type for the nearest neighbour scaling algorithm tag
 *
 * An empty struct that acts as the type for `nearest_neighbour_algorithm`.
 */
struct nearest_neighbour_algorithm_tag_t {};


/**
 * @ingroup imgscalingtags
 * @brief Type for the bilinear scaling algorithm tag
 *
 * An empty struct that acts as the type for `bilinear_algorithm`.
 */
struct bilinear_algorithm_tag_t {};


/**
 * @ingroup imgscalingtags
 * @brief Type for the cosine scaling algorithm tag
 *
 * An empty struct that acts as the type for `cosine_algorithm`.
 */
struct cosine_algorithm_tag_t {};


/**
 * @ingroup imgscalingtags
 * @brief Tag for nearest neigbour scaling
 *
 * When passed as an argument in the @ref scale function, it indicates that
 * said function must use the nearest-neighbour algorithm for scaling
 * images.
 */
constexpr nearest_neighbour_algorithm_tag_t nearest_neighbour_algorithm;


/**
 * @ingroup imgscalingtags
 * @brief Tag for bilinear scaling
 *
 * When passed as an argument in the @ref scale function, it indicates that
 * said function must use the bilinear algorithm for scaling images.
 */
constexpr bilinear_algorithm_tag_t bilinear_algorithm;


/**
 * @ingroup imgscalingtags
 * @brief Tag for cosine scaling
 *
 * When passed as an argument in the @ref scale function, it indicates that
 * said function must use the cosine algorithm for scaling images.
 */
constexpr cosine_algorithm_tag_t cosine_algorithm;


#ifndef DOXYGEN_SHOULD_SKIP_THIS

template <typename PixelType>
void scale(basic_image<PixelType>& img,const std::size_t& new_width,const std::size_t& new_height,nearest_neighbour_algorithm_tag_t)
{
	const std::size_t old_width = img.width();
	const std::size_t old_height = img.height();

	basic_image<PixelType> tmp(new_width,new_height,img.get_color_space());

	const double xratio = static_cast<double>(old_width)/static_cast<double>(new_width);
	const double yratio = static_cast<double>(old_height)/static_cast<double>(new_height);

	std::size_t ix;
	std::size_t iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(ix,iy) schedule(dynamic)
#endif
	for (iy = 0; iy < new_height; iy++)
	{
		for (ix = 0; ix < new_width; ix++)
		{
			std::size_t xpos = static_cast<std::size_t>(static_cast<double>(ix)*xratio);
			std::size_t ypos = static_cast<std::size_t>(static_cast<double>(iy)*yratio);
			
			tmp(ix,iy) = img(xpos,ypos);
		}
	}

	img = std::move(tmp);
}


template <typename PixelType>
void scale(basic_image<PixelType>& img,const rectangle& new_dimensions,nearest_neighbour_algorithm_tag_t)
{
	const std::size_t new_width = new_dimensions.width;
	const std::size_t new_height = new_dimensions.height;

	const std::size_t old_width = img.width();
	const std::size_t old_height = img.height();

	basic_image<PixelType> tmp(new_width,new_height,img.get_color_space());

	const double xratio = static_cast<double>(old_width)/static_cast<double>(new_width);
	const double yratio = static_cast<double>(old_height)/static_cast<double>(new_height);

	std::size_t ix;
	std::size_t iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(ix,iy) schedule(dynamic)
#endif
	for (iy = 0; iy < new_height; iy++)
	{
		for (ix = 0; ix < new_width; ix++)
		{
			std::size_t xpos = static_cast<std::size_t>(static_cast<double>(ix)*xratio);
			std::size_t ypos = static_cast<std::size_t>(static_cast<double>(iy)*yratio);
			
			tmp(ix,iy) = img(xpos,ypos);
		}
	}

	img = std::move(tmp);
}


template <typename PixelType>
void scale(basic_image<PixelType>& img,const std::size_t& new_width,const std::size_t& new_height,bilinear_algorithm_tag_t)
{
	const std::size_t old_width = img.width();
	const std::size_t old_height = img.height();

	basic_image<PixelType> tmp(new_width,new_height,img.get_color_space());

	const double xratio = static_cast<double>(old_width - 1)/static_cast<double>(new_width);
	const double yratio = static_cast<double>(old_height - 1)/static_cast<double>(new_height);

	std::size_t ix;
	std::size_t iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(ix,iy) schedule(dynamic)
#endif
	for (iy = 0; iy < new_height; iy++)
	{
		for (ix = 0; ix < new_width; ix++)
		{
			double xpos = static_cast<double>(ix)*xratio;
			double ypos = static_cast<double>(iy)*yratio;

			std::size_t ixp = static_cast<std::size_t>(xpos);
			std::size_t iyp = static_cast<std::size_t>(ypos);

			tmp(ix,iy) = detail::pix_lerp_2d(
				img(ixp    ,iyp    ),img(ixp    ,iyp + 1),
				img(ixp + 1,iyp    ),img(ixp + 1,iyp + 1),
				xpos - static_cast<double>(ixp),
				ypos - static_cast<double>(iyp)
			);
		}
	}

	img = std::move(tmp);
}


template <typename PixelType>
void scale(basic_image<PixelType>& img,const rectangle& new_dimensions,bilinear_algorithm_tag_t)
{
	const std::size_t new_width = new_dimensions.width;
	const std::size_t new_height = new_dimensions.height;

	const std::size_t old_width = img.width();
	const std::size_t old_height = img.height();

	basic_image<PixelType> tmp(new_width,new_height,img.get_color_space());

	const double xratio = static_cast<double>(old_width - 1)/static_cast<double>(new_width);
	const double yratio = static_cast<double>(old_height - 1)/static_cast<double>(new_height);

	std::size_t ix;
	std::size_t iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(ix,iy) schedule(dynamic)
#endif
	for (iy = 0; iy < new_height; iy++)
	{
		for (ix = 0; ix < new_width; ix++)
		{
			double xpos = static_cast<double>(ix)*xratio;
			double ypos = static_cast<double>(iy)*yratio;

			std::size_t ixp = static_cast<std::size_t>(xpos);
			std::size_t iyp = static_cast<std::size_t>(ypos);

			tmp(ix,iy) = detail::pix_lerp_2d(
				img(ixp    ,iyp    ),img(ixp    ,iyp + 1),
				img(ixp + 1,iyp    ),img(ixp + 1,iyp + 1),
				xpos - static_cast<double>(ixp),
				ypos - static_cast<double>(iyp)
			);
		}
	}

	img = std::move(tmp);
}


template <typename PixelType>
void scale(basic_image<PixelType>& img,const std::size_t& new_width,const std::size_t& new_height,cosine_algorithm_tag_t)
{
	const std::size_t old_width = img.width();
	const std::size_t old_height = img.height();

	basic_image<PixelType> tmp(new_width,new_height,img.get_color_space());

	const double xratio = static_cast<double>(old_width - 1)/static_cast<double>(new_width);
	const double yratio = static_cast<double>(old_height - 1)/static_cast<double>(new_height);

	std::size_t ix;
	std::size_t iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(ix,iy) schedule(dynamic)
#endif
	for (iy = 0; iy < new_height; iy++)
	{
		for (ix = 0; ix < new_width; ix++)
		{
			double xpos = static_cast<double>(ix)*xratio;
			double ypos = static_cast<double>(iy)*yratio;

			std::size_t ixp = static_cast<std::size_t>(xpos);
			std::size_t iyp = static_cast<std::size_t>(ypos);

			tmp(ix,iy) = detail::pix_citp_2d(
				img(ixp    ,iyp    ),img(ixp    ,iyp + 1),
				img(ixp + 1,iyp    ),img(ixp + 1,iyp + 1),
				xpos - static_cast<double>(ixp),
				ypos - static_cast<double>(iyp)
			);
		}
	}

	img = std::move(tmp);
}


template <typename PixelType>
void scale(basic_image<PixelType>& img,const rectangle& new_dimensions,cosine_algorithm_tag_t)
{
	const std::size_t new_width = new_dimensions.width;
	const std::size_t new_height = new_dimensions.height;

	const std::size_t old_width = img.width();
	const std::size_t old_height = img.height();

	basic_image<PixelType> tmp(new_width,new_height,img.get_color_space());

	const double xratio = static_cast<double>(old_width - 1)/static_cast<double>(new_width);
	const double yratio = static_cast<double>(old_height - 1)/static_cast<double>(new_height);

	std::size_t ix;
	std::size_t iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(ix,iy) schedule(dynamic)
#endif
	for (iy = 0; iy < new_height; iy++)
	{
		for (ix = 0; ix < new_width; ix++)
		{
			double xpos = static_cast<double>(ix)*xratio;
			double ypos = static_cast<double>(iy)*yratio;

			std::size_t ixp = static_cast<std::size_t>(xpos);
			std::size_t iyp = static_cast<std::size_t>(ypos);

			tmp(ix,iy) = detail::pix_citp_2d(
				img(ixp    ,iyp    ),img(ixp    ,iyp + 1),
				img(ixp + 1,iyp    ),img(ixp + 1,iyp + 1),
				xpos - static_cast<double>(ixp),
				ypos - static_cast<double>(iyp)
			);
		}
	}

	img = std::move(tmp);
}

#else // DOXYGEN_SHOULD_SKIP_THIS

/**
 * @ingroup transformations
 * @brief Image scaling
 *
 * Changes the dimensions of an image to another ones, using a scaling algorithm
 * (nearest neighbour, bilinear interpolation and cosine interpolation) that is
 * indicated by the `scaling_algorithm_tag` argument.
 *
 * @param img                   The image to resize.
 * @param new_width             The new width of the image.
 * @param new_height            The new height of the image.
 * @param scaling_algorithm_tag A @link imgscalingtags tag @endlink corresponding
 *                              to the desired scaling algorithm
 */
template <typename PixelType>
void scale(basic_image<PixelType>& img,const std::size_t& new_width,const std::size_t& new_height,/* type of tag */ scaling_algorithm_tag);


/**
 * @ingroup transformations
 * @brief Image scaling
 *
 * Changes the dimensions of an image to another ones, using a scaling algorithm
 * (nearest neighbour, bilinear interpolation and cosine interpolation) that is
 * indicated by the `scaling_algorithm_tag` argument.
 *
 * @param img                   The image to resize.
 * @param new_dimensions        The new dimensions of the image. Its `x` and `y`
 *                              members are ignored.
 * @param scaling_algorithm_tag A @link imgscalingtags tag @endlink corresponding
 *                              to the desired scaling algorithm
 */
template <typename PixelType>
void scale(basic_image<PixelType>& img,const rectangle& new_dimensions,/* type of tag */ scaling_algorithm_tag);

#endif // DOXYGEN_SHOULD_SKIP_THIS


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_UTILITIES_TRANSFORMATIONS_SCALE_HPP

