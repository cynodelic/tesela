/*
 * - pseudo_pop_art.cpp:
 *
 * Applies a "pop art"-like filter.
 *
 * Usage: ./pseudo_pop_art [image]
 */

#include <iostream>
#include <cstdlib>
#include <cstdint>

#define CYNODELIC_TESELA_VERBOSE
#include "cynodelic/tesela/tesela.hpp"

int main(int argc,char **argv)
{
	cynodelic::tesela::image orig, t1, t2, t3, t4, out;
	cynodelic::tesela::image_read(argv[1],orig);
	t1  = cynodelic::tesela::image(orig.width(),orig.height());
	t2  = cynodelic::tesela::image(orig.width(),orig.height());
	t3  = cynodelic::tesela::image(orig.width(),orig.height());
	t4  = cynodelic::tesela::image(orig.width(),orig.height());
	out = cynodelic::tesela::image(2*orig.width(),2*orig.height());
	t1.color = t2.color = t3.color = t4.color = out.color = orig.color;
	
	std::size_t ow = orig.width();
	std::size_t oh = orig.height();
	
	for (std::size_t iy=0;iy<oh;iy++)
		for (std::size_t ix=0;ix<ow;ix++)
			t1(ix,iy) = t2(ix,iy) = t3(ix,iy) = t4(ix,iy) = orig(ix,iy);
	
	std::cout << "Applying duotone filters...\n";
	cynodelic::tesela::duotone(t1,cynodelic::tesela::rgba_t( 40,221, 68),cynodelic::tesela::rgba_t( 10, 32, 56));
	cynodelic::tesela::duotone(t2,cynodelic::tesela::rgba_t(140,175,243),cynodelic::tesela::rgba_t( 45, 30, 19));
	cynodelic::tesela::duotone(t3,cynodelic::tesela::rgba_t(210, 70,197),cynodelic::tesela::rgba_t( 54, 43, 20));
	cynodelic::tesela::duotone(t4,cynodelic::tesela::rgba_t(195,248, 41),cynodelic::tesela::rgba_t( 14, 20, 57));
	
	std::cout << "Joining images...\n";
	for (std::size_t iy=0;iy<oh;iy++)
	{
		for (std::size_t ix=0;ix<ow;ix++)
		{
			out(ix   ,iy   ) = t1(ix,iy);
			out(ix+ow,iy   ) = t2(ix,iy);
			out(ix   ,iy+oh) = t3(ix,iy);
			out(ix+ow,iy+oh) = t4(ix,iy);
		}
	}
	
	std::cout << "Saving image...\n";
	cynodelic::tesela::image_write("pseudo_pop_art_demo.png",out);
}

