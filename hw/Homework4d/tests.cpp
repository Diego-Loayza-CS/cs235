#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

#include "Vector.h"
#include "test_utils.h"


TEST(vector_iterator_begin_and_dereference, 15)
{
    Vector<std::string> vector;
    vector.push_back("Hello");
    vector.push_back("there!");

    ASSERT_EQ(*vector.begin(), "Hello");
}

TEST(vector_iterator_advance, 10)
{
    Vector<std::string> vector;
    vector.push_back("Hello");
    vector.push_back("there!");
    vector.push_back("It");
    vector.push_back("is");
    vector.push_back("a");
    vector.push_back("good");
    vector.push_back("day!");
    Vector<std::string>::iterator iter = vector.begin();
    ASSERT_EQ(*++iter, "there!");
    ASSERT_EQ(*++iter, "It");
    ASSERT_EQ(*++iter, "is");
    ASSERT_EQ(*++iter, "a");
    ASSERT_EQ(*++iter, "good");
    ASSERT_EQ(*++iter, "day!");
}

TEST(vector_iterator_equals, 10)
{
    Vector<std::string> vector;
    vector.push_back("Hello");
    vector.push_back("there!");

    ASSERT_EQ(vector.begin()==vector.end(), false);

    Vector<std::string>::iterator iter = vector.begin();
    ASSERT(iter==vector.begin());

    ++iter;
    ++iter;
    ASSERT(iter==vector.end());
}

TEST(vector_iterator_not_equals, 10)
{
    Vector<std::string> vector;
    vector.push_back("Hello");

    ASSERT(vector.begin()!=vector.end());
    ASSERT_EQ(++vector.begin()!=vector.end(), false);

    ASSERT_EQ(vector.begin()!=vector.begin(), false);

    vector.push_back("Hi!");

    ASSERT(vector.begin()!=vector.end());
}

TEST(vector_iterator_integers, 25)
{
    Vector<int> vector;

    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(4);
    vector.push_back(5);

    std::cout << "using for-each syntax to add one to each item" << std::endl;
    for (int &item: vector) {
        item += 1;
    }
    std::vector<int> exp = {2, 3, 4, 5, 6};
    ASSERT_VEQ(vector, exp);
}

TEST(vector_iterator_strings, 25)
{
    Vector<std::string> vector;

    vector.push_back("waterfall");
    vector.push_back("enigma");
    vector.push_back("guitar");
    vector.push_back("zebra");
    vector.push_back("luminous");

    std::cout << "using for-each syntax to make each element uppercase..." << std::endl;
    for (std::string &item: vector) {
        std::transform(item.begin(), item.end(), item.begin(), [](unsigned char c) { return std::toupper(c); });
    }

    std::vector<std::string> exp = {"WATERFALL", "ENIGMA", "GUITAR", "ZEBRA", "LUMINOUS"};
    ASSERT_VEQ(vector, exp);
}

DO_VALGRIND(5);

TEST_MAIN();
