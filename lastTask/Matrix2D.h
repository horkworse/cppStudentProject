#include "MatrixBase.h";
#pragma once

constexpr unsigned int m2Size = 2;
class Matrix2D :public MatrixBase
{
public:
    Matrix2D() :MatrixBase(m2Size) {}
    ~Matrix2D()
    {
    }

    int element(unsigned int i, unsigned int j) const override
    {
        return matrix[i][j];
    }

    int& element(unsigned int i, unsigned int j) override
    {
        return matrix[i][j];
    }
private:
    int matrix[m2Size][m2Size];
};


