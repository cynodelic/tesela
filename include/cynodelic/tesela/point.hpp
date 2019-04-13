// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file point.hpp
 *
 * @brief Defines the `point` type.
 */

#ifndef CYNODELIC_TESELA_POINT_HPP
#define CYNODELIC_TESELA_POINT_HPP


#include <istream>
#include <ostream>
#include <sstream>
#include <cstdlib>
#include <cstddef>
#include <utility>

#include <cynodelic/tesela/config.hpp>


namespace cynodelic { namespace tesela {


/**
 * @ingroup types
 * @brief Point type
 *
 * A type that represents a point in the X-Y coordinates.
 */
struct point
{
	/// @brief Reference to its type
	using type = point;


	/// @brief X position
	std::size_t x;

	/// @brief Y position
	std::size_t y;


	/**
	 * @brief Default constructor
	 *
	 * Creates a @ref point with the default values (0,0).
	 */
	constexpr point() :
		x(0), y(0)
	{}


	/**
	 * @brief Constructor with X and Y values
	 *
	 * Creates a @ref point with the values corresponding to the X and Y
	 * coordinates.
	 *
	 * @param x The X position.
	 * @param y The Y position.
	 */
	constexpr point(const std::size_t& x,const std::size_t& y) :
		x(x), y(y)
	{}


	/**
	 * @brief Copy constructor
	 *
	 * Initializes a @ref point with the content of `other`.
	 *
	 * @param other The other instance.
	 */
	constexpr point(const point& other) :
		x(other.x),
		y(other.y)
	{}


	/**
	 * @brief Copy assignment operator
	 *
	 * Replaces the content of a @ref point with the one from `other`.
	 */
	constexpr point& operator=(const point& other)
	{
		x = other.x;
		y = other.y;

		return *this;
	}


	/**
	 * @brief Swaps contents
	 *
	 * Swaps (exchanges) the contents of a @ref point with those of `other`.
	 *
	 * @param other the other instance.
	 */
	void swap(point& other)
	{
		std::swap(x,other.x);
		std::swap(y,other.y);
	}


	/**
	 * @brief Equality operator
	 *
	 * Checks if two @ref point s are equal.
	 */
	constexpr friend bool operator==(const point& lhs,const point& rhs)
	{
		return (lhs.x == rhs.x) && (lhs.y == rhs.y);
	}


	/**
	 * @brief Inquality operator
	 *
	 * Checks if two @ref point s are not equal.
	 */
	constexpr friend bool operator!=(const point& lhs,const point& rhs)
	{
		return !(lhs == rhs);
	}
	

	/**
	 * @brief Output stream operator
	 *
	 * Writes to an output stream.
	 */
	template <typename CharT,typename Traits>
	friend std::basic_ostream<CharT,Traits>& operator<<(std::basic_ostream<CharT,Traits>& os,const point& pt)
	{
		std::basic_ostringstream<CharT,Traits> ss;
		ss.flags(os.flags());
		ss.imbue(os.getloc());
		ss.precision(os.precision());
		
		ss << pt.x << ' ' << pt.y;

		return os << ss.str();
	}


	/**
	 * @brief Input stream operator
	 *
	 * Reads from an input stream.
	 */
	template <typename CharT,typename Traits>
	friend std::basic_istream<CharT,Traits>& operator>>(std::basic_istream<CharT,Traits>& is,point& pt)
	{
		is >> pt.x >> std::ws
		   >> pt.y >> std::ws;
		
		return is;
	}
};


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_POINT_HPP
