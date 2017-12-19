//
// Created by hjzh on 17-12-19.
//

#ifndef ZBLAS_VECTOR_H
#define ZBLAS_VECTOR_H

#include <cstring>
#include <vector>

namespace ZBLAS
{
    class Vector
    {
    public:
        virtual ~Vector();

        virtual Vector(Vector&& vector) noexcept;

        Vector& operator=(Vector&& vector) noexcept;

        virtual explicit Vector(float... elements)
        {
            __memory.reserve(sizeof...(elements));
            AddElement(elements...);
        }

        std::vector<float>& GetValue()
        {
            return __memory;
        }

        Vector& operator+(const Vector& vector);

    private:
        std::vector<float> __memory;

        void AddElement(float element)
        {
            __memory.push_back(element);
        }

        void AddElement(float head, float... elements)
        {
            __memory.push_back(head);
            AddElement(elements...);
        }

    public:
        // forbidden constructor functions
        Vector() = delete;
        Vector(const Vector& vector) = delete;
        void operator=(const Vector& vector) = delete;
    };
}

#endif //ZBLAS_VECTOR_H
