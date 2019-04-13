// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file void_t.hpp
 *
 * @brief Defines the `void_t` helper alias.
 */

#ifndef CYNODELIC_TESELA_DETAIL_VOID_T_HPP
#define CYNODELIC_TESELA_DETAIL_VOID_T_HPP


#include <cynodelic/tesela/config.hpp>


namespace cynodelic { namespace tesela {

namespace detail
{
	/**
	 * @brief Helper for `void_t`
	 */
	template <typename...>
	struct void_t_impl
	{
		using type = void;
	};


	/**
	 * @brief Helper alias for `void`.
	 *
	 * A helper alias, useful for checking the existence of a class member.
	 */
	template <typename... Args>
	using void_t = typename void_t_impl<Args...>::type;
} // end of "detail" namespace

}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_DETAIL_VOID_T_HPP
