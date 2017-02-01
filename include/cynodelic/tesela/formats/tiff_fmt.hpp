// Copyright (c) 2017 Alvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_FORMATS_TIFF_FMT_HPP
#define CYNODELIC_TESELA_FORMATS_TIFF_FMT_HPP

#include "../internal.hpp"
#include "../types.hpp"

namespace cynodelic { namespace tesela {

namespace formats
{

class tiff_fmt
{
	public:
	const static int read(char* file_name,image& img)
	{
		std::size_t w, h;
		unsigned short bps, spp;
		TIFF * in = TIFFOpen(file_name,"r");
		uint32* raster;
		
		if (in == NULL)
		{
			std::cerr << "[cynodelic::tesela::formats::tiff_fmt::read] ERROR: Could not read " << file_name << ".\n";
			std::exit(EXIT_FAILURE);
		}
		
		unsigned short ort;
		TIFFGetField(in,TIFFTAG_IMAGEWIDTH,&w);
		TIFFGetField(in,TIFFTAG_IMAGELENGTH,&h);
		TIFFGetField(in,TIFFTAG_SAMPLESPERPIXEL,&spp);
		TIFFGetField(in,TIFFTAG_BITSPERSAMPLE,&bps);
		TIFFGetField(in,TIFFTAG_ORIENTATION,&ort);
		img = image(w,h);
		switch (spp)
		{
			case 4: img.color = color_mode::RGBA; break;
			case 3: img.color = color_mode::RGB ; break;
			case 1: img.color = color_mode::GRAY; break;
		}
		
#ifdef CYNODELIC_TESELA_VERBOSE
		std::cout << "[cynodelic::tesela::formats::tiff_fmt::read] Reading TIFF file...\n";
		std::cout << "Width: " << w << ", height: " << h << "\n";
		std::cout << "Samples per pixel: " << spp << "\n";
		std::cout << "Bits per sample: " << bps << "\n";
		std::cout << "Orientation: " << ort << "\n";
#endif
		
		std::size_t npixels = w*h;
#ifdef CYNODELIC_TESELA_VERBOSE
		std::cout << "Number of pixels: " << npixels << "\n";
#endif
		if ((raster = (uint32*) _TIFFmalloc(npixels*sizeof(uint32))) == NULL)
		{
			std::cerr << "[cynodelic::tesela::formats::tiff_fmt::read] ERROR: Could not allocate buffer.\n";
			std::exit(EXIT_FAILURE);
		}
		
		TIFFReadRGBAImage(in,w,h,raster,0);
		std::size_t px, py;
		for (std::size_t i=0;i<h;i++)
		{
			for (std::size_t j=0;j<w;j++)
			{
				std::size_t loc = w*i+j;
				px = j;
				py = h-1-i;
				img(px,py).r = std::uint8_t(TIFFGetR(raster[loc]));
				img(px,py).g = std::uint8_t(TIFFGetG(raster[loc]));
				img(px,py).b = std::uint8_t(TIFFGetB(raster[loc]));
				img(px,py).a = std::uint8_t(TIFFGetA(raster[loc]));
			}
		}
		_TIFFfree(raster);
		TIFFClose(in);
	}
	
	const static void write(char* file_name,image& img)
	{
		std::size_t w = img.width(), h = img.height();
		TIFF * out = TIFFOpen(file_name,"w");
		unsigned spp;
		switch (img.color)
		{
			case color_mode::RGBA: spp = 4; break;
			case color_mode::RGB : spp = 4; break;
			case color_mode::GRAY: spp = 1; break;
			case color_mode::GA  : spp = 4; break;
		}
		std::uint32_t *img_buff;
		std::uint8_t *img_buff_gs;
		TIFFSetField(out,TIFFTAG_IMAGEWIDTH,w);
		TIFFSetField(out,TIFFTAG_IMAGELENGTH,h);
		TIFFSetField(out,TIFFTAG_SAMPLESPERPIXEL,spp);
		TIFFSetField(out,TIFFTAG_BITSPERSAMPLE,8);
		TIFFSetField(out,TIFFTAG_ORIENTATION,ORIENTATION_TOPLEFT);
		TIFFSetField(out,TIFFTAG_PLANARCONFIG,PLANARCONFIG_CONTIG);
		TIFFSetField(out,TIFFTAG_COMPRESSION,COMPRESSION_DEFLATE);
		if (spp == 1)
			TIFFSetField(out,TIFFTAG_PHOTOMETRIC,PHOTOMETRIC_MINISBLACK);
		else
			TIFFSetField(out,TIFFTAG_PHOTOMETRIC,PHOTOMETRIC_RGB);
		
		std::size_t bsiz = w*h*spp, npix = w*h;
		if (img.color == color_mode::GRAY)
			img_buff_gs = new std::uint8_t[npix];
		else
			img_buff = new std::uint32_t[npix];
		tsize_t linebytes = spp*w;
		tsize_t tss = TIFFScanlineSize(out);
#ifdef CYNODELIC_TESELA_VERBOSE
		std::cout << "[cynodelic::tesela::formats::tiff_fmt::write] Writing TIFF file...\n";
		std::cout << "Samples per pixel (channels): " << spp << "\n";
		std::cout << "Bytes per line: "  << linebytes << "\n";
		std::cout << "Number of pixels: " << w*h << "\n";
		std::cout << "Number of image bytes: " << bsiz << "\n";
#endif
		for (std::size_t i=0;i<npix;i++)
		{
			std::size_t px = i%w, py = i/w;
			if (img.color == color_mode::GRAY)
			{
				img_buff_gs[i]  = img(px,py).r;
			}
			else if (img.color == color_mode::RGB)
			{
				img_buff[i]  = std::uint32_t(img(px,py).r);
				img_buff[i] |= std::uint32_t(img(px,py).g) << 8;
				img_buff[i] |= std::uint32_t(img(px,py).b) << 16;
				img_buff[i] |= 0xFF000000;
			}
			else if (img.color == color_mode::RGBA)
			{
				img_buff[i]  = std::uint32_t(img(px,py).r);
				img_buff[i] |= std::uint32_t(img(px,py).g) << 8;
				img_buff[i] |= std::uint32_t(img(px,py).b) << 16;
				img_buff[i] |= std::uint32_t(img(px,py).a) << 24;
			}
		}
		
		if (img.color == color_mode::GRAY)
		{
			if (TIFFWriteEncodedStrip(out,0,&img_buff_gs[0],npix) == -1)
			{
				std::cerr << "[cynodelic::tesela::formats::tiff_fmt::write] ERROR: Could not write TIFF image.\n";
				std::exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (TIFFWriteEncodedStrip(out,0,&img_buff[0],w*h*4) == -1)
			{
				std::cerr << "[cynodelic::tesela::formats::tiff_fmt::write] ERROR: Could not write TIFF image." << std::endl;
				std::exit(EXIT_FAILURE);
			}
		}
		TIFFClose(out);
	}
};

} // end of "formats" namespace

}} // end of "cynodelic::tesela" namespace

#endif
