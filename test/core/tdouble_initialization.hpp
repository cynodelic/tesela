// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_TDOUBLE_INITIALIZATION_HPP
#define CYNODELIC_TESELA_TEST_CORE_TDOUBLE_INITIALIZATION_HPP


CYNODELIC_TESTER_TEST_CASE(tdouble_initialization);

CYNODELIC_TESTER_SECTION(tdouble_initialization,empty_constructor)
{
	tsl::tdouble instance;

	CYNODELIC_TESTER_MESSAGE << "Value of the instance of tdouble: " << instance;

	CYNODELIC_TESTER_ASSERT_EQUALS(instance.get(),0.0);
	CYNODELIC_TESTER_ASSERT_EQUALS(instance,tsl::tdouble{0.0});
}

CYNODELIC_TESTER_SECTION(tdouble_initialization,constructor_quantized_value)
{
	double input_val = 37.0/255.0;

	CYNODELIC_TESTER_MESSAGE << "Initial value for inizializating the instance of tdouble: " << input_val;

	tsl::tdouble instance(input_val);

	CYNODELIC_TESTER_MESSAGE << "Value of the instance of tdouble: " << instance;

	CYNODELIC_TESTER_ASSERT_EQUALS(instance.get(),input_val);
	CYNODELIC_TESTER_ASSERT_EQUALS(instance,input_val);
}

CYNODELIC_TESTER_SECTION(tdouble_initialization,assignment_quantized_value)
{
	double input_val = 199.0/255.0;

	CYNODELIC_TESTER_MESSAGE << "Initial value for inizializating the instance of tdouble: " << input_val;

	tsl::tdouble instance = static_cast<tsl::tdouble>(input_val);

	CYNODELIC_TESTER_MESSAGE << "Value of the instance of tdouble: " << instance;

	CYNODELIC_TESTER_ASSERT_EQUALS(instance.get(),input_val);
	CYNODELIC_TESTER_ASSERT_EQUALS(instance,input_val);
}



#endif // CYNODELIC_TESELA_TEST_CORE_TDOUBLE_INITIALIZATION_HPP
