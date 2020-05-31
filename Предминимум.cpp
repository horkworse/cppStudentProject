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

void sortArr(int* arr, int* size)
{
    int max;
    int index = 0;
    
    for (int i = 0; i < *size; i++)
    {
        index = i;
        for (int j = index; j < *size; j++)
        {
            if (*(arr + index) > *(arr + j))
                index = j;
        }
        
        max = *(arr + i);
        *(arr + i) = *(arr + index);
        *(arr + index) = max;
    }
}

int main()
{
    int qty;
    cin >> qty;
    int* arr = new int[qty];

    fillArr(arr, &qty);
    printArr(arr, &qty);
    
    sortArr(arr, &qty);
    
    printArr(arr, &qty);
    cout << *(arr + 1);
    
    return 0;
}
