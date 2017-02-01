/*
 * - converter.cpp:
 *
 * A simple image converter.
 *
 * Usage: ./converter [image] [format]
 * Values for format: 0 (JPEG), 1 (PNG), 2 (TIFF)
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

#define CYNODELIC_TESELA_VERBOSE
#include "cynodelic/tesela/tesela.hpp"

int main(int argc,char **argv)
{
	std::string out_name = "converter_demo";
	int fid = std::stoi(argv[2]);
	
	std::cout << "Converting " << argv[1] << " to "
	          << ((fid == 0) ? "JPEG" : ((fid == 1) ? "PNG" : ((fid == 2) ? "TIFF" : "???")))
	          << "\n";
	
	cynodelic::tesela::image img;
	cynodelic::tesela::image_read(argv[1],img);
	
	switch (fid)
	{
		case 0: cynodelic::tesela::remove_alpha(img,true); out_name += ".jpg"; break;
		case 1: out_name += ".png"; break;
		case 2: out_name += ".tif"; break;
		default: std::cout << "AAAAAAAAAAAAAAAAAAAAA\n"; std::exit(EXIT_FAILURE);
	}
	
	std::cout << "File name: " << out_name << "\n";
	cynodelic::tesela::image_write(out_name.c_str(),img);
}

