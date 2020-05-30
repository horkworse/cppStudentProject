#include "MatrixXnX.h"
#include <time.h>
#include <xutility>

MatrixXnX::MatrixXnX(const int iDim)
{
    this->size = iDim;
    values = new int* [iDim];

    for (int i = 0; i < iDim; i++)
    {
        values[i] = new int[iDim];
        for (int j = 0; j < iDim; j++)
            values[i][j] = 0;
    }
}
MatrixXnX::~MatrixXnX()
{
    for (int i = 0; i < size; i++)
        delete[] values[i];
    delete[] values;
}

const int MatrixXnX::element(const int i, const int j)
{
    return values[i][j];
}

void MatrixXnX::setElement(const int i, const int j, const int value)
{
    values[i][j] = value;
}

void MatrixXnX::fillRandomElements(const int minVal, const int maxVal)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            values[i][j] = rand() % (maxVal * 2) + minVal;
}

const int MatrixXnX::sumPrincipalDiag()
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += values[i][i];
    return sum;
}

const int MatrixXnX::sumSecondaryDiag()
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += values[i][size - 1 - i];
    return sum;
}

const int MatrixXnX::productPrincipalDiag()
{
    int result = 1;
    for (int i = 0; i < size; i++)
        result *= values[i][i];
    return result;
}

const int MatrixXnX::productSecondaryDiag()
{
    int result = 1;
    for (int i = 0; i < size; i++)
        result *= values[i][size - 1 - i];
    return result;
}

const int MatrixXnX::sumRow(const int iRow)
{
    int sum = 0;
    for (int j = 0; j < size; j++)
        sum = values[iRow][j];
    return sum;
}

const int MatrixXnX::minColumn(const int iCol)
{
    int min = values[0][iCol];

    for (int i = 1; i < size; i++)
        if (min > values[i][iCol])
            min = values[i][iCol];
    return min;
}

const int MatrixXnX::maxColumn(const int iCol)
{
    int max = values[0][iCol];

    for (int i = 1; i < size; i++)
        if (max < values[i][iCol])
            max = values[i][iCol];
    return max;
}