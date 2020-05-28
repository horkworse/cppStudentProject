#pragma once
#include <time.h>

class Matrix3x3
{
public:
    Matrix3x3()
    {
        values = new int* [size];

        for (int i = 0; i < size; i++)
        {
            values[i] = new int[size];
            for (int j = 0; j < size; j++)
                values[i][j] = 0;
        }
    }
    ~Matrix3x3()
    {
        for (int i = 0; i < size; i++)
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
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                values[i][j] = rand() % (maxVal * 2) + minVal;
    }

    void print()
    {
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                std::cout << values[i][j] << '\t';
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    const int sumPrincipalDiag()
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
            sum += values[i][i];
        return sum;
    }

    const int sumSecondaryDiag()
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
            sum += values[i][2 - i];
        return sum;
    }

    const int productPrincipalDiag()
    {
        int result = 1;
        for (int i = 0; i < size; i++)
            result *= values[i][i];
        return result;
    }

    const int productSecondaryDiag()
    {
        int result = 1;
        for (int i = 0; i < size; i++)
            result *= values[i][2 - i];
        return result;
    }

    const int sumRow(const int iRow)
    {
        int sum = 0;
        for (int j; j < size; j++)
            sum = values[iRow][j];
        return sum;
    }

    const int minColumn(const int iCol)
    {
        int min = values[0][iCol];

        for (int i = 1; i < size; i++)
            if (min > values[i][iCol])
                min = values[i][iCol];
        return min;
    }

    const int maxColumn(const int iCol)
    {
        int max = values[0][iCol];

        for (int i = 1; i < size; i++)
            if (max < values[i][iCol])
                max = values[i][iCol];
        return max;
    }


private:
    int** values;
    int size = 3;
};

class MatrixXnX
{
public:
    MatrixXnX(const int iDim)
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
    ~MatrixXnX()
    {
        for (int i = 0; i < size; i++)
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
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                values[i][j] = rand() % (maxVal * 2) + minVal;
    }

    void print()
    {
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                std::cout << values[i][j] << "  ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    const int sumPrincipalDiag()
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
            sum += values[i][i];
        return sum;
    }

    const int sumSecondaryDiag()
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
            sum += values[i][size - 1 - i];
        return sum;
    }

    const int productPrincipalDiag()
    {
        int result = 1;
        for (int i = 0; i < size; i++)
            result *= values[i][i];
        return result;
    }

    const int productSecondaryDiag()
    {
        int result = 1;
        for (int i = 0; i < size; i++)
            result *= values[i][size - 1 - i];
        return result;
    }

    const int sumRow(const int iRow)
    {
        int sum = 0;
        for (int j; j < size; j++)
            sum = values[iRow][j];
        return sum;
    }

    const int minColumn(const int iCol)
    {
        int min = values[0][iCol];

        for (int i = 1; i < size; i++)
            if (min > values[i][iCol])
                min = values[i][iCol];
        return min;
    }

    const int maxColumn(const int iCol)
    {
        int max = values[0][iCol];

        for (int i = 1; i < size; i++)
            if (max < values[i][iCol])
                max = values[i][iCol];
        return max;
    }

private:
    int** values;
    int size;
};

class linkedList
{
public:
    linkedList();

    ~linkedList();

    void add(int value);

    bool contains(int value);

    int count();

    void removeDuplicates();

    int findFromBack(int index);

    bool remove(int value);

    void clear();

    void print();

private:

    class ListNode
    {
    public:
        ListNode()
        {
            this->value = 0;
            this->next = nullptr;
        };

        ListNode(int value, ListNode* next)
        {
            this->value = value;
            this->next = next;
        };

        int value;
        ListNode* next;
    };

    ListNode* _head;
    ListNode* _tail;
    int _count;
};