// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file type_cast_helpers.hpp
 *
 * @brief Helpers for `pixel_cast`
 */

#ifndef CYNODELIC_TESELA_DETAIL_TYPE_CAST_HELPERS_HPP
#define CYNODELIC_TESELA_DETAIL_TYPE_CAST_HELPERS_HPP


#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/detail/utils.hpp>
#include <cynodelic/tesela/rgb_types.hpp>
#include <cynodelic/tesela/rgba_types.hpp>
#include <cynodelic/tesela/gray_types.hpp>
#include <cynodelic/tesela/ga_types.hpp>


namespace cynodelic { namespace tesela {

namespace detail
{
	template <typename>
	struct pixel_cast_helper;

	template <>
	struct pixel_cast_helper<rgb_t>
	{
		static inline constexpr rgb_t call(const rgb_t& pix)
		{
			return pix;
		}
		
		static inline constexpr rgb_t call(const rgba_t& pix)
		{
			return rgb_t(pix.red,pix.green,pix.blue);
		}
		
		static inline constexpr rgb_t call(const gray_t& pix)
		{
			return rgb_t(pix.gray,pix.gray,pix.gray);
		}
		
		static inline constexpr rgb_t call(const ga_t& pix)
		{
			return rgb_t(pix.gray,pix.gray,pix.gray);
		}

		static inline constexpr rgb_t call(const nrgb_t& pix)
		{
			return rgb_t(
				dbl_to_u8(pix.red),
				dbl_to_u8(pix.green),
				dbl_to_u8(pix.blue)
			);
		}
		
		static inline constexpr rgb_t call(const nrgba_t& pix)
		{
			return rgb_t(
				dbl_to_u8(pix.red),
				dbl_to_u8(pix.green),
				dbl_to_u8(pix.blue)
			);
		}
		
		static inline constexpr rgb_t call(const ngray_t& pix)
		{
			return rgb_t(
				dbl_to_u8(pix.gray),
				dbl_to_u8(pix.gray),
				dbl_to_u8(pix.gray)
			);
		}
		
		static inline constexpr rgb_t call(const nga_t& pix)
		{
			return rgb_t(
				dbl_to_u8(pix.gray),
				dbl_to_u8(pix.gray),
				dbl_to_u8(pix.gray)
			);
		}
	};

	template <>
	struct pixel_cast_helper<nrgb_t>
	{
		static inline constexpr nrgb_t call(const rgb_t& pix)
		{
			return nrgb_t(
				u8_to_dbl(pix.red),
				u8_to_dbl(pix.green),
				u8_to_dbl(pix.blue)
			);
		}
		
		static inline constexpr nrgb_t call(const rgba_t& pix)
		{
			return nrgb_t(
				u8_to_dbl(pix.red),
				u8_to_dbl(pix.green),
				u8_to_dbl(pix.blue)
			);
		}
		
		static inline constexpr nrgb_t call(const gray_t& pix)
		{
			return nrgb_t(
				u8_to_dbl(pix.gray),
				u8_to_dbl(pix.gray),
				u8_to_dbl(pix.gray)
			);
		}
		
		static inline constexpr nrgb_t call(const ga_t& pix)
		{
			return nrgb_t(
				u8_to_dbl(pix.gray),
				u8_to_dbl(pix.gray),
				u8_to_dbl(pix.gray)
			);
		}
		
		static inline constexpr nrgb_t call(const nrgb_t& pix)
		{
			return pix;
		}
		
		static inline constexpr nrgb_t call(const nrgba_t& pix)
		{
			return nrgb_t(pix.red,pix.green,pix.blue);
		}
		
		static inline constexpr nrgb_t call(const ngray_t& pix)
		{
			return nrgb_t(pix.gray,pix.gray,pix.gray);
		}
		
		static inline constexpr nrgb_t call(const nga_t& pix)
		{
			return nrgb_t(pix.gray,pix.gray,pix.gray);
		}	
	};

	template <>
	struct pixel_cast_helper<rgba_t>
	{
		static inline constexpr rgba_t call(const rgb_t& pix)
		{
			return rgba_t(pix.red,pix.green,pix.blue,255);
		}

		static inline constexpr rgba_t call(const rgba_t& pix)
		{
			return pix;
		}

		static inline constexpr rgba_t call(const gray_t& pix)
		{
			return rgba_t(pix.gray,pix.gray,pix.gray,255);
		}

		static inline constexpr rgba_t call(const ga_t& pix)
		{
			return rgba_t(pix.gray,pix.gray,pix.gray,pix.alpha);
		}

		static inline constexpr rgba_t call(const nrgb_t& pix)
		{
			return rgba_t(
				dbl_to_u8(pix.red),
				dbl_to_u8(pix.green),
				dbl_to_u8(pix.blue),
				255
			);
		}

