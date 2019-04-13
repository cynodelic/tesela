// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file ga_types.hpp
 *
 * @brief Defines gray-alpha pixel types.
 */

#ifndef CYNODELIC_TESELA_GA_TYPES_HPP
#define CYNODELIC_TESELA_GA_TYPES_HPP


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
 * @brief gray-alpha pixel type
 *
 * A gray-alpha pixel type, with values between 0 and 255.
 */
struct ga_t
{
	/// @brief Reference to itself
	using type = ga_t;

	/// @brief Type used for each component
	using component_type = std::uint8_t;

	/// @brief The corresponding color space
	static constexpr color_space pixel_color_space = color_space::ga;


	/// @brief Red
	component_type gray;
	
	/// @brief Alpha
	component_type alpha;

	
	/**
	 * @brief Default constructor
	 *
	 * Initializes with default gray-alpha values (0,0).
	 */
	constexpr ga_t() :
		gray(0x00), alpha(0x00)
	{}

		
	/**
	 * @brief Initialize with brightness
	 *
	 * Initializes with a brightness value @c y (y,255).
	 *
	 * @param y Brightness.
	 */
	constexpr ga_t(const component_type& y) :
		gray(y), alpha(0xff)
	{}

		
	/**
	 * @brief Initialize with brightness and alpha
	 *
	 * Initializes with brightness and alpha values (y,a).
	 *
	 * @param y Brightness.
	 * @param a Alpha.
	 */
	constexpr ga_t(const component_type& y,const component_type& a) :
		gray(y), alpha(a)
	{}



	/**
	 * @brief Copy assignment operator
	 *
	 * Replaces the contents of a @ref ga_t with those of `other`.
	 */
	ga_t& operator=(const ga_t& other)
	{
		gray  = other.gray;
		alpha = other.alpha;

		return *this;
	}


	/**
	 * @brief Sets gray value
	 *
	 * Sets a value for the gray component.
	 *
	 * @param new_y The new value.
	 */
	ga_t& set_gray(const component_type& new_y)
	{
		gray = new_y;
		return *this;
	}


	/**
	 * @brief Sets alpha value
	 *
	 * Sets a value for the alpha component.
	 *
	 * @param new_a The new value.
	 */
	ga_t& set_alpha(const component_type& new_a)
	{
		alpha = new_a;
		return *this;
	}
		

	/**
	 * @brief Equality operator
	 *
	 * Checks if two @ref ga_t s are equal.
	 */
	constexpr friend bool operator==(const ga_t& lhs,const ga_t& rhs)
	{
		return (lhs.gray == rhs.gray) && (lhs.alpha == rhs.alpha);
	}

		
	/**
	 * @brief Inequality operator
	 *
	 * Checks if two @ref ga_t s are not equal.
	 */
	constexpr friend bool operator!=(const ga_t& lhs,const ga_t& rhs)
	{
		return !(lhs == rhs);
	}


	/**
	 * @brief Swaps the contents
	 *
	 * Swaps (exchanges) the contents with those of `other`.
	 */
	void swap(ga_t& other)
	{
		std::swap(gray,other.gray);
		std::swap(alpha,other.alpha);
	}
		
		
	/**
	 * @brief Output stream operator
	 *
	 * Writes to an output stream.
	 */
	template <typename CharT,typename Traits>
	friend std::basic_ostream<CharT,Traits>& operator<<(std::basic_ostream<CharT,Traits>& os,const ga_t& out)
	{
		std::basic_ostringstream<CharT,Traits> ss;
		ss.flags(os.flags());
		ss.imbue(os.getloc());
		ss.precision(os.precision());

		ss << static_cast<unsigned>(out.gray) << ' '
		   << static_cast<unsigned>(out.alpha);
		
		return os << ss.str();
	}

		
	/**
	 * @brief Input stream operator
	 *
	 * Reads from an input stream.
	 */
	template <typename CharT,typename Traits>
	friend std::basic_istream<CharT,Traits>& operator>>(std::basic_istream<CharT,Traits>& is,ga_t& in)
	{
		unsigned aux_y, aux_a;

		is >> aux_y >> std::ws
		   >> aux_a >> std::ws;
		
		in = ga_t(
			static_cast<std::uint8_t>(aux_y),
			static_cast<std::uint8_t>(aux_a)
		);
		
		return is;
	}
};

constexpr color_space ga_t::pixel_color_space;


/**
 * @ingroup pixeltypes
 * @brief Normalized gray-alpha pixel type
 *
 * A gray-alpha pixel type, with values between 0.0 and 1.0.
 */
struct nga_t
{
	/// @brief Reference to itself
	using type = nga_t;

