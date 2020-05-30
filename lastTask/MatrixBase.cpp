#include "MatrixBase.h"

MatrixBase::~MatrixBase()
{

}

MatrixBase::MatrixBase(unsigned int iSize) :m_size(iSize)
{
    
}

unsigned int MatrixBase::size()
{
    return m_size;
}

void  MatrixBase::operator *= (int iMult)
{
    for (int i = 0; i < m_size; i++)
        for (int j = 0; j < m_size; j++)
            this->element(i, j) *= iMult;
}

void  MatrixBase::operator += (MatrixBase& iAdd)
{
    for (int i = 0; i < m_size; i++)
        for (int j = 0; j < m_size; j++)
            this->element(i, j) += iAdd.element(i, j);
}

std::ostream& operator<< (std::ostream& out, const MatrixBase& matrixNd)
{
    for (int i = 0; i < matrixNd.m_size; i++)
    {
        for (int j = 0; j < matrixNd.m_size; j++)
            out << matrixNd.element(i, j) << "  ";
        out << '\n';
    }
    out << '\n';
    return out;
}