		static inline constexpr rgba_t call(const nrgba_t& pix)
		{
			return rgba_t(
				dbl_to_u8(pix.red),
				dbl_to_u8(pix.green),
				dbl_to_u8(pix.blue),
				dbl_to_u8(pix.alpha)
			);
		}

		static inline constexpr rgba_t call(const ngray_t& pix)
		{
			return rgba_t(
				dbl_to_u8(pix.gray),
				dbl_to_u8(pix.gray),
				dbl_to_u8(pix.gray),
				255
			);
		}

		static inline constexpr rgba_t call(const nga_t& pix)
		{
			return rgba_t(
				dbl_to_u8(pix.gray),
				dbl_to_u8(pix.gray),
				dbl_to_u8(pix.gray),
				dbl_to_u8(pix.alpha)
			);
		}
	};

	template <>
	struct pixel_cast_helper<nrgba_t>
	{
		static inline constexpr nrgba_t call(const rgb_t& pix)
		{
			return nrgba_t(
				u8_to_dbl(pix.red),
				u8_to_dbl(pix.green),
				u8_to_dbl(pix.blue),
				1.0
			);
		}
		
		static inline constexpr nrgba_t call(const rgba_t& pix)
		{
			return nrgba_t(
				u8_to_dbl(pix.red),
				u8_to_dbl(pix.green),
				u8_to_dbl(pix.blue),
				u8_to_dbl(pix.alpha)
			);
		}
		
		static inline constexpr nrgba_t call(const gray_t& pix)
		{
			return nrgba_t(
				u8_to_dbl(pix.gray),
				u8_to_dbl(pix.gray),
				u8_to_dbl(pix.gray),
				1.0
			);
		}
		
		static inline constexpr nrgba_t call(const ga_t& pix)
		{
			return nrgba_t(
				u8_to_dbl(pix.gray),
				u8_to_dbl(pix.gray),
				u8_to_dbl(pix.gray),
				u8_to_dbl(pix.alpha)
			);
		}
		
		static inline constexpr nrgba_t call(const nrgb_t& pix)
		{
			return nrgba_t(pix.red,pix.green,pix.blue,1.0);
		}
		
		static inline constexpr nrgba_t call(const nrgba_t& pix)
		{
			return pix;
		}
		
		static inline constexpr nrgba_t call(const ngray_t& pix)
		{
			return nrgba_t(pix.gray,pix.gray,pix.gray,1.0);
		}
		
		static inline constexpr nrgba_t call(const nga_t& pix)
		{
			return nrgba_t(pix.gray,pix.gray,pix.gray,pix.alpha);
		}
	};

	template <>
	struct pixel_cast_helper<gray_t>
	{
		static inline constexpr gray_t call(const rgb_t& pix)
		{
			tdouble gray_res{0.2126*u8_to_dbl(pix.red) + 0.7152*u8_to_dbl(pix.green) + 0.0722*u8_to_dbl(pix.blue)};

			return gray_t(dbl_to_u8(gray_res.get()));
		}
		
		static inline constexpr gray_t call(const rgba_t& pix)
		{
			tdouble gray_res{0.2126*u8_to_dbl(pix.red) + 0.7152*u8_to_dbl(pix.green) + 0.0722*u8_to_dbl(pix.blue)};

			return gray_t(dbl_to_u8(gray_res.get()));
		}
		
		static inline constexpr gray_t call(const gray_t& pix)
		{
			return pix;
		}
		
		static inline constexpr gray_t call(const ga_t& pix)
		{
			return gray_t(pix.gray);
		}
		
		static inline constexpr gray_t call(const nrgb_t& pix)
		{
			tdouble gray_res{0.2126*pix.red.get() + 0.7152*pix.green.get() + 0.0722*pix.blue.get()};

			return gray_t(dbl_to_u8(gray_res.get()));
		}
		
		static inline constexpr gray_t call(const nrgba_t& pix)
		{
			tdouble gray_res{0.2126*pix.red.get() + 0.7152*pix.green.get() + 0.0722*pix.blue.get()};

			return gray_t(dbl_to_u8(gray_res.get()));
		}
		
		static inline constexpr gray_t call(const ngray_t& pix)
		{
			return gray_t(
				dbl_to_u8(pix.gray)
			);
		}
		
		static inline constexpr gray_t call(const nga_t& pix)
		{
			return gray_t(
				dbl_to_u8(pix.gray)
			);
		}
	};

	template <>
	struct pixel_cast_helper<ngray_t>
	{
		static inline constexpr ngray_t call(const rgb_t& pix)
		{
			tdouble gray_res{0.2126*u8_to_dbl(pix.red) + 0.7152*u8_to_dbl(pix.green) + 0.0722*u8_to_dbl(pix.blue)};

			return ngray_t(gray_res);
		}
		
		static inline constexpr ngray_t call(const rgba_t& pix)
		{
			tdouble gray_res{0.2126*u8_to_dbl(pix.red) + 0.7152*u8_to_dbl(pix.green) + 0.0722*u8_to_dbl(pix.blue)};

			return ngray_t(gray_res);
		}
		
