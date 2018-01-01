//
// Created by hjzh on 18-1-1.
//

#ifndef ZBLAS_PLANE_H
#define ZBLAS_PLANE_H

#include "Vector.h"
#include "Common.h"

namespace ZBLAS
{
    class Plane
    {
    public:
        Plane() = delete;

        virtual ~Plane();

        Plane(const Vector& vector, double cterm);

        Plane(const Plane& other);

        Plane& operator=(const Plane& other);

        Plane(Plane&& other) noexcept;

        Plane& operator=(Plane&& other) noexcept;

    public:
        static INTERSECTION_STATUS CheckParallelNSame(const Plane& lPlane, const Plane& rPlane) throw(std::runtime_error);

    private:
        Vector __NormalVector;
        double __CTerm;
    };
}

#endif //ZBLAS_PLANE_H
