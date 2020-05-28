// matrixList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Header.h"

using namespace std;

linkedList::linkedList()
{
    this->_head = nullptr;
    this->_tail = nullptr;
    this->_count = 0;
};

linkedList::~linkedList()
{
    clear();
}

void linkedList::add(int value)
{
    ListNode* temp = new ListNode;
    temp->value = value;
    temp->next = nullptr;

    if (_head == nullptr)
    {
        _head = temp;
        _head->next = nullptr;
    }
    else
        _tail->next = temp;
    _tail = temp;
    this->_count++;
}

bool linkedList::contains(int value)
{
    ListNode* current = _head;
    ListNode* previous = new ListNode;

    while (current->next != nullptr)
    {
        previous = current;
        current = current->next;

        if (current->value == value)
            return true;
    }
    return false;
}

int linkedList::count()
{
    return this->_count;
}

void linkedList::removeDuplicates()
{
    if (_head == nullptr)
        return;

    ListNode* current = _head;

    while (current != nullptr)
    {
        ListNode* runner = current;
        while (runner->next != nullptr)
        {
            if (runner->next->value == current->value)
            {
                ListNode* temp = runner->next->next;
                delete runner->next;
                runner->next = nullptr;
                _count--;
                if (temp != nullptr)
                    runner->next = temp;
            }
            else
                runner = runner->next;
        }
        current = current->next;
    }
}

int linkedList::findFromBack(int index)
{
    if (index > _count)
        return -1;

    int counter = 0;
    int itemIndex = this->_count - index;

    ListNode* temp = _head;
    while (counter != itemIndex)
    {
        temp = temp->next;
        counter++;
    }
    return temp->value;
}

bool linkedList::remove(int value)
{
    ListNode* current = _head;
    ListNode* previous = new ListNode;

    while (current->next != nullptr)
    {
        previous = current;
        current = current->next;

        if (current->value == value)
        {
            previous->next = current->next;
            delete current;
            _count--;
            return true;
        }
    }
    return false;
}

void linkedList::clear()
{
    if (_head == nullptr)
        return;

    ListNode* tmp;
    while (_head != nullptr)
    {
        tmp = _head->next;
        delete _head;
        _head = tmp;
        _count = 0;
    }
}

void linkedList::print()
{
    if (_head == nullptr)
    {
        cout << "none";
        return;
    }

    ListNode* temp = _head;

    while (temp != nullptr)
    {
        cout << temp->value << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Работа с матрицей 3х3
	Matrix3x3 matrix3x3;
	// заполняем случайными элементами
    matrix3x3.fillRandomElements(-10, 10);
    // выводим
    matrix3x3.print();

	// вычисляем минимальный элемент в столбце 0
    cout << "minimal in 0 column is " << matrix3x3.minColumn(0) << endl;
    // вычисляем максимальный элемент в столбце 0
    cout << "maximal in 0 column is "  << matrix3x3.maxColumn(0) << endl;

	// вычисляем сумму элементов главной диагонали
    cout << "sum principal diag is " << matrix3x3.sumPrincipalDiag() << endl;
    // вычисляем сумму элементов побочной диагонали
    cout << "sum secondary diag is " << matrix3x3.sumSecondaryDiag() << endl;

    // вычисляем произведение элементов главной диагонали
    cout << "product principal diag is " << matrix3x3.productPrincipalDiag() << endl;
    // вычисляем произведение элементов побочной диагонали
    cout << "product secondary diag is " << matrix3x3.productSecondaryDiag() << endl;

    // Работа с матрицей nхn
    MatrixXnX matrix4x4(4);
    // заполняем случайными элементами
    matrix4x4.fillRandomElements(-10, 10);
    // выводим
    matrix4x4.print();

    // вычисляем минимальный элемент в столбце 0
    cout << "minimal in 0 column is " << matrix4x4.minColumn(0) << endl;
    // вычисляем максимальный элемент в столбце 0
    cout << "maximal in 0 column is " << matrix4x4.maxColumn(0) << endl;

    // вычисляем сумму элементов главной диагонали
    cout << "sum principal diag is " << matrix4x4.sumPrincipalDiag() << endl;
    // вычисляем сумму элементов побочной диагонали
    cout << "sum secondary diag is " << matrix4x4.sumSecondaryDiag() << endl;

    // вычисляем произведение элементов главной диагонали
    cout << "product principal diag is " << matrix4x4.productPrincipalDiag() << endl;
    // вычисляем произведение элементов побочной диагонали
    cout << "product secondary diag is " << matrix4x4.productSecondaryDiag() << endl << endl;


	// Работа со связным списком
	linkedList list;
	// добавляем элементы в список
	list.add(6);
	list.add(1);
	list.add(5);
	list.add(1);
	list.add(2);
	list.add(5);
	list.add(8);
	// выводим
	list.print();

	// Выводим 3 элемент с конца
	cout << list.findFromBack(3) << endl;

	// Удаляем дубликаты
	list.removeDuplicates();
	// выводим
	list.print();   
}