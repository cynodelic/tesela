// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_IMAGE_CAST_HPP
#define CYNODELIC_TESELA_TEST_CORE_IMAGE_CAST_HPP


CYNODELIC_TESTER_TEST_CASE(image_cast);

CYNODELIC_TESTER_SECTION(image_cast,rgba_to_rgba)
{
	tsl::rgba_image input(2,2);
	input(0,0) = tsl::rgba_t(200,98,132,122);
	input(0,1) = tsl::rgba_t(14,50,197,20);
	input(1,0) = tsl::rgba_t(154,3,200,199);
	input(1,1) = tsl::rgba_t(77,86,5,250);

	tsl::rgba_image output = tsl::image_cast<tsl::rgba_t>(input);
	CYNODELIC_TESTER_ASSERT_EQUALS(output(0,0),tsl::rgba_t(200,98,132,122));
	CYNODELIC_TESTER_ASSERT_EQUALS(output(0,1),tsl::rgba_t(14,50,197,20));
	CYNODELIC_TESTER_ASSERT_EQUALS(output(1,0),tsl::rgba_t(154,3,200,199));
	CYNODELIC_TESTER_ASSERT_EQUALS(output(1,1),tsl::rgba_t(77,86,5,250));
}

CYNODELIC_TESTER_SECTION(image_cast,rgba_to_nrgba)
{
	tsl::rgba_image input(2,2);
	input(0,0) = tsl::rgba_t(49,144,100,234);
	input(0,1) = tsl::rgba_t(221,166,90,100);
	input(1,0) = tsl::rgba_t(0,98,189,77);
	input(1,1) = tsl::rgba_t(44,133,21,40);

	tsl::nrgba_image output = tsl::image_cast<tsl::nrgba_t>(input);

	CYNODELIC_TESTER_ASSERT_EQUALS(output(0,0),tsl::nrgba_t(49.0/255.0,144.0/255.0,100.0/255.0,234.0/255.0));
	CYNODELIC_TESTER_ASSERT_EQUALS(output(0,1),tsl::nrgba_t(221.0/255.0,166.0/255.0,90.0/255.0,100.0/255.0));
	CYNODELIC_TESTER_ASSERT_EQUALS(output(1,0),tsl::nrgba_t(0.0,98.0/255.0,189.0/255.0,77.0/255.0));
	CYNODELIC_TESTER_ASSERT_EQUALS(output(1,1),tsl::nrgba_t(44.0/255.0,133.0/255.0,21.0/255.0,40.0/255.0));
}

CYNODELIC_TESTER_SECTION(image_cast,nrgba_to_rgba)
{
	tsl::nrgba_image input(2,2);
	input(0,0) = tsl::nrgba_t(49.0/255.0,100.0/255.0,6.0/255.0,231.0/255.0);
	input(0,1) = tsl::nrgba_t(1.0,100.0/255.0,1.0,30.0/255.0);
	input(1,0) = tsl::nrgba_t(11.0/255.0,4.0/255.0,245.0/255.0,61.0/255.0);
	input(1,1) = tsl::nrgba_t(101.0/255.0,37.0/255.0,89.0/255.0,132.0/255.0);

	tsl::rgba_image output = tsl::image_cast<tsl::rgba_t>(input);
	CYNODELIC_TESTER_ASSERT_EQUALS(output(0,0),tsl::rgba_t(49,100,6,231));
	CYNODELIC_TESTER_ASSERT_EQUALS(output(0,1),tsl::rgba_t(255,100,255,30));
	CYNODELIC_TESTER_ASSERT_EQUALS(output(1,0),tsl::rgba_t(11,4,245,61));
	CYNODELIC_TESTER_ASSERT_EQUALS(output(1,1),tsl::rgba_t(101,37,89,132));
}

CYNODELIC_TESTER_SECTION(image_cast,nrgba_to_nrgba)
{
	tsl::nrgba_image input(2,2);
	input(0,0) = tsl::nrgba_t(30.0/255.0,188.0/255.0,1.0,4.0/255.0);
	input(0,1) = tsl::nrgba_t(244.0/255.0,101.0/255.0,67.0/255.0,191.0/255.0);
	input(1,0) = tsl::nrgba_t(141.0/255.0,99.0/255.0,0.0,104.0/255.0);
	input(1,1) = tsl::nrgba_t(34.0/255.0,2.0/255.0,222.0/255.0,111.0/255.0);
	
	tsl::nrgba_image output = tsl::image_cast<tsl::nrgba_t>(input);
	CYNODELIC_TESTER_ASSERT_EQUALS(output(0,0),tsl::nrgba_t(30.0/255.0,188.0/255.0,1.0,4.0/255.0));
	CYNODELIC_TESTER_ASSERT_EQUALS(output(0,1),tsl::nrgba_t(244.0/255.0,101.0/255.0,67.0/255.0,191.0/255.0));
	CYNODELIC_TESTER_ASSERT_EQUALS(output(1,0),tsl::nrgba_t(141.0/255.0,99.0/255.0,0.0,104.0/255.0));
	CYNODELIC_TESTER_ASSERT_EQUALS(output(1,1),tsl::nrgba_t(34.0/255.0,2.0/255.0,222.0/255.0,111.0/255.0));
}


#endif // CYNODELIC_TESELA_TEST_CORE_IMAGE_CAST_HPP
