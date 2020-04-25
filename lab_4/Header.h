#pragma once
#ifndef ADD_H
#define ADD_H

void Print(const int* array, const int n)
{
    for (int i = 0; i < n; i++)
        std::cout << array[i] << '\t';
    std::cout << std::endl;
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

void QuickSortReq(int* array, int first, int last)
{
    int left = first;
    int right = last;
    int temp = 0;
    int middle = array[left];

    while (left < right)
    {
        while ((array[right] >= middle) && (left < right))
            right--;
        if (left != right)
        {
            array[left] = array[right];
            left++;
        }
        while ((array[left] <= middle) && (left < right))
            left++;
        if (left != right)
        {
            array[right] = array[left];
            right--;
        }
        array[left] = middle;

        if (first < left)
            QuickSortReq(array, first, left - 1);
        if (last > left)
            QuickSortReq(array, left + 1, last);

    }
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
}
#endif