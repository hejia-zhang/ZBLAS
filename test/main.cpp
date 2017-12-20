//
// Created by hjzh on 17-12-19.
//
#include "VectorTest.h"

// Tests that the Vector::operator+ method
TEST_F(VectorTest, OpAddEq)
{
    ::ZBLAS::Vector t_vector1{8.218, -9.341};
    ::ZBLAS::Vector t_vector2{-1.129, 2.111};
    t_vector1 += t_vector2;
    ::ZBLAS::Vector t_sum{7.089, -7.23};
    EXPECT_EQ(t_vector1, t_sum);
}

TEST_F(VectorTest, OpAdd)
{
    ::ZBLAS::Vector t_vector1{8.218, -9.341};
    ::ZBLAS::Vector t_vector2{-1.129, 2.111};
    ::ZBLAS::Vector t_res = t_vector1 + t_vector2;
    ::ZBLAS::Vector t_sum{7.089, -7.23};
    EXPECT_EQ(t_res, t_sum);
}

TEST_F(VectorTest, OpMinus)
{
    ::ZBLAS::Vector t_vector1{7.119, 8.215};
    ::ZBLAS::Vector t_vector2{-8.223, 0.878};
    ::ZBLAS::Vector t_sum{7.119 + 8.223, 8.215 - 0.878};
    ::ZBLAS::Vector t_res = t_vector1 - t_vector2;
    EXPECT_EQ(t_res, t_sum);
}

TEST_F(VectorTest, OpMinusEq)
{
    ::ZBLAS::Vector t_vector1{7.119, 8.215};
    ::ZBLAS::Vector t_vector2{-8.223, 0.878};
    ::ZBLAS::Vector t_sum{7.119 + 8.223, 8.215 - 0.878};
    t_vector1 -= t_vector2;
    EXPECT_EQ(t_vector1, t_sum);
}

TEST_F(VectorTest, OpScale)
{
    ::ZBLAS::Vector t_vector1{1.671, -1.012, -0.318};
    ::ZBLAS::Vector t_res = t_vector1 * 7.41;
    ::ZBLAS::Vector t_scale{1.671 * 7.41, -1.012 * 7.41, -0.318 * 7.41};
    EXPECT_EQ(t_scale, t_res);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}