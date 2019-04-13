// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file rgba_types.hpp
 *
 * @brief Defines RGBA pixel types.
 */

#ifndef CYNODELIC_TESELA_RGBA_TYPES_HPP
#define CYNODELIC_TESELA_RGBA_TYPES_HPP


#include <istream>
#include <ostream>
#include <sstream>
#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <utility>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/detail/utils.hpp>
#include <cynodelic/tesela/color_space.hpp>
#include <cynodelic/tesela/tdouble.hpp>


namespace cynodelic { namespace tesela {


/**
 * @ingroup pixeltypes
 * @brief RGBA pixel type
 *
 * An RGBA pixel type, with values between 0 and 255.
 */
struct rgba_t
{
	/// @brief Reference to itself
	using type = rgba_t;

	/// @brief Type used for each component
	using component_type = std::uint8_t;

	/// @brief The corresponding color space
	static constexpr color_space pixel_color_space = color_space::rgba;


	/// @brief Red
	component_type red;
	
	/// @brief Green
	component_type green;
	
	/// @brief Blue
	component_type blue;
	
	/// @brief Alpha
	component_type alpha;
	
	
	/**
	 * @brief Default constructor
	 *
	 * Initializes with default RGBA values (0,0,0,0).
	 */
	constexpr rgba_t() :
		red(0x00), green(0x00), blue(0x00), alpha(0x00)
	{}
	
	
	/**
	 * @brief Initialize with brightness
	 *
	 * Initializes with a brightness value @c y (y,y,y,255).
	 *
	 * @param y Brightness.
	 */
	constexpr rgba_t(const component_type& y) :
		red(y), green(y), blue(y), alpha(0xff)
	{}
	
	
	/**
	 * @brief Initialize with brightness and alpha
	 *
	 * Initializes with brightness and alpha values (y,y,y,a).
	 *
	 * @param y Brightness.
	 * @param a Alpha.
	 */
	constexpr rgba_t(const component_type& y,const component_type& a) :
		red(y), green(y), blue(y), alpha(a)
	{}
	
	
	/**
	 * @brief RGB initializer
	 *
	 * Initializes with values for red, green and blue channels (r,g,b,255).
	 *
	 * @param r Red.
	 * @param g Green.
	 * @param b Blue.
	 */
	constexpr rgba_t(const component_type& r,const component_type& g,const component_type& b) :
		red(r), green(g), blue(b), alpha(0xff)
	{}
	
	
	/**
	 * @brief RGBA initializer
	 *
	 * Initializes with values for red, green, blue and alpha channels (r,g,b,a).
	 *
	 * @param r Red.
	 * @param g Green.
	 * @param b Blue.
	 * @param a Alpha.
	 */
	constexpr rgba_t(const component_type& r,const component_type& g,const component_type& b,const component_type& a) :
		red(r), green(g), blue(b), alpha(a)
	{}
	

	/**
	 * @brief Copy assignment operator
	 *
	 * Replaces the contents of a @ref rgba_t with those of `other`.
	 */
	rgba_t& operator=(const rgba_t& other)
	{
		red   = other.red;
		green = other.green;
		blue  = other.blue;
		alpha = other.alpha;

		return *this;
	}
	

	/**
	 * @brief Sets red value
	 *
	 * Sets a value for the red component.
	 *
	 * @param new_r The new value.
	 */
	rgba_t& set_red(const component_type& new_r)
	{
		red = new_r;
		return *this;
	}
	

	/**
	 * @brief Sets green value
	 *
	 * Sets a value for the green component.
	 *
	 * @param new_g The new value.
	 */
	rgba_t& set_green(const component_type& new_g)
	{
		green = new_g;
		return *this;
	}
	

	/**
	 * @brief Sets blue value
	 *
	 * Sets a value for the blue component.
	 *
	 * @param new_b The new value.
	 */
	rgba_t& set_blue(const component_type& new_b)
	{
		blue = new_b;
		return *this;
	}
	

	/**
	 * @brief Sets alpha value
	 *
	 * Sets a value for the alpha component.
	 *
	 * @param new_a The new value.
	 */
	rgba_t& set_alpha(const component_type& new_a)
	{
		alpha = new_a;
		return *this;
	}
	
	
	/**
	 * @brief Equality operator
	 *
	 * Checks if two @ref rgba_t s are equal.
	 */
	constexpr friend bool operator==(const rgba_t& lhs,const rgba_t& rhs)
	{
		return (lhs.red == rhs.red) && (lhs.green == rhs.green) && (lhs.blue == rhs.blue) && (lhs.alpha == rhs.alpha);
	}
	

	/**
	 * @brief Inequality operator
	 *
	 * Checks if two @ref rgba_t s are not equal.
	 */
	constexpr friend bool operator!=(const rgba_t& lhs,const rgba_t& rhs)
	{
		return !(lhs == rhs);
	}
	

