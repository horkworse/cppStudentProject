// StaticMemory.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include "matrix.h"

using namespace std;

class Matrix3x3
{
    public:
        Matrix3x3()
        {
            values = new int* [3];

            for (int i = 0; i < 3; i++)
            {
                values[i] = new int[3];
                for (int j = 0; j < 3; j++)
                    values[i][j] = 0;
            }
        }
        ~Matrix3x3()
        {
            for (int i = 0; i < 3; i++)
                delete[] values[i];
            delete[] values;
        }

        const int element(const int i, const int j)
        {
            return values[i][j];
        }

        void setElement(const int i, const int j, const int value)
        {
            values[i][j] = value;
        }

        void fillRandomElements(const int minVal, const int maxVal)
        {
            srand(time(NULL));
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    values[i][j] = rand() % (maxVal * 2 ) + minVal;
        }

        void print()
        {
            srand(time(NULL));
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                    std::cout << values[i][j] << '\t';
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

        const int sumPrincipalDiag()
        {
            int sum = 0;
            for (int i = 0; i < 3; i++)
                sum += values[i][i];
            return sum;
        }

        const int sumSecondaryDiag()
        {
            int sum = 0;
            for (int i = 0; i < 3; i++)
                sum += values[i][2 - i];
            return sum;
        }

        const int productPrincipalDiag()
        {
            int result = 1;
            for (int i = 0; i < 3; i++)
                result *= values[i][i];
            return result;
        }

        const int productSecondaryDiag()
        {
            int result = 1;
            for (int i = 0; i < 3; i++)
                result *= values[i][2 - i];
            return result;
        }

        const int sumRow(const int iRow)
        {
            int sum = 0;
            for (int j; j < 3; j++)
                sum = values[iRow][j];
            return sum;
        }

        const int minColumn(const int iCol)
        {
                int min = values[0][iCol];

                for (int i = 1; i < 3; i++)
                    if (min > values[i][iCol])
                        min = values[i][iCol];
                return min;
        }

        const int maxColumn(const int iCol)
        {
            int max = values[0][iCol];

            for (int i = 1; i < 3; i++)
                if (max < values[i][iCol])
                    max = values[i][iCol];
            return max;
        }
           

    private:
        int **values;
};


int main()
{
    Matrix3x3 matrix;
    matrix.fillRandomElements(-10, 10);
    matrix.print();

    cout << matrix.minColumn(0) << endl;
    cout << matrix.maxColumn(0) << endl;

    cout << matrix.sumPrincipalDiag() << endl;
    cout << matrix.sumSecondaryDiag() << endl;

    cout << matrix.productPrincipalDiag() << endl;
    cout << matrix.productSecondaryDiag() << endl;
    return 0;
}