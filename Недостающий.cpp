#include <iostream>

using namespace std;

int main()
{
    const int qty = 7;
    int arr[qty] = { 0, 1, 2, 4, 5, 8, 9 };

    int size = arr[qty - 1] + 1;

    int* newArr = new int[size];

    int k = 0;

    for (int i = 0; i <= qty - 1; i++)
    {
        int different = arr[i + 1] - arr[i];
        if (different == 1 || i == qty-1 )
        {
            newArr[k] = arr[i];
            k++;
        }
        else
        {
            int temp = arr[i];
            while (different != 0)
            {
                newArr[k] = temp;
                temp++;
                different--;
                k++;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << newArr[i] << endl;
    }


    return 0;
}