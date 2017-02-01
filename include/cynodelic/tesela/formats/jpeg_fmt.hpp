// Copyright (c) 2017 Alvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_FORMATS_JPEG_FMT_HPP
#define CYNODELIC_TESELA_FORMATS_JPEG_FMT_HPP

#include "../internal.hpp"
#include "../types.hpp"

namespace cynodelic { namespace tesela {

namespace formats
{

struct tesela_error_mgr
{
	struct jpeg_error_mgr pub;
	std::jmp_buf setjmp_buffer;
};

METHODDEF(void) tesela_error_exit(j_common_ptr cinfo)
{
	tesela_error_mgr* err = (tesela_error_mgr*)cinfo->err;
	(*cinfo->err->output_message)(cinfo);
	std::longjmp(err->setjmp_buffer,1);
}

class jpeg_fmt
{
	public:
	const static void read(char* file_name,image& img)
	{
		struct jpeg_decompress_struct cinfo;
		struct tesela_error_mgr jerr;
		FILE * in;
		JSAMPARRAY buffer;
		int row_stride;
		
		if ((in = fopen(file_name,"rb")) == NULL)
		{
			std::cerr << "[cynodelic::tesela::formats::jpeg_fmt::read] ERROR: Cannot open " << file_name << ".\n";
			std::exit(EXIT_FAILURE);
		}
		
		cinfo.err = jpeg_std_error(&jerr.pub);
		jerr.pub.error_exit = tesela_error_exit;
		if (setjmp(jerr.setjmp_buffer))
		{
			jpeg_destroy_decompress(&cinfo);
			fclose(in);
			std::exit(EXIT_FAILURE);
		}
		
		jpeg_create_decompress(&cinfo);
		jpeg_stdio_src(&cinfo,in);
		(void)jpeg_read_header(&cinfo,TRUE);
		
		(void)jpeg_start_decompress(&cinfo);
		row_stride = cinfo.output_width*cinfo.output_components;
		
		img = image(cinfo.output_width,cinfo.output_height);
		if      (cinfo.output_components == 3) img.color = color_mode::RGB;
		else if (cinfo.output_components == 1) img.color = color_mode::GRAY;
		
		int buff_height = 1;
		buffer = (JSAMPARRAY)malloc(sizeof(JSAMPROW)*buff_height);
		buffer[0] = (JSAMPROW)malloc(sizeof(JSAMPLE)*row_stride);
		
		std::uint8_t* tmp_pix = new std::uint8_t[cinfo.output_width*cinfo.output_height*cinfo.output_components];
		std::size_t counter = 0;
		while (cinfo.output_scanline < cinfo.output_height)
		{
			jpeg_read_scanlines(&cinfo,buffer,1);
			memcpy(tmp_pix+counter,buffer[0],row_stride);
			counter += row_stride;
		}
#ifdef CYNODELIC_TESELA_VERBOSE
		std::cout << "[cynodelic::tesela::formats::jpeg_fmt::read] Reading JPEG image...\n";
		std::cout << "Width: " << cinfo.output_width << ", height: " << cinfo.output_height << "\n";
		std::cout << "Color mode: ";
		if      (img.color == color_mode::RGB ) std::cout << "RGB";
		else if (img.color == color_mode::GRAY) std::cout << "Grayscale";
		std::cout << "\n";
#endif
		
		for (std::size_t i=0;i<cinfo.output_height;i++)
		{
			for (std::size_t j=0;j<cinfo.output_width;j++)
			{
				std::size_t loc = cinfo.output_width*i+j;
				if (cinfo.output_components == 3)
				{
					img(j,i).r = tmp_pix[3*loc  ];
					img(j,i).g = tmp_pix[3*loc+1];
					img(j,i).b = tmp_pix[3*loc+2];
					img(j,i).a = std::uint8_t(CYNODELIC_TESELA_DEFAULT_ALPHA_FILL);
				}
				else
				{
					img(j,i).r = img(j,i).g = img(j,i).b =  tmp_pix[loc];
					img(j,i).a = std::uint8_t(CYNODELIC_TESELA_DEFAULT_ALPHA_FILL);
				}
			}
		}
		
		(void)jpeg_finish_decompress(&cinfo);
		jpeg_destroy_decompress(&cinfo);
		fclose(in);
	}
	const static void write(char* file_name,image& img)
	{
		std::size_t w = img.width();
		std::size_t h = img.height();
		char* fn = file_name;
		struct jpeg_compress_struct cinfo;
		struct jpeg_error_mgr jerr;
		FILE * out;
		JSAMPROW row_ptr;
		int row_stride;
		
		cinfo.err = jpeg_std_error(&jerr);
		jpeg_create_compress(&cinfo);
		
		if ((out = fopen(fn,"wb")) == NULL)
		{
			std::cerr << "[cynodelic::tesela::formats::jpeg_fmt::write] ERROR: Cannot open " << file_name << ".\n";
			std::exit(EXIT_FAILURE);
		}
		jpeg_stdio_dest(&cinfo,out);
		
		cinfo.image_width = w;
		cinfo.image_height = h;
		switch (img.color)
		{
			case color_mode::RGB :
				cinfo.input_components = 3;
				cinfo.in_color_space = JCS_RGB;
				break;
			case color_mode::GRAY:
				cinfo.input_components = 1;
				cinfo.in_color_space = JCS_GRAYSCALE;
				break;
			default:
				std::cerr << "[cynodelic::tesela::formats::jpeg_fmt::write] ERROR: Colorspace is not valid for JPEG images." << std::endl;
				std::exit(EXIT_FAILURE);
		}
		jpeg_set_defaults(&cinfo);
		jpeg_set_quality(&cinfo,CYNODELIC_TESELA_DEFAULT_JPEG_QUALITY,TRUE);
		
#ifdef CYNODELIC_TESELA_VERBOSE
		std::cout << "[cynodelic::tesela::formats::jpeg_fmt::write] Writing JPEG image...\n";
		std::cout << "Image width: " << cinfo.image_width << "\n";
		std::cout << "Image height: " << cinfo.image_height << "\n";
		std::cout << "Input components (bytes per pixel): " << cinfo.input_components << "\n";
		std::cout << "Number of components: " << cinfo.num_components << "\n";
		std::cout << "Buffer size: " << w*h*cinfo.input_components << "\n";
#endif
		
		std::uint8_t *img_buffer = new std::uint8_t[w*h*cinfo.input_components];
		
		for (std::size_t iy=0;iy<h;iy++)
		{
			for (std::size_t ix=0;ix<w;ix++)
			{
				std::size_t pix_idx = (w*iy+ix)*cinfo.input_components;
				if (cinfo.input_components == 3)
				{
					img_buffer[pix_idx+0] = img(ix,iy).r;
					img_buffer[pix_idx+1] = img(ix,iy).g;
					img_buffer[pix_idx+2] = img(ix,iy).b;
				}
				else
					img_buffer[pix_idx] = img(ix,iy).r;
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
		fclose(out);
		jpeg_destroy_compress(&cinfo);
	}
};

} // end of "formats" namespace

}} // end of "cynodelic::tesela" namespace

#endif
