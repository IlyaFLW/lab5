#include <gtest.h>
#include "Steck.h"

TEST(TSteck, can_create_steck_with_positive_length) 
{
	ASSERT_NO_THROW(TSteck<int> S_INT(5));
	ASSERT_NO_THROW(TSteck<char> S_CHAR(5));

}

TEST(TSteck, throws_when_create_steck_with_negative_length) 
{
	ASSERT_ANY_THROW(TSteck<int> S_INT(-5));
	ASSERT_ANY_THROW(TSteck<char> S_CHAR(-5));

}

TEST(TSteck, can_set_elem) 
{
	TSteck<int> S(5);

	ASSERT_NO_THROW(S.push(1));

}

TEST(TSteck, can_get_size) 
{
	TSteck<int> S(5);

	EXPECT_EQ(S.getSteckSize(), 5);

}


TEST(TSteck, can_clear_bit) 
{
	TSteck<int> S(2);
	S.push(2);
	S.push(3);


	ASSERT_NO_THROW(S.del());

}


TEST(TSteck, get_elem)
{
	TSteck<int> S(2);
	S.push(2);

	EXPECT_EQ(S.Peek(1), 2);

}


TEST(TSteck, can_create_copy) 
{
	TSteck<int> S1(5);
	S1.push(1);
	TSteck<int> S2 = S1;
	EXPECT_EQ(S1.Peek(1), S2.Peek(1));

}

TEST(TSteck, throws_when_set_steck_with_too_large_index) 
{
	TSteck<int> S(2);
	S.push(1);
	S.push(2);
	ASSERT_ANY_THROW(S.push(3));

}

TEST(TSteck, can_get_pointer) 
{
	TSteck<int> S(5);

	ASSERT_NO_THROW(S.getPtr());

}

TEST(TSteck, can_get_num) 
{
	TSteck<int> S(5);
	EXPECT_EQ(S.getNum(), 0);
}

TEST(TSteck, can_get_MIN_elem) 
{
	TSteck<int> S(3);
	S.push(6);
	S.push(2);
	S.push(9);

	EXPECT_EQ(S.min_elem(), 2);
}

TEST(TSteck, can_get_MAX_elem) 
{
	TSteck<int> S(3);
	S.push(6);
	S.push(2);
	S.push(9);

	EXPECT_EQ(S.max_elem(), 9);
}

TEST(TSteck, can_write_file)
{
	TSteck<int> S(2);
	S.push(1);
	S.push(2);

	ASSERT_NO_THROW(S.file());
}