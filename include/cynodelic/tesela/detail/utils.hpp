// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file utils.hpp
 *
 * @brief Internal functions and constants.
 */

#ifndef CYNODELIC_TESELA_DETAIL_UTILS_HPP
#define CYNODELIC_TESELA_DETAIL_UTILS_HPP


#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <cmath>

#include <cynodelic/tesela/config.hpp>


namespace cynodelic { namespace tesela {

namespace detail
{
	/**
	 * @brief Pi
	 */
	static constexpr double pi = 3.1415926535897932384626433832795;

	/**
	 * @brief Floor function
	 *
	 * Compile-time floor function.
	 */
	template <typename T>
	inline constexpr T dfloor_cx(const double& x)
	{
		return static_cast<T>(static_cast<long long>(x));
	}


	/**
	 * @brief Double-precision to 8-bit integer conversion
	 *
	 * Converts a `double` value, ranging from 0 to 1, to an 8-bit value
	 * (`std::uint8_t`) ranging from 0 to 255.
	 * 
	 */
	inline constexpr std::uint8_t dbl_to_u8(const double& x)
	{
		return dfloor_cx<std::uint8_t>(x*255.0);
	}


	/**
	 * @brief 8-bit integer to double-precision conversion
	 *
	 * Converts an 8-bit value, ranging from 0 to 255, to a `double` value,
	 * ranging from 0 to 1.
	 */
	inline constexpr double u8_to_dbl(const std::uint8_t& x)
	{
		return static_cast<double>(x)/255.0;
	}

	/**
	 * @brief Limits a value within a range
	 */
	template <typename T>
	inline constexpr T clip(const T& x,const T& a,const T& b)
	{
		return (x < a) ? a : ((x > b) ? b : x);
	}

	/**
	 * @brief Two-dimensional Gaussian function
	 */
	inline double gaussian_2d(const double& x,const double& y,const double& sigma)
	{
		return std::exp(-(x*x + y*y)/(2.0*sigma*sigma))/(2.0*pi*sigma*sigma);
	}

	/**
	 * @brief Linear interpolation function
	 */
	double linear_interpolate(const double& x,const double& y,const double& fct)
	{
		return x*(1.0 - fct) + y*fct;
	}

	/**
	 * @brief Two-dimensional linear interpolation function
	 */
	double linear_interpolate_2d(const double& x00,const double& x01,const double& x10,const double& x11,const double& fctx,const double& fcty)
	{
		return (
			x00*(1.0 - fctx)*(1.0 - fcty) +
			x01*fctx*(1.0 - fcty) +
			x10*(1.0 - fctx)*fcty +
			x11*fctx*fcty
		);
	}

	/**
	 * @brief Cosine interpolation function
	 */
	double cosine_interpolate(const double& x,const double& y,const double& fct)
	{
		const double csfct = (1.0 - std::cos(fct*pi))/2.0;
		
		return x*(1.0 - csfct) + y*csfct;
	}

	/**
	 * @brief Cosine interpolation function
	 */
	double cosine_interpolate_2d(const double& x00,const double& x01,const double& x10,const double& x11,const double& fctx,const double& fcty)
	{
		const double csfctx = (1.0 - std::cos(fctx*pi))/2.0;
		const double csfcty = (1.0 - std::cos(fcty*pi))/2.0;
		
		return (
			x00*(1.0 - csfctx)*(1.0 - csfcty) +
			x01*csfctx*(1.0 - csfcty) +
			x10*(1.0 - csfctx)*csfcty +
			x11*csfctx*csfcty
		);
	}
} // end of "detail" namespace

}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_DETAIL_UTILS_HPP
