#include "MatrixBase.h";
#pragma once

constexpr unsigned int m3Size = 3;
class Matrix3D :public MatrixBase
{
public:
    Matrix3D();
    ~Matrix3D();

    int element(unsigned int i, unsigned int j) const override;

    int& element(unsigned int i, unsigned int j) override;
private:
    int matrix[m3Size][m3Size];
};