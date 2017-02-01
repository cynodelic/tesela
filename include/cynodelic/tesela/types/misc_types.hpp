// Copyright (c) 2017 Alvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TYPES_MISC_TYPES_HPP
#define CYNODELIC_TESELA_TYPES_MISC_TYPES_HPP

#include "../internal.hpp"

namespace cynodelic { namespace tesela {

// Types for image unrolling (turn image data into an 1-D array)
enum class unroll_type : std::uint8_t
{
	BYTE   = 0x30,
	DOUBLE = 0x31,
	DWORD  = 0x32
};

template <unroll_type ut> struct unrolled_type_picker {};
template <> struct unrolled_type_picker<unroll_type::BYTE  > { typedef std::uint8_t  type; };
template <> struct unrolled_type_picker<unroll_type::DOUBLE> { typedef double        type; };
template <> struct unrolled_type_picker<unroll_type::DWORD > { typedef std::uint32_t type; };


// Rectangle (useful for crop images)
class rectangle
{
	public:
	// Position (x,y)
	std::size_t x, y;
	
	// Width, height
	std::size_t w, h;
	
	// Default
	rectangle() : x(0), y(0), w(0), h(0) {}
	
	// Width, height
	rectangle(std::size_t w,std::size_t h) : w(w), h(h), x(0), y(0) {}
	
	// Width, height, position
	rectangle(std::size_t x,std::size_t y,std::size_t w,std::size_t h) : w(w), h(h), x(x), y(y) {}
	
	// Copy/move constructors
	rectangle(const rectangle& c) : x(c.x), y(c.y), w(c.w), h(c.h) {}
	rectangle(rectangle&& c) = default;
	~rectangle() {}
	
	// Relative width (width minus X position) and height (height minus Y position)
	std::size_t rw() const { return w-x; }
	std::size_t rh() const { return h-y; }
	
	// Assignment
	rectangle& operator=(const rectangle& c)
	{
		x = c.x; y = c.y;
		w = c.w; h = c.h;
		
		return *this;
	}
	rectangle& operator=(rectangle&& c)
	{
		x = c.x; y = c.y;
		w = c.w; h = c.h;
		c.x = c.y = c.w = c.h = 0;
		
		return *this;
	}
	
	// Swap
	void swap(rectangle& c)
	{
		std::swap(x,c.x); std::swap(y,c.y);
		std::swap(w,c.w); std::swap(h,c.h);
	}
	friend void swap(rectangle& lhs,rectangle& rhs)
	{
		lhs.swap(rhs);
	}
	
	// Comparision
	friend bool operator==(const rectangle& lhs,const rectangle& rhs)
	{
		return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.w == rhs.w) && (lhs.h == rhs.h);
	}
	
	friend bool operator!=(const rectangle& lhs,const rectangle& rhs)
	{
		return !(lhs == rhs);
	}
	
	// Stream operators
	template <class CharT,class Traits>
	friend std::basic_ostream<CharT,Traits>& operator<<(std::basic_ostream<CharT,Traits>& os,const rectangle& r)
	{
		os << r.x << ' '
		   << r.y << ' '
		   << r.w << ' '
		   << r.h;
		return os;
	}
	
	template <class CharT,class Traits>
	friend std::basic_istream<CharT,Traits>& operator>>(std::basic_istream<CharT,Traits>& is,rectangle& r)
	{
		is >> r.x >> std::ws
		   >> r.y >> std::ws
		   >> r.w >> std::ws
		   >> r.h >> std::ws;
		return is;
	}
};

}} // end of "cynodelic::tesela" namespace

#endif

