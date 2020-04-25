#include <iostream>
#include <time.h>
#include "Header.h";

using namespace std;

int main()
{
    int n = 100;
    int* array = new int[n];

    srand(time(nullptr));
    
    for (int i = 0; i < n; i++)
        array[i] = rand() % 21 - 10;

    Print(array, n / 2);
    QuickSortReq(array, 0, n - 1);
    Print(array, n / 2);
}
