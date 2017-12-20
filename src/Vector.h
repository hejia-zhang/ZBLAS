//
// Created by hjzh on 17-12-19.
//

#ifndef ZBLAS_VECTOR_H
#define ZBLAS_VECTOR_H

#include <cstring>
#include <vector>
#include <stdexcept>

namespace ZBLAS
{
    class Vector
    {
    public:
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

        Vector operator+(const Vector& other) throw(std::runtime_error);

        Vector& operator+=(const Vector& other) throw(std::runtime_error);

        Vector operator-(const Vector& other) throw(std::runtime_error);

        Vector& operator-=(const Vector& other) throw(std::runtime_error);

        bool operator==(const Vector& other) const noexcept;

        friend Vector operator* (float scalar, const Vector& other)
        {
            Vector t_res(other);
            for (auto& val : t_res.__memory)
            {
                val *= scalar;
            }
            return t_res;
        }

        friend Vector operator* (const Vector& other, float scalar)
        {
            Vector t_res(other);
            for (auto& val : t_res.__memory)
            {
                val *= scalar;
            }
            return t_res;
        }

    private:
        std::vector<float> __memory;

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

    public:
        // forbidden constructor functions
        Vector() = delete;
    };
}

#endif //ZBLAS_VECTOR_H