	/**
	 * @brief Swaps the contents
	 *
	 * Swaps (exchanges) the contents with those of `other`.
	 */
	void swap(rgba_t& other)
	{
		std::swap(red,other.red);
		std::swap(green,other.green);
		std::swap(blue,other.blue);
		std::swap(alpha,other.alpha);
	}
	
	
	/**
	 * @brief Output stream operator
	 *
	 * Writes to an output stream.
	 */
	template <typename CharT,typename Traits>
	friend std::basic_ostream<CharT,Traits>& operator<<(std::basic_ostream<CharT,Traits>& os,const rgba_t& out)
	{
		std::basic_ostringstream<CharT,Traits> ss;
		ss.flags(os.flags());
		ss.imbue(os.getloc());
		ss.precision(os.precision());
	
		ss << static_cast<unsigned>(out.red) << ' '
		   << static_cast<unsigned>(out.green) << ' '
		   << static_cast<unsigned>(out.blue) << ' '
		   << static_cast<unsigned>(out.alpha);
		
		return os << ss.str();
	}
	

	/**
	 * @brief Input stream operator
	 *
	 * Reads from an input stream.
	 */
	template <typename CharT,typename Traits>
	friend std::basic_istream<CharT,Traits>& operator>>(std::basic_istream<CharT,Traits>& is,rgba_t& in)
	{
		unsigned aux_r, aux_g, aux_b, aux_a;
	
		is >> aux_r >> std::ws
		   >> aux_g >> std::ws
		   >> aux_b >> std::ws
		   >> aux_a >> std::ws;
	
		in = rgba_t(
			static_cast<std::uint8_t>(aux_r),
			static_cast<std::uint8_t>(aux_g),
			static_cast<std::uint8_t>(aux_b),
			static_cast<std::uint8_t>(aux_a)
		);
	
		return is;
	}
};

constexpr color_space rgba_t::pixel_color_space;


/**
 * @ingroup pixeltypes
 * @brief Normalized RGBA pixel type
 *
 * An RGBA pixel type, with values between 0.0 and 1.0.
 */
struct nrgba_t
{
	/// @brief Reference to itself
	using type = nrgba_t;

	/// @brief Type used for each component
	using component_type = tdouble;

	/// @brief The underlying type of the component type
	using component_base_type = typename component_type::value_type;

	/// @brief The corresponding color space
	static constexpr color_space pixel_color_space = color_space::rgba;


	/// @brief Red
	component_type red;
	
	/// @brief Green
	component_type green;
	
	/// @brief Blue
	component_type blue;
	
	/// @brief Alpha
	component_type alpha;
	
	
	/**
	 * @brief Default constructor
	 *
	 * Initializes with default RGBA values (0,0,0,0).
	 */
	constexpr nrgba_t() :
		red(0.0), green(0.0), blue(0.0), alpha(0.0)
	{}
	
	
	/**
	 * @brief Initialize with brightness
	 *
	 * Initializes with a brightness value @c y (y,y,y,1.0).
	 *
	 * @param y Brightness.
	 */
	constexpr nrgba_t(const component_type& y) :
		red(y), green(y), blue(y), alpha(1.0)
	{}
	
	
	/**
	 * @brief Initialize with brightness and alpha
	 *
	 * Initializes with brightness and alpha values (y,y,y,a).
	 *
	 * @param y Brightness.
	 * @param a Alpha.
	 */
	constexpr nrgba_t(const component_type& y,const component_type& a) :
		red(y), green(y), blue(y), alpha(a)
	{}
	
	
	/**
	 * @brief RGB initializer
	 *
	 * Initializes with values for red, green and blue channels (r,g,b,255).
	 *
	 * @param r Red.
	 * @param g Green.
	 * @param b Blue.
	 */
	constexpr nrgba_t(const component_type& r,const component_type& g,const component_type& b) :
		red(r), green(g), blue(b), alpha(1.0)
	{}
	
	
	/**
	 * @brief RGBA initializer
	 *
	 * Initializes with values for red, green, blue and alpha channels (r,g,b,a).
	 *
	 * @param r Red.
	 * @param g Green.
	 * @param b Blue.
	 * @param a Alpha.
	 */
	constexpr nrgba_t(const component_type& r,const component_type& g,const component_type& b,const component_type& a) :
		red(r), green(g), blue(b), alpha(a)
	{}
	
	
	/**
	 * @brief Initialize with brightness
	 *
	 * Initializes with a brightness value @c y (y,y,y,1.0).
	 *
	 * @param y Brightness.
	 */
	constexpr nrgba_t(const component_base_type& y) :
		red(y), green(y), blue(y), alpha(1.0)
	{}
	
	
	/**
	 * @brief Initialize with brightness and alpha
	 *
	 * Initializes with brightness and alpha values (y,y,y,a).
	 *
	 * @param y Brightness.
	 * @param a Alpha.
	 */
	constexpr nrgba_t(const component_base_type& y,const component_base_type& a) :
		red(y), green(y), blue(y), alpha(a)
	{}
	
	
	/**
	 * @brief RGB initializer
	 *
	 * Initializes with values for red, green and blue channels (r,g,b,255).
	 *
	 * @param r Red.
	 * @param g Green.
	 * @param b Blue.
	 */
	constexpr nrgba_t(const component_base_type& r,const component_base_type& g,const component_base_type& b) :
		red(r), green(g), blue(b), alpha(1.0)
	{}
	
	
	/**
	 * @brief RGBA initializer
	 *
	 * Initializes with values for red, green, blue and alpha channels (r,g,b,a).
	 *
	 * @param r Red.
	 * @param g Green.
	 * @param b Blue.
	 * @param a Alpha.
	 */
	constexpr nrgba_t(const component_base_type& r,const component_base_type& g,const component_base_type& b,const component_base_type& a) :
		red(r), green(g), blue(b), alpha(a)
	{}
	
	
	/**
	 * @brief Copy constructor
	 *
	 * Initializes an @ref nrgba_t with the contents of `other`.
	 */
	constexpr nrgba_t(const nrgba_t& other) :
		red(other.red),
		green(other.green),
		blue(other.blue),
		alpha(other.alpha)
	{}
	

