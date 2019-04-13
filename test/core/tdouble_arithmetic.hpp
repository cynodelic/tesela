// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_TEST_CORE_TDOUBLE_ARITHMETIC_HPP
#define CYNODELIC_TESELA_TEST_CORE_TDOUBLE_ARITHMETIC_HPP


#define CYNODELIC_TESELA_TEST_TDOUBLE_ARITHMETIC_OP_TEST(op_name,op,cmp_op,val11,val12,expc1,val21,val22,expc2) \
CYNODELIC_TESTER_TEST_CASE(tdouble_##op_name); \
\
CYNODELIC_TESTER_SECTION(tdouble_##op_name,normal) \
{ \
	double value1_dbl = val11; \
	double value2_dbl = val12; \
	\
	tsl::tdouble value1(value1_dbl); \
	tsl::tdouble value2(value2_dbl); \
	\
	CYNODELIC_TESTER_MESSAGE \
		<< "Values used for testing:" << tst::newline \
		<< "value1 = " << value1 << tst::newline \
		<< "value2 = " << value2; \
	\
	tsl::tdouble result = value1 op value2; \
	tsl::tdouble expected(expc1); \
	\
	CYNODELIC_TESTER_MESSAGE << "value1 " #op " value2 = " << result; \
	CYNODELIC_TESTER_MESSAGE << "Expected value: " << expected; \
	\
	CYNODELIC_TESTER_CHECK_EQUALS(value1 op value2,result); \
	CYNODELIC_TESTER_CHECK_EQUALS(value1_dbl op value2,result); \
	CYNODELIC_TESTER_CHECK_EQUALS(value1 op value2_dbl,result); \
	CYNODELIC_TESTER_CHECK_EQUALS(result,expected); \
} \
\
CYNODELIC_TESTER_SECTION(tdouble_##op_name,compound) \
{ \
	double value1_dbl = val21; \
	double value2_dbl = val22; \
	\
	tsl::tdouble value1(value1_dbl); \
	tsl::tdouble value2(value2_dbl); \
	\
	CYNODELIC_TESTER_MESSAGE \
		<< "Values used for testing:" << tst::newline \
		<< "value1 = " << value1 << tst::newline \
		<< "value2 = " << value2; \
	\
	tsl::tdouble value1_new_1 = value1; \
	tsl::tdouble value1_new_2 = value1; \
	\
	value1_new_1 cmp_op value2; \
	value1_new_2 cmp_op value2_dbl; \
	tsl::tdouble expected(expc2); \
	\
	CYNODELIC_TESTER_MESSAGE << "New value for value1 (value1 " #op " value2): " << value1_new_1; \
	CYNODELIC_TESTER_MESSAGE << "Expected value: " << expected; \
	\
	CYNODELIC_TESTER_CHECK_EQUALS(value1 op value2,expected); \
	CYNODELIC_TESTER_CHECK_EQUALS(value1 op value2,value1_new_1); \
	CYNODELIC_TESTER_CHECK_EQUALS(value1 op value2,value1_new_2); \
	CYNODELIC_TESTER_CHECK_EQUALS(value1_new_1,expected); \
	CYNODELIC_TESTER_CHECK_EQUALS(value1_new_2,expected); \
}


CYNODELIC_TESELA_TEST_TDOUBLE_ARITHMETIC_OP_TEST(
	addition,+,+=,
	126.0/255.0,49.0/255.0,175.0/255.0,
	201.0/255.0,31.0/255.0,232.0/255.0
)


CYNODELIC_TESELA_TEST_TDOUBLE_ARITHMETIC_OP_TEST(
	substraction,-,-=,
	250.0/255.0,57.0/255.0,193.0/255.0,
	100.0/255.0,34.0/255.0,66.0/255.0
)


CYNODELIC_TESELA_TEST_TDOUBLE_ARITHMETIC_OP_TEST(
	multiplication,*,*=,
	239.0/255.0,166.0/255.0,155.0/255.0,
	127.0/255.0,199.0/255.0,99.0/255.0
)


CYNODELIC_TESELA_TEST_TDOUBLE_ARITHMETIC_OP_TEST(
	division,/,/=,
	240.0/255.0,155.0/255.0,394.0/255.0,
	212.0/255.0,121.0/255.0,446.0/255.0
)


#endif // CYNODELIC_TESELA_TEST_CORE_TDOUBLE_ARITHMETIC_HPP
