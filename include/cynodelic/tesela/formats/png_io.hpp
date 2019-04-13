// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file png_io.hpp
 *
 * @brief Defines a PNG input/output helper type.
 */

#ifndef CYNODELIC_TESELA_FORMATS_PNG_IO_HPP
#define CYNODELIC_TESELA_FORMATS_PNG_IO_HPP


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
#include <zlib.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#define PNG_SKIP_SETJMP_CHECK // Avoids "__pngconf.h__ in libpng..." errors
#define PNG_DEBUG 3
#endif

#include <png.h>
}


namespace cynodelic { namespace tesela {


/**
 * @ingroup imageio
 * @brief PNG input/output.
 *
 * Reads and writes PNG files.
 */
class png_io
{
	public:
		/**
		 * @brief Parameter type for `png_io`
		 *
		 * Class that holds parameters for the PNG image format.
		 */
		class param_type
		{
			public:
				enum class interlace : int
				{
					none  = PNG_INTERLACE_NONE,
					adam7 = PNG_INTERLACE_ADAM7
				};
				

				enum class row_filter : int
				{
					none  = PNG_FILTER_NONE,
					sub   = PNG_FILTER_SUB,
					up    = PNG_FILTER_UP,
					avg   = PNG_FILTER_AVG,
					paeth = PNG_FILTER_PAETH
				};
				

				enum class cmp_strategy : int
				{
					default_     = Z_DEFAULT_STRATEGY,
					filtered     = Z_FILTERED,
					huffman_only = Z_HUFFMAN_ONLY,
					rle          = Z_RLE
				};
				

				param_type() :
					interlacing_(interlace::none),
					row_filtering_(row_filter::none),
					compression_level_(1),
					compression_strategy_(cmp_strategy::default_)
				{}


				/**
				 * @brief Interlacing mode
				 */
				param_type& interlacing(const interlace& val)
				{
					interlacing_ = val;

					return *this;
				}


				/**
				 * @brief Compression level
				 *
				 * Sets the compression level, between 0 and 9.
				 */
				param_type& compression_level(const int& val)
				{
					if (val < 0 || val > 9)
						throw std::invalid_argument("[cynodelic::tesela::png_io::param_type::compression_level] The compression level must be between 0 and 9");

					compression_level_ = val; // 0-9

					return *this;
				}


				/**
				 * @brief Compression strategy
				 */
				param_type& compression_strategy(const cmp_strategy& val)
				{
					compression_strategy_ = val;

					return *this;
				}


				/**
				 * @brief Row filtering
				 */
				param_type& row_filtering(const row_filter& val)
				{
					row_filtering_ = val;

					return *this;
				}

				interlace get_interlacing() const
				{
					return interlacing_;
				}

				int get_compression_level() const
				{
					return compression_level_;
				}

				cmp_strategy get_compression_strategy() const
				{
					return compression_strategy_;
				}

				row_filter get_row_filtering() const
				{
					return row_filtering_;
				}
			private:
				interlace    interlacing_;
				row_filter   row_filtering_;
				int          compression_level_;
				cmp_strategy compression_strategy_;
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
		static constexpr const char *file_extension_regex = "(.*)\\.([P|p][N|n][G|g])";

		
		/**
		 * @brief Reads a PNG file.
		 *
		 * Reads a PNG image file into an @ref image.
		 *
		 * @param file_name File name.
		 * @param img       The output.
		 */
		template <typename PixelType>
		static void read(const std::string& file_name,basic_image<PixelType>& img)
		{
			char *nocv_file_name = strdup(file_name.c_str());

			png_structp  png_ptr;
			png_infop    info_ptr;
			std::FILE*   in;
			std::size_t  w, h; // Width and height
			unsigned     bit_depth;
			unsigned     col_type; // Color type
			
			if ((in = std::fopen(nocv_file_name,"rb")) == NULL)
			{
				throw io_error(std::string("[cynodelic::tesela::png_io::read] The file ") + file_name + std::string(" could not be opened."));
			}
			
			std::uint8_t mn[8];
			std::fread(mn,1,8,in);
			if (png_sig_cmp(mn,0,8))
			{
				throw io_error(std::string("[cynodelic::tesela::png_io::read] ") + file_name + std::string(" is not a valid PNG file."));
			}
			
			png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,NULL,NULL,NULL);
			if (png_ptr == NULL)
			{
				std::fclose(in);
				throw io_error("[cynodelic::tesela::png_io::read] The \'read\' struct could not be allocated.");
			}
			
			info_ptr = png_create_info_struct(png_ptr);
			if (info_ptr == NULL)
			{
				throw io_error("[cynodelic::tesela::png_io::read] The \'info\' struct could not be allocated.");
			}
			
			if (setjmp(png_jmpbuf(png_ptr)))
			{
				throw io_error(std::string("[cynodelic::tesela::png_io::read] The file ") + file_name + std::string(" could not be read."));
			}
			
			png_init_io(png_ptr,in);
			png_set_sig_bytes(png_ptr,8);
			png_read_info(png_ptr,info_ptr);
			
