// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/*
 * @file literals.cpp
 *
 * Demonstrates the use of literals.
 */

#include <iostream>
#include <cstdlib>

#include <cynodelic/tesela/tdouble.hpp>
#include <cynodelic/tesela/rgb_types.hpp>
#include <cynodelic/tesela/rgba_types.hpp>
#include <cynodelic/tesela/gray_types.hpp>
#include <cynodelic/tesela/ga_types.hpp>
#include <cynodelic/tesela/literals.hpp>


namespace tsl = cynodelic::tesela;


int main()
{
	using namespace tsl::literals;

	std::cout << "Instance of tdouble initialized with literal:\n";
	std::cout << "    0.46667324521_td: " << 0.46667324521_td << "\n";

	std::cout << "Instance of rgb_t initialized with literal:\n";
	std::cout << "    0x3f551a_hrgb: " << 0x3f551a_hrgb << "\n";

	std::cout << "Instance of rgba_t initialized with literal:\n";
	std::cout << "    0xf0ab6792_hrgba: " << 0xf0ab6792_hrgba << "\n";

	std::cout << "Instance of gray_t initialized with literal:\n";
	std::cout << "    0xa8_hgray: " << 0xa8_hgray << "\n";

	std::cout << "Instance of ga_t initialized with literal:\n";
	std::cout << "    0x39ce_hga: " << 0x39ce_hga << "\n";

	std::cout << "Instance of nrgb_t initialized with literal:\n";
	std::cout << "    0x3f551a_hnrgb: " << 0x3f551a_hnrgb << "\n";

	std::cout << "Instance of nrgba_t initialized with literal:\n";
	std::cout << "    0xf0ab6792_hnrgba: " << 0xf0ab6792_hnrgba << "\n";

	std::cout << "Instance of ngray_t initialized with literal:\n";
	std::cout << "    0xa8_hngray: " << 0xa8_hngray << "\n";

	std::cout << "Instance of nga_t initialized with literal:\n";
	std::cout << "    0x39ce_hnga: " << 0x39ce_hnga << "\n";
}
