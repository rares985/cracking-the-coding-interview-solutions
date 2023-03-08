#include "gtest/gtest.h"

#define private public
#define protected public

#include <stdio.h>
#include "Chapter1.h"

#include <bits/stdc++.h>

// using ::testing::ByRef;
// using ::testing::DoAll;
// using ::testing::Eq;
// using ::testing::Pointee;
// using ::testing::Return;
// using ::testing::ReturnRef;
// using ::testing::SetArgPointee;
// using ::testing::SetArrayArgument;
// using ::testing::StrEq;

class Chapter1Test : public ::testing::Test
{

public:
    Chapter1Test()
    {
    }

    virtual ~Chapter1Test()
    {
    }

    virtual void SetUp() override
    {
    }

    virtual void TearDown() override
    {
    }
};

TEST_F(Chapter1Test, AllUniqueCharacters)
{
    Chapter1 s;

    std::vector<std::string> strs{
        "a", "ab", "aa", "abb", "aab", "aaa", "abc", "abca"};

    for (auto &elem : strs)
    {
        bool expect = (std::set<char>(elem.begin(), elem.end()).size() == elem.size());
        bool ret = s.AllUniqueCharacters(elem);
        EXPECT_EQ(ret, expect);
    }
}

TEST_F(Chapter1Test, ArePermutations)
{
    Chapter1 s;

    std::vector<std::string> lefts{"a", "aa", "abc", "aca", "bca"};
    std::vector<std::string> rights{"b", "aa", "cba", "ccc", "dce"};
    std::vector<bool> expects{false, true, true, false, false};

    for (unsigned int i = 0; i < lefts.size(); i++)
    {
        bool ret = s.ArePermutations(lefts[i], rights[i]);
        EXPECT_EQ(ret, expects[i]);
    }
}

TEST_F(Chapter1Test, IsPalindromePermutation)
{
    Chapter1 s;
    std::vector<std::string> strs{"taco cat", "ccaa", "ooo", "bbooo"};
    std::vector<bool> expects{true, true, true, true};

    for (unsigned int i = 0; i < strs.size(); i++)
    {
        bool ret = s.IsPalindromePermutation(strs[i]);
        EXPECT_EQ(ret, expects[i]);
    }
}
