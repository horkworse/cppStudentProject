#include <iostream>
#pragma once

class MatrixBase
{
public:
    unsigned int size();
    virtual int element(unsigned int i, unsigned int j) const = 0;
    virtual int& element(unsigned int i, unsigned int j) = 0;
    void  operator *= (int iMult);
    void  operator += (MatrixBase& iAdd);
    friend std::ostream& operator<< (std::ostream& out, const MatrixBase& matrixNd);
    ~MatrixBase();

protected:
    MatrixBase(unsigned int iSize);

private:
    const unsigned int m_size;
};