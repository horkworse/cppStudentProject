#include "Matrix3x3.h"
#include <time.h>
#include <xutility>

Matrix3x3::Matrix3x3()
{
    values = new int* [size];

    for (int i = 0; i < size; i++)
    {
        values[i] = new int[size];
        for (int j = 0; j < size; j++)
            values[i][j] = 0;
    }
}

Matrix3x3::~Matrix3x3()
{
    for (int i = 0; i < size; i++)
        delete[] values[i];
    delete[] values;
}

const int Matrix3x3::element(const int i, const int j)
{
    return values[i][j];
}

void Matrix3x3::setElement(const int i, const int j, const int value)
{
    values[i][j] = value;
}

void Matrix3x3::fillRandomElements(const int minVal, const int maxVal)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            values[i][j] = rand() % (maxVal * 2) + minVal;
}

const int Matrix3x3::sumPrincipalDiag()
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += values[i][i];
    return sum;
}

const int Matrix3x3::sumSecondaryDiag()
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += values[i][2 - i];
    return sum;
}

const int Matrix3x3:: productPrincipalDiag()
{
    int result = 1;
    for (int i = 0; i < size; i++)
        result *= values[i][i];
    return result;
}

const int Matrix3x3::productSecondaryDiag()
{
    int result = 1;
    for (int i = 0; i < size; i++)
        result *= values[i][2 - i];
    return result;
}

const int Matrix3x3::sumRow(const int iRow)
{
    int sum = 0;
    for (int j = 0; j < size; j++)
        sum = values[iRow][j];
    return sum;
}

const int Matrix3x3::minColumn(const int iCol)
{
    int min = values[0][iCol];

    for (int i = 1; i < size; i++)
        if (min > values[i][iCol])
            min = values[i][iCol];
    return min;
}

const int Matrix3x3::maxColumn(const int iCol)
{
    int max = values[0][iCol];

    for (int i = 1; i < size; i++)
        if (max < values[i][iCol])
            max = values[i][iCol];
    return max;
}