			w = png_get_image_width(png_ptr,info_ptr);
			h = png_get_image_height(png_ptr,info_ptr);
			bit_depth = png_get_bit_depth(png_ptr,info_ptr);
			col_type = png_get_color_type(png_ptr,info_ptr);
			//int num_passes = png_set_interlace_handling(png_ptr);
			
			if (bit_depth == 16)                    png_set_strip_16(png_ptr);
			if (col_type == PNG_COLOR_TYPE_PALETTE) png_set_palette_to_rgb(png_ptr);
			if (col_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
				png_set_expand_gray_1_2_4_to_8(png_ptr);
			if (png_get_valid(png_ptr,info_ptr,PNG_INFO_tRNS))
				png_set_tRNS_to_alpha(png_ptr);
			png_set_interlace_handling(png_ptr);
			
			png_read_update_info(png_ptr,info_ptr);
			
			if (setjmp(png_jmpbuf(png_ptr)))
			{
				throw io_error(std::string("[cynodelic::tesela::png_io::read] The file ") + file_name + std::string(" could not be read."));
			}
			
			std::size_t bpp = (std::size_t)png_get_rowbytes(png_ptr,info_ptr)/w;
			std::uint8_t* tmp_pix = new std::uint8_t[w*h*bpp];
			//png_bytep rows[h];
			png_bytep* rows = new png_bytep[h];
			std::uint8_t* tp = tmp_pix;
			for (std::size_t i=0;i<h;i++)
			{
				rows[i] = tp;
				tp += w*bpp;
			}
			
			png_read_image(png_ptr,rows);
			std::fclose(in);
			
			rgba_image in_img(w,h);
			
			switch (col_type)
			{
				case PNG_COLOR_TYPE_GRAY:
					in_img.write_with_color_space(color_space::gray);
					break;
				case PNG_COLOR_TYPE_GRAY_ALPHA:
					in_img.write_with_color_space(color_space::ga);
					break;
				case PNG_COLOR_TYPE_RGB:
					in_img.write_with_color_space(color_space::rgb);
					break;
				case PNG_COLOR_TYPE_RGB_ALPHA:
					in_img.write_with_color_space(color_space::rgba);
					break;
			}


			if (col_type == PNG_COLOR_TYPE_GRAY)
			{
				for (std::size_t i = 0; i < h; i++)
				{
					for (std::size_t j = 0; j < w; j++)
					{
						std::size_t loc = w*i+j;
						in_img(j,i).red = in_img(j,i).green = in_img(j,i).blue = tmp_pix[loc];
						in_img(j,i).alpha = 255;
					}
				}
			}
			else if (col_type == PNG_COLOR_TYPE_GRAY_ALPHA)
			{
				for (std::size_t i = 0; i < h; i++)
				{
					for (std::size_t j = 0; j < w; j++)
					{
						std::size_t loc = w*i+j;
						in_img(j,i).red = in_img(j,i).green = in_img(j,i).blue = tmp_pix[loc*2];
						in_img(j,i).alpha = tmp_pix[2*loc+1];
					}
				}
			}
			else if (col_type == PNG_COLOR_TYPE_RGB)
			{
				for (std::size_t i = 0; i < h; i++)
				{
					for (std::size_t j = 0; j < w; j++)
					{
						std::size_t loc = w*i+j;
						in_img(j,i).red   = tmp_pix[3*loc  ];
						in_img(j,i).green = tmp_pix[3*loc+1];
						in_img(j,i).blue  = tmp_pix[3*loc+2];
						in_img(j,i).alpha = 255;
					}
				}
			}
			else if (col_type == PNG_COLOR_TYPE_RGB_ALPHA)
			{
				for (std::size_t i = 0; i < h; i++)
				{
					for (std::size_t j = 0; j < w; j++)
					{
						std::size_t loc = w*i+j;
						in_img(j,i).red   = tmp_pix[4*loc  ];
						in_img(j,i).green = tmp_pix[4*loc+1];
						in_img(j,i).blue  = tmp_pix[4*loc+2];
						in_img(j,i).alpha = tmp_pix[4*loc+3];
					}
				}
			}

			delete [] tmp_pix;
			delete [] rows;

			img = std::move(image_cast<PixelType>(in_img));
		}
		