	/// @brief Type used for each component
	using component_type = tdouble;

	/// @brief The underlying type of the component type
	using component_base_type = typename component_type::value_type;

	/// @brief The corresponding color space
	static constexpr color_space pixel_color_space = color_space::ga;


	/// @brief Red
	component_type gray;
	
	/// @brief Alpha
	component_type alpha;

		
	/**
	 * @brief Default constructor
	 *
	 * Initializes with default gray and alpha values (0,0).
	 */
	constexpr nga_t() :
		gray(0.0), alpha(0.0)
	{}

	
	/**
	 * @brief Initialize with brightness
	 *
	 * Initializes with a brightness value @c y (y,1.0).
	 *
	 * @param y Brightness.
	 */
	constexpr nga_t(const component_type& y) :
		gray(y), alpha(1.0)
	{}
	

	/**
	 * @brief Initialize with brightness and alpha
	 *
	 * Initializes with brightness and alpha values (y,a).
	 *
	 * @param y Brightness.
	 * @param a Alpha.
	 */
	constexpr nga_t(const component_type& y,const component_type& a) :
		gray(y), alpha(a)
	{}
	
	
	/**
	 * @brief Initialize with brightness
	 *
	 * Initializes with a brightness value @c y (y,1.0).
	 *
	 * @param y Brightness.
	 */
	constexpr nga_t(const component_base_type& y) :
		gray(y), alpha(1.0)
	{}
	
	
	/**
	 * @brief Initialize with brightness and alpha
	 *
	 * Initializes with brightness and alpha values (y,a).
	 *
	 * @param y Brightness.
	 * @param a Alpha.
	 */
	constexpr nga_t(const component_base_type& y,const component_base_type& a) :
		gray(y), alpha(a)
	{}
	
	
	/**
	 * @brief Copy constructor
	 *
	 * Initializes an @ref nga_t with the contents of `other`.
	 */
	constexpr nga_t(const nga_t& other) :
		gray(other.gray),
		alpha(other.alpha)
	{}


	/**
	 * @brief Copy assignment operator
	 *
	 * Replaces the contents of a @ref nga_t with those of `other`.
	 */
	nga_t& operator=(const nga_t& other)
	{
		gray  = other.gray;
		alpha = other.alpha;

		return *this;
	}


	/**
	 * @brief Sets gray value
	 *
	 * Sets a value for the gray component.
	 *
	 * @param new_y The new value.
	 */
	nga_t& set_gray(const component_type& new_y)
	{
		gray = new_y;
		return *this;
	}
	

	/**
	 * @brief Sets alpha value
	 *
	 * Sets a value for the alpha component.
	 *
	 * @param new_a The new value.
	 */
	nga_t& set_alpha(const component_type& new_a)
	{
		alpha = new_a;
		return *this;
	}
	
	
	/**
	 * @brief Equality operator
	 *
	 * Checks if two @ref nga_t s are equal.
	 */
	constexpr friend bool operator==(const nga_t& lhs,const nga_t& rhs)
	{
		return (lhs.gray == rhs.gray) && (lhs.alpha == rhs.alpha);
	}
	

	/**
	 * @brief Inquality operator
	 *
	 * Checks if two @ref nga_t s are not equal.
	 */
	constexpr friend bool operator!=(const nga_t& lhs,const nga_t& rhs)
	{
		return !(lhs == rhs);
	}
	

	/**
	 * @brief Swaps the contents
	 *
	 * Swaps (exchanges) the contents with those of `other`.
	 */
	void swap(nga_t& other)
	{
		std::swap(gray,other.gray);
		std::swap(alpha,other.alpha);
	}
	
	
	/**
	 * @brief Output stream operator
	 *
	 * Writes to an output stream.
	 */
	template <typename CharT,typename Traits>
	friend std::basic_ostream<CharT,Traits>& operator<<(std::basic_ostream<CharT,Traits>& os,const nga_t& out)
	{
		std::basic_ostringstream<CharT,Traits> ss;
		ss.flags(os.flags());
		ss.imbue(os.getloc());
		ss.precision(os.precision());
	
		ss << out.gray << ' ' << out.alpha;
	
		return os << ss.str();
	}
	
	/**
	 * @brief Input stream operator
	 *
	 * Reads from an input stream.
	 */
	template <typename CharT,typename Traits>
	friend std::basic_istream<CharT,Traits>& operator>>(std::basic_istream<CharT,Traits>& is,nga_t& in)
	{
		is >> in.gray >> std::ws
		   >> in.alpha >> std::ws;
	
		return is;
	}
};

constexpr color_space nga_t::pixel_color_space;


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_GA_TYPES_HPP
