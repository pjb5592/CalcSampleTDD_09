// calc_sample_test.cpp
#include <gtest/gtest.h>
#include "calc_sample.hpp"

TEST(CalcSampleTest, Plus_Basic) {
    EXPECT_EQ(3, CalcSample::sum(1, 2));
    EXPECT_EQ(5, CalcSample::sum(4, 1));
}

// 매개변수화 버전
class SumTest :
    public ::testing::TestWithParam<std::tuple<int,int,int>>{};

TEST_P(SumTest, Check) {
    auto [a,b,exp] = GetParam();
    EXPECT_EQ(exp, CalcSample::sum(a,b));
}

INSTANTIATE_TEST_SUITE_P(Cases, SumTest,
    ::testing::Values(
        std::make_tuple(1,2,3), std::make_tuple(4,1,5)));