	/**
	 * @brief Copy assignment operator
	 *
	 * Replaces the contents of a @ref nrgba_t with those of `other`.
	 */
	nrgba_t& operator=(const nrgba_t& other)
	{
		red   = other.red;
		green = other.green;
		blue  = other.blue;
		alpha = other.alpha;
	
		return *this;
	}
	

	/**
	 * @brief Sets red value
	 *
	 * Sets a value for the red component.
	 *
	 * @param new_r The new value.
	 */
	nrgba_t& set_red(const component_type& new_r)
	{
		red = new_r;
		return *this;
	}
	

	/**
	 * @brief Sets green value
	 *
	 * Sets a value for the green component.
	 *
	 * @param new_g The new value.
	 */
	nrgba_t& set_green(const component_type& new_g)
	{
		green = new_g;
		return *this;
	}
	

	/**
	 * @brief Sets blue value
	 *
	 * Sets a value for the blue component.
	 *
	 * @param new_b The new value.
	 */
	nrgba_t& set_blue(const component_type& new_b)
	{
		blue = new_b;
		return *this;
	}
	

	/**
	 * @brief Sets alpha value
	 *
	 * Sets a value for the alpha component.
	 *
	 * @param new_a The new value.
	 */
	nrgba_t& set_alpha(const component_type& new_a)
	{
		alpha = new_a;
		return *this;
	}
	
	
	/**
	 * @brief Equality operator
	 *
	 * Checks if two @ref nrgba_t s are equal.
	 */
	constexpr friend bool operator==(const nrgba_t& lhs,const nrgba_t& rhs)
	{
		return (lhs.red == rhs.red) && (lhs.green == rhs.green) && (lhs.blue == rhs.blue) && (lhs.alpha == rhs.alpha);
	}
	
	
	/**
	 * @brief Inquality operator
	 *
	 * Checks if two @ref nrgba_t s are not equal.
	 */
	constexpr friend bool operator!=(const nrgba_t& lhs,const nrgba_t& rhs)
	{
		return !(lhs == rhs);
	}
	

	/**
	 * @brief Swaps the contents
	 *
	 * Swaps (exchanges) the contents with those of `other`.
	 */
	void swap(nrgba_t& other)
	{
		std::swap(red,other.red);
		std::swap(green,other.green);
		std::swap(blue,other.blue);
		std::swap(alpha,other.alpha);
	}
	
	
	/**
	 * @brief Output stream operator
	 *
	 * Writes to an output stream.
	 */
	template <typename CharT,typename Traits>
	friend std::basic_ostream<CharT,Traits>& operator<<(std::basic_ostream<CharT,Traits>& os,const nrgba_t& out)
	{
		std::basic_ostringstream<CharT,Traits> ss;
		ss.flags(os.flags());
		ss.imbue(os.getloc());
		ss.precision(os.precision());

		ss << out.red << ' ' << out.green << ' ' << out.blue << ' ' << out.alpha;

		return os << ss.str();
	}
	
	
	/**
	 * @brief Input stream operator
	 *
	 * Reads from an input stream.
	 */
	template <typename CharT,typename Traits>
	friend std::basic_istream<CharT,Traits>& operator>>(std::basic_istream<CharT,Traits>& is,nrgba_t& in)
	{
		is >> in.red >> std::ws
		   >> in.green >> std::ws
		   >> in.blue >> std::ws
		   >> in.alpha >> std::ws;

		return is;
	}
};

constexpr color_space nrgba_t::pixel_color_space;


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_RGBA_TYPES_HPP
