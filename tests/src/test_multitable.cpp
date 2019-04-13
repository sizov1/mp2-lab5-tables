#include <gtest.h>
#include "multitable.h"

TEST(Multitable, can_create_multitable)
{
    const size_t sz = 4;
    Multitable mt(sz);

    EXPECT_EQ(sz, mt.GetSizeTab());
    EXPECT_EQ(0, mt.GetCurrSize());
}

TEST(Multitable, can_insert_record)
{
    const string name = "q";
    Polynomial q;  q.Insert(2,3);
    Multitable mt;
    
    mt.Insert(name, q);

    EXPECT_EQ(q, mt[name]);
}

TEST(Multitable, insert_increases_current_size_table)
{
    Polynomial q;
    Multitable mt;

    mt.Insert("q", q);

    EXPECT_EQ(1, mt.GetCurrSize());
}

TEST(Multitable, cannot_insert_when_table_is_full)
{
    Polynomial a, b;
    Multitable mt(1);

    mt.Insert("a", a);

    EXPECT_ANY_THROW(mt.Insert("b", b));
}

TEST(Multitable, can_delete_record)
{
    Polynomial a;
    Multitable mt;
    mt.Insert("a", a);

    mt.Delete("a");
    EXPECT_ANY_THROW(mt["a"]);
}

TEST(Multitable, delete_decreases_current_size_table)
{
    Polynomial q;
    Multitable mt;
    mt.Insert("q", q);
    
    mt.Delete("q");

    EXPECT_EQ(0, mt.GetCurrSize());
}

TEST(Multitable, cannot_delete_from_empty_record)
{
    Multitable mt;

    EXPECT_ANY_THROW(mt.Delete("a"));
}