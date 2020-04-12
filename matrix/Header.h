#pragma once

template<typename T>
class SmartLinkedList
{
public:
	SmartLinkedList();
	~SmartLinkedList();

	void unshift();

	void shift(T data);

	void clear();

	int getSize() { return Size; }

	T& operator[](const int index);

	void removeAt(int index);

	void push(T data);

	void pop();

private:

	template<typename T>
	class ListItem
	{
	public:
		ListItem* pNext;
		T data;

		ListItem(T data = T(), ListItem* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	ListItem<T>* head;
};

template<typename T>
SmartLinkedList<T>::SmartLinkedList()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
SmartLinkedList<T>::~SmartLinkedList()
{
	clear();
}


template<typename T>
void SmartLinkedList<T>::unshift()
{
	ListItem<T>* tmp = head;
	head = head->pNext;
	delete tmp;
	Size--;
}

template<typename T>
void SmartLinkedList<T>::push(T data)
{
	if (head == nullptr)
		head = new ListItem<T>(data);
	else
	{
		ListItem<T>* current = this->head;
		while (current->pNext != nullptr)
			current = current->pNext;
		current->pNext = new ListItem<T>(data);
	}

	Size++;
}

template<typename T>
void SmartLinkedList<T>::clear()
{
	while (Size)
		pop();
}


template<typename T>
T& SmartLinkedList<T>::operator[](const int index)
{
	ListItem<T>* current = this->head;
	int counter = 0;
	while (current != nullptr)
	{
		if (counter == index)
			return current->data;
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void SmartLinkedList<T>::shift(T data)
{
	head = new ListItem<T>(data, head);
	Size++;
}

template<typename T>
void SmartLinkedList<T>::removeAt(int index)
{
	if (index == 0)
		unshift();
	else
	{
		ListItem<T>* prev = this->head;
		for (int i = 0; i < index - 1; i++)
			prev = prev->pNext;
		ListItem<T>* del = prev->pNext;
		prev->pNext = del->pNext;
		delete del;

		Size--;
	}

}

template<typename T>
void SmartLinkedList<T>::pop()
{
	removeAt(Size - 1);
}