		static inline constexpr ngray_t call(const gray_t& pix)
		{
			return ngray_t(
				u8_to_dbl(pix.gray)
			);
		}
		
		static inline constexpr ngray_t call(const ga_t& pix)
		{
			return ngray_t(
				u8_to_dbl(pix.gray)
			);
		}
		
		static inline constexpr ngray_t call(const nrgb_t& pix)
		{
			tdouble gray_res{0.2126*pix.red.get() + 0.7152*pix.green.get() + 0.0722*pix.blue.get()};

			return ngray_t(gray_res);
		}
		
		static inline constexpr ngray_t call(const nrgba_t& pix)
		{
			tdouble gray_res{0.2126*pix.red.get() + 0.7152*pix.green.get() + 0.0722*pix.blue.get()};

			return ngray_t(gray_res);
		}
		
		static inline constexpr ngray_t call(const ngray_t& pix)
		{
			return pix;
		}
		
		static inline constexpr ngray_t call(const nga_t& pix)
		{
			return ngray_t(pix.gray);
		}
	};

	template <>
	struct pixel_cast_helper<ga_t>
	{
		static inline constexpr ga_t call(const rgb_t& pix)
		{
			tdouble gray_res{0.2126*u8_to_dbl(pix.red) + 0.7152*u8_to_dbl(pix.green) + 0.0722*u8_to_dbl(pix.blue)};

			return ga_t(dbl_to_u8(gray_res),255);
		}
		
		static inline constexpr ga_t call(const rgba_t& pix)
		{
			tdouble gray_res{0.2126*u8_to_dbl(pix.red) + 0.7152*u8_to_dbl(pix.green) + 0.0722*u8_to_dbl(pix.blue)};

			return ga_t(dbl_to_u8(gray_res),pix.alpha);
		}

		static inline constexpr ga_t call(const gray_t& pix)
		{
			return ga_t(pix.gray,255);
		}

		static inline constexpr ga_t call(const ga_t& pix)
		{
			return pix;
		}
		
		static inline constexpr ga_t call(const nrgb_t& pix)
		{
			tdouble gray_res{0.2126*pix.red.get() + 0.7152*pix.green.get() + 0.0722*pix.blue.get()};

			return ga_t(dbl_to_u8(gray_res),255);
		}
		
		static inline constexpr ga_t call(const nrgba_t& pix)
		{
			tdouble gray_res{0.2126*pix.red.get() + 0.7152*pix.green.get() + 0.0722*pix.blue.get()};

			return ga_t(
				dbl_to_u8(gray_res),
				dbl_to_u8(pix.alpha)
			);
		}
		
		static inline constexpr ga_t call(const ngray_t& pix)
		{
			return ga_t(
				dbl_to_u8(pix.gray),
				255
			);
		}

		static inline constexpr ga_t call(const nga_t& pix)
		{
			return ga_t(
				dbl_to_u8(pix.gray),
				dbl_to_u8(pix.alpha)
			);
		}
	};

	template <>
	struct pixel_cast_helper<nga_t>
	{
		static inline constexpr nga_t call(const rgb_t& pix)
		{
			tdouble gray_res{0.2126*u8_to_dbl(pix.red) + 0.7152*u8_to_dbl(pix.green) + 0.0722*u8_to_dbl(pix.blue)};

			return nga_t(gray_res,1.0);
		}

		static inline constexpr nga_t call(const rgba_t& pix)
		{
			tdouble gray_res{0.2126*u8_to_dbl(pix.red) + 0.7152*u8_to_dbl(pix.green) + 0.0722*u8_to_dbl(pix.blue)};

			return nga_t(
				gray_res,
				u8_to_dbl(pix.alpha)
			);
		}

		static inline constexpr nga_t call(const gray_t& pix)
		{
			return nga_t(
				u8_to_dbl(pix.gray),
				1.0
			);
		}

		static inline constexpr nga_t call(const ga_t& pix)
		{
			return nga_t(
				u8_to_dbl(pix.gray),
				u8_to_dbl(pix.alpha)
			);
		}

		static inline constexpr nga_t call(const nrgb_t& pix)
		{
			tdouble gray_res{0.2126*pix.red.get() + 0.7152*pix.green.get() + 0.0722*pix.blue.get()};

			return nga_t(gray_res,1.0);
		}

		static inline constexpr nga_t call(const nrgba_t& pix)
		{
			tdouble gray_res{0.2126*pix.red.get() + 0.7152*pix.green.get() + 0.0722*pix.blue.get()};

			return nga_t(gray_res,pix.alpha);
		}

		static inline constexpr nga_t call(const ngray_t& pix)
		{
			return nga_t(pix.gray,1.0);
		}

		static inline constexpr nga_t call(const nga_t& pix)
		{
			return pix;
		}
	};
} // end of "detail" namespace

}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_DETAIL_TYPE_CAST_HELPERS_HPP
