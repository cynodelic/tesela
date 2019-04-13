// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_NGRAY_T_INITIALIZATION_HPP
#define CYNODELIC_TESELA_TEST_CORE_NGRAY_T_INITIALIZATION_HPP


CYNODELIC_TESTER_TEST_CASE(ngray_t_initialization);

CYNODELIC_TESTER_SECTION(ngray_t_initialization,empty_constructor)
{
	tsl::ngray_t value_0;

	CYNODELIC_TESTER_CHECK_EQUALS(value_0.gray,0.0);
}

CYNODELIC_TESTER_SECTION(ngray_t_initialization,constructor)
{
	tsl::ngray_t value_1(211.0/255.0);

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.gray = " << value_1.gray << " (red)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.gray,211.0/255.0);
}

CYNODELIC_TESTER_SECTION(ngray_t_initialization,assignment)
{
	tsl::ngray_t value_1 = tsl::ngray_t{211.0/255.0};

	CYNODELIC_TESTER_MESSAGE
		<< "Values for value_1" << tst::newline
		<< "value_1.gray = " << value_1.gray << " (red)"; 
	CYNODELIC_TESTER_CHECK_EQUALS(value_1.gray,211.0/255.0);
}


#endif // CYNODELIC_TESELA_TEST_CORE_NGRAY_T_INITIALIZATION_HPP
