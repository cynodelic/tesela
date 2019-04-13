// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file jpeg_io.hpp
 *
 * @brief Defines a JPEG input/output helper type.
 */

#ifndef CYNODELIC_TESELA_FORMATS_JPEG_IO_HPP
#define CYNODELIC_TESELA_FORMATS_JPEG_IO_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <csetjmp>
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
#include <jpeglib.h>
}


namespace cynodelic { namespace tesela {


/**
 * @ingroup imageio
 * @brief JPEG input/output.
 *
 * Reads and writes JPEG files.
 */
class jpeg_io
{
	private:
		struct jerror_mgr_
		{
			jpeg_error_mgr pub;
			std::jmp_buf   setjmp_buffer;
		};

		METHODDEF(void) error_exit_(j_common_ptr cinfo)
		{
			jerror_mgr_ *err = (jerror_mgr_*)cinfo->err;
			(*cinfo->err->output_message)(cinfo);
			std::longjmp(err->setjmp_buffer,1);
		}
	public:
		/**
		 * @brief Parameter type for `jpeg_io`
		 *
		 * Class that holds parameters for the JPEG image format.
		 */
		class param_type
		{
			public:
				param_type() :
					quality_(95),
					force_baseline_(true),
					optimized_(false),
					progressive_(false),
					dct_method_(JDCT_ISLOW)
				{}


				/**
				 * @brief Quality
				 *
				 * Sets the quality of the output JPEG file, between 1 and 100.
				 */
				param_type& quality(const int& val)
				{
					if (val < 1 || val > 100)
					{
						throw std::invalid_argument("[cynodelic::tesela::jpeg_io::param_type::quality] The quality for JPEG images must be between 1 and 100.");
					}

					quality_ = val;

					return *this;
				}


				/**
				 * @brief Force baseline
				 */
				param_type& force_baseline(const bool& val)
				{
					force_baseline_ = val;

					return *this;
				}


				/**
				 * @brief Encoding optimization
				 *
				 * Allows the encoder to generate optimal Huffman coding tables for the image.
				 */
				param_type& optimized(const bool& val)
				{
					optimized_ = val;

					return *this;
				}


				/**
				 * @brief Write as progressive
				 *
				 * Makes the encoder to generate a scan script for writing the image as a
				 * progressive-JPEG file.
				 */
				param_type& progressive(const bool& val)
				{
					progressive_ = val;

					return *this;
				}

				
				/**
				 * @brief DCT method
				 *
				 * Selects the algorithm for the DCT step.
				 */
				param_type& dct_method(const J_DCT_METHOD& val)
				{
					dct_method_ = val;

					return *this;
				}

				
				int get_quality() const
				{
					return quality_;
				}

				
				bool get_force_baseline() const
				{
					return force_baseline_;
				}

				
				bool get_optimized() const
				{
					return optimized_;
				}

				
				bool get_progressive() const
				{
					return progressive_;
				}

				
				J_DCT_METHOD get_dct_method() const
				{
					return dct_method_;
				}
			private:
				int          quality_;
				bool         force_baseline_;
				bool         optimized_;
				bool         progressive_;
				J_DCT_METHOD dct_method_;
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
		static constexpr const char *file_extension_regex = "(.*)\\.([J|j][P|p][E|e]?[G|g])";


		/**
		 * @brief Reads a JPEG file.
		 *
		 * Reads a JPEG image file into an @ref image.
		 *
		 * @param file_name File name.
		 * @param img       The image.
		 */
		template <typename PixelType>
		static void read(const std::string& file_name,basic_image<PixelType>& img)
		{
			char *nocv_file_name = strdup(file_name.c_str());

			jpeg_decompress_struct  cinfo;
			jerror_mgr_             jerr;
			std::FILE*              in;
			JSAMPARRAY              buffer;
			int                     row_stride;
			
			if ((in = std::fopen(nocv_file_name,"rb")) == NULL)
			{
				throw io_error(std::string("[cynodelic::tesela::jpeg_io::read] The file ") + std::string(file_name) + std::string(" could not be opened."));
			}
			
			cinfo.err = jpeg_std_error(&jerr.pub);
			jerr.pub.error_exit = error_exit_;

			if (setjmp(jerr.setjmp_buffer))
			{
				jpeg_destroy_decompress(&cinfo);
				std::fclose(in);
				throw io_error("[cynodelic::tesela::jpeg_io::read] An error ocurred during JPEG image opening.");
			}
			
			jpeg_create_decompress(&cinfo);
			jpeg_stdio_src(&cinfo,in);
			(void)jpeg_read_header(&cinfo,TRUE);
			
			(void)jpeg_start_decompress(&cinfo);
			row_stride = cinfo.output_width*cinfo.output_components;
			
			rgba_image in_img(cinfo.output_width,cinfo.output_height);
			if (cinfo.output_components == 3)
				in_img.write_with_color_space(color_space::rgb);
			else if (cinfo.output_components == 1)
				in_img.write_with_color_space(color_space::gray);
			
			int buff_height = 1;
			buffer    = (JSAMPARRAY)std::malloc(sizeof(JSAMPROW)*buff_height);
			buffer[0] = (JSAMPROW)std::malloc(sizeof(JSAMPLE)*row_stride);
			
			std::uint8_t* tmp_pix = new std::uint8_t[cinfo.output_width*cinfo.output_height*cinfo.output_components];
			std::size_t   counter = 0;

			while (cinfo.output_scanline < cinfo.output_height)
			{
				jpeg_read_scanlines(&cinfo,buffer,1);
				std::memcpy(tmp_pix+counter,buffer[0],row_stride);
				counter += row_stride;
			}

			if (cinfo.output_components == 3)
			{
				for (std::size_t i = 0; i < cinfo.output_height ;i++)
				{
					for (std::size_t j = 0; j < cinfo.output_width; j++)
					{
						std::size_t loc = cinfo.output_width*i + j;

						in_img(j,i).red   = tmp_pix[3*loc    ];
						in_img(j,i).green = tmp_pix[3*loc + 1];
						in_img(j,i).blue  = tmp_pix[3*loc + 2];
						in_img(j,i).alpha = 255;
					}
				}
			}
			else
			{
				for (std::size_t i = 0; i < cinfo.output_height ;i++)
				{
					for (std::size_t j = 0; j < cinfo.output_width; j++)
					{
						std::size_t loc = cinfo.output_width*i + j;

						in_img(j,i).red = in_img(j,i).green = in_img(j,i).blue =  tmp_pix[loc];
						in_img(j,i).alpha = 255;
					}
				}
			}
			
			
			(void)jpeg_finish_decompress(&cinfo);
			jpeg_destroy_decompress(&cinfo);
			std::fclose(in);

			delete [] tmp_pix;

			img = std::move(image_cast<PixelType>(in_img));
		}
		
