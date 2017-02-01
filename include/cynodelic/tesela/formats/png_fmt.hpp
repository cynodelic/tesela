// Copyright (c) 2017 Alvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_FORMATS_PNG_FMT_HPP
#define CYNODELIC_TESELA_FORMATS_PNG_FMT_HPP

#include "../internal.hpp"
#include "../types.hpp"

namespace cynodelic { namespace tesela {

namespace formats
{

class png_fmt
{
	public:
	const static void read(char* file_name,image& img)
	{
		png_structp png_ptr;
		png_infop info_ptr;
		FILE * in;
		std::size_t w, h; // Width and height
		unsigned bit_depth;
		unsigned col_type; // Color type
		
		if ((in = fopen(file_name,"rb")) == NULL)
		{
			std::cerr << "[cynodelic::tesela::formats::png_fmt::read] ERROR: Could not read " << file_name << ".\n";
			std::exit(EXIT_FAILURE);
		}
		
		std::uint8_t mn[8];
		fread(mn,1,8,in);
		if (png_sig_cmp(mn,0,8))
		{
			std::cerr << "[cynodelic::tesela::formats::png_fmt::read] ERROR: " << file_name << " is not a valid PNG file.\n";
			std::exit(EXIT_FAILURE);
		}
		
		png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,NULL,NULL,NULL);
		if (png_ptr == NULL)
		{
			std::cerr << "[cynodelic::tesela::formats::png_fmt::read] ERROR: Could not allocate read struct.\n";
			fclose(in);
			std::exit(EXIT_FAILURE);
		}
		
		info_ptr = png_create_info_struct(png_ptr);
		if (info_ptr == NULL)
		{
			std::cerr << "[cynodelic::tesela::formats::png_fmt::read] ERROR: Could not allocate info struct.\n";
			std::exit(EXIT_FAILURE);
		}
		
		if (setjmp(png_jmpbuf(png_ptr)))
		{
			std::cerr << "[cynodelic::tesela::formats::png_fmt::read] ERROR: Could not read image.\n";
			std::exit(EXIT_FAILURE);
		}
		
		png_init_io(png_ptr,in);
		png_set_sig_bytes(png_ptr,8);
		png_read_info(png_ptr,info_ptr);
		
		w = png_get_image_width(png_ptr,info_ptr);
		h = png_get_image_height(png_ptr,info_ptr);
		bit_depth = png_get_bit_depth(png_ptr,info_ptr);
		col_type = png_get_color_type(png_ptr,info_ptr);
		int num_passes = png_set_interlace_handling(png_ptr);
		
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
			std::cerr << "[cynodelic::tesela::formats::png_fmt::read] ERROR: Could not read image.\n";
			std::exit(EXIT_FAILURE);
		}
		
		std::size_t bpp = (std::size_t)png_get_rowbytes(png_ptr,info_ptr)/w;
		std::uint8_t *tmp_pix = new std::uint8_t[w*h*bpp];
		png_bytep rows[h];
		std::uint8_t *tp = tmp_pix;
		for (std::size_t i=0;i<h;i++)
		{
			rows[i] = tp;
			tp += w*bpp;
		}
		
		png_read_image(png_ptr,rows);
		fclose(in);
		
#ifdef CYNODELIC_TESELA_VERBOSE
		std::cout << "[cynodelic::tesela::formats::png_fmt::read] Reading PNG image...\n";
		std::cout << "Width: " << w << ", height: " << h << "\n";
		std::cout << "Bytes per pixel: " << bpp << "\n";
#endif
		
		img = image(w,h);
		
		switch (col_type)
		{
			case PNG_COLOR_TYPE_GRAY:
				img.color = color_mode::GRAY;
				break;
			case PNG_COLOR_TYPE_GRAY_ALPHA:
				img.color = color_mode::GA;
				break;
			case PNG_COLOR_TYPE_RGB:
				img.color = color_mode::RGB;
				break;
			case PNG_COLOR_TYPE_RGB_ALPHA:
				img.color = color_mode::RGBA;
				break;
		}
#ifdef CYNODELIC_TESELA_VERBOSE
		std::cout << "[cynodelic::tesela::formats::png_fmt::read] Color type: ";
		switch (img.color)
		{
			case color_mode::GRAY: std::cout << "Grayscale "; break;
			case color_mode::GA:   std::cout << "Grayscale + alpha "; break;
			case color_mode::RGB:  std::cout << "RGB "; break;
		        case color_mode::RGBA: std::cout << "RGBA "; break;
		}
		std::cout << "\n";
#endif
		
