// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file tdouble_ops.hpp
 *
 * @brief Macros for defining `tdouble` operators.
 */

#ifndef CYNODELIC_TESELA_DETAIL_TDOUBLE_OPS_HPP
#define CYNODELIC_TESELA_DETAIL_TDOUBLE_OPS_HPP


#include <cynodelic/tesela/config.hpp>


#define CYNODELIC_TESELA_TDOUBLE_DEFINE_ARITHMETIC_OPERATOR(op) \
		constexpr friend tdouble operator op(const tdouble& lhs,const tdouble& rhs) \
		{ \
			return tdouble(lhs.data op rhs.data); \
		} \
		constexpr friend tdouble operator op(const tdouble& lhs,const value_type& rhs) \
		{ \
			return tdouble(lhs.data op tdouble(rhs).data); \
		} \
		constexpr friend tdouble operator op(const value_type& lhs,const tdouble& rhs) \
		{ \
			return tdouble(tdouble(lhs).data op rhs.data); \
		}


#define CYNODELIC_TESELA_TDOUBLE_DEFINE_COMPARISON_OPERATOR(op) \
		constexpr friend bool operator op(const tdouble& lhs,const tdouble& rhs) \
		{ \
			return lhs.data op rhs.data; \
		} \
		constexpr friend bool operator op(const tdouble& lhs,const value_type& rhs) \
		{ \
			return lhs.data op rhs; \
		} \
		constexpr friend bool operator op(const value_type& lhs,const tdouble& rhs) \
		{ \
			return lhs op rhs.data; \
		}


#define CYNODELIC_TESELA_TDOUBLE_DEFINE_COMPOUND_OPERATOR(cmp_op,op) \
		template <typename T> \
		tdouble& operator cmp_op(const T& rhs) \
		{ \
			data = quantize(data op quantize(rhs)); \
			return *this; \
		} \
		tdouble& operator cmp_op(const tdouble& rhs) \
		{ \
			data = quantize(data op rhs.data); \
			return *this; \
		}


#endif // CYNODELIC_TESELA_DETAIL_TDOUBLE_OPS_HPP
