// 280002 Минеев Е.С. 4 задание

#include <iostream>
#include <time.h>
#include <chrono>
#include "Header.h";

using namespace std;

int main()
{
    int n = 10000;
    int* bigArray = new int[n];

    srand(time(nullptr));

    for (int i = 0; i < n; i++)
        bigArray[i] = rand() % 2001 - 1000;

    // Search
    cout << "Search function:" << endl;
    cout << "Element with 20 value is on " << Search(bigArray, n, 20) << endl << endl << endl;

    // Quick sort
    
    int m = 100;
    int* smallArray = new int[m];
    int* otherSmallArray = new int[m];

    srand(time(nullptr));

     for (int i = 0; i < m; i++)
     {
         smallArray[i] = rand() % 21 - 10;
         otherSmallArray[i] = smallArray[i];
     }

     cout << "Quick sort with recursion:" << endl;
     cout << "Inital array:" << endl;
     Print(smallArray, m / 2);
     QuickSortReq(smallArray, 0, m - 1);
     cout << "Sorted array:" << endl;
     Print(smallArray, m / 2);

     cout << endl << endl;

     cout << "Quick sort:" << endl;
     cout << "Inital array:" << endl;
     Print(otherSmallArray, m / 2);
     QuickSort(otherSmallArray, 0, m - 1);
     cout << "Sorted array:" << endl;
     Print(otherSmallArray, m / 2);

     cout << endl;

     // Binary search

     cout << "Binary search with recursion:" << endl;
     cout << "0 is " << BSearchReq(0, smallArray, 0, m - 1) << endl << endl;;

     cout << "Binary search:" << endl;
     cout << "10 is " << BSearch(10, smallArray, 0, m - 1) << endl;

     cout << endl << endl;

     // benchmarking
    long k = 10000;
    int* testArray = new int[k];

    srand(time(nullptr));

    for (int i = 0; i < k; i++)
        testArray[i] = rand() % 100001 - 100000;

    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    Search(testArray, k, testArray[648]);
    chrono::steady_clock::time_point end = chrono::steady_clock::now();

    cout << "Search: " <<chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

    QuickSort(testArray, 0, k);

    start = chrono::steady_clock::now();
    BSearch(testArray[648], testArray, 0, k);
    end = chrono::steady_clock::now();

    cout << "Bsearch: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}
