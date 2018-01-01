//
// Created by hjzh on 18-1-1.
//

#include "Plane.h"

namespace ZBLAS
{
    Plane::~Plane()
    {
    }

    Plane::Plane(const Vector& vector, double cterm)
            : __NormalVector(vector)
    {
        if (__NormalVector.Size() != 3)
        {
            __NormalVector.Resize(3);
        }
        __CTerm = cterm;
    }

    Plane::Plane(const Plane& other)
            : __NormalVector(other.__NormalVector)
    {
        __CTerm = other.__CTerm;
    }

    Plane& Plane::operator=(const Plane& other)
    {
        __NormalVector = other.__NormalVector;
        __CTerm = other.__CTerm;
        return *this;
    }

    Plane::Plane(Plane&& other) noexcept
            : __NormalVector(other.__NormalVector)
    {
        __CTerm = other.__CTerm;
    }

    Plane& Plane::operator=(Plane&& other) noexcept
    {
        __NormalVector = other.__NormalVector;
        __CTerm = other.__CTerm;
        return *this;
    }

    INTERSECTION_STATUS Plane::CheckParallelNSame(const Plane& lPlane, const Plane& rPlane) throw(std::runtime_error)
    {
        if (lPlane.__NormalVector.CheckIfZeroVector() || rPlane.__NormalVector.CheckIfZeroVector())
        {
            throw(std::runtime_error("Normal Vector should not be zero vector!"));
        }

        if (Vector::CheckParallel(lPlane.__NormalVector, rPlane.__NormalVector))
        {
            std::srand((unsigned int)time(nullptr));
            std::vector<double> t_vecLPoint;
            t_vecLPoint.resize(lPlane.__NormalVector.Size());
            double t_kL = lPlane.__CTerm;
            int t_idxLNz; // record the coordinate of the last dimension whose coefficient is not zero
            // set coordinates of all dimensions whose coefficient is 0 in normal vector
            for (int i = 0; i < lPlane.__NormalVector.Size(); i++)
            {
                if (fabs(lPlane.__NormalVector[i]) > 1e-5)
                {
                    t_idxLNz = i;
                    continue;
                }
                double t_one = rand() % 10;
                t_vecLPoint[i] = t_one;
            }

            for (int i = 0; i <= t_idxLNz; i++)
            {
                if (fabs(lPlane.__NormalVector[i]) > 1e-5)
                {
                    if (i < t_idxLNz)
                    {
                        double t_one = rand() % 10;
                        t_vecLPoint[i] = t_one;
                        t_kL -= t_vecLPoint[i] * lPlane.__NormalVector[i];
                    }
                    else
                    {
                        t_vecLPoint[t_idxLNz] = t_kL / lPlane.__NormalVector[t_idxLNz];
                    }
                }
            }

            std::vector<double> t_vecRPoint;
            t_vecRPoint.resize(rPlane.__NormalVector.Size());
            double t_kR = rPlane.__CTerm;
            int t_idxRNz; // record the coordinate of the last dimension whose coefficient is not zero
            // set coordinates of all dimensions whose coefficient is 0 in normal vector
            for (int i = 0; i < rPlane.__NormalVector.Size(); i++)
            {
                if (fabs(rPlane.__NormalVector[i]) > 1e-5)
                {
                    t_idxRNz = i;
                    continue;
                }
                double t_one = rand() % 10;
                t_vecRPoint[i] = t_one;
            }

            for (int i = 0; i <= t_idxRNz; i++)
            {
                if (fabs(rPlane.__NormalVector[i]) > 1e-5)
                {
                    if (i < t_idxRNz)
                    {
                        double t_one = rand() % 10;
                        t_vecRPoint[i] = t_one;
                        t_kR -= t_vecRPoint[i] * rPlane.__NormalVector[i];
                    }
                    else
                    {
                        t_vecRPoint[t_idxRNz] = t_kR / rPlane.__NormalVector[t_idxRNz];
                    }
                }
            }

            std::vector<double> t_vector;
            t_vector.resize(t_vecLPoint.size());
            for (int i = 0; i < t_vecLPoint.size(); i++)
            {
                t_vector[i] = t_vecLPoint[i] - t_vecRPoint[i];
            }
            if (Vector::CheckOrthogonal(t_vector, lPlane.__NormalVector)
                && Vector::CheckOrthogonal(t_vector, rPlane.__NormalVector))
            {
                return SAM;
            }
            return PAR;
        }
        return NPAR;
    }
}