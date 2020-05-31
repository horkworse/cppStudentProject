// 280002 Минеев Е.С. 10 задание

#include <iostream>
#include "MatrixBase.h"
#include "Matrix2D.h"
#include "Matrix3D.h"

using namespace std;


int main()
{
    Matrix2D m2a, m2b;
    Matrix3D m3a, m3b;

    // заполняем матрицы 2х2 элементами
    int value = 1;
    for (int i = 0; i < m2a.size(); i++)
    {
        for (int j = 0; j < m2a.size(); j++)
        {
            m2a.element(i, j) = value;
            m2b.element(i, j) = value;
            value++;
        }
    }

    // заполняем матрицы 3х3 элементами
    value = 1;
    for (int i = 0; i < m3a.size(); i++)
    {
        for (int j = 0; j < m3a.size(); j++)
        {
            m3a.element(i, j) = value;
            m3b.element(i, j) = value;
            value++;
        }
    }

    cout << "inital matrix2x2" << endl << m2a << endl;
    int multipleValue = 3;
    m2a *= multipleValue;
    cout << "changed matrix2x2 with *= " << endl << m2a << endl;

    cout << "inital matrix2x2" << endl << m2b << endl;
    m2b += m2a;
    cout << "changed matrix2x2 with += " << endl << m2b << endl << endl;


    cout << "inital matrix3x3 " << endl << m3a << endl;
    multipleValue = 4;
    m3a *= multipleValue;
    cout << "changed matrix3x3 with *= " << endl << m3a << endl;

    cout << "inital matrix3x3" << endl << m3b << endl;
    m3b += m3a;
    cout << "changed matrix3x3 with += " << endl << m3b << endl;
}