		/**
		 * @brief Writes a PNG file.
		 *
		 * Writes an @ref image into a PNG image file.
		 *
		 * @param file_name File name.
		 * @param img       The input.
		 * @param param     The parameters.
		 */
		template <typename PixelType>
		static void write(const std::string& file_name,const basic_image<PixelType>& img,param_type param = param_type{})
		{
			char *nocv_file_name = strdup(file_name.c_str());

			std::FILE*   out;
			png_structp  png_ptr;
			png_infop    info_ptr;
			std::size_t  w = img.width();
			std::size_t  h = img.height();
			unsigned     bit_depth = 8;
			unsigned     col_type, bpp;

			int interlacing     = static_cast<int>(param.get_interlacing());
			int compression_lvl = param.get_compression_level();
			int filtering       = static_cast<int>(param.get_row_filtering());
			int cmp_strategy    = static_cast<int>(param.get_compression_strategy());

			switch (img.get_color_space())
			{
				case color_space::gray: col_type = PNG_COLOR_TYPE_GRAY;       bpp = 1; break;
				case color_space::ga:   col_type = PNG_COLOR_TYPE_GRAY_ALPHA; bpp = 2; break;
				case color_space::rgb:  col_type = PNG_COLOR_TYPE_RGB;        bpp = 3; break;
				case color_space::rgba: col_type = PNG_COLOR_TYPE_RGB_ALPHA;  bpp = 4; break;
			}

			rgba_image out_img = image_cast<rgba_t>(img);
			
			if ((out = std::fopen(nocv_file_name,"wb")) == NULL)
			{
				throw io_error(std::string("[cynodelic::tesela::png_io::write] The ") + file_name + std::string(" file could not be created."));
			}
			
			png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING,NULL,NULL,NULL);
			if (png_ptr == NULL)
			{
				std::fclose(out);
				throw io_error("[cynodelic::tesela::png_io::write] The \'write\' struct could not be allocated.");
			}
			
			info_ptr = png_create_info_struct(png_ptr);
			if (info_ptr == NULL)
			{
				throw io_error("[cynodelic::tesela::png_io::write] The \'info\' struct could not be allocated.");
			}
			
			if (setjmp(png_jmpbuf(png_ptr)))
			{
				throw io_error(std::string("[cynodelic::tesela::png_io::write] The ") + file_name + std::string(" file cannot be written."));
			}
			
			png_init_io(png_ptr,out);
			
			png_set_filter(png_ptr,0,filtering);
			png_set_compression_level(png_ptr,compression_lvl);
			png_set_compression_strategy(png_ptr,cmp_strategy);
			png_set_IHDR(
				png_ptr,info_ptr,w,h,
				bit_depth,col_type,
				interlacing,
				PNG_COMPRESSION_TYPE_DEFAULT,
				PNG_FILTER_TYPE_DEFAULT
			);

			
			png_write_info(png_ptr,info_ptr);
			
			if (setjmp(png_jmpbuf(png_ptr)))
			{
				throw io_error(std::string("[cynodelic::tesela::png_io::write] The ") + file_name + std::string(" file cannot be written."));
			}
			
			png_byte **row_ptrs;
			row_ptrs = (png_byte**)png_malloc(png_ptr,sizeof(png_byte*)*h);

			if (out_img.get_color_space() == color_space::gray)
			{
				for (std::size_t i = 0; i < h; i++)
				{
					png_byte *row;
					row = (png_byte*)png_malloc(png_ptr,sizeof(std::uint8_t)*w*bpp);
					row_ptrs[i] = row;
					for (std::size_t j=0;j<w;j++)
					{
						*row++ = out_img(j,i).red;
					}
				}
			}
			else if (out_img.get_color_space() == color_space::ga)
			{
				for (std::size_t i = 0; i < h; i++)
				{
					png_byte *row;
					row = (png_byte*)png_malloc(png_ptr,sizeof(std::uint8_t)*w*bpp);
					row_ptrs[i] = row;
					for (std::size_t j=0;j<w;j++)
					{
						*row++ = out_img(j,i).red;
						*row++ = out_img(j,i).alpha;
					}
				}
			}
			else if (out_img.get_color_space() == color_space::rgb)
			{
				for (std::size_t i = 0; i < h; i++)
				{
					png_byte *row;
					row = (png_byte*)png_malloc(png_ptr,sizeof(std::uint8_t)*w*bpp);
					row_ptrs[i] = row;
					for (std::size_t j=0;j<w;j++)
					{
						*row++ = out_img(j,i).red;
						*row++ = out_img(j,i).green;
						*row++ = out_img(j,i).blue;
					}
				}
			}
			else if (out_img.get_color_space() == color_space::rgba)
			{
				for (std::size_t i = 0; i < h; i++)
				{
					png_byte *row;
					row = (png_byte*)png_malloc(png_ptr,sizeof(std::uint8_t)*w*bpp);
					row_ptrs[i] = row;
					for (std::size_t j=0;j<w;j++)
					{
						*row++ = out_img(j,i).red;
						*row++ = out_img(j,i).green;
						*row++ = out_img(j,i).blue;
						*row++ = out_img(j,i).alpha;
					}
				}
			}
			
			png_init_io(png_ptr,out);
			png_set_rows(png_ptr,info_ptr,row_ptrs);
			png_write_png(png_ptr,info_ptr,PNG_TRANSFORM_IDENTITY,NULL);
			
			for (std::size_t i=0;i<h;i++)
				std::free(row_ptrs[i]);
			std::free(row_ptrs);
			
			std::fclose(out);
		}
};

constexpr std::regex_constants::syntax_option_type png_io::regex_syntax;


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_FORMATS_PNG_IO_HPP
