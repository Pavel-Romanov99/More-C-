#ifndef __PROB2_TESTS_H
#define __PROB2_TESTS_H

#include "test_utils.hpp"

TEST_CASE("Empty list")
{
    //must not crash
    node<int> *l = nullptr;
    removeIdx (l);
}

TEST_CASE("Single element list, no deletion")
{
    node<int> *l = tolist<int>({1});
    removeIdx (l);
    CHECK(tovector(l) == std::vector<int>{1});
}

TEST_CASE("Single element list, WITH deletion")
{
    node<int> *l = tolist<int>({0});
    removeIdx (l);
    CHECK(l == nullptr);
}

TEST_CASE("Delete all")
{ 
    node<int> *l = tolist<int>({2,1,0});
    removeIdx (l);
    CHECK(l == nullptr);
}

TEST_CASE("Delete some")
{
    node<int> *l = tolist<int>({11,6,12,4,3,13,1,0});
    removeIdx (l);
    CHECK(tovector(l) == std::vector<int>{11,12,13});
}

#endif
