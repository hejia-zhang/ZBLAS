//
// Created by hjzh on 17-12-19.
//
#include "VectorTest.h"

// Tests that the Vector::operator+ method
TEST_F(VectorTest, OpAdd)
{
    ::ZBLAS::Vector t_vector1{8.218, -9.341};
    ::ZBLAS::Vector t_vector2{-1.129, 2.111};
    t_vector1 += t_vector2;
    ::ZBLAS::Vector t_sum{7.089, -7.23};
    EXPECT_EQ(t_vector1, t_sum);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}