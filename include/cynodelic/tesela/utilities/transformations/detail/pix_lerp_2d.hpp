// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/** 
 * @file pix_lerp_2d.hpp
 *
 * @brief Defines the `pix_lerp_2d` function.
 */

#ifndef CYNODELIC_TESELA_UTILITIES_TRANSFORMATIONS_DETAIL_PIX_LERP_2D_HPP
#define CYNODELIC_TESELA_UTILITIES_TRANSFORMATIONS_DETAIL_PIX_LERP_2D_HPP


#include <cstdlib>
#include <cstddef>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/detail/utils.hpp>
#include <cynodelic/tesela/rgb_types.hpp>
#include <cynodelic/tesela/rgba_types.hpp>
#include <cynodelic/tesela/gray_types.hpp>
#include <cynodelic/tesela/ga_types.hpp>


namespace cynodelic { namespace tesela {

namespace detail
{
	/**
	 * @brief Two-dimensional linear interpolation function for pixel types
	 */
	inline rgb_t pix_lerp_2d(
		const rgb_t& pix_00,
		const rgb_t& pix_01,
		const rgb_t& pix_10,
		const rgb_t& pix_11,
		const double& fctx,
		const double& fcty
	)
	{
		return rgb_t(
			dbl_to_u8(
				linear_interpolate_2d(
					u8_to_dbl(pix_00.red),
					u8_to_dbl(pix_01.red),
					u8_to_dbl(pix_10.red),
					u8_to_dbl(pix_11.red),
					fctx,fcty
				)
			),
			dbl_to_u8(
				linear_interpolate_2d(
					u8_to_dbl(pix_00.green),
					u8_to_dbl(pix_01.green),
					u8_to_dbl(pix_10.green),
					u8_to_dbl(pix_11.green),
					fctx,fcty
				)
			),
			dbl_to_u8(
				linear_interpolate_2d(
					u8_to_dbl(pix_00.blue),
					u8_to_dbl(pix_01.blue),
					u8_to_dbl(pix_10.blue),
					u8_to_dbl(pix_11.blue),
					fctx,fcty
				)
			)
		);
	}

	
	/**
	 * @brief Two-dimensional linear interpolation function for pixel types
	 */
	inline rgba_t pix_lerp_2d(
		const rgba_t& pix_00,
		const rgba_t& pix_01,
		const rgba_t& pix_10,
		const rgba_t& pix_11,
		const double& fctx,
		const double& fcty
	)
	{
		return rgba_t(
			dbl_to_u8(
				linear_interpolate_2d(
					u8_to_dbl(pix_00.red),
					u8_to_dbl(pix_01.red),
					u8_to_dbl(pix_10.red),
					u8_to_dbl(pix_11.red),
					fctx,fcty
				)
			),
			dbl_to_u8(
				linear_interpolate_2d(
					u8_to_dbl(pix_00.green),
					u8_to_dbl(pix_01.green),
					u8_to_dbl(pix_10.green),
					u8_to_dbl(pix_11.green),
					fctx,fcty
				)
			),
			dbl_to_u8(
				linear_interpolate_2d(
					u8_to_dbl(pix_00.blue),
					u8_to_dbl(pix_01.blue),
					u8_to_dbl(pix_10.blue),
					u8_to_dbl(pix_11.blue),
					fctx,fcty
				)
			),
			dbl_to_u8(
				linear_interpolate_2d(
					u8_to_dbl(pix_00.alpha),
					u8_to_dbl(pix_01.alpha),
					u8_to_dbl(pix_10.alpha),
					u8_to_dbl(pix_11.alpha),
					fctx,fcty
				)
			)
		);
	}

	
	/**
	 * @brief Two-dimensional linear interpolation function for pixel types
	 */
	inline gray_t pix_lerp_2d(
		const gray_t& pix_00,
		const gray_t& pix_01,
		const gray_t& pix_10,
		const gray_t& pix_11,
		const double& fctx,
		const double& fcty
	)
	{
		return gray_t(
			dbl_to_u8(
				linear_interpolate_2d(
					u8_to_dbl(pix_00.gray),
					u8_to_dbl(pix_01.gray),
					u8_to_dbl(pix_10.gray),
					u8_to_dbl(pix_11.gray),
					fctx,fcty
				)
			)
		);
	}

	
	/**
	 * @brief Two-dimensional linear interpolation function for pixel types
	 */
	inline ga_t pix_lerp_2d(
		const ga_t& pix_00,
		const ga_t& pix_01,
		const ga_t& pix_10,
		const ga_t& pix_11,
		const double& fctx,
		const double& fcty
	)
	{
		return ga_t(
			dbl_to_u8(
				linear_interpolate_2d(
					u8_to_dbl(pix_00.gray),
					u8_to_dbl(pix_01.gray),
					u8_to_dbl(pix_10.gray),
					u8_to_dbl(pix_11.gray),
					fctx,fcty
				)
			),
			dbl_to_u8(
				linear_interpolate_2d(
					u8_to_dbl(pix_00.alpha),
					u8_to_dbl(pix_01.alpha),
					u8_to_dbl(pix_10.alpha),
					u8_to_dbl(pix_11.alpha),
					fctx,fcty
				)
			)
		);
	}

	
	/**
	 * @brief Two-dimensional linear interpolation function for pixel types
	 */
	inline nrgb_t pix_lerp_2d(
		const nrgb_t& pix_00,
		const nrgb_t& pix_01,
		const nrgb_t& pix_10,
		const nrgb_t& pix_11,
		const double& fctx,
		const double& fcty
	)
	{
		return nrgb_t(
			linear_interpolate_2d(
				pix_00.red.get(),
				pix_01.red.get(),
				pix_10.red.get(),
				pix_11.red.get(),
				fctx,fcty
			),
			linear_interpolate_2d(
				pix_00.green.get(),
				pix_01.green.get(),
				pix_10.green.get(),
				pix_11.green.get(),
				fctx,fcty
			),
			linear_interpolate_2d(
				pix_00.blue.get(),
				pix_01.blue.get(),
				pix_10.blue.get(),
				pix_11.blue.get(),
				fctx,fcty
			)
		);
	}

	
	/**
	 * @brief Two-dimensional linear interpolation function for pixel types
	 */
	inline nrgba_t pix_lerp_2d(
		const nrgba_t& pix_00,
		const nrgba_t& pix_01,
		const nrgba_t& pix_10,
		const nrgba_t& pix_11,
		const double& fctx,
		const double& fcty
	)
	{
		return nrgba_t(
			linear_interpolate_2d(
				pix_00.red.get(),
				pix_01.red.get(),
				pix_10.red.get(),
				pix_11.red.get(),
				fctx,fcty
			),
			linear_interpolate_2d(
				pix_00.green.get(),
				pix_01.green.get(),
				pix_10.green.get(),
				pix_11.green.get(),
				fctx,fcty
			),
			linear_interpolate_2d(
				pix_00.blue.get(),
				pix_01.blue.get(),
				pix_10.blue.get(),
				pix_11.blue.get(),
				fctx,fcty
			),
			linear_interpolate_2d(
				pix_00.alpha.get(),
				pix_01.alpha.get(),
				pix_10.alpha.get(),
				pix_11.alpha.get(),
				fctx,fcty
			)
		);
	}

	
	/**
	 * @brief Two-dimensional linear interpolation function for pixel types
	 */
	inline ngray_t pix_lerp_2d(
		const ngray_t& pix_00,
		const ngray_t& pix_01,
		const ngray_t& pix_10,
		const ngray_t& pix_11,
		const double& fctx,
		const double& fcty
	)
	{
		return ngray_t(
			linear_interpolate_2d(
				pix_00.gray.get(),
				pix_01.gray.get(),
				pix_10.gray.get(),
				pix_11.gray.get(),
				fctx,fcty
			)
		);
	}

	
	/**
	 * @brief Two-dimensional linear interpolation function for pixel types
	 */
	inline nga_t pix_lerp_2d(
		const nga_t& pix_00,
		const nga_t& pix_01,
		const nga_t& pix_10,
		const nga_t& pix_11,
		const double& fctx,
		const double& fcty
	)
	{
		return nga_t(
			linear_interpolate_2d(
				pix_00.gray.get(),
				pix_01.gray.get(),
				pix_10.gray.get(),
				pix_11.gray.get(),
				fctx,fcty
			),
			linear_interpolate_2d(
				pix_00.alpha.get(),
				pix_01.alpha.get(),
				pix_10.alpha.get(),
				pix_11.alpha.get(),
				fctx,fcty
			)
		);
	}
}

}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_UTILITIES_TRANSFORMATIONS_DETAIL_PIX_LERP_2D_HPP

