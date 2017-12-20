//
// Created by hjzh on 17-12-20.
//

#include "Vector.h"
#include <iostream>

int main()
{
    ::ZBLAS::Vector vector1{-0.221, 7.437};
    std::cout << vector1.GetMagnitude() << std::endl;

    ::ZBLAS::Vector vector2{8.813, -1.331, -6.247};
    std::cout << vector2.GetMagnitude() << std::endl;

    ::ZBLAS::Vector vector3{5.581, -2.136};
    std::cout << vector3.GetNomalizedVector() << std::endl;

    ::ZBLAS::Vector vector4{1.996, 3.108, -4.554};
    std::cout << vector4.GetNomalizedVector() << std::endl;

    std::cout << ::ZBLAS::Vector::GetDotProduct(::ZBLAS::Vector{7.887, 4.138}, ::ZBLAS::Vector{-8.802, 6.776}) << std::endl;

    std::cout << ::ZBLAS::Vector::GetDotProduct(::ZBLAS::Vector{-5.955, -4.904, -1.874}, ::ZBLAS::Vector{-4.496, -8.755, 7.103}) << std::endl;

    std::cout << ::ZBLAS::Vector::GetAngleInRadians(::ZBLAS::Vector{3.183, -7.627}, ::ZBLAS::Vector{-2.668, 5.319}) << std::endl;

    std::cout << ::ZBLAS::Vector::GetAngleInDegrees(::ZBLAS::Vector{7.35, 0.221, 5.188}, ::ZBLAS::Vector{2.751, 8.259, 3.985}) << std::endl;

    std::cout << ::ZBLAS::Vector::CheckParallel(::ZBLAS::Vector{-7.579, -7.88}, ::ZBLAS::Vector{22.737, 23.64}) << std::endl;

    std::cout << ::ZBLAS::Vector::CheckOrthogonal(::ZBLAS::Vector{-7.579, -7.88}, ::ZBLAS::Vector{22.737, 23.64}) << std::endl;

    std::cout << ::ZBLAS::Vector::CheckParallel(::ZBLAS::Vector{-2.029, 9.97, 4.172}, ::ZBLAS::Vector{-9.231, -6.639, -7.245}) << std::endl;

    std::cout << ::ZBLAS::Vector::CheckOrthogonal(::ZBLAS::Vector{-2.029, 9.97, 4.172}, ::ZBLAS::Vector{-9.231, -6.639, -7.245}) << std::endl;

    std::cout << ::ZBLAS::Vector::CheckParallel(::ZBLAS::Vector{-2.328, -7.284, -1.214}, ::ZBLAS::Vector{-1.821, 1.072, -2.94}) << std::endl;

    std::cout << ::ZBLAS::Vector::CheckOrthogonal(::ZBLAS::Vector{-2.328, -7.284, -1.214}, ::ZBLAS::Vector{-1.821, 1.072, -2.94}) << std::endl;

    std::cout << ::ZBLAS::Vector::CheckParallel(::ZBLAS::Vector{2.118, 4.827}, ::ZBLAS::Vector{0, 0}) << std::endl;

    std::cout << ::ZBLAS::Vector::CheckOrthogonal(::ZBLAS::Vector{2.118, 4.827}, ::ZBLAS::Vector{0, 0}) << std::endl;

    ::ZBLAS::Vector vector5{3.039, 1.879};
    ::ZBLAS::Vector base1{0.825, 2.036};
    std::cout << vector5.GetParellalOntoBase(base1) << std::endl;

    ::ZBLAS::Vector vector6{-9.88, -3.264, -8.159};
    ::ZBLAS::Vector base2{-2.155, -9.353, -9.473};
    std::cout << vector6.GetPerpOntoBase(base2) << std::endl;

    ::ZBLAS::Vector vector7{3.009, -6.172, 3.692, -2.51};
    ::ZBLAS::Vector base3{6.404, -9.144, 2.759, 8.718};
    std::cout << vector7.GetParellalOntoBase(base3) << ", " << vector7.GetPerpOntoBase(base3) << std::endl;

    ::ZBLAS::Vector vector8{8.462, 7.893, -8.187};
    ::ZBLAS::Vector wector1{6.984, -5.975, 4.778};
    std::cout << vector8 * wector1 << std::endl;

    std::cout << ::ZBLAS::Vector::GetParallelogramArea(::ZBLAS::Vector{-8.987, -9.838, 5.031}, ::ZBLAS::Vector{-4.268, -1.861, -8.866}) << std::endl;

    std::cout << ::ZBLAS::Vector::GetTriangleArea(::ZBLAS::Vector{1.5, 9.547, 3.691}, ::ZBLAS::Vector{-6.007, 0.124, 5.772}) << std::endl;
}