// 280002 Минеев Е.С. 1 задание

#include <iostream>

using namespace std;

int main()
{
	// Работа с матрицей 3х3
	Matrix3x3 matrix;
	// заполняем случайными элементами
    matrix.fillRandomElements(-10, 10);
    // выводим
    matrix.print();

	// вычисляем минимальный элемент в столбце 0
    cout << matrix.minColumn(0) << endl;
    // вычисляем максимальный элемент в столбце 0
    cout << matrix.maxColumn(0) << endl;

	// вычисляем сумму элементов главной диагонали
    cout << matrix.sumPrincipalDiag() << endl;
    // вычисляем сумму элементов побочной диагонали
    cout << matrix.sumSecondaryDiag() << endl;

    // вычисляем произведение элементов главной диагонали
    cout << matrix.productPrincipalDiag() << endl;
    // вычисляем произведение элементов побочной диагонали
    cout << matrix.productSecondaryDiag() << endl;

    // Работа с матрицей nхn
    MatrixXnX matrix(4);
    // заполняем случайными элементами
    matrix.fillRandomElements(-10, 10);
    // выводим
    matrix.print();

    // вычисляем минимальный элемент в столбце 0
    cout << matrix.minColumn(0) << endl;
    // вычисляем максимальный элемент в столбце 0
    cout << matrix.maxColumn(0) << endl;

    // вычисляем сумму элементов главной диагонали
    cout << matrix.sumPrincipalDiag() << endl;
    // вычисляем сумму элементов побочной диагонали
    cout << matrix.sumSecondaryDiag() << endl;

    // вычисляем произведение элементов главной диагонали
    cout << matrix.productPrincipalDiag() << endl;
    // вычисляем произведение элементов побочной диагонали
    cout << matrix.productSecondaryDiag() << endl;


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