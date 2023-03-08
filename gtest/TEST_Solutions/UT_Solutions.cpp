#include "gtest/gtest.h"

#define private public
#define protected public

#include <stdio.h>
#include "Solutions.h"

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

class SolutionsTest : public ::testing::Test
{

public:
    SolutionsTest()
    {
    }

    virtual ~SolutionsTest()
    {
    }

    virtual void SetUp() override
    {
    }

    virtual void TearDown() override
    {
    }
};

TEST_F(SolutionsTest, AllUniqueCharacters)
{
    Solutions s;

    std::vector<std::string> strs{
        "a", "ab", "aa", "abb", "aab", "aaa", "abc", "abca"};

    for (auto &elem : strs)
    {
        bool expect = (std::set<char>(elem.begin(), elem.end()).size() == elem.size());
        bool ret = s.AllUniqueCharacters(elem);
        EXPECT_EQ(ret, expect);
    }
}

TEST_F(SolutionsTest, ArePermutations)
{
    Solutions s;

    std::vector<std::string> lefts{"a", "aa", "abc", "aca", "bca"};
    std::vector<std::string> rights{"b", "aa", "cba", "ccc", "dce"};
    std::vector<bool> expects{false, true, true, false, false};

    for (unsigned int i = 0; i < lefts.size(); i++)
    {
        bool ret = s.ArePermutations(lefts[i], rights[i]);
        EXPECT_EQ(ret, expects[i]);
    }
}

TEST_F(SolutionsTest, IsPalindromePermutation)
{
    Solutions s;
    std::vector<std::string> strs{"taco cat", "ccaa", "ooo", "bbooo"};
    std::vector<bool> expects{true, true, true, true};

    for (unsigned int i = 0; i < strs.size(); i++)
    {
        bool ret = s.IsPalindromePermutation(strs[i]);
        EXPECT_EQ(ret, expects[i]);
    }
}
