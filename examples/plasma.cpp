/*
 * - plasma.cpp:
 *
 * Generates a random plasma pattern.
 */

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <random>

#define CYNODELIC_TESELA_VERBOSE
#include "cynodelic/tesela/tesela.hpp"

static const double PI = 3.1415926535897932384626433832795;

std::random_device rd;
std::mt19937 rnd(rd());
std::uniform_real_distribution<double> dist(-1.0,1.0);
double rrnd() { return dist(rnd); }

static const std::uint32_t max_uint32 = 0xffffffff;

double ssin(double x,double phs[8],double amp[8])
{
	double y = 0;
	for (int i=0;i<8;i++) y += amp[i]*std::sin(double(i+1)*PI*(x+phs[i]));
	return y/8;
}

double scos(double x,double phs[8],double amp[8])
{
	double y = 0;
	for (int i=0;i<8;i++) y += amp[i]*std::cos(double(i+1)*PI*(x+phs[i]));
	return y/8;
}

double csin(double x,double phs[3])
{
	return std::sin(PI*(std::sin(PI*(std::sin(PI*(x + phs[0])) + phs[1])) + phs[2]));
}

int main(int argc,char **argv)
{
	cynodelic::tesela::norm_image plasma(640,480);
	plasma.color = cynodelic::tesela::color_mode::RGB;
	
	double freq = 0.005;
	double phs_xr[8], phs_xg[8], phs_xb[8];
	double phs_yr[8], phs_yg[8], phs_yb[8];
	double amp_xr[8], amp_xg[8], amp_xb[8];
	double amp_yr[8], amp_yg[8], amp_yb[8];
	double phs_zr[8], phs_zg[8], phs_zb[8];
	
	std::cout << "Generating random parameters...\n";
	for (int i=0;i<8;i++)
	{
		phs_xr[i] = rrnd(); phs_xg[i] = rrnd(); phs_xb[i] = rrnd();
		phs_yr[i] = rrnd(); phs_yg[i] = rrnd(); phs_yb[i] = rrnd();
		amp_xr[i] = rrnd(); amp_xg[i] = rrnd(); amp_xb[i] = rrnd();
		amp_yr[i] = rrnd(); amp_yg[i] = rrnd(); amp_yb[i] = rrnd();
	}
	
	for (int i=0;i<3;i++)
	{
		phs_zr[i] = rrnd();
		phs_zg[i] = rrnd();
		phs_zb[i] = rrnd();
	}
	
	std::cout << "Generating plasma pattern...\n";
	double zr, zg, zb;
	for (std::size_t iy=0;iy<plasma.height();iy++)
	{
		for (std::size_t ix=0;ix<plasma.width();ix++)
		{
			zr = (ssin(double(ix)*freq,phs_xr,amp_xr)+scos(double(iy)*freq,phs_yr,amp_yr))*0.5+0.5;
			zg = (ssin(double(ix)*freq,phs_xg,amp_xg)+scos(double(iy)*freq,phs_yg,amp_yg))*0.5+0.5;
			zb = (ssin(double(ix)*freq,phs_xb,amp_xb)+scos(double(iy)*freq,phs_yb,amp_yb))*0.5+0.5;
			zr = csin(zr,phs_zr)*0.5+0.5;
			zg = csin(zg,phs_zg)*0.5+0.5;
			zb = csin(zb,phs_zb)*0.5+0.5;
			plasma(ix,iy) = cynodelic::tesela::nrgba_t(zr,zg,zb);
		}
	}
	
	std::cout << "Saving image...\n";
	cynodelic::tesela::image out(plasma);
	cynodelic::tesela::image_write("plasma_demo.png",out);
}

