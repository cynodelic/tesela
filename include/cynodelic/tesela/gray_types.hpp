// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file gray_types.hpp
 *
 * @brief Defines grayscale pixel types.
 */

#ifndef CYNODELIC_TESELA_GRAY_TYPES_HPP
#define CYNODELIC_TESELA_GRAY_TYPES_HPP


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
 * @brief grayscale pixel type
 *
 * A grayscale pixel type, with values between 0 and 255.
 */
struct gray_t
{
	/// @brief Reference to itself
	using type = gray_t;

	/// @brief Type used for each component
	using component_type = std::uint8_t;

	/// @brief The corresponding color space
	static constexpr color_space pixel_color_space = color_space::gray;


	/// @brief Gray
	component_type gray;
	

	/**
	 * @brief Default constructor
	 *
	 * Initializes with the default gray value (0).
	 */
	constexpr gray_t() :
		gray(0x00)
	{}

	
	/**
	 * @brief Initialize with brightness
	 *
	 * Initializes with a brightness value @c y.
	 *
	 * @param y Brightness.
	 */
	constexpr gray_t(const component_type& y) :
		gray(y)
	{}
	

	/**
	 * @brief Copy assignment operator
	 *
	 * Replaces the contents of a @ref gray_t with those of `other`.
	 */
	gray_t& operator=(const gray_t& other)
	{
		gray = other.gray;

		return *this;
	}
	

	/**
	 * @brief Sets gray value
	 *
	 * Sets a value for the gray component.
	 *
	 * @param new_r The new value.
	 */
	gray_t& set_gray(const component_type& new_y)
	{
		gray = new_y;
		return *this;
	}
	

	/**
	 * @brief Equality operator
	 *
	 * Checks if two @ref gray_t s are equal.
	 */
	constexpr friend bool operator==(const gray_t& lhs,const gray_t& rhs)
	{
		return (lhs.gray == rhs.gray);
	}
	
	
	/**
	 * @brief Inequality operator
	 *
	 * Checks if two @ref gray_t s are not equal.
	 */
	constexpr friend bool operator!=(const gray_t& lhs,const gray_t& rhs)
	{
		return !(lhs == rhs);
	}
	

	/**
	 * @brief Swaps the contents
	 *
	 * Swaps (exchanges) the contents with those of `other`.
	 */
	void swap(gray_t& other)
	{
		std::swap(gray,other.gray);
	}
	
	
	/**
	 * @brief Output stream operator
	 *
	 * Writes to an output stream.
	 */
	template <typename CharT,typename Traits>
	friend std::basic_ostream<CharT,Traits>& operator<<(std::basic_ostream<CharT,Traits>& os,const gray_t& out)
	{
		std::basic_ostringstream<CharT,Traits> ss;
		ss.flags(os.flags());
		ss.imbue(os.getloc());
		ss.precision(os.precision());
	
		ss << static_cast<unsigned>(out.gray);
		
		return os << ss.str();
	}
	
	/**
	 * @brief Input stream operator
	 *
	 * Reads from an input stream.
	 */
	template <typename CharT,typename Traits>
	friend std::basic_istream<CharT,Traits>& operator>>(std::basic_istream<CharT,Traits>& is,gray_t& in)
	{
		unsigned aux_y;
	
		is >> aux_y >> std::ws;
	
		in = gray_t(
			static_cast<std::uint8_t>(aux_y)
		);

		return is;
	}
};

constexpr color_space gray_t::pixel_color_space;


/**
 * @ingroup pixeltypes
 * @brief Normalized grayscale pixel type
 *
 * A grayscale pixel type, with values between 0.0 and 1.0.
 */
struct ngray_t
{
	/// @brief Reference to itself
	using type = ngray_t;
	
	/// @brief Type used for each component
	using component_type = tdouble;
	
	/// @brief The underlying type of the component type
	using component_base_type = typename component_type::value_type;
	
	/// @brief The corresponding color space
	static constexpr color_space pixel_color_space = color_space::gray;
	

	/// @brief Gray
	component_type gray;
	

	/**
	 * @brief Default constructor
	 *
	 * Initializes with a default gray value (0).
	 */
	constexpr ngray_t() :
		gray(0.0)
	{}
	

	/**
	 * @brief Initialize with brightness
	 *
	 * Initializes with a brightness value @c y.
	 *
	 * @param y Brightness.
	 */
	constexpr ngray_t(const component_type& y) :
		gray(y)
	{}
	

	/**
	 * @brief Initialize with brightness
	 *
	 * Initializes with a brightness value @c y.
	 *
	 * @param y Brightness.
	 */
	constexpr ngray_t(const component_base_type& y) :
		gray(y)
	{}
	

	/**
	 * @brief Copy constructor
	 *
	 * Initializes an @ref ngray_t with the contents of `other`.
	 */
	constexpr ngray_t(const ngray_t& other) :
		gray(other.gray)
	{}


	/**
	 * @brief Copy assignment operator
	 *
	 * Replaces the contents of a @ref ngray_t with those of `other`.
	 */
	ngray_t& operator=(const ngray_t& other)
	{
		gray = other.gray;

		return *this;
	}


	/**
	 * @brief Sets gray value
	 *
	 * Sets a value for the gray component.
	 *
	 * @param new_y The new value.
	 */
	ngray_t& set_gray(const component_type& new_y)
	{
		gray = new_y;
		return *this;
	}
	
	
	/**
	 * @brief Equality operator
	 *
	 * Checks if two @ref ngray_t s are equal.
	 */
	constexpr friend bool operator==(const ngray_t& lhs,const ngray_t& rhs)
	{
		return (lhs.gray == rhs.gray);
	}
	
	
	/**
	 * @brief Inquality operator
	 *
	 * Checks if two @ref ngray_t s are not equal.
	 */
	constexpr friend bool operator!=(const ngray_t& lhs,const ngray_t& rhs)
	{
		return !(lhs == rhs);
	}


	/**
	 * @brief Swaps the contents
	 *
	 * Swaps (exchanges) the contents with those of `other`.
	 */
	void swap(ngray_t& other)
	{
		std::swap(gray,other.gray);
	}
	
	
	/**
	 * @brief Output stream operator
	 *
	 * Writes to an output stream.
	 */
	template <typename CharT,typename Traits>
	friend std::basic_ostream<CharT,Traits>& operator<<(std::basic_ostream<CharT,Traits>& os,const ngray_t& out)
	{
		std::basic_ostringstream<CharT,Traits> ss;
		ss.flags(os.flags());
		ss.imbue(os.getloc());
		ss.precision(os.precision());

		ss << out.gray;

		return os << ss.str();
	}
	
	
	/**
	 * @brief Input stream operator
	 *
	 * Reads from an input stream.
	 */
	template <typename CharT,typename Traits>
	friend std::basic_istream<CharT,Traits>& operator>>(std::basic_istream<CharT,Traits>& is,ngray_t& in)
	{
		is >> in.gray >> std::ws;

		return is;
	}
};

constexpr color_space ngray_t::pixel_color_space;


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_GRAY_TYPES_HPP
