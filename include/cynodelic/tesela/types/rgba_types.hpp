// Copyright (c) 2017 Alvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TYPES_RGBA_TYPES_HPP
#define CYNODELIC_TESELA_TYPES_RGBA_TYPES_HPP

#include "../internal.hpp"

namespace cynodelic { namespace tesela {

// Which color mode is the image in?
enum class color_mode : std::uint8_t
{
	GRAY = 0x01,
	GA   = 0x02,
	RGB  = 0x11,
	RGBA = 0x12,
};

// Pixel types
class nrgba_t; // Forward declaration of nrgba_t

class rgba_t // "As is" [0-255]
{
	public:
	// Red, green, blue, alpha
	std::uint8_t r, g, b, a;
	
	// Default
	rgba_t() : r(0x00), g(0x00), b(0x00), a(0x00) {}
	
	// Brightness
	rgba_t(std::uint8_t y) : r(y), g(y), b(y), a(CYNODELIC_TESELA_DEFAULT_ALPHA_FILL) {}
	
	// Brightness, alpha
	rgba_t(std::uint8_t y,std::uint8_t a) : r(y), g(y), b(y), a(a) {}
	
	// RGB
	rgba_t(std::uint8_t r,std::uint8_t g,std::uint8_t b) : r(r), g(g), b(b), a(CYNODELIC_TESELA_DEFAULT_ALPHA_FILL) {}
	
	// RGBA
	rgba_t(std::uint8_t r,std::uint8_t g,std::uint8_t b,std::uint8_t a) : r(r), g(g), b(b), a(a) {}
	
	// Empty destructor
	~rgba_t() {}
	
	// Copy and move
	rgba_t(const rgba_t& x) : r(x.r), g(x.g), b(x.b), a(x.a) {}
	rgba_t(rgba_t&& x) = default;
	
	// Copy from nrgba_t (methods declared below so it can be done properly)
	rgba_t(const nrgba_t& x);
	
	// Assignment
	rgba_t& operator=(const rgba_t& x)
	{
		r = x.r; g = x.g; b = x.b; a = x.a;
		return *this;
	}
	rgba_t& operator=(rgba_t&& x)
	{
		r = x.r; g = x.g; b = x.b; a = x.a;
		return *this;
	}
	rgba_t& operator=(const nrgba_t& x);
	
	// Convert to 32-bit (RGBA/ABGR)
	std::uint32_t to_dword()
	{
		std::uint32_t y = (std::uint32_t(r) << 24)|
		                  (std::uint32_t(g) << 16)|
		                  (std::uint32_t(b) <<  8)|
		                  (std::uint32_t(a) <<  0);
		return y;
	}
	
	// Check equality and inequality
	friend bool operator==(const rgba_t& lhs,const rgba_t& rhs)
	{
		return (lhs.r == rhs.r) && (lhs.g == rhs.g) && (lhs.b == rhs.b) && (lhs.a == rhs.a);
	}
	friend bool operator!=(const rgba_t& lhs,const rgba_t& rhs)
	{
		return !(lhs == rhs);
	}
	
	// Swap
	void swap(rgba_t& x)
	{
		std::swap(r,x.r);
		std::swap(g,x.g);
		std::swap(b,x.b);
		std::swap(a,x.a);
	}
	friend void swap(rgba_t& lhs,rgba_t& rhs)
	{
		lhs.swap(rhs);
	}
	
	// Stream operators
	template <class CharT,class Traits>
	friend std::basic_ostream<CharT,Traits>& operator<<(std::basic_ostream<CharT,Traits>& os,const rgba_t& x)
	{
		os << x.r << ' '
		   << x.g << ' '
		   << x.b << ' '
		   << x.a;
		return os;
	}
	
	template <class CharT,class Traits>
	friend std::basic_istream<CharT,Traits>& operator>>(std::basic_istream<CharT,Traits>& is,rgba_t& x)
	{
		is >> x.r >> std::ws
		   >> x.g >> std::ws
		   >> x.b >> std::ws
		   >> x.a >> std::ws;
		return is;
	}
};

class nrgba_t // Normalized to 1 [0.0-1.0]
{
	public:
	// Red, green, blue, alpha
	double r, g, b, a;
	
	// Default
	nrgba_t() : r(0.0), g(0.0), b(0.0), a(0.0) {}
	
	// Brightness
	nrgba_t(double y) : r(internal::quantize(y)), g(internal::quantize(y)), b(internal::quantize(y)), a(1.0) {}
	
	// Brightness, alpha
	nrgba_t(double y,double a) : r(internal::quantize(y)), g(internal::quantize(y)), b(internal::quantize(y)), a(internal::quantize(a)) {}
	
	// RGB
	nrgba_t(double r,double g,double b) : r(internal::quantize(r)), g(internal::quantize(g)), b(internal::quantize(b)), a(1.0) {}
	
