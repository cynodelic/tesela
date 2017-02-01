/*
 * - image_crop.cpp:
 *
 * Crops an image.
 *
 * Usage: ./image_crop [image] [x start] [y start] [x size] [y size]
 */

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <string>

#define CYNODELIC_TESELA_VERBOSE
#include "cynodelic/tesela/tesela.hpp"

int main(int argc,char **argv)
{
	cynodelic::tesela::image img;
	cynodelic::tesela::image_read(argv[1],img);
	
	cynodelic::tesela::rectangle area(
		std::stoi(argv[2]),std::stoi(argv[3]),
		std::stoi(argv[4]),std::stoi(argv[5])
	);
	
	std::cout << "Cropping image...\n";
	std::cout << " x: From " << area.x << " to " << (area.x+area.w) << "\n";
	std::cout << " y: From " << area.y << " to " << (area.y+area.h) << "\n";
	
	cynodelic::tesela::crop(img,area);
	
	cynodelic::tesela::image_write("image_crop_demo.png",img);
}

