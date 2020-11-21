#ifndef __PROB1_TESTS_H
#define __PROB1_TESTS_H

#include "test_utils.hpp"

TEST_CASE("Empty list")
{
    //must not crash
    fillgaps(nullptr);
}

TEST_CASE("Fill Gaps")
{
    node<int> *l = tolist<int>({1, 3, 7});
    fillgaps (l);
    CHECK (tovector(l) == std::vector<int>{1, 2, 3, 4, 5, 6, 7});
}

TEST_CASE("Fill all between two")
{
    node<int> *l = tolist<int>({1, 10});
    fillgaps (l);
    CHECK (tovector(l) == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
}

TEST_CASE("Fill none between two")
{
    node<int> *l = tolist<int>({1, 2});
    fillgaps (l);
    CHECK (tovector(l) == std::vector<int>{1, 2});
}

TEST_CASE("Fill none in already consecutive numbers")
{
    node<int> *l = tolist<int>({1, 2, 3, 4, 5, 6, 7});
    fillgaps (l);
    CHECK (tovector(l) == std::vector<int>{1, 2, 3, 4, 5, 6, 7});
}

TEST_CASE("Fill only one number in almost consecutive numbers")
{
    node<int> *l = tolist<int>({1, 2, 3, 4, 5, 7});
    fillgaps (l);
    CHECK (tovector(l) == std::vector<int>{1, 2, 3, 4, 5, 6, 7});
}

#endif