	// RGBA
	nrgba_t(double r,double g,double b,double a) : r(internal::quantize(r)), g(internal::quantize(g)), b(internal::quantize(b)), a(internal::quantize(a)) {}
	
	// Empty destructor
	~nrgba_t() {}
	
	// Copy and move
	nrgba_t(const nrgba_t& x) : r(x.r), g(x.g), b(x.b), a(x.a) {}
	nrgba_t(nrgba_t&& x) = default;
	
	// Copy from rgba_t
	nrgba_t(const rgba_t& x)
	{
		r = internal::u8_to_dbl(x.r);
		g = internal::u8_to_dbl(x.g);
		b = internal::u8_to_dbl(x.b);
		a = internal::u8_to_dbl(x.a);
	}
	
	// Assignment
	nrgba_t& operator=(const nrgba_t& x)
	{
		r = x.r; g = x.g; b = x.b; a = x.a;
		return *this;
	}
	nrgba_t& operator=(nrgba_t&& x)
	{
		r = x.r; g = x.g; b = x.b; a = x.a;
		return *this;
	}
	nrgba_t& operator=(const rgba_t& x)
	{
		r = internal::u8_to_dbl(x.r);
		g = internal::u8_to_dbl(x.g);
		b = internal::u8_to_dbl(x.b);
		a = internal::u8_to_dbl(x.a);
		return *this;
	}
	
	// Convert to 32-bit (RGBA/ABGR)
	std::uint32_t to_dword()
	{
		std::uint32_t y = (std::uint32_t(internal::dbl_to_u8(r)) << 24)|
		                  (std::uint32_t(internal::dbl_to_u8(g)) << 16)|
		                  (std::uint32_t(internal::dbl_to_u8(b)) <<  8)|
		                  (std::uint32_t(internal::dbl_to_u8(a)) <<  0);
		return y;
	}
	
	// Check equality and inequality
	friend bool operator==(const nrgba_t& lhs,const nrgba_t& rhs)
	{
		return (lhs.r == rhs.r) && (lhs.g == rhs.g) && (lhs.b == rhs.b) && (lhs.a == rhs.a);
	}
	friend bool operator!=(const nrgba_t& lhs,const nrgba_t& rhs)
	{
		return !(lhs == rhs);
	}
	
	// Swap
	void swap(nrgba_t& x)
	{
		std::swap(r,x.r);
		std::swap(g,x.g);
		std::swap(b,x.b);
		std::swap(a,x.a);
	}
	friend void swap(nrgba_t& lhs,nrgba_t& rhs)
	{
		lhs.swap(rhs);
	}
	
	// Stream operators
	template <class CharT,class Traits>
	friend std::basic_ostream<CharT,Traits>& operator<<(std::basic_ostream<CharT,Traits>& os,const nrgba_t& x)
	{
		os << std::setprecision(CYNODELIC_TESELA_NRGBA_T_COUT_PRECISION) << x.r
		   << ' ' << std::setprecision(CYNODELIC_TESELA_NRGBA_T_COUT_PRECISION) << x.g
		   << ' ' << std::setprecision(CYNODELIC_TESELA_NRGBA_T_COUT_PRECISION) << x.b
		   << ' ' << std::setprecision(CYNODELIC_TESELA_NRGBA_T_COUT_PRECISION) << x.a;
		return os;
	}
	
	template <class CharT,class Traits>
	friend std::basic_istream<CharT,Traits>& operator>>(std::basic_istream<CharT,Traits>& is,nrgba_t& x)
	{
		double r_ = 0, g_ = 0, b_ = 0, a_ = 0;
		is >> r_ >> std::ws
		   >> g_ >> std::ws
		   >> b_ >> std::ws
		   >> a_ >> std::ws;
		x.r = internal::quantize(r_);
		x.g = internal::quantize(g_);
		x.b = internal::quantize(b_);
		x.a = internal::quantize(a_);
		return is;
	}
};

// Copy constructor from nrgba_t (placed here because of forward 
// declaration and dependence between each other)
rgba_t::rgba_t(const nrgba_t& x)
{
	r = internal::dbl_to_u8(x.r);
	g = internal::dbl_to_u8(x.g);
	b = internal::dbl_to_u8(x.b);
	a = internal::dbl_to_u8(x.a);
}

// Assignement operator from nrgba_t (placed here because of forward 
// declaration and dependence between each other)
rgba_t& rgba_t::operator=(const nrgba_t& x)
{
	r = internal::dbl_to_u8(x.r);
	g = internal::dbl_to_u8(x.g);
	b = internal::dbl_to_u8(x.b);
	a = internal::dbl_to_u8(x.a);
	return *this;
}

}} // end of "cynodelic::tesela" namespace

#endif

