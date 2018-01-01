//
// Created by hjzh on 17-12-19.
//

#ifndef ZBLAS_VECTOR_H
#define ZBLAS_VECTOR_H

#include <cstring>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <math.h>

namespace ZBLAS
{
    class Vector
    {
    public:
        // constructors
        virtual ~Vector();

        Vector(const Vector& other);

        Vector& operator=(const Vector& other);

        Vector(Vector&& other) noexcept;

        Vector& operator=(Vector&& other) noexcept;

        template <typename... T>
        explicit Vector(T... elements)
        {
            __memory.reserve(sizeof...(elements));
            AddElement(elements...);
        }

    public:
        // override operators
        double operator[](size_t i) const throw(std::runtime_error);

        Vector operator+(const Vector& other) throw(std::runtime_error);

        Vector& operator+=(const Vector& other) throw(std::runtime_error);

        Vector operator-(const Vector& other) throw(std::runtime_error);

        Vector& operator-=(const Vector& other) throw(std::runtime_error);

        bool operator==(const Vector& other) const noexcept;

        Vector operator*(const Vector& other) const throw(std::runtime_error);

        friend Vector operator* (double scalar, const Vector& other);

        friend Vector operator* (const Vector& other, double scalar);

        friend std::ostream& operator<< (std::ostream& out, const Vector& vector);

    public:
        double GetMagnitude() const;

        Vector GetNomalizedVector() const throw(std::runtime_error);

        static double GetDotProduct(const Vector& lVec, const Vector& rVec) throw(std::runtime_error);

        static double GetAngleInRadians(const Vector& lVec, const Vector& rVec) throw(std::runtime_error);

        static double GetAngleInDegrees(const Vector& lVec, const Vector& rVec) throw(std::runtime_error);

        static bool CheckParallel(const Vector& lVec, const Vector& rVec) throw(std::runtime_error);

        static bool CheckOrthogonal(const Vector& lVec, const Vector& rVec) throw(std::runtime_error);

        static double GetTriangleArea(const Vector& lVec, const Vector& rVec) throw(std::runtime_error);

        static double GetParallelogramArea(const Vector& lVec, const Vector& rVec) throw(std::runtime_error);

        Vector GetParellalOntoBase(const Vector& base) throw(std::runtime_error);

        Vector GetPerpOntoBase(const Vector& base) throw(std::runtime_error);

    private:
        std::vector<double> __memory;

        template <typename T>
        void AddElement(T element)
        {
            __memory.push_back(element);
        }

        template <typename T1, typename... T2>
        void AddElement(T1 head, T2... elements)
        {
            __memory.push_back(head);
            AddElement(elements...);
        }

        bool CheckIfZeroVector() const
        {
            if (fabs(GetMagnitude() - 0) < 1e-5)
            {
                return true;
            }
            return false;
        }

    public:
        // forbidden constructor functions
        Vector() = delete;
    };
}

#endif //ZBLAS_VECTOR_H
