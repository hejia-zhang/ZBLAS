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

    double Vector::GetMagnitude() const
    {
        double res = 0;
        for (const auto& val : __memory)
        {
            res += val * val;
        }
        return sqrt(res);
    }

    Vector Vector::GetNomalizedVector() const throw(std::runtime_error)
    {
        double t_magnitude = this->GetMagnitude();
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

    Vector operator* (const Vector& other, double scalar)
    {
        Vector t_res(other);
        for (auto& val : t_res.__memory)
        {
            val *= scalar;
        }
        return t_res;
    }

    Vector operator* (double scalar, const Vector& other)
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
        std::vector<double>::const_iterator ite = vector.__memory.begin();
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

    double Vector::GetDotProduct(const Vector &lVec, const Vector &rVec) throw(std::runtime_error)
    {
        double res = 0;
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

    double Vector::GetAngleInRadians(const Vector& lVec, const Vector& rVec) throw(std::runtime_error)
    {
        double lMag = lVec.GetMagnitude();
        double rMag = rVec.GetMagnitude();

        if (fabs(lMag - 0) < 1e-5 || fabs(rMag - 0) < 1e-5)
        {
            throw(std::runtime_error("Zero vector has no direction!"));
        }

        double cosTheta = GetDotProduct(lVec, rVec) / lMag / rMag;

        double angleInRadians = acos(cosTheta);

        return angleInRadians;
    }

    double Vector::GetAngleInDegrees(const Vector& lVec, const Vector& rVec) throw(std::runtime_error)
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

        double scale = *lVec.__memory.begin() / *rVec.__memory.begin();
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

    Vector Vector::GetParellalOntoBase(const Vector &base) throw(std::runtime_error)
    {
        if (__memory.empty() || base.__memory.empty())
        {
            throw(std::runtime_error("NO zero dimension vector"));
        }

        if (__memory.size() != base.__memory.size())
        {
            throw(std::runtime_error("Should have the same dimension with Base vector"));
        }

        Vector unitVectorB = base.GetNomalizedVector();
        return Vector(GetDotProduct(*this, unitVectorB) * unitVectorB);
    }

    Vector Vector::GetPerpOntoBase(const Vector &base) throw(std::runtime_error)
    {
        return Vector(*this - GetParellalOntoBase(base));
    }

    Vector Vector::operator*(const Vector &other) const throw(std::runtime_error)
    {
        if (__memory.size() != 3 || other.__memory.size() != 3)
        {
            throw(std::runtime_error("The cross product is only supported in three dimensional space!"));
        }
        return Vector{__memory[1] * other.__memory[2] - __memory[2] * other.__memory[1],
                      -(__memory[0] * other.__memory[2] - __memory[2] * other.__memory[0]),
                      __memory[0] * other.__memory[1] - __memory[1] * other.__memory[0]};
    }

    double Vector::GetTriangleArea(const Vector& lVec, const Vector& rVec) throw(std::runtime_error)
    {
        return (lVec * rVec).GetMagnitude() / 2;
    }

    double Vector::GetParallelogramArea(const Vector &lVec, const Vector &rVec) throw(std::runtime_error)
    {
        return (lVec * rVec).GetMagnitude();
    }
}



