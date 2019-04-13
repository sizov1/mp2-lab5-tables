#include <gtest.h>
#include "unsorttable.h"

TEST(Unsorttable, can_create_unsorttable)
{
    const size_t sz = 4;
    Unsorttable ut(sz);

    EXPECT_EQ(sz, ut.GetSizeTab());
    EXPECT_EQ(0, ut.GetCurrSize());
    EXPECT_EQ(0, ut.GetNumberOperations());
}

TEST(Unsorttable, can_insert_record)
{
    const string name = "q";
    Polynomial q;  q.Insert(2,3);
    Unsorttable ut;
    
    ut.Insert(name, q);

    EXPECT_EQ(q, ut[name]);
}

TEST(Unsorttable, insert_increases_current_size_table)
{
    Polynomial q;
    Unsorttable ut;

    ut.Insert("q", q);

    EXPECT_EQ(1, ut.GetCurrSize());
}

TEST(Unsorttable, cannot_insert_when_table_is_full)
{
    Polynomial a, b;
    Unsorttable ut(1);

    ut.Insert("a", a);

    EXPECT_ANY_THROW(ut.Insert("b", b));
}

TEST(Unsorttable, can_delete_record)
{
    Polynomial a;
    Unsorttable ut;
    ut.Insert("a", a);

    ut.Delete("a");
    EXPECT_ANY_THROW(ut["a"]);
}

TEST(Unsorttable, delete_decreases_current_size_table)
{
    Polynomial q;
    Unsorttable ut;
    ut.Insert("q", q);
    
    ut.Delete("q");

    EXPECT_EQ(0, ut.GetCurrSize());
}

TEST(Unsorttable, cannot_delete_from_empty_record)
{
    Unsorttable ut;

    EXPECT_ANY_THROW(ut.Delete("a"));
}