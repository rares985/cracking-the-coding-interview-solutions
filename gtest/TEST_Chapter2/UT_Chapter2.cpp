#include "gtest/gtest.h"

#define private public
#define protected public

#include <stdio.h>
#include "Chapter2.h"

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

class Chapter2Test : public ::testing::Test
{

public:
    Chapter2Test()
    {
    }

    virtual ~Chapter2Test()
    {
    }

    virtual void SetUp() override
    {
    }

    virtual void TearDown() override
    {
    }
};

TEST_F(Chapter2Test, Testt)
{
    Chapter2 s;
    EXPECT_EQ(true, true);
}