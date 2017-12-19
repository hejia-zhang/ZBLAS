//
// Created by hjzh on 17-12-19.
//

#ifndef ZBLAS_VECTORTEST_H
#define ZBLAS_VECTORTEST_H


#include "../src/Vector.h"
#include "gtest/gtest.h"

class VectorTest : public ::testing::Test
{
protected:
    VectorTest()
    {
    }

    virtual ~VectorTest()
    {
    }

    virtual void Setup()
    {
    }

    virtual void TearDown()
    {
    }
};
#endif //ZBLAS_VECTORTEST_H
