// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file rgb_types.hpp
 *
 * @brief Defines RGB pixel types.
 */

#ifndef CYNODELIC_TESELA_RGB_TYPES_HPP
#define CYNODELIC_TESELA_RGB_TYPES_HPP


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
 * @brief RGB pixel type
 *
 * An RGB pixel type, with values between 0 and 255.
 */
struct rgb_t
{
	/// @brief Reference to itself
	using type = rgb_t;

	/// @brief Type used for each component
	using component_type = std::uint8_t;
	
	/// @brief The corresponding color space
	static constexpr color_space pixel_color_space = color_space::rgb;
	

	/// @brief Red
	component_type red;
	
	/// @brief Green
	component_type green;
	
	/// @brief Blue
	component_type blue;
	
	
	/**
	 * @brief Default constructor
	 *
	 * Initializes with default RGB values (0,0,0).
	 */
	constexpr rgb_t() :
		red(0x00), green(0x00), blue(0x00)
	{}
	
	
	/**
	 * @brief Initialize with brightness
	 *
	 * Initializes with a brightness value @c y (y,y,y).
	 *
	 * @param y Brightness.
	 */
	constexpr rgb_t(const component_type& y) :
		red(y), green(y), blue(y)
	{}
	
	
	/**
	 * @brief RGB initializer
	 *
	 * Initializes with values for red, green and blue channels (r,g,b).
	 *
	 * @param r Red.
	 * @param g Green.
	 * @param b Blue.
	 */
	constexpr rgb_t(const component_type& r,const component_type& g,const component_type& b) :
		red(r), green(g), blue(b)
	{}
	

	/**
	 * @brief Copy assignment operator
	 *
	 * Replaces the contents of a @ref rgb_t with those of `other`.
	 */
	rgb_t& operator=(const rgb_t& other)
	{
		red   = other.red;
		green = other.green;
		blue  = other.blue;
	
		return *this;
	}
	

	/**
	 * @brief Sets red value
	 *
	 * Sets a value for the red component.
	 *
	 * @param new_r The new value.
	 */
	rgb_t& set_red(const component_type& new_r)
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
	rgb_t& set_green(const component_type& new_g)
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
	rgb_t& set_blue(const component_type& new_b)
	{
		blue = new_b;
		return *this;
	}
	
	
	/**
	 * @brief Equality operator
	 *
	 * Checks if two @ref rgb_t s are equal.
	 */
	constexpr friend bool operator==(const rgb_t& lhs,const rgb_t& rhs)
	{
		return (lhs.red == rhs.red) && (lhs.green == rhs.green) && (lhs.blue == rhs.blue);
	}
	
	
	/**
	 * @brief Inequality operator
	 *
	 * Checks if two @ref rgb_t s are not equal.
	 */
	constexpr friend bool operator!=(const rgb_t& lhs,const rgb_t& rhs)
	{
		return !(lhs == rhs);
	}
	

	/**
	 * @brief Swaps the contents
	 *
	 * Swaps (exchanges) the contents with those of `other`.
	 */
	void swap(rgb_t& other)
	{
		std::swap(red,other.red);
		std::swap(green,other.green);
		std::swap(blue,other.blue);
	}
	
	
	/**
	 * @brief Output stream operator
	 *
	 * Writes to an output stream.
	 */
	template <typename CharT,typename Traits>
	friend std::basic_ostream<CharT,Traits>& operator<<(std::basic_ostream<CharT,Traits>& os,const rgb_t& out)
	{
		std::basic_ostringstream<CharT,Traits> ss;
		ss.flags(os.flags());
		ss.imbue(os.getloc());
		ss.precision(os.precision());
	
		ss << static_cast<unsigned>(out.red) << ' '
		   << static_cast<unsigned>(out.green) << ' '
		   << static_cast<unsigned>(out.blue);
		
		return os << ss.str();
	}
	
	
	/**
	 * @brief Input stream operator
	 *
	 * Reads from an input stream.
	 */
	template <typename CharT,typename Traits>
	friend std::basic_istream<CharT,Traits>& operator>>(std::basic_istream<CharT,Traits>& is,rgb_t& in)
	{
		unsigned aux_r, aux_g, aux_b;
	
		is >> aux_r >> std::ws
		   >> aux_g >> std::ws
		   >> aux_b >> std::ws;
	
		in = rgb_t(
			static_cast<std::uint8_t>(aux_r),
			static_cast<std::uint8_t>(aux_g),
			static_cast<std::uint8_t>(aux_b)
		);
	
		return is;
	}
};

constexpr color_space rgb_t::pixel_color_space;


/**
 * @ingroup pixeltypes
 * @brief Normalized RGB pixel type
 *
 * An RGB pixel type, with values between 0.0 and 1.0.
 */
struct nrgb_t
{
	/// @brief Reference to itself
	using type = nrgb_t;

