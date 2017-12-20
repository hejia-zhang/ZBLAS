//
// Created by hjzh on 17-12-19.
//
#include "VectorTest.h"
#include <math.h>

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

TEST_F(VectorTest, GetMagnitude)
{
    ::ZBLAS::Vector t_vector{-0.221, 7.437};
    EXPECT_TRUE((t_vector.GetMagnitude() - sqrt(0.221 * 0.221 + 7.437 * 7.437)) < 1e-5);
}

TEST_F(VectorTest, Nomalize)
{
    ::ZBLAS::Vector t_vector{5.581, -2.136};
    EXPECT_TRUE(fabs(t_vector.GetNomalizedVector().GetMagnitude() - 1) < 1e-5);
}

TEST_F(VectorTest, GetDotProduct)
{
    ::ZBLAS::Vector t_v{7.887, 4.138};
    ::ZBLAS::Vector t_w{-8.802, 6.776};
    EXPECT_FLOAT_EQ(::ZBLAS::Vector::GetDotProduct(t_v, t_w), 7.887 * -8.802 + 4.138 * 6.776);
}

TEST_F(VectorTest, GetAngleInRadians)
{
    ::ZBLAS::Vector t_v{-1, 1};
    ::ZBLAS::Vector t_w{1, 1};
    EXPECT_FLOAT_EQ(::ZBLAS::Vector::GetAngleInRadians(t_v, t_w), 3.1415926 / 2);
}

TEST_F(VectorTest, GetAngleInDegrees)
{
    ::ZBLAS::Vector t_v{-1, 1};
    ::ZBLAS::Vector t_w{1, 1};
    EXPECT_FLOAT_EQ(::ZBLAS::Vector::GetAngleInDegrees(t_v, t_w), 90);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}