#include <iostream>
#include <ctime>
#include "Header.h"

using namespace std;


int main()
{
	SmartLinkedList<int> list;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		list.push(rand() % (20 * 2) - 10);
	}

	int indexOfEnd = 3;

	cout << list[list.getSize() - indexOfEnd + 1];

	return 0;
}

