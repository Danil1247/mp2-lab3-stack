#include "Stack.h"
#include <gtest.h>

TEST(STACK, can_create_stack)
{
	ASSERT_NO_THROW(new TStack<int>());
}

TEST(STACK, can_check_emptiness)
{
	TStack<int>* s = new TStack<int>;
	EXPECT_EQ(1, s->IsEmpty());
}

TEST(STACK, throws_when_pop_from_empty_stack)
{
	TStack<int>* s = new TStack<int>;
	ASSERT_ANY_THROW(s->Pop());
}

TEST(STACK, can_check_fullness)
{
	TStack<int>* s = new TStack<int>;
	s->Push(5);
	EXPECT_EQ(0, s->IsFull());
}

TEST(STACK, can_push_element)
{
	TStack<int>* s = new TStack<int>;
	ASSERT_NO_THROW(s->Push(2));
}

TEST(STACK, can_copy_stack)
{
	TStack<int>* s = new TStack<int>;
	s->Push(6);
	ASSERT_NO_THROW(TStack<int>* s1 = new TStack<int>(*s));
}

//TEST(STACK, copied_stack_is_equal_to_source_one)
//{
//	TStack<int>* s = new TStack<int>;
//	s->Push(6);
//	TStack<int>* s1 = new TStack<int>(*s);
//	EXPECT_EQ(*s, *s1);
//}
//
//TEST(STACK, can_pop_element)
//{
//	TStack<int>* s = new TStack<int>();
//	s->Push(4);
//	s->Push(6);
//	int tmp;
//	ASSERT_NO_THROW(tmp = s->Pop());
//	EXPECT_EQ(6, tmp);
//}
//
//TEST(STACK, compare_different_stacks_returns_false)
//{
//	TStack<int>* s = new TStack<int>();
//	s->Push(4);
//	s->Push(6);
//	TStack<int>* s1 = new TStack<int>();
//	s->Push(2);
//	s->Push(3);
//	EXPECT_NE(*s, *s1);
//}
//
//TEST(STACK, can_compare_different_stacks)
//{
//	TStack<int>* s = new TStack<int>();
//	s->Push(4);
//	s->Push(6);
//	TStack<int>* s1 = new TStack<int>();
//	s->Push(2);
//	s->Push(3);
//	ASSERT_NO_THROW(s == s1);
//}
//
//TEST(STACK, can_compare_equal_stacks)
//{
//	TStack<int>* s = new TStack<int>();
//	s->Push(4);
//	s->Push(6);
//	TStack<int>* s1 = new TStack<int>();
//	s->Push(4);
//	s->Push(6);
//	ASSERT_NO_THROW(s == s1);
//}