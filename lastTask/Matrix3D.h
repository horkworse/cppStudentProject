#include "MatrixBase.h";
#pragma once

constexpr unsigned int m3Size = 3;
class Matrix3D :public MatrixBase
{
public:
    Matrix3D() :MatrixBase(m3Size) {}
    ~Matrix3D()
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
    int matrix[m3Size][m3Size];
};