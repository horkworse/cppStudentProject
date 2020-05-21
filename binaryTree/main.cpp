// 280002 - Минеев Е.С. - 3 задание
#include <iostream>
#include <locale>
#include "Header.h"
using namespace std;

int main()
{
	BinaryTree<int>* tree = new BinaryTree<int>;
	
	const int n = 9;
	int array[n];
	for (int i = 0; i < n; i++)
	{
		array[i] = i;
	}
	tree->CreateMinimalBST(array, 0, n - 1);
}
