#include <iostream>

using namespace std;

void printArr(int* arr, int* qty)
{
    for (int i = 0; i < *qty; i++)
        cout << *(arr + i) << '\t';
    cout << '\n';
}

void fillArr(int* arr, int* qty)
{
    unsigned int rndParam = 11;
    srand(rndParam);
    
    for (int i = 0; i < *qty; i++)
        arr[i] = 1 + rand() %100;
}

int* searchMin(int* arr, int* size)
{
    int min = *arr;
    int index = 0;
    
    for (int i = 1; i < *size; i++)
        if(min > *(arr + i))
        {
            min = *(arr + i);
            index = i;
        }
    return arr + index;
}


int main()
{
    int qty;
    cin >> qty;
    int* arr = new int[qty];

    fillArr(arr, &qty);
    printArr(arr, &qty);
    
    cout << *searchMin(arr, &qty);
    
    return 0;
}
ta