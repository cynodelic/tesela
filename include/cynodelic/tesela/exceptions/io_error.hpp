// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file io_error.hpp
 *
 * @brief Defines the `io_error` exception class.
 */

#ifndef CYNODELIC_TESELA_EXCEPTIONS_IO_ERROR_HPP
#define CYNODELIC_TESELA_EXCEPTIONS_IO_ERROR_HPP


#include <cstdlib>
#include <string>
#include <stdexcept>

#include <cynodelic/tesela/config.hpp>


namespace cynodelic { namespace tesela
{


/**
 * @ingroup exceptions
 * @brief Input/output exception
 *
 * An exception that is thrown during reading and/or writing image files, if
 * an error ocurred.
 */
class io_error : public std::runtime_error
{
	public:
		/**
		 * @brief Constructor
		 */
		io_error(const std::string& what_arg) :
			std::runtime_error(what_arg)
		{}


		/**
		 + @brief Constructor
		 */
		io_error(const char* what_arg) :
			std::runtime_error(what_arg)
		{}
};


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_EXCEPTIONS_IO_ERROR_HPP
