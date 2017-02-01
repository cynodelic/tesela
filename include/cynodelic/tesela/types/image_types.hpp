// Copyright (c) 2017 Alvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TYPES_IMAGE_TYPES_HPP
#define CYNODELIC_TESELA_TYPES_IMAGE_TYPES_HPP

#include "../internal.hpp"
#include "rgba_types.hpp"
#include "misc_types.hpp"

namespace cynodelic { namespace tesela {

class norm_image;

// "As is"
class image
{
	private:
		std::size_t width_, height_;
		rgba_t **pixels;
	public:
		// Color mode (RGB, RGBA, grayscale, grayscale and alpha)
		color_mode color;
		
		// Default constructor
		image() : width_(0), height_(0) { pixels = nullptr; color = color_mode::RGB; }
		
		// Constructor (allocate a width*height 2D array)
		image(std::size_t width,std::size_t height,color_mode cm = color_mode::RGB)
		{
			pixels = new rgba_t*[height];
			for (std::size_t i=0;i<height;i++)
				pixels[i] = new rgba_t[width];
			width_ = width;
			height_ = height;
			color = cm;
		}
		
		// Constructor (from rectangle)
		image(const rectangle& rec,color_mode cm = color_mode::RGB) : image(rec.rw(),rec.rh(),cm) {}
		
		// Destroy
		~image() noexcept
		{
			for (std::size_t i=0;i<height_;i++)
				delete [] pixels[i];
			delete [] pixels;
			pixels = nullptr;
		}
		
		// Copy and move constructors
		image(const image& x)
		{
			// Deallocate array of pixels
			pixels = nullptr;
			
			// Reallocate array
			pixels = new rgba_t*[x.height_];
			for (std::size_t i=0;i<x.height_;i++)
				pixels[i] = new rgba_t[x.width_];
			
			// Copy content
			for (std::size_t iy=0;iy<x.height_;iy++)
				for (std::size_t ix=0;ix<x.width_;ix++)
					pixels[iy][ix] = x.pixels[iy][ix];
			
			width_ = x.width_;
			height_ = x.height_;
			color = x.color;
		}
		image(image&& x) noexcept
		{
			// Deallocate array of pixels
			pixels = nullptr;
			
			// Reallocate array
			pixels = new rgba_t*[x.height_];
			for (std::size_t i=0;i<x.height_;i++)
				pixels[i] = new rgba_t[x.width_];
			
			// Copy content
			for (std::size_t iy=0;iy<x.height_;iy++)
				for (std::size_t ix=0;ix<x.width_;ix++)
					pixels[iy][ix] = x.pixels[iy][ix];
			
			width_ = x.width_;
			height_ = x.height_;
			color = x.color;
			
			// "Reset" x
			x.pixels = nullptr;
			x.width_ = x.height_ = 0;
		}
		
		// Copy constructors (from norm_image)
		image(const norm_image& x);
		
		// Assignement operators (image)
		image& operator=(const image& x)
		{
			// Deallocate array of pixels
			pixels = nullptr;
			
			// Reallocate array
			pixels = new rgba_t*[x.height_];
			for (std::size_t i=0;i<x.height_;i++)
				pixels[i] = new rgba_t[x.width_];
			
			// Copy content
			for (std::size_t iy=0;iy<x.height_;iy++)
				for (std::size_t ix=0;ix<x.width_;ix++)
					pixels[iy][ix] = x.pixels[iy][ix];
			
			width_ = x.width_;
			height_ = x.height_;
			color = x.color;
			
			return *this;
		}
		image& operator=(image&& x) noexcept
		{
			// Deallocate array of pixels
			pixels = nullptr;
			
			// Reallocate array
			pixels = new rgba_t*[x.height_];
			for (std::size_t i=0;i<x.height_;i++)
				pixels[i] = new rgba_t[x.width_];
			
			// Copy content
			for (std::size_t iy=0;iy<x.height_;iy++)
				for (std::size_t ix=0;ix<x.width_;ix++)
					pixels[iy][ix] = x.pixels[iy][ix];
			
			width_ = x.width_;
			height_ = x.height_;
			color = x.color;
			
			// "Reset" x
			x.pixels = nullptr;
			x.width_ = x.height_ = 0;
			
			return *this;
		}
		
		// Get/set pixel from image (x,y)
		rgba_t& operator()(const std::size_t& x,const std::size_t& y) const
		{
			return pixels[y][x];
		}
		
