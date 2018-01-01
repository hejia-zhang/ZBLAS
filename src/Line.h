//
// Created by hjzh on 17-12-21.
//

#ifndef ZBLAS_LINE_H
#define ZBLAS_LINE_H

#include "Vector.h"

namespace ZBLAS
{
    enum INTERSECTION_STATUS
    {
        PAR = 0,
        SAM = 1,
        NPAR = 2,
    };

    class Line
    {
        friend std::ostream& operator<< (std::ostream& out, const Line& line);

    public:
        Line(const Vector& vector, double cTerm);

        virtual ~Line();

        Line(const Line& other);

        Line& operator=(const Line& other);

        Line(Line&& other) noexcept;

        Line& operator=(Line&& other) noexcept;


    public:
        static INTERSECTION_STATUS CheckParallelNSame(const Line& lLine, const Line& rLine) throw(std::runtime_error);

        static Vector GetIntersectionOfTwoNonParLines(const Line& lLine, const Line& rLine) throw(std::runtime_error);

    private:
        Vector __NormalVector; // Ax + By = C; it's (A, B)
        double __cTerm; // it's C

    public:
        Line() = delete;
    };
}
#endif //ZBLAS_LINE_H
