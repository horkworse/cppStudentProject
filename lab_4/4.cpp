#include <iostream>
#include <time.h>
#include "Header.h"

using namespace std;

int main()
{
    int n = 100;
    int* array = new int[n];

    srand((unsigned)time(nullptr));

    for (int i = 0; i < n; i++)
        array[i] = rand() % 21 - 10;

    clock_t start = clock();
    Search(array, n, 5);
    clock_t end = clock();

    float searchSeconds = (float)(end - start) ;
    QuickSort(array, 0, n - 1);  
    
    start = clock();
    BSearchReq(5, array, 0, n - 1);
    end = clock();

    float bSearchSeconds = (float)(end - start) ;

    cout << "search seconds are " << searchSeconds << endl;
    cout << "bsearch seconds are " << bSearchSeconds << endl;
}
