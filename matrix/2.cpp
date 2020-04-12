
#include <iostream>
#include <ctime>
#include "Header.h"
#include <set>
#include <string>
#include <map>
using namespace std;


int main()
{
	SmartLinkedList<int> list;
	srand(time(NULL));
	
	list.push(2);
	list.push(1);
	list.push(6);
	list.push(5);
	list.push(2);
	list.push(6);
	list.push(4);

	map<string, int> table;

	int i = 0;

	while (i != list.getSize())
	{
		map <string, int> ::iterator it;

		it = table.find(to_string(list[i]));

		if (it != table.end())
			list.removeAt(i);
		else
		{
			table[to_string(list[i])] = 0;
			i++;
		}
	}

	for (int i = 0; i < list.getSize(); i++)
	{
		cout << list[i] << '\t';
	}

	return 0;
}

