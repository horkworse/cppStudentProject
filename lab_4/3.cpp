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

    QuickSortReq(array, 0, n - 1);

    Print(array, n);
    cout << endl;
    cout << endl;

    cout << "-11  is " << BSearchReq(-11, array, 0, n - 1) << endl;
    cout << "0    is " << BSearchReq(0, array, 0, n - 1) << endl;
    cout << "5    is " << BSearchReq(5, array, 0, n - 1) << endl;
    cout << "10   is " << BSearchReq(10, array, 0, n - 1) << endl;
    cout << "11   is " << BSearchReq(11, array, 0, n - 1) << endl;

    cout << endl;
    cout << endl;

    cout << "-11  is " << BSearch(-11, array, 0, n - 1) << endl;
    cout << "0    is " << BSearch(0, array, 0, n - 1) << endl;
    cout << "5    is " << BSearch(5, array, 0, n - 1) << endl;
    cout << "10   is " << BSearch(10, array, 0, n - 1) << endl;
    cout << "11   is " << BSearch(11, array, 0, n - 1) << endl;
}