		// Width, height and size
		std::size_t width() const  { return width_;  }
		std::size_t height() const { return height_; }
		std::size_t size() const   { return width_*height_; }
		
		// Width and height as a rectangle
		rectangle rect() const
		{
			return rectangle(width_,height_);
		}
		
		// Unroll image data to 1-D array
		template <unroll_type utp>
		std::vector<typename unrolled_type_picker<utp>::type> unroll()
		{
			typedef typename unrolled_type_picker<utp>::type ur_type;
			
			std::vector<ur_type> unrolled;
			
			if (utp == unroll_type::BYTE)
			{
				for (std::size_t iy=0;iy<height_;iy++)
				{
					for (std::size_t ix=0;ix<width_;ix++)
					{
						if (color == color_mode::RGB)
						{
							unrolled.push_back(pixels[iy][ix].r);
							unrolled.push_back(pixels[iy][ix].g);
							unrolled.push_back(pixels[iy][ix].b);
						}
						if (color == color_mode::RGBA)
						{
							unrolled.push_back(pixels[iy][ix].r);
							unrolled.push_back(pixels[iy][ix].g);
							unrolled.push_back(pixels[iy][ix].b);
							unrolled.push_back(pixels[iy][ix].a);
						}
						if (color == color_mode::GRAY)
						{
							unrolled.push_back(pixels[iy][ix].r);
						}
						if (color == color_mode::GA)
						{
							unrolled.push_back(pixels[iy][ix].r);
							unrolled.push_back(pixels[iy][ix].a);
						}
					}
				}
			}
			else if (utp == unroll_type::DOUBLE)
			{
				for (std::size_t iy=0;iy<height_;iy++)
				{
					for (std::size_t ix=0;ix<width_;ix++)
					{
						if (color == color_mode::RGB)
						{
							unrolled.push_back(internal::u8_to_dbl(pixels[iy][ix].r));
							unrolled.push_back(internal::u8_to_dbl(pixels[iy][ix].g));
							unrolled.push_back(internal::u8_to_dbl(pixels[iy][ix].b));
						}
						if (color == color_mode::RGBA)
						{
							unrolled.push_back(internal::u8_to_dbl(pixels[iy][ix].r));
							unrolled.push_back(internal::u8_to_dbl(pixels[iy][ix].g));
							unrolled.push_back(internal::u8_to_dbl(pixels[iy][ix].b));
							unrolled.push_back(internal::u8_to_dbl(pixels[iy][ix].a));
						}
						if (color == color_mode::GRAY)
						{
							unrolled.push_back(internal::u8_to_dbl(pixels[iy][ix].r));
						}
						if (color == color_mode::GA)
						{
							unrolled.push_back(internal::u8_to_dbl(pixels[iy][ix].r));
							unrolled.push_back(internal::u8_to_dbl(pixels[iy][ix].a));
						}
					}
				}
			}
			else if (utp == unroll_type::DWORD)
			{
				for (std::size_t iy=0;iy<height_;iy++)
					for (std::size_t ix=0;ix<width_;ix++)
						unrolled.push_back(pixels[iy][ix].to_dword());
			}
			else
			{
				std::cerr << "[cynodelic::tesela::image::unroll] Could not unroll image data.\n";
				std::exit(EXIT_FAILURE);
			}
			
			return unrolled;
		}
		
		// Comparision operators
		friend bool operator==(const image& lhs,const image& rhs)
		{
			if (!(lhs.width() == rhs.width() && lhs.height() == rhs.height()))
				return false;
			
			for (std::size_t iy=0;iy<lhs.height();iy++)
			{
				for (std::size_t ix=0;ix<lhs.width();ix++)
				{
					if (lhs(ix,iy) != rhs(ix,iy))
						return false;
					else
						continue;
				}
			}
			
			return true;
		}
		friend bool operator!=(const image& lhs,const image& rhs)
		{
			return !(lhs == rhs);
		}
};


// Nnormalized to 1
class norm_image
{
	private:
		std::size_t width_, height_;
		nrgba_t **pixels;
	public:
		// Color mode (RGB, RGBA, grayscale, grayscale and alpha)
		color_mode color;
		
		// Default constructor
		norm_image() : width_(0), height_(0) { pixels = nullptr; color = color_mode::RGB; }
		
