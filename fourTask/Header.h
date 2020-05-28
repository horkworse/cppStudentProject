#pragma once
#ifndef ADD_H
#define ADD_H

void Print(const int* array, const int n)
{
    for (int i = 0; i < n; i++)
        std::cout << array[i] << "  ";
    std::cout << std::endl << std::endl;
}

/* 1 task */

int Search(const int* array, const int n, const int value)
{
    for (int i = 0; i < n; i++)
        if (array[i] == value)
            return i;

    return -1;
}

/* 2 task */

void QuickSort(int* array, int start, int end)
{
    int index = 0;
    int temp = 0;
    int* leftStorage = new int[end];
    int* rightStorage = new int[end];

    leftStorage[index] = start;
    rightStorage[index] = end;

    while (index >= 0)
    {
        int first = leftStorage[index];
        int last = rightStorage[index];
        index--;

        while (first < last)
        {
            int left = first;
            int right = last;
            int middle = (first + last) / 2;
            int center = array[middle];

            while (left < right)
            {
                while (array[left] < center)
                    left++;
                while (array[right] > center)
                    right--;

                if (left <= right)
                {
                    temp = array[right];
                    array[right] = array[left];
                    array[left] = temp;
                    left++;
                    right--;
                }
            }

            if (right > middle)
            {
                if (right > first)
                {
                    index++;
                    rightStorage[index] = right;
                    leftStorage[index] = first;
                }
                first = left;
            }
            else
            {
                if (last > left)
                {
                    index++;
                    rightStorage[index] = last;
                    leftStorage[index] = left;
                }
                last = right;
            }
        }
    }
}

void QuickSortReq(int* array, int start, int end)
{
    int left = start;
    int right = end;
    int temp = 0;
    int middle = array[(start + end) / 2];

    while (left < right)
    {
        while (array[left] < middle)
            left++;
        while (array[right] > middle)
            right--;
        if (left <= right)
        {
            temp = array[right];
            array[right] = array[left];
            array[left] = temp;
            left++;
            right--;
        }
    }

    if (right > start)
        QuickSortReq(array, start, right);
    if (end > left)
        QuickSortReq(array, left, end);
}

/*3 task*/

int BSearch(int value, int* array, int first, int last)
{
    int middle = 0;
    while (first <= last)
    {
        middle = (first + last) / 2;

        if (value == array[middle])
            return middle;
        if (value <= array[middle])
            last = middle - 1;
        if (value >= array[middle])
            first = middle + 1;
    }
    return -1;
}

int BSearchReq(int value, int* array, int first, int last)
{
    int middle = (first + last) / 2;

    if (value == array[middle])
        return middle;

    if (first > last)
        return -1;

    if (value <= array[middle])
        BSearchReq(value, array, first, middle - 1);
    else if (value >= array[middle])
        BSearchReq(value, array, middle + 1, last);
    return -1;
}
#endif