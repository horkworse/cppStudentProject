#include "Matrix2D.h"

Matrix2D::Matrix2D() :MatrixBase(m2Size) {}
Matrix2D::~Matrix2D() {}

int Matrix2D::element(unsigned int i, unsigned int j) const
{
    return matrix[i][j];
}

int& Matrix2D::element(unsigned int i, unsigned int j)
{
    return matrix[i][j];
}