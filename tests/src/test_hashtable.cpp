#include <gtest.h>
#include "hashtable.h"

TEST(Hashtable, can_create_sorttable)
{
    const size_t sz = 4;
    Hashtable ht(sz);

    EXPECT_EQ(sz, ht.GetSizeTab());
    EXPECT_EQ(0, ht.GetCurrSize());
    EXPECT_EQ(0, ht.GetNumberOperations());
}


TEST(Hashtable, can_insert_record)
{
    const string name = "q";
    Polynomial q, p, f;  q.Insert(2, 3);
    Hashtable ht;

    ht.Insert("f", f);
    ht.Insert(name, q);
    ht.Insert("p", p);

    EXPECT_EQ(q, ht[name]);
}

TEST(Hashtable, insert_increases_current_size_table)
{
    Polynomial q;
    Hashtable ht;

    ht.Insert("q", q);

    EXPECT_EQ(1, ht.GetCurrSize());
}

TEST(Hashtable, cannot_insert_when_table_is_full)
{
    Polynomial a, b;
    Hashtable ht(1);

    ht.Insert("a", a);

    EXPECT_ANY_THROW(ht.Insert("b", b));
}


TEST(Hashtable, can_delete_record)
{
    Polynomial a;
    Hashtable ht;
    ht.Insert("a", a);

    ht.Delete("a");
    EXPECT_ANY_THROW(ht["a"]);
}

TEST(Hashtable, delete_decreases_current_size_table)
{
    Polynomial q, p;
    Hashtable ht;
    ht.Insert("q", q);
    ht.Insert("p", p);

    ht.Delete("q");

    EXPECT_EQ(1, ht.GetCurrSize());
}

TEST(Hashtable, cannot_delete_from_empty_record)
{
    Hashtable ht;

    EXPECT_ANY_THROW(ht.Delete("a"));
}
   