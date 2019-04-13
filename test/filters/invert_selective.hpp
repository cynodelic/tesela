// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_FILTERS_INVERT_SELECTIVE_HPP
#define CYNODELIC_TESELA_TEST_FILTERS_INVERT_SELECTIVE_HPP


CYNODELIC_TESTER_TEST_CASE(invert_selective);

CYNODELIC_TESTER_SECTION(invert_selective,rgb)
{
	tsl::rgb_image img(2,1);

	img(0,0) = tsl::rgb_t(231,44,101);
	img(1,0) = tsl::rgb_t(33,155,70);

	tsl::rgb_image expected_ir(2,1);

	expected_ir(0,0) = tsl::rgb_t(24,44,101);
	expected_ir(1,0) = tsl::rgb_t(222,155,70);

	tsl::rgb_image expected_ig(2,1);

	expected_ig(0,0) = tsl::rgb_t(231,211,101);
	expected_ig(1,0) = tsl::rgb_t(33,100,70);

	tsl::rgb_image expected_ib(2,1);

	expected_ib(0,0) = tsl::rgb_t(231,44,154);
	expected_ib(1,0) = tsl::rgb_t(33,155,185);

	tsl::rgb_image img_ir(img);
	tsl::rgb_image img_ig(img);
	tsl::rgb_image img_ib(img);

	tsl::invert(img_ir,true,false,false);
	tsl::invert(img_ig,false,true,false);
	tsl::invert(img_ib,false,false,true);

	CYNODELIC_TESTER_CHECK_EQUALS(img_ir(0,0),expected_ir(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img_ir(1,0),expected_ir(1,0));

	CYNODELIC_TESTER_CHECK_EQUALS(img_ig(0,0),expected_ig(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img_ig(1,0),expected_ig(1,0));

	CYNODELIC_TESTER_CHECK_EQUALS(img_ib(0,0),expected_ib(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img_ib(1,0),expected_ib(1,0));
}

CYNODELIC_TESTER_SECTION(invert_selective,rgba)
{
	tsl::rgba_image img(2,1);

	img(0,0) = tsl::rgba_t(231,44,101,133);
	img(1,0) = tsl::rgba_t(33,155,70,21);

	tsl::rgba_image expected_ir(2,1);

	expected_ir(0,0) = tsl::rgba_t(24,44,101,133);
	expected_ir(1,0) = tsl::rgba_t(222,155,70,21);

	tsl::rgba_image expected_ig(2,1);

	expected_ig(0,0) = tsl::rgba_t(231,211,101,133);
	expected_ig(1,0) = tsl::rgba_t(33,100,70,21);

	tsl::rgba_image expected_ib(2,1);

	expected_ib(0,0) = tsl::rgba_t(231,44,154,133);
	expected_ib(1,0) = tsl::rgba_t(33,155,185,21);

	tsl::rgba_image img_ir(img);
	tsl::rgba_image img_ig(img);
	tsl::rgba_image img_ib(img);

	tsl::invert(img_ir,true,false,false);
	tsl::invert(img_ig,false,true,false);
	tsl::invert(img_ib,false,false,true);

	CYNODELIC_TESTER_CHECK_EQUALS(img_ir(0,0),expected_ir(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img_ir(1,0),expected_ir(1,0));

	CYNODELIC_TESTER_CHECK_EQUALS(img_ig(0,0),expected_ig(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img_ig(1,0),expected_ig(1,0));

	CYNODELIC_TESTER_CHECK_EQUALS(img_ib(0,0),expected_ib(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img_ib(1,0),expected_ib(1,0));
}

CYNODELIC_TESTER_SECTION(invert_selective,nrgb)
{
	tsl::nrgb_image img(2,1);

	img(0,0) = tsl::nrgb_t(231.0/255.0,44.0/255.0,101.0/255.0);
	img(1,0) = tsl::nrgb_t(33.0/255.0,155.0/255.0,70.0/255.0);

	tsl::nrgb_image expected_ir(2,1);

	expected_ir(0,0) = tsl::nrgb_t(24.0/255.0,44.0/255.0,101.0/255.0);
	expected_ir(1,0) = tsl::nrgb_t(222.0/255.0,155.0/255.0,70.0/255.0);

	tsl::nrgb_image expected_ig(2,1);

	expected_ig(0,0) = tsl::nrgb_t(231.0/255.0,211.0/255.0,101.0/255.0);
	expected_ig(1,0) = tsl::nrgb_t(33.0/255.0,100.0/255.0,70.0/255.0);

	tsl::nrgb_image expected_ib(2,1);

	expected_ib(0,0) = tsl::nrgb_t(231.0/255.0,44.0/255.0,154.0/255.0);
	expected_ib(1,0) = tsl::nrgb_t(33.0/255.0,155.0/255.0,185.0/255.0);

	tsl::nrgb_image img_ir(img);
	tsl::nrgb_image img_ig(img);
	tsl::nrgb_image img_ib(img);

	tsl::invert(img_ir,true,false,false);
	tsl::invert(img_ig,false,true,false);
	tsl::invert(img_ib,false,false,true);

	CYNODELIC_TESTER_CHECK_EQUALS(img_ir(0,0),expected_ir(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img_ir(1,0),expected_ir(1,0));

	CYNODELIC_TESTER_CHECK_EQUALS(img_ig(0,0),expected_ig(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img_ig(1,0),expected_ig(1,0));

	CYNODELIC_TESTER_CHECK_EQUALS(img_ib(0,0),expected_ib(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img_ib(1,0),expected_ib(1,0));
}

CYNODELIC_TESTER_SECTION(invert_selective,nrgba)
{
	tsl::nrgba_image img(2,1);

	img(0,0) = tsl::nrgba_t(231.0/255.0,44.0/255.0,101.0/255.0,133.0/255.0);
	img(1,0) = tsl::nrgba_t(33.0/255.0,155.0/255.0,70.0/255.0,21.0/255.0);

	tsl::nrgba_image expected_ir(2,1);

	expected_ir(0,0) = tsl::nrgba_t(24.0/255.0,44.0/255.0,101.0/255.0,133.0/255.0);
	expected_ir(1,0) = tsl::nrgba_t(222.0/255.0,155.0/255.0,70.0/255.0,21.0/255.0);

	tsl::nrgba_image expected_ig(2,1);

	expected_ig(0,0) = tsl::nrgba_t(231.0/255.0,211.0/255.0,101.0/255.0,133.0/255.0);
	expected_ig(1,0) = tsl::nrgba_t(33.0/255.0,100.0/255.0,70.0/255.0,21.0/255.0);

	tsl::nrgba_image expected_ib(2,1);

	expected_ib(0,0) = tsl::nrgba_t(231.0/255.0,44.0/255.0,154.0/255.0,133.0/255.0);
	expected_ib(1,0) = tsl::nrgba_t(33.0/255.0,155.0/255.0,185.0/255.0,21.0/255.0);

	tsl::nrgba_image img_ir(img);
	tsl::nrgba_image img_ig(img);
	tsl::nrgba_image img_ib(img);

	tsl::invert(img_ir,true,false,false);
	tsl::invert(img_ig,false,true,false);
	tsl::invert(img_ib,false,false,true);

	CYNODELIC_TESTER_CHECK_EQUALS(img_ir(0,0),expected_ir(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img_ir(1,0),expected_ir(1,0));

	CYNODELIC_TESTER_CHECK_EQUALS(img_ig(0,0),expected_ig(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img_ig(1,0),expected_ig(1,0));

	CYNODELIC_TESTER_CHECK_EQUALS(img_ib(0,0),expected_ib(0,0));
	CYNODELIC_TESTER_CHECK_EQUALS(img_ib(1,0),expected_ib(1,0));
}


#endif // CYNODELIC_TESELA_TEST_FILTERS_INVERT_SELECTIVE_HPP
