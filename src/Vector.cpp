//
// Created by hjzh on 17-12-19.
//
#include "Vector.h"

using namespace ZBLAS;

Vector::Vector(const Vector& other)
{
    __memory = other.__memory;
}

Vector& Vector::operator=(const Vector &other)
{
    __memory = other.__memory;
}

Vector::Vector(Vector&& other) noexcept
{
    __memory = std::move(other.__memory);
}

Vector& Vector::operator=(Vector &&other) noexcept
{
    __memory = std::move(other.__memory);
    return *this;
}

Vector::~Vector()
{
    __memory.clear();
}

Vector Vector::operator+(const Vector &other) throw(std::runtime_error)
{
    Vector res(*this);

    if (__memory.size() != other.__memory.size())
    {
        throw (std::runtime_error("Two operands' dimension don't match!"));
    }
    else
    {
        for (int i = 0; i < __memory.size(); i++)
        {
            res.__memory[i] = __memory[i] + other.__memory[i];
        }
    }
    return res;
}

Vector& Vector::operator+=(const Vector& other) throw(std::runtime_error)
{
    if (__memory.size() != other.__memory.size())
    {
        throw (std::runtime_error("Two operands' dimension don't match!"));
    }
    else
    {
        for (int i = 0; i < __memory.size(); i++)
        {
            __memory[i] += other.__memory[i];
        }
    }
    return *this;
}

Vector Vector::operator-(const Vector& other) throw(std::runtime_error)
{
    Vector res(*this);

    if (__memory.size() != other.__memory.size())
    {
        throw (std::runtime_error("Two operands' dimension don't match!"));
    }
    else
    {
        for (int i = 0; i < __memory.size(); i++)
        {
            res.__memory[i] = __memory[i] - other.__memory[i];
        }
    }
    return res;
}

Vector& Vector::operator-=(const Vector& other) throw(std::runtime_error)
{
    if (__memory.size() != other.__memory.size())
    {
        throw (std::runtime_error("Two operands' dimension don't match!"));
    }
    else
    {
        for (int i = 0; i < __memory.size(); i++)
        {
            __memory[i] -= other.__memory[i];
        }
    }
    return *this;
}

bool Vector::operator==(const Vector& other) const noexcept
{
    if (__memory.size() != other.__memory.size())
    {
        return false;
    }
    for (int i = 0; i < __memory.size(); i++)
    {
        if ((__memory[i] - other.__memory[i]) > 1e-5)
        {
            return false;
        }
    }
    return true;
}



