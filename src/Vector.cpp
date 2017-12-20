//
// Created by hjzh on 17-12-19.
//
#include "Vector.h"
#include <math.h>

namespace ZBLAS
{
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
            if (fabs(__memory[i] - other.__memory[i]) > 1e-5)
            {
                return false;
            }
        }
        return true;
    }

    float Vector::GetMagnitude() const
    {
        float res = 0;
        for (const auto& val : __memory)
        {
            res += val * val;
        }
        return sqrt(res);
    }

    Vector Vector::GetNomalizedVector() const throw(std::runtime_error)
    {
        float t_magnitude = this->GetMagnitude();
        if (fabs(t_magnitude - 0) < 1e-5)
        {
            throw(std::runtime_error("Zero vector has no direction!"));
        }
        Vector vector(*this);
        for (auto& val : vector.__memory)
        {
            val /= t_magnitude;
        }
        return vector;
    }

    Vector operator* (const Vector& other, float scalar)
    {
        Vector t_res(other);
        for (auto& val : t_res.__memory)
        {
            val *= scalar;
        }
        return t_res;
    }

    Vector operator* (float scalar, const Vector& other)
    {
        Vector t_res(other);
        for (auto& val : t_res.__memory)
        {
            val *= scalar;
        }
        return t_res;
    }

    std::ostream& operator<< (std::ostream& out, const Vector& vector)
    {
        out << "[";
        std::vector<float>::const_iterator ite = vector.__memory.begin();
        while (ite != vector.__memory.end())
        {
            if (ite + 1 == vector.__memory.end())
            {
                out << *ite << "]";
            }
            else
            {
                out << *ite << ", ";
            }

            ite++;
        }
        return out;
    }

    float Vector::GetDotProduct(const Vector &lVec, const Vector &rVec) throw(std::runtime_error)
    {
        float res = 0;
        if (lVec.__memory.size() != rVec.__memory.size())
        {
            throw(std::runtime_error("Two vectors should have the same dimensions!"));
        }
        for (int i = 0; i < lVec.__memory.size(); i++)
        {
            res += lVec.__memory[i] * rVec.__memory[i];
        }
        return res;
    }

    float Vector::GetAngleInRadians(const Vector& lVec, const Vector& rVec) throw(std::runtime_error)
    {
        float lMag = lVec.GetMagnitude();
        float rMag = rVec.GetMagnitude();

        if (fabs(lMag - 0) < 1e-5 || fabs(rMag - 0) < 1e-5)
        {
            throw(std::runtime_error("Zero vector has no direction!"));
        }

        float cosTheta = GetDotProduct(lVec, rVec) / lMag / rMag;

        float angleInRadians = acos(cosTheta);

        return angleInRadians;
    }

    float Vector::GetAngleInDegrees(const Vector& lVec, const Vector& rVec) throw(std::runtime_error)
    {
        return GetAngleInRadians(lVec, rVec) / M_PI * 180;
    }

    bool Vector::CheckParallel(const Vector &lVec, const Vector &rVec) throw(std::runtime_error)
    {
        if (lVec.__memory.size() != rVec.__memory.size())
        {
            throw(std::runtime_error("Two vectors should have the same dimensions!"));
        }

        if (lVec.__memory.empty())
        {
            throw(std::runtime_error("No zero dimension vector!"));
        }

        if (lVec.CheckIfZeroVector() || rVec.CheckIfZeroVector())
        {
            return true;
        }

        float scale = *lVec.__memory.begin() / *rVec.__memory.begin();
        for (int i = 1; i < lVec.__memory.size(); i++)
        {
            if (fabs(lVec.__memory[i] / rVec.__memory[i] - scale) > 1e-5)
            {
                return false;
            }
        }
        return true;
    }

    bool Vector::CheckOrthogonal(const Vector &lVec, const Vector &rVec) throw(std::runtime_error)
    {
        if (fabs(GetDotProduct(lVec, rVec) - 0) < 1e-5)
        {
            return true;
        }
        return false;
    }
}



