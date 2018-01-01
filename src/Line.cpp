//
// Created by hjzh on 17-12-21.
//

#include "Line.h"

namespace ZBLAS
{
    std::ostream& operator<< (std::ostream& out, const Line& line)
    {
        out << line.__NormalVector[0] << " * x + " << line.__NormalVector[1] << " * y = " << line.__cTerm;
        return out;
    }

    Line::Line(const Vector &vector, double cTerm)
            : __NormalVector(vector), __cTerm(cTerm)
    {
    }

    Line::~Line()
    {
    }

    Line::Line(const Line& other)
        : __NormalVector(other.__NormalVector)
    {
        __cTerm = other.__cTerm;
    }

    Line& Line::operator=(const Line& other)
    {
        __NormalVector = other.__NormalVector;
        __cTerm = other.__cTerm;
        return *this;
    }

    Line::Line(Line&& other) noexcept
            : __NormalVector(other.__NormalVector)
    {
        __cTerm = other.__cTerm;
    }

    Line& Line::operator=(Line&& other) noexcept
    {
        __NormalVector = other.__NormalVector;
        __cTerm = other.__cTerm;
        return *this;
    }

    INTERSECTION_STATUS Line::CheckParallelNSame(const Line &lLine, const Line &rLine) throw(std::runtime_error)
    {
        if (Vector::CheckParallel(lLine.__NormalVector, rLine.__NormalVector))
        {
            // there is no possibility that both of two elements in normal vector are 0
            if (lLine.__NormalVector[0] == 0 && rLine.__NormalVector[0] == 0
                && (fabs(lLine.__cTerm / lLine.__NormalVector[1] - rLine.__cTerm / rLine.__NormalVector[1]) < 1e-5))
            {
                return SAM;
            }

            if (lLine.__NormalVector[1] == 0 && rLine.__NormalVector[1] == 0
                && (fabs(lLine.__cTerm / lLine.__NormalVector[0] - rLine.__cTerm / rLine.__NormalVector[0]) < 1e-5))
            {
                return SAM;
            }

            // pick one point each
            double xl = 1;
            double yl = (lLine.__cTerm - xl * lLine.__NormalVector[0]) / lLine.__NormalVector[1];

            double xr = 2;
            double yr = (rLine.__cTerm - xr * rLine.__NormalVector[0]) / rLine.__NormalVector[1];

            Vector t_vector{xr - xl, yr - yl};

            if (Vector::CheckOrthogonal(t_vector, lLine.__NormalVector)
                && Vector::CheckOrthogonal(t_vector, rLine.__NormalVector))
            {
                return SAM;
            }
            return PAR;
        }
        return NPAR;
    }

    Vector Line::GetIntersectionOfTwoNonParLines(const Line &lLine, const Line &rLine) throw(std::runtime_error)
    {
        // Ax + By = k1
        // Cx + Dy = k2
        double x = (rLine.__NormalVector[1] * lLine.__cTerm - lLine.__NormalVector[1] * rLine.__cTerm)
                   / (lLine.__NormalVector[0] * rLine.__NormalVector[1] - lLine.__NormalVector[1] * rLine.__NormalVector[0]);

        double y = (-rLine.__NormalVector[0] * lLine.__cTerm + lLine.__NormalVector[0] * rLine.__cTerm)
                   / (lLine.__NormalVector[0] * rLine.__NormalVector[1] - lLine.__NormalVector[1] * rLine.__NormalVector[0]);

        return Vector(x, y);
    }
}