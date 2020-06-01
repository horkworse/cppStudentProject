#include "MatrixBase.h";
#pragma once

constexpr unsigned int m2Size = 2;
class Matrix2D :public MatrixBase
{
public:
    Matrix2D();
    ~Matrix2D();

    int element(unsigned int i, unsigned int j) const override;

    int& element(unsigned int i, unsigned int j) override;
private:
    int matrix[m2Size][m2Size];
};


