//
// Created by hjzh on 17-12-19.
//
#include "Vector.h"

using namespace ZBLAS;

Vector::Vector(Vector&& vector)
{
    __memory = std::move(vector.GetValue());
}

Vector& Vector::operator=(Vector &&vector)
{
    __memory = std::move(vector.GetValue());
}

Vector::~Vector()
{
    __memory.clear();
}

Vector& Vector::operator+(const Vector &vector)
{

}