		for (std::size_t i=0;i<h;i++)
		{
			for (std::size_t j=0;j<w;j++)
			{
				std::size_t loc = w*i+j;
				if (col_type == PNG_COLOR_TYPE_GRAY)
				{
					img(j,i).r = img(j,i).g = img(j,i).b = tmp_pix[loc];
					img(j,i).a = std::uint8_t(CYNODELIC_TESELA_DEFAULT_ALPHA_FILL);
				}
				if (col_type == PNG_COLOR_TYPE_GRAY_ALPHA)
				{
					img(j,i).r = img(j,i).g = img(j,i).b = tmp_pix[loc*2];
					img(j,i).a = tmp_pix[2*loc+1];
				}
				if (col_type == PNG_COLOR_TYPE_RGB)
				{
					img(j,i).r = tmp_pix[3*loc  ];
					img(j,i).g = tmp_pix[3*loc+1];
					img(j,i).b = tmp_pix[3*loc+2];
					img(j,i).a = std::uint8_t(CYNODELIC_TESELA_DEFAULT_ALPHA_FILL);
				}
				if (col_type == PNG_COLOR_TYPE_RGB_ALPHA)
				{
					img(j,i).r = tmp_pix[4*loc  ];
					img(j,i).g = tmp_pix[4*loc+1];
					img(j,i).b = tmp_pix[4*loc+2];
					img(j,i).a = tmp_pix[4*loc+3];
				}
			}
		}
#ifdef CYNODELIC_TESELA_VERBOSE
		std::cout << "[cynodelic::tesela::formats::png_fmt::read] Done reading.\n";
#endif
	}
	const static void write(char* file_name,image& img)
	{
		FILE * out;
		png_structp png_ptr;
		png_infop info_ptr;
		png_bytep row;
		std::size_t w = img.width();
		std::size_t h = img.height();
		unsigned bit_depth = 8;
		unsigned col_type, bpp;
		switch (img.color)
		{
			case color_mode::GRAY: col_type = PNG_COLOR_TYPE_GRAY;       bpp = 1; break;
			case color_mode::GA:   col_type = PNG_COLOR_TYPE_GRAY_ALPHA; bpp = 4; break;
			case color_mode::RGB:  col_type = PNG_COLOR_TYPE_RGB;        bpp = 3; break;
			case color_mode::RGBA: col_type = PNG_COLOR_TYPE_RGB_ALPHA;  bpp = 4; break;
		}
		
#ifdef CYNODELIC_TESELA_VERBOSE
		std::cout << "[cynodelic::tesela::formats::png_fmt::write] Writing PNG file...\n";
		std::cout << "Number of pixels: " << w*h << "\n";
		std::cout << "Bit depth: " << bit_depth << "\n";
		std::cout << "Color type ID: " << col_type << "\n";
		std::cout << "Bytes per pixel: " << bpp << "\n";
#endif
		
		if ((out = fopen(file_name,"wb")) == NULL)
		{
			std::cerr << "[cynodelic::tesela::formats::png_fmt::write] ERROR: Could not create " << file_name << ".\n";
			std::exit(EXIT_FAILURE);
		}
		
		png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING,NULL,NULL,NULL);
		if (png_ptr == NULL)
		{
			std::cerr << "[cynodelic::tesela::formats::png_fmt::write] ERROR: Could not allocate write struct.\n";
			fclose(out);
			std::exit(EXIT_FAILURE);
		}
		
		info_ptr = png_create_info_struct(png_ptr);
		if (info_ptr == NULL)
		{
			std::cerr << "[cynodelic::tesela::formats::png_fmt::write] ERROR: Could not allocate info struct.\n";
			std::exit(EXIT_FAILURE);
		}
		
		if (setjmp(png_jmpbuf(png_ptr)))
		{
			std::cerr << "[cynodelic::tesela::formats::png_fmt::write] ERROR: Could not write image.\n";
			std::exit(EXIT_FAILURE);
		}
		
		png_init_io(png_ptr,out);
		
		png_set_IHDR(png_ptr,info_ptr,w,h,
			bit_depth,col_type,PNG_INTERLACE_NONE,
			PNG_COMPRESSION_TYPE_BASE,PNG_FILTER_TYPE_BASE);
		
		png_write_info(png_ptr,info_ptr);
		
		if (setjmp(png_jmpbuf(png_ptr)))
		{
			std::cerr << "[cynodelic::tesela::formats::png_fmt::write] ERROR: Could not write image.\n";
			std::exit(EXIT_FAILURE);
		}
		
		png_byte **row_ptrs;
		row_ptrs = (png_byte**)png_malloc(png_ptr,sizeof(png_byte*)*h);
		for (std::size_t i=0;i<h;i++)
		{
			png_byte *row;
			row = (png_byte*)png_malloc(png_ptr,sizeof(std::uint8_t)*w*bpp);
			row_ptrs[i] = row;
			for (std::size_t j=0;j<w;j++)
			{
				std::size_t loc = w*i+j;
				if (img.color == color_mode::GRAY)
				{
					*row++ = img(j,i).r;
				}
				if (img.color == color_mode::GA)
				{
					*row++ = img(j,i).r;
					*row++ = img(j,i).r;
					*row++ = img(j,i).r;
					*row++ = img(j,i).a;
				}
				if (img.color == color_mode::RGB)
				{
					*row++ = img(j,i).r;
					*row++ = img(j,i).g;
					*row++ = img(j,i).b;
				}
				if (img.color == color_mode::RGBA)
				{
					*row++ = img(j,i).r;
					*row++ = img(j,i).g;
					*row++ = img(j,i).b;
					*row++ = img(j,i).a;
				}
			}
		}
		
		png_init_io(png_ptr,out);
		png_set_rows(png_ptr,info_ptr,row_ptrs);
		png_write_png(png_ptr,info_ptr,PNG_TRANSFORM_IDENTITY,NULL);
		
		for (std::size_t i=0;i<h;i++)
			free(row_ptrs[i]);
		free(row_ptrs);
		
		fclose(out);
	}
};

} // end of "formats" namespace

}} // end of "cynodelic::tesela" namespace

#endif