		/**
		 * @brief Writes a JPEG file.
		 *
		 * Writes an @ref image into a JPEG image file.
		 *
		 * @param file_name File name.
		 * @param img       The input.
		 * @param param     The parameters.
		 */
		template <typename PixelType>
		static void write(const std::string& file_name,const basic_image<PixelType>& img,param_type param = param_type{})
		{
			if (img.get_color_space() == color_space::rgba || img.get_color_space() == color_space::ga)
			{
				throw std::invalid_argument("[cynodelic::tesela::jpeg_io::write] The image's color space is not valid for JPEG images.");
			}

			rgb_image out_img = image_cast<rgb_t>(img);
			
			char *nocv_file_name = strdup(file_name.c_str());

			std::size_t w = out_img.width();
			std::size_t h = out_img.height();

			jpeg_compress_struct cinfo;
			jpeg_error_mgr       jerr;
			std::FILE*           out;
			JSAMPROW             row_ptr;
			int                  row_stride;

			int           quality        = param.get_quality();
			bool          force_baseline = param.get_force_baseline();
			bool          optimized      = param.get_optimized();
			bool          progressive    = param.get_progressive();
			J_DCT_METHOD  dct_method     = param.get_dct_method();

			cinfo.err = jpeg_std_error(&jerr);
			jpeg_create_compress(&cinfo);
			
			if ((out = std::fopen(nocv_file_name,"wb")) == NULL)
			{
				throw io_error(std::string("[cynodelic::tesela::jpeg_io::write] The ") + file_name + std::string(" file could not be created."));
			}
			jpeg_stdio_dest(&cinfo,out);
			
			cinfo.image_width  = w;
			cinfo.image_height = h;

			if (out_img.get_color_space() == color_space::rgb)
			{
				cinfo.input_components = 3;
				cinfo.in_color_space   = JCS_RGB;
			}
			else if (out_img.get_color_space() == color_space::gray)
			{
				cinfo.input_components = 1;
				cinfo.in_color_space   = JCS_GRAYSCALE;
			}

			jpeg_set_defaults(&cinfo);

			jpeg_set_quality(&cinfo,quality,force_baseline ? TRUE : FALSE);

			if (optimized)
				cinfo.optimize_coding = TRUE;

			cinfo.dct_method = dct_method;

			if (progressive)
				jpeg_simple_progression(&cinfo);
			
			std::uint8_t *img_buffer = new std::uint8_t[w*h*cinfo.input_components];

			if (cinfo.input_components == 3)
			{
				for (std::size_t iy = 0; iy < h; iy++)
				{
					for (std::size_t ix = 0; ix < w; ix++)
					{
						std::size_t pix_idx = (w*iy + ix)*cinfo.input_components;

						img_buffer[pix_idx    ] = out_img(ix,iy).red;
						img_buffer[pix_idx + 1] = out_img(ix,iy).green;
						img_buffer[pix_idx + 2] = out_img(ix,iy).blue;
					}
				}
			}
			else
			{
				for (std::size_t iy = 0; iy < h; iy++)
				{
					for (std::size_t ix = 0; ix < w; ix++)
					{
						std::size_t pix_idx = (w*iy + ix)*cinfo.input_components;

						img_buffer[pix_idx] = out_img(ix,iy).red;
					}
				}
			}
			
			jpeg_start_compress(&cinfo,TRUE);
			row_stride = w*cinfo.input_components;
			
			while (cinfo.next_scanline < cinfo.image_height)
			{
				row_ptr = (JSAMPROW)&img_buffer[cinfo.next_scanline*row_stride];
				(void)jpeg_write_scanlines(&cinfo,&row_ptr,1);
			}
			
			jpeg_finish_compress(&cinfo);
			std::fclose(out);
			jpeg_destroy_compress(&cinfo);

			delete [] img_buffer;
		}
};

constexpr std::regex_constants::syntax_option_type jpeg_io::regex_syntax;


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_FORMATS_JPEG_IO_HPP
