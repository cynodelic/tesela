// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file tiff_io.hpp
 *
 * @brief Defines a TIFF input/output type.
 */

#ifndef CYNODELIC_TESELA_FORMATS_TIFF_IO_HPP
#define CYNODELIC_TESELA_FORMATS_TIFF_IO_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <string>
#include <regex>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/exceptions/io_error.hpp>
#include <cynodelic/tesela/rgba_types.hpp>
#include <cynodelic/tesela/image_types.hpp>
#include <cynodelic/tesela/type_casts.hpp>


extern "C"
{
#include <tiff.h>
#include <tiffio.h>
#include <tiffconf.h>
}


namespace cynodelic { namespace tesela {


/**
 * @ingroup imageio
 * @brief TIFF input/output.
 *
 * Reads and writes TIFF files.
 */
class tiff_io
{
	public:
		/**
		 * @brief Parameter type for `tiff_io`
		 *
		 * Class that holds parameters for the TIFF image format.
		 */
		class param_type
		{
			public:
				enum class compression : unsigned
				{
					none    = COMPRESSION_NONE,
					deflate = COMPRESSION_DEFLATE,
					jpeg    = COMPRESSION_JPEG,
					lzw     = COMPRESSION_LZW
				};


				param_type() :
					compression_mode_(compression::none)
				{}


				/**
				 * @brief Compression mode
				 *
				 * Sets the compression mode.
				 */
				param_type& compression_mode(const compression& val)
				{
					compression_mode_ = val;

					return *this;
				}
				

				compression get_compression_mode() const
				{
					return compression_mode_;
				}
			private:
				compression compression_mode_;
		};


		/**
		 * @brief Regex type
		 *
		 * The type of syntax used for the image file extension's regular expression.
		 */
		static constexpr std::regex_constants::syntax_option_type regex_syntax = std::regex_constants::ECMAScript;


		/**
		 * @brief Extension regex.
		 *
		 * Regular expression for this image format.
		 */
		static constexpr const char *file_extension_regex = "(.*)\\.([T|t][I|i][F|f][F|f]?)";

		
		/**
		 * @brief Reads a TIFF file.
		 *
		 * Reads a TIFF image file into an @ref image.
		 *
		 * @param file_name File name.
		 * @param img       The output.
		 */
		template <typename PixelType>
		static void read(const std::string& file_name,basic_image<PixelType>& img)
		{
			char *nocv_file_name = strdup(file_name.c_str());

			uint32 width_  = 0;
			uint32 height_ = 0;
			unsigned short bps, spp;
			TIFF *in = TIFFOpen(nocv_file_name,"r");
			uint32 *raster;
			
			if (in == NULL)
			{
				throw io_error(std::string("[cynodelic::tesela::tiff_io::read] The file ") + file_name + std::string(" could not be opened."));
			}
			
			unsigned short ort;
			TIFFGetField(in,TIFFTAG_IMAGEWIDTH,&width_);
			TIFFGetField(in,TIFFTAG_IMAGELENGTH,&height_);
			TIFFGetField(in,TIFFTAG_SAMPLESPERPIXEL,&spp);
			TIFFGetField(in,TIFFTAG_BITSPERSAMPLE,&bps);
			TIFFGetField(in,TIFFTAG_ORIENTATION,&ort);

			rgba_image in_img(width_,height_);

			switch (spp)
			{
				case 4:
					in_img.write_with_color_space(color_space::rgba);
					break;
				case 3:
					in_img.write_with_color_space(color_space::rgb);
					break;
				case 1:
					in_img.write_with_color_space(color_space::gray);
					break;
			}
			
			std::size_t npixels = width_*height_;

			if ((raster = (uint32*)_TIFFmalloc(npixels*sizeof(uint32))) == NULL)
			{
				throw io_error("[cynodelic::tesela::tiff_io::read] The input buffer could not be allocated.");
			}
			
			TIFFReadRGBAImage(in,width_,height_,raster,0);
			std::size_t px, py;
			for (std::size_t i = 0; i < height_; i++)
			{
				for (std::size_t j = 0; j < width_; j++)
				{
					std::size_t loc = width_*i + j;
					px = j;
					py = height_ - 1 - i;
					in_img(px,py).red   = static_cast<std::uint8_t>(TIFFGetR(raster[loc]));
					in_img(px,py).green = static_cast<std::uint8_t>(TIFFGetG(raster[loc]));
					in_img(px,py).blue  = static_cast<std::uint8_t>(TIFFGetB(raster[loc]));
					in_img(px,py).alpha = static_cast<std::uint8_t>(TIFFGetA(raster[loc]));
				}
			}
			_TIFFfree(raster);
			TIFFClose(in);

			img = std::move(image_cast<PixelType>(in_img));
		}

