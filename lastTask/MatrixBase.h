#pragma once
#ifndef ADD_H
#define ADD_H

class MatrixBase
{
public:
    unsigned int size()
    {
        return m_size;
    }

    virtual int element(unsigned int i, unsigned int j) const
    {
        return matrix[i][j];
    }

    virtual int& elementLink(unsigned int i, unsigned int j) const
    {
        return matrix[i][j];
    }

    void  operator *= (int iMult)
    {
        for (int i = 0; i < m_size; i++)
            for (int j = 0; j < m_size; j++)
                this->elementLink(i, j) *= iMult;
    }

    void  operator += (MatrixBase &iAdd)
    {
        for (int i = 0; i < m_size; i++)
            for (int j = 0; j < m_size; j++)
                this->elementLink(i, j) += iAdd.element(i, j);
    }

    friend std::ostream& operator<< (std::ostream& out, const MatrixBase& matrixNd);
    
    ~MatrixBase()
    {
        for (int i = 0; i < this->size(); i++)
            delete[] this->matrix[i];
        delete[] this->matrix;
    }

protected:
    MatrixBase(unsigned int iSize):m_size(iSize)
    {        
        matrix = new int* [iSize];

        for (int i = 0; i < m_size; i++)
        {
            matrix[i] = new int[m_size];
            for (int j = 0; j < m_size; j++)
                this->elementLink(i, j) = 0;
        }
    }

private:
    const unsigned int m_size;
    int** matrix;
};

class Matrix2D :public MatrixBase
{
    public:
        Matrix2D() :MatrixBase(2) {}
        ~Matrix2D() {}

    private:

};

class Matrix3D :public MatrixBase
{
    public:
        Matrix3D() :MatrixBase(3) {}
        ~Matrix3D() {}

    private:

};
#endif