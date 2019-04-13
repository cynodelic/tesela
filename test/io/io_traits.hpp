// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_IO_IO_TRAITS_HPP
#define CYNODELIC_TESELA_TEST_IO_IO_TRAITS_HPP


CYNODELIC_TESTER_TEST_CASE(io_traits);

CYNODELIC_TESTER_SECTION(io_traits,is_image_format_io)
{
	CYNODELIC_TESTER_CHECK_TRUE(tsl::is_image_format_io<tsl::jpeg_io>::value);
	CYNODELIC_TESTER_CHECK_TRUE(tsl::is_image_format_io<tsl::png_io>::value);
	CYNODELIC_TESTER_CHECK_TRUE(tsl::is_image_format_io<tsl::tiff_io>::value);
	CYNODELIC_TESTER_CHECK_FALSE(tsl::is_image_format_io<int>::value);
}

#endif // CYNODELIC_TESELA_TEST_IO_IO_TRAITS_HPP
