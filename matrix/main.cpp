#include <iostream>
#include "LinkedList.h"
#include "MatrixXnX.h"
#include "Matrix3x3.h"

using namespace std;

// методы вывода, решил вынести сюда, чтобы не подключать iostream каждый раз
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

void MatrixXnX::print()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            std::cout << values[i][j] << "  ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Matrix3x3::print()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            std::cout << values[i][j] << '\t';
        std::cout << std::endl;
    }
    std::cout << std::endl;
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
    cout << "////////////Linked list////////////" << endl << endl;

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
    cout << "inital list: " << endl;
	list.print();

	// Выводим 3 элемент с конца
	cout << endl << "3 element from the back is " << list.findFromBack(3) << endl << endl;

	// Удаляем дубликаты
	list.removeDuplicates();
	// выводим
    cout << "list without dublicates: " << endl;
	list.print();   
}