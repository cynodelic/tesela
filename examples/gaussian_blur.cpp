/*
 * - gaussian_blur.cpp:
 *
 * Applies a Gaussian blur effect to an image.
 *
 * Note: Tesela's gaussian blur filter has an O(n^4) complexity,
 * but I encourage you to make a faster one.
 *
 * Usage: ./gaussian_blur [image] [blur size]
 */

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <string>

#define CYNODELIC_TESELA_VERBOSE
#include "cynodelic/tesela/tesela.hpp"

int main(int argc,char **argv)
{
	cynodelic::tesela::image img;
	cynodelic::tesela::image_read(argv[1],img);
	
	int rad = std::stoi(argv[2]);
	
	std::cout << "Blur radius: " << rad << "\n";
	
	cynodelic::tesela::gaussian_blur(img,rad);
	
	cynodelic::tesela::image_write("gaussian_blur_demo.png",img);
}

