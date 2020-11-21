#ifndef __PROB4_TESTS_H
#define __PROB4_TESTS_H

#include "test_utils.hpp"

TEST_CASE("Empty list")
{
    //must not crash
    mirror<int> (nullptr);
}

TEST_CASE("One element")
{  
    node<int> *l = tolist<int>({1});
    mirror (l);
    CHECK(tovector(l) == std::vector<int>{1, 1});
}

TEST_CASE("Three elements")
{
    node<int> *l = tolist<int>({1, 2, 3});
    mirror (l);
    CHECK(tovector(l) == std::vector<int>{1, 2, 3, 3, 2, 1});
}

#endif
