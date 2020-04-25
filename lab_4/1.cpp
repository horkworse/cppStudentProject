#include <iostream>
#include <time.h>
#include "Header.h";

using namespace std;

int main()
{
    int n = 10000;
    int* array = new int[n];

    srand(time(nullptr));

    for (int i = 0; i < n; i++)
        array[i] = rand() % 2001 - 1000;

    cout << Search(array, &n, 20) << endl;
    cout << Search(array, &n, -123) << endl;
    cout << Search(array, &n, -492) << endl;
    cout << Search(array, &n, 0) << endl;
    cout << Search(array, &n, 32) << endl;
    cout << Search(array, &n, -5) << endl;
    cout << Search(array, &n, 81) << endl;
    cout << Search(array, &n, 1190) << endl;
    cout << Search(array, &n, -1470) << endl;
}
