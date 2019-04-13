// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file tdouble.hpp
 *
 * @brief Defines the `tdouble` type.
 */

#ifndef CYNODELIC_TESELA_TDOUBLE_HPP
#define CYNODELIC_TESELA_TDOUBLE_HPP


#include <istream>
#include <ostream>
#include <sstream>
#include <cstdlib>
#include <cstddef>
#include <limits>
#include <utility>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/detail/utils.hpp>
#include <cynodelic/tesela/detail/tdouble_ops.hpp>


namespace cynodelic { namespace tesela {


/**
 * @ingroup types
 * @brief Quantized double
 *
 * Double-precision floating point type, which reduces all values between
 * 1 and 0, to 255 values, for easing image conversion.
 */
class tdouble
{
	public:
		/// @brief Reference to its type
		using type = tdouble;
		

		/// @brief Wrapped type
		using value_type = double;
		

		/// @brief Threshold of quantization
		static constexpr unsigned threshold = 255;


		/**
		 * @brief Default constructor
		 *
		 * Initializes the @ref tdouble with the default value (0.0).
		 */
		constexpr explicit tdouble() :
			data(0.0)
		{}


		/**
		 * @brief Constructor with arithmetic value
		 *
		 * Initializes the @ref tdouble with a numeric (arithmetic) value.
		 */
		template <typename T>
		constexpr explicit tdouble(T val) :
			data(quantize(val))
		{}


		/**
		 * @brief Copy constructor
		 *
		 * Initializes the @ref tdouble with the content of `other`.
		 */
		constexpr tdouble(const tdouble& other) :
			data(other.data)
		{}


		/// @brief Destructor
		~tdouble() = default;


		/**
		 * @brief Copy assignment operator
		 *
		 * Replaces the value of a @ref tdouble with the value of `other`.
		 */
		constexpr tdouble& operator=(const tdouble& other)
		{
			data = other.data;
			return *this;
		}

		/**
		 * @brief Assignment operator
		 *
		 * Assigns a value of an arithmetic type to a @ref tdouble.
		 */
		template <typename T>
		constexpr tdouble& operator=(T val)
		{
			data = quantize(val);
			return *this;
		}


		/**
		 * @brief Gets the current value
		 *
		 * Returns the current value from an instance of @ref tdouble.
		 */
		constexpr const value_type& get() const
		{
			return data;
		}


		/**
		 * @brief Casts to double
		 *
		 * Casts the instance of @ref tdouble to its base type.
		 */
		constexpr operator value_type() const noexcept
		{
			return data;
		}


		/**
		 * @brief Swaps the content
		 *
		 * Swaps (exchanges) the current value with the one of `other`.
		 */
		void swap(tdouble& other)
		{
			std::swap(data,other.data);
		}


		/**
		 * @brief Unary plus operator
		 *
		 * Does not alter the current value.
		 */
		tdouble operator+()
		{
			return *this;
		}


		/**
		 * @brief Unary minus operator
		 *
		 * Negates the current value.
		 */
		tdouble operator-()
		{
			return tdouble(-data);
		}

		CYNODELIC_TESELA_TDOUBLE_DEFINE_ARITHMETIC_OPERATOR(+)
		CYNODELIC_TESELA_TDOUBLE_DEFINE_ARITHMETIC_OPERATOR(-)
		CYNODELIC_TESELA_TDOUBLE_DEFINE_ARITHMETIC_OPERATOR(*)
		CYNODELIC_TESELA_TDOUBLE_DEFINE_ARITHMETIC_OPERATOR(/)

		CYNODELIC_TESELA_TDOUBLE_DEFINE_COMPOUND_OPERATOR(+=,+)
		CYNODELIC_TESELA_TDOUBLE_DEFINE_COMPOUND_OPERATOR(-=,-)
		CYNODELIC_TESELA_TDOUBLE_DEFINE_COMPOUND_OPERATOR(*=,*)
		CYNODELIC_TESELA_TDOUBLE_DEFINE_COMPOUND_OPERATOR(/=,/)

		CYNODELIC_TESELA_TDOUBLE_DEFINE_COMPARISON_OPERATOR(>)
		CYNODELIC_TESELA_TDOUBLE_DEFINE_COMPARISON_OPERATOR(<)
		CYNODELIC_TESELA_TDOUBLE_DEFINE_COMPARISON_OPERATOR(>=)
		CYNODELIC_TESELA_TDOUBLE_DEFINE_COMPARISON_OPERATOR(<=)
		CYNODELIC_TESELA_TDOUBLE_DEFINE_COMPARISON_OPERATOR(==)
		CYNODELIC_TESELA_TDOUBLE_DEFINE_COMPARISON_OPERATOR(!=)


		/**
		 * @brief Output stream operator
		 *
		 * Writes to an output stream.
		 */
		template <class CharT,class Traits>
		friend std::basic_ostream<CharT,Traits>& operator<<(std::basic_ostream<CharT,Traits>& os,const tdouble& out)
		{
			std::basic_ostringstream<CharT,Traits> ss;
			ss.flags(os.flags());
			ss.imbue(os.getloc());
			ss.precision(os.precision());

			ss << out.data;
			
			return os << ss.str();
		}


		/**
		 * @brief Input stream operator
		 *
		 * Reads from an input stream.
		 */
		template <class CharT,class Traits>
		friend std::basic_istream<CharT,Traits>& operator>>(std::basic_istream<CharT,Traits>& is,tdouble& in)
		{
			is >> in.data;
			return is;
		}
	private:
		value_type data;

		inline constexpr value_type quantize(const value_type& x,value_type fth = static_cast<value_type>(threshold))
		{
			return detail::dfloor_cx<value_type>((x + std::numeric_limits<value_type>::epsilon())*fth)/fth;
		}
};

constexpr unsigned tdouble::threshold;


}} // end of "cynodelic::tesela" namespace


#undef CYNODELIC_TESELA_TDOUBLE_DEFINE_ARITHMETIC_OPERATOR
#undef CYNODELIC_TESELA_TDOUBLE_DEFINE_COMPARISION_OPERATOR
#undef CYNODELIC_TESELA_TDOUBLE_DEFINE_COMPOUND_OPERATOR


#endif // CYNODELIC_TESELA_TDOUBLE_HPP
