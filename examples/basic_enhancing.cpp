/*
 * - basic_enhancing.cpp:
 *
 * Basic enhancing (brightness, contrast and gamma) for images.
 * Brightness and contrast should be between -1 and 1, and gamma should not
 * be 0 (zero).
 *
 * Usage: ./basic_enhancing [image] [brightness] [contrast] [gamma]
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

#define CYNODELIC_TESELA_VERBOSE
#include "cynodelic/tesela/tesela.hpp"

int main(int argc,char **argv)
{
	double b, c, g;
	b = std::stod(argv[2]);
	c = std::stod(argv[3]);
	g = std::stod(argv[4]);
	
	std::cout << "Brightness: " << b << "\n";
	std::cout << "Contrast:   " << c << "\n";
	std::cout << "Gamma:      " << g << "\n";
	
	cynodelic::tesela::image img;
	cynodelic::tesela::image_read(argv[1],img);
	cynodelic::tesela::brightness(img,b);
	cynodelic::tesela::contrast(img,c);
	cynodelic::tesela::gamma(img,g);
	cynodelic::tesela::image_write("basic_enhancing_demo.png",img);
}