		// Constructor (allocate a width*height 2D array)
		norm_image(std::size_t width,std::size_t height,color_mode cm = color_mode::RGB)
		{
			pixels = new nrgba_t*[height];
			for (std::size_t i=0;i<height;i++)
				pixels[i] = new nrgba_t[width];
			width_ = width;
			height_ = height;
			color = cm;
		}
		
		// Constructor (from rectangle)
		norm_image(const rectangle& rec,color_mode cm = color_mode::RGB) : norm_image(rec.rw(),rec.rh(),cm) {}
		
		// Destroy
		~norm_image() noexcept
		{
			for (std::size_t i=0;i<height_;i++)
				delete [] pixels[i];
			delete [] pixels;
			pixels = nullptr;
		}
		
		// Copy and move constructors
		norm_image(const norm_image& x)
		{
			// Deallocate array of pixels
			pixels = nullptr;
			
			// Reallocate array
			pixels = new nrgba_t*[x.height_];
			for (std::size_t i=0;i<x.height_;i++)
				pixels[i] = new nrgba_t[x.width_];
			
			// Copy content
			for (std::size_t iy=0;iy<x.height_;iy++)
				for (std::size_t ix=0;ix<x.width_;ix++)
					pixels[iy][ix] = x.pixels[iy][ix];
			
			width_ = x.width_;
			height_ = x.height_;
			color = x.color;
		}
		norm_image(norm_image&& x) noexcept
		{
			// Deallocate array of pixels
			pixels = nullptr;
			
			// Reallocate array
			pixels = new nrgba_t*[x.height_];
			for (std::size_t i=0;i<x.height_;i++)
				pixels[i] = new nrgba_t[x.width_];
			
			// Copy content
			for (std::size_t iy=0;iy<x.height_;iy++)
				for (std::size_t ix=0;ix<x.width_;ix++)
					pixels[iy][ix] = x.pixels[iy][ix];
			
			width_ = x.width_;
			height_ = x.height_;
			color = x.color;
			
			// "Reset" x
			x.pixels = nullptr;
			x.width_ = x.height_ = 0;
		}
		
		// Copy from image
		norm_image(const image& x)
		{
			// Deallocate array of pixels
			pixels = nullptr;
			
			// Reallocate array
			pixels = new nrgba_t*[x.height()];
			for (std::size_t i=0;i<x.height();i++)
				pixels[i] = new nrgba_t[x.width()];
			
			// Copy content
			for (std::size_t iy=0;iy<x.height();iy++)
				for (std::size_t ix=0;ix<x.width();ix++)
					pixels[iy][ix] = x(ix,iy);
			
			width_ = x.width();
			height_ = x.height();
			color = x.color;
		}
		
		// Assignement operators
		norm_image& operator=(const norm_image& x)
		{
			// Deallocate array of pixels
			pixels = nullptr;
			
			// Reallocate array
			pixels = new nrgba_t*[x.height_];
			for (std::size_t i=0;i<x.height_;i++)
				pixels[i] = new nrgba_t[x.width_];
			
			// Copy content
			for (std::size_t iy=0;iy<x.height_;iy++)
				for (std::size_t ix=0;ix<x.width_;ix++)
					pixels[iy][ix] = x.pixels[iy][ix];
			
			width_ = x.width_;
			height_ = x.height_;
			color = x.color;
			
			return *this;
		}
		norm_image& operator=(norm_image&& x) noexcept
		{
			// Deallocate array of pixels
			pixels = nullptr;
			
			// Reallocate array
			pixels = new nrgba_t*[x.height_];
			for (std::size_t i=0;i<x.height_;i++)
				pixels[i] = new nrgba_t[x.width_];
			
			// Copy content
			for (std::size_t iy=0;iy<x.height_;iy++)
				for (std::size_t ix=0;ix<x.width_;ix++)
					pixels[iy][ix] = x.pixels[iy][ix];
			
			width_ = x.width_;
			height_ = x.height_;
			color = x.color;
			
			// "Reset" x
			x.pixels = nullptr;
			x.width_ = x.height_ = 0;
			
			return *this;
		}
		
		// Get/set pixel from image (x,y)
		nrgba_t& operator()(const std::size_t& x,const std::size_t& y) const
		{
			return pixels[y][x];
		}
		
		// Width, height and size
		std::size_t width() const  { return width_;  }
		std::size_t height() const { return height_; }
		std::size_t size() const   { return width_*height_; }
		
		// Width and height as a rectangle
		rectangle rect() const
		{
			return rectangle(width_,height_);
		}
		