	/// @brief Type used for each component
	using component_type = tdouble;

	/// @brief The underlying type of the component type
	using component_base_type = typename component_type::value_type;

	/// @brief The corresponding color space
	static constexpr color_space pixel_color_space = color_space::rgb;


	/// @brief Red
	component_type red;
	
	/// @brief Green
	component_type green;
	
	/// @brief Blue
	component_type blue;
	

	/**
	 * @brief Default constructor
	 *
	 * Initializes with default RGB values (0,0,0,0).
	 */
	constexpr nrgb_t() :
		red(0.0), green(0.0), blue(0.0)
	{}
	
	
	/**
	 * @brief Initialize with brightness
	 *
	 * Initializes with a brightness value @c y (y,y,y).
	 *
	 * @param y Brightness.
	 */
	constexpr nrgb_t(const component_type& y) :
		red(y), green(y), blue(y)
	{}
	
	
	/**
	 * @brief RGB initializer
	 *
	 * Initializes with values for red, green and blue channels (r,g,b).
	 *
	 * @param r Red.
	 * @param g Green.
	 * @param b Blue.
	 */
	constexpr nrgb_t(const component_type& r,const component_type& g,const component_type& b) :
		red(r), green(g), blue(b)
	{}
	
	
	/**
	 * @brief Initialize with brightness
	 *
	 * Initializes with a brightness value @c y (y,y,y).
	 *
	 * @param y Brightness.
	 */
	constexpr nrgb_t(const component_base_type& y) :
		red(y), green(y), blue(y)
	{}
	
	
	/**
	 * @brief RGB initializer
	 *
	 * Initializes with values for red, green and blue channels (r,g,b).
	 *
	 * @param r Red.
	 * @param g Green.
	 * @param b Blue.
	 */
	constexpr nrgb_t(const component_base_type& r,const component_base_type& g,const component_base_type& b) :
		red(r), green(g), blue(b)
	{}
	
	
	/**
	 * @brief Copy constructor
	 *
	 * Initializes an @ref nrgb_t with the contents of `other`.
	 */
	constexpr nrgb_t(const nrgb_t& other) :
		red(other.red),
		green(other.green),
		blue(other.blue)
	{}
	

	/**
	 * @brief Copy assignment operator
	 *
	 * Replaces the contents of a @ref nrgb_t with those of `other`.
	 */
	nrgb_t& operator=(const nrgb_t& other)
	{
		red   = other.red;
		green = other.green;
		blue  = other.blue;
	
		return *this;
	}
	

	/**
	 * @brief Sets red value
	 *
	 * Sets a value for the red component.
	 *
	 * @param new_r The new value.
	 */
	nrgb_t& set_red(const component_type& new_r)
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
	nrgb_t& set_green(const component_type& new_g)
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
	nrgb_t& set_blue(const component_type& new_b)
	{
		blue = new_b;
		return *this;
	}
	
	
	/**
	 * @brief Equality operator
	 *
	 * Checks if two @ref nrgb_t s are equal.
	 */
	constexpr friend bool operator==(const nrgb_t& lhs,const nrgb_t& rhs)
	{
		return (lhs.red == rhs.red) && (lhs.green == rhs.green) && (lhs.blue == rhs.blue);
	}
	
	
	/**
	 * @brief Inquality operator
	 *
	 * Checks if two @ref nrgb_t s are not equal.
	 */
	constexpr friend bool operator!=(const nrgb_t& lhs,const nrgb_t& rhs)
	{
		return !(lhs == rhs);
	}
	

	/**
	 * @brief Swaps the contents
	 *
	 * Swaps (exchanges) the contents with those of `other`.
	 */
	void swap(nrgb_t& other)
	{
		std::swap(red,other.red);
		std::swap(green,other.green);
		std::swap(blue,other.blue);
	}
	
	
	/**
	 * @brief Output stream operator
	 *
	 * Writes to an output stream.
	 */
	template <typename CharT,typename Traits>
	friend std::basic_ostream<CharT,Traits>& operator<<(std::basic_ostream<CharT,Traits>& os,const nrgb_t& out)
	{
		std::basic_ostringstream<CharT,Traits> ss;
		ss.flags(os.flags());
		ss.imbue(os.getloc());
		ss.precision(os.precision());
	
		ss << out.red << ' ' << out.green << ' ' << out.blue;
	
		return os << ss.str();
	}
	
	
	/**
	 * @brief Input stream operator
	 *
	 * Reads from an input stream.
	 */
	template <typename CharT,typename Traits>
	friend std::basic_istream<CharT,Traits>& operator>>(std::basic_istream<CharT,Traits>& is,nrgb_t& in)
	{
		is >> in.red >> std::ws
		   >> in.green >> std::ws
		   >> in.blue >> std::ws;
	
		return is;
	}
};

constexpr color_space nrgb_t::pixel_color_space;


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_RGB_TYPES_HPP