		/**
		 * @brief Writes a TIFF file.
		 *
		 * Writes an @ref image into a TIFF image file.
		 *
		 * @param file_name File name.
		 * @param img       The input.
		 * @param param     The parameters.
		 */
		template <typename PixelType>
		static void write(const std::string& file_name,const basic_image<PixelType>& img,param_type param = param_type{})
		{
			char *nocv_file_name = strdup(file_name.c_str());

			uint32 width_  = static_cast<uint32>(img.width());
			uint32 height_ = static_cast<uint32>(img.height());
			TIFF *out = TIFFOpen(nocv_file_name,"w");
			unsigned spp;
			
			if (out == NULL)
			{
				throw io_error(std::string("[cynodelic::tesela::tiff_io::write] The file ") + file_name + std::string(" could not be created."));
			}

			unsigned cmp_type = static_cast<unsigned>(param.get_compression_mode());

			switch (img.get_color_space())
			{
				case color_space::rgba: spp = 4; break;
				case color_space::rgb : spp = 4; break;
				case color_space::gray: spp = 1; break;
				case color_space::ga  : spp = 4; break;
			}

			std::uint32_t *img_buff;
			std::uint8_t  *img_buff_gs;

			TIFFSetField(out,TIFFTAG_IMAGEWIDTH,width_);
			TIFFSetField(out,TIFFTAG_IMAGELENGTH,height_);
			TIFFSetField(out,TIFFTAG_SAMPLESPERPIXEL,spp);
			TIFFSetField(out,TIFFTAG_BITSPERSAMPLE,8);
			TIFFSetField(out,TIFFTAG_ORIENTATION,ORIENTATION_TOPLEFT);
			TIFFSetField(out,TIFFTAG_PLANARCONFIG,PLANARCONFIG_CONTIG);
			TIFFSetField(out,TIFFTAG_COMPRESSION,cmp_type);

			rgba_image out_img = image_cast<rgba_t>(img);

			if (spp == 1)
				TIFFSetField(out,TIFFTAG_PHOTOMETRIC,PHOTOMETRIC_MINISBLACK);
			else
				TIFFSetField(out,TIFFTAG_PHOTOMETRIC,PHOTOMETRIC_RGB);
			
			//std::size_t bsiz = w*h*spp;
			std::size_t npix = width_*height_;

			if (out_img.get_color_space() == color_space::gray)
				img_buff_gs = new std::uint8_t[npix];
			else
				img_buff = new std::uint32_t[npix];

			//tsize_t linebytes = spp*w;
			//tsize_t tss = TIFFScanlineSize(out);

			if (out_img.get_color_space() == color_space::gray)
			{
				for (std::size_t i = 0; i < npix; i++)
				{
					std::size_t px = i%width_, py = i/width_;
					img_buff_gs[i]  = out_img(px,py).red;
				}
			}
			else if (out_img.get_color_space() == color_space::rgb)
			{
				for (std::size_t i = 0; i < npix; i++)
				{
					std::size_t px = i%width_, py = i/width_;
					img_buff[i]  = static_cast<std::uint32_t>(out_img(px,py).red);
					img_buff[i] |= static_cast<std::uint32_t>(out_img(px,py).green) << 8;
					img_buff[i] |= static_cast<std::uint32_t>(out_img(px,py).blue) << 16;
					img_buff[i] |= 0xff000000;
				}
			}
			else if (out_img.get_color_space() == color_space::ga || out_img.get_color_space() == color_space::rgba)
			{
				for (std::size_t i = 0; i < npix; i++)
				{
					std::size_t px = i%width_, py = i/width_;
					img_buff[i]  = static_cast<std::uint32_t>(out_img(px,py).red);
					img_buff[i] |= static_cast<std::uint32_t>(out_img(px,py).green) << 8;
					img_buff[i] |= static_cast<std::uint32_t>(out_img(px,py).blue) << 16;
					img_buff[i] |= static_cast<std::uint32_t>(out_img(px,py).alpha) << 24;
				}
			}

			
			if (out_img.get_color_space() == color_space::gray)
			{
				if (TIFFWriteEncodedStrip(out,0,&img_buff_gs[0],npix) == -1)
				{
					throw io_error(std::string("[cynodelic::tesela::tiff_io::write] The ") + file_name + std::string(" file cannot be written."));
				}
			}
			else
			{
				if (TIFFWriteEncodedStrip(out,0,&img_buff[0],width_*height_*4) == -1)
				{
					throw io_error(std::string("[cynodelic::tesela::tiff_io::write] The ") + file_name + std::string(" file cannot be written."));
				}
			}
			
			TIFFClose(out);
		}
};

constexpr std::regex_constants::syntax_option_type tiff_io::regex_syntax;


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_FORMATS_TIFF_IO_HPP