		// Unroll image data to 1-D array
		template <unroll_type utp>
		std::vector<typename unrolled_type_picker<utp>::type> unroll()
		{
			typedef typename unrolled_type_picker<utp>::type ur_type;
			
			std::vector<ur_type> unrolled;
			
			if (utp == unroll_type::BYTE)
			{
				for (std::size_t iy=0;iy<height_;iy++)
				{
					for (std::size_t ix=0;ix<width_;ix++)
					{
						std::size_t loc = width_*iy+ix;
						if (color == color_mode::RGB)
						{
							unrolled.push_back(internal::dbl_to_u8(pixels[iy][ix].r));
							unrolled.push_back(internal::dbl_to_u8(pixels[iy][ix].g));
							unrolled.push_back(internal::dbl_to_u8(pixels[iy][ix].b));
						}
						if (color == color_mode::RGBA)
						{
							unrolled.push_back(internal::dbl_to_u8(pixels[iy][ix].r));
							unrolled.push_back(internal::dbl_to_u8(pixels[iy][ix].g));
							unrolled.push_back(internal::dbl_to_u8(pixels[iy][ix].b));
							unrolled.push_back(internal::dbl_to_u8(pixels[iy][ix].a));
						}
						if (color == color_mode::GRAY)
						{
							unrolled.push_back(internal::dbl_to_u8(pixels[iy][ix].r));
						}
						if (color == color_mode::GA)
						{
							unrolled.push_back(internal::dbl_to_u8(pixels[iy][ix].r));
							unrolled.push_back(internal::dbl_to_u8(pixels[iy][ix].a));
						}
					}
				}
			}
			else if (utp == unroll_type::DOUBLE)
			{
				for (std::size_t iy=0;iy<height_;iy++)
				{
					for (std::size_t ix=0;ix<width_;ix++)
					{
						if (color == color_mode::RGB)
						{
							unrolled.push_back(pixels[iy][ix].r);
							unrolled.push_back(pixels[iy][ix].g);
							unrolled.push_back(pixels[iy][ix].b);
						}
						if (color == color_mode::RGBA)
						{
							unrolled.push_back(pixels[iy][ix].r);
							unrolled.push_back(pixels[iy][ix].g);
							unrolled.push_back(pixels[iy][ix].b);
							unrolled.push_back(pixels[iy][ix].a);
						}
						if (color == color_mode::GRAY)
						{
							unrolled.push_back(pixels[iy][ix].r);
						}
						if (color == color_mode::GA)
						{
							unrolled.push_back(pixels[iy][ix].r);
							unrolled.push_back(pixels[iy][ix].a);
						}
					}
				}
			}
			else if (utp == unroll_type::DWORD)
			{
				for (std::size_t iy=0;iy<height_;iy++)
					for (std::size_t ix=0;ix<width_;ix++)
						unrolled.push_back(pixels[iy][ix].to_dword());
			}
			else
			{
				std::cerr << "[cynodelic::tesela::image::unroll] Could not unroll image data.\n";
				std::exit(EXIT_FAILURE);
			}
			
			return unrolled;
		}
		
		// Comparision operators
		friend bool operator==(const norm_image& lhs,const norm_image& rhs)
		{
			if (!(lhs.width() == rhs.width() && lhs.height() == rhs.height()))
				return false;
			
			for (std::size_t iy=0;iy<lhs.height();iy++)
			{
				for (std::size_t ix=0;ix<lhs.width();ix++)
				{
					if (lhs(ix,iy) != rhs(ix,iy))
						return false;
					else
						continue;
				}
			}
			
			return true;
		}
		friend bool operator!=(const norm_image& lhs,const norm_image& rhs)
		{
			return !(lhs == rhs);
		}
};

// Copy from norm_image
image::image(const norm_image& x)
{
	// Deallocate array of pixels
	pixels = nullptr;
	
	// Reallocate array
	rgba_t **tmp;
	tmp = new rgba_t*[x.height()];
	for (std::size_t i=0;i<x.height();i++)
		tmp[i] = new rgba_t[x.width()];
	
	// Copy content
	for (std::size_t iy=0;iy<x.height();iy++)
		for (std::size_t ix=0;ix<x.width();ix++)
			tmp[iy][ix] = x(ix,iy);
	
	pixels = tmp;
	
	width_ = x.width();
	height_ = x.height();
	color = x.color;
}

}} // end of "cynodelic::tesela" namespace

#endif

