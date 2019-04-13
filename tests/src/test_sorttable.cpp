#include <gtest.h>
#include "sorttable.h"

TEST(Sorttable, can_create_sorttable)
{
    const size_t sz = 4;
    Sorttable st(sz);

    EXPECT_EQ(sz, st.GetSizeTab());
    EXPECT_EQ(0, st.GetCurrSize());
    EXPECT_EQ(0, st.GetNumberOperations());
}

TEST(Sorttable, can_insert_record)
{
    const string name = "q";
    Polynomial q, p, f;  q.Insert(2, 3);
    Sorttable st;

    st.Insert("f", f);
    st.Insert(name, q);
    st.Insert("p", p);

    EXPECT_EQ(q, st[name]);
}

TEST(Sorttable, insert_increases_current_size_table)
{
    Polynomial q;
    Sorttable st;

    st.Insert("q", q);

    EXPECT_EQ(1, st.GetCurrSize());
}

TEST(Sorttable, cannot_insert_when_table_is_full)
{
    Polynomial a, b;
    Sorttable st(1);

    st.Insert("a", a);

    EXPECT_ANY_THROW(st.Insert("b", b));
}

TEST(Sorttable, can_delete_record)
{
    Polynomial a;
    Sorttable st;
    st.Insert("a", a);

    st.Delete("a");
    EXPECT_ANY_THROW(st["a"]);
}

TEST(Sorttable, delete_decreases_current_size_table)
{
    Polynomial q;
    Sorttable st;
    st.Insert("q", q);
    
    st.Delete("q");

    EXPECT_EQ(0, st.GetCurrSize());
}

TEST(Sorttable, cannot_delete_from_empty_record)
{
    Sorttable st;

    EXPECT_ANY_THROW(st.Delete("a"));
}
