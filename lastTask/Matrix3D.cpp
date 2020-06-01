#include "Matrix3D.h"

Matrix3D::Matrix3D() :MatrixBase(m3Size) {}
Matrix3D::~Matrix3D() {}

int Matrix3D::element(unsigned int i, unsigned int j) const
{
    return matrix[i][j];
}

int& Matrix3D::element(unsigned int i, unsigned int j)
{
    return matrix[i][j];
}