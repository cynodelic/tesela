// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/*
 * @file plasma.cpp
 *
 * Generates a random plasma pattern.
 */

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <random>
#include <chrono>

#include <cynodelic/tesela/rgba_types.hpp>
#include <cynodelic/tesela/image_types.hpp>
#include <cynodelic/tesela/formats/jpeg_io.hpp>
#include <cynodelic/tesela/formats/png_io.hpp>
#include <cynodelic/tesela/formats/tiff_io.hpp>
#include <cynodelic/tesela/image_io.hpp>

static constexpr double pi = 3.1415926535897932384626433832795;

namespace tsl = cynodelic::tesela;


using my_image_io = tsl::image_io<
	tsl::jpeg_io,
	tsl::png_io,
	tsl::tiff_io
>;


double ssin(const double& x,double phs[8],double amp[8])
{
	double y = 0;

	for (int i = 0; i < 8; i++)
	{
		y += amp[i]*std::sin(double(i + 1)*pi*(x + phs[i]));
	}
	
	return y/8;
}

double scos(const double& x,double phs[8],double amp[8])
{
	double y = 0;

	for (int i = 0; i < 8; i++)
	{
		y += amp[i]*std::cos(double(i + 1)*pi*(x + phs[i]));
	}

	return y/8;
}

double csin(const double& x,double phs[3])
{
	return std::sin(pi*(std::sin(pi*(std::sin(pi*(x + phs[0])) + phs[1])) + phs[2]));
}


int main()
{
	std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_real_distribution<double> dist(-1.0,1.0);

	tsl::norm_image plasma(640,480);
	
	double freq = 0.005;
	double phs_xr[8], phs_xg[8], phs_xb[8];
	double phs_yr[8], phs_yg[8], phs_yb[8];
	double amp_xr[8], amp_xg[8], amp_xb[8];
	double amp_yr[8], amp_yg[8], amp_yb[8];
	double phs_zr[8], phs_zg[8], phs_zb[8];
	
	std::cout << "Generating random parameters...\n";
	
	for (int i = 0; i < 8; i++)
	{
		phs_xr[i] = dist(rnd); phs_xg[i] = dist(rnd); phs_xb[i] = dist(rnd);
		phs_yr[i] = dist(rnd); phs_yg[i] = dist(rnd); phs_yb[i] = dist(rnd);
		amp_xr[i] = dist(rnd); amp_xg[i] = dist(rnd); amp_xb[i] = dist(rnd);
		amp_yr[i] = dist(rnd); amp_yg[i] = dist(rnd); amp_yb[i] = dist(rnd);
	}
	
	for (int i = 0; i < 3; i++)
	{
		phs_zr[i] = dist(rnd);
		phs_zg[i] = dist(rnd);
		phs_zb[i] = dist(rnd);
	}
	
	std::cout << "Generating plasma pattern...\n";
	double zr, zg, zb;
	for (std::size_t iy = 0; iy < plasma.height(); iy++)
	{
		for (std::size_t ix = 0; ix < plasma.width(); ix++)
		{
			zr = (ssin(double(ix)*freq,phs_xr,amp_xr)+scos(double(iy)*freq,phs_yr,amp_yr))*0.5+0.5;
			zg = (ssin(double(ix)*freq,phs_xg,amp_xg)+scos(double(iy)*freq,phs_yg,amp_yg))*0.5+0.5;
			zb = (ssin(double(ix)*freq,phs_xb,amp_xb)+scos(double(iy)*freq,phs_yb,amp_yb))*0.5+0.5;
			zr = csin(zr,phs_zr)*0.5+0.5;
			zg = csin(zg,phs_zg)*0.5+0.5;
			zb = csin(zb,phs_zb)*0.5+0.5;
			plasma(ix,iy) = tsl::nrgba_t(zr,zg,zb);
		}
	}
	
	std::cout << "Saving image...\n";

	my_image_io::write("plasma_demo.png",plasma);
}

