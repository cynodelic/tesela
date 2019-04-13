// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file rectangle.hpp
 *
 * @brief Defines the `rectangle` type.
 */

#ifndef CYNODELIC_TESELA_RECTANGLE_HPP
#define CYNODELIC_TESELA_RECTANGLE_HPP


#include <istream>
#include <ostream>
#include <sstream>
#include <cstdlib>
#include <cstddef>
#include <utility>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/point.hpp>


namespace cynodelic { namespace tesela {


/**
 * @ingroup types
 * @brief Rectangle type
 *
 * A rectangle type, that contains width and height information, as well as
 * X-Y position.
 */
struct rectangle
{
	/// @brief Reference to its type
	using type = rectangle;


	/// @brief Width
	std::size_t width;
	
	/// @brief Height
	std::size_t height;

	/// @brief X position
	std::size_t x;
	
	/// @brief Y position
	std::size_t y;
	

	/**
	 * @brief Default constructor
	 *
	 * Initializes a rectangle with its default values (0, 0, 0, 0).
	 */
	constexpr rectangle() :
		width(0), height(0), x(0), y(0)
	{}

	
	/**
	 * @brief Constructor with width and height
	 *
	 * Creates an instance of @ref rectangle, providing its width and height.
	 *
	 * @param w Width
	 * @param h Height
	 */
	constexpr rectangle(
		const std::size_t& w,
		const std::size_t& h
	) :
		width(w),
		height(h),
		x(0), y(0)
	{}

	
	/**
	 * @brief Constructor with width and height
	 *
	 * Creates an instance of @ref rectangle, providing its width, height and
	 * its X-Y position.
	 *
	 * @param w Width
	 * @param h Height
	 * @param x X position
	 * @param y Y position
	 */
	constexpr rectangle(
		const std::size_t& w,
		const std::size_t& h,
		const std::size_t& x,
		const std::size_t& y
	) :
		width(w),
		height(h),
		x(x), y(y)
	{}


	/**
	 * @brief Constructor from two points
	 *
	 * Creates a rectangle from two @ref point s: the top left corner (`from`) and
	 * the bottom right corner (`to`).
	 *
	 * @param from The point corresponding to the position of the top left corner.
	 * @param to   The point corresponding to the position of the bottom right
	 *             corner.
	 */
	constexpr rectangle(
		const point& from,
		const point& to
	) :
		width(to.x - from.x),
		height(to.y - from.y),
		x(from.x),
		y(from.y)
	{}
	
	
	/**
	 * @brief Copy constructor
	 *
	 * Initializes a rectangle with the content of `other`.
	 */
	constexpr rectangle(const rectangle& other) :
		width(other.width),
		height(other.height),
		x(other.x),
		y(other.y)
	{}
	
	
	/**
	 * @brief Copy assignment
	 *
	 * Replaces the content of a rectangle with the content of `other`.
	 */
	constexpr rectangle& operator=(const rectangle& other)
	{
		width  = other.width;
		height = other.height;
		x      = other.x;
		y      = other.y;
		
		return *this;
	}


	/**
	 * @brief Swaps the contents
	 *
	 * Swaps (exchanges) the contents of the rectangle with those of another one.
	 */
	void swap(rectangle& other)
	{
		std::swap(width,other.width);
		std::swap(height,other.height);
		std::swap(x,other.x);
		std::swap(y,other.y);
	}
	
	
	/**
	 * @brief Equality operator
	 *
	 * Checks if two @ref rectangle s are equal.
	 */
	constexpr friend bool operator==(const rectangle& lhs,const rectangle& rhs)
	{
		return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.width == rhs.width) && (lhs.height == rhs.height);
	}
	
	
	/**
	 * @brief Inequality operator
	 *
	 * Checks if two @ref rectangle s are not equal.
	 */
	constexpr friend bool operator!=(const rectangle& lhs,const rectangle& rhs)
	{
		return !(lhs == rhs);
	}
	
	
	/**
	 * @brief Output stream operator
	 *
	 * Writes to an output stream.
	 */
	template <class CharT,class Traits>
	friend std::basic_ostream<CharT,Traits>& operator<<(std::basic_ostream<CharT,Traits>& os,const rectangle& r)
	{
		std::basic_ostringstream<CharT,Traits> ss;
		ss.flags(os.flags());
		ss.imbue(os.getloc());
		ss.precision(os.precision());
		
		ss << r.width << ' '
		   << r.height << ' '
		   << r.x << ' '
		   << r.y;

		return os << ss.str();
	}
	
	
	/**
	 * @brief Input stream operator
	 *
	 * Reads from an input stream.
	 */
	template <class CharT,class Traits>
	friend std::basic_istream<CharT,Traits>& operator>>(std::basic_istream<CharT,Traits>& is,rectangle& r)
	{
		is >> r.width >> std::ws
		   >> r.height >> std::ws
		   >> r.x >> std::ws
		   >> r.y >> std::ws;
		
		return is;
	}
};


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_RECTANGLE_HPP
