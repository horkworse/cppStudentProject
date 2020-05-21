// 280002 Минеев Е.С. 1 задание

#include <iostream>

using namespace std;

int main()
{
	// Работа с матрицей 3х3
	Matrix3x3 matrix;
    matrix.fillRandomElements(-10, 10);
    matrix.print();

    cout << matrix.minColumn(0) << endl;
    cout << matrix.maxColumn(0) << endl;

    cout << matrix.sumPrincipalDiag() << endl;
    cout << matrix.sumSecondaryDiag() << endl;

    cout << matrix.productPrincipalDiag() << endl;
    cout << matrix.productSecondaryDiag() << endl;

    // Работа с матрицей nхn
    MatrixXnX matrix(4);
    matrix.fillRandomElements(-10, 10);
    matrix.print();

    cout << matrix.minColumn(0) << endl;
    cout << matrix.maxColumn(0) << endl;

    cout << matrix.sumPrincipalDiag() << endl;
    cout << matrix.sumSecondaryDiag() << endl;

    cout << matrix.productPrincipalDiag() << endl;
    cout << matrix.productSecondaryDiag() << endl;


	// Работа со связным списком
	linkedList<int> list;
	list.add(6);
	list.add(1);
	list.add(5);
	list.add(1);
	list.add(2);
	list.add(5);
	list.add(8);
	
	list.print();

	// Выводим 3 элемент с конца
	cout << list.findFromBack(3) << endl;

	// Удаляем дубликаты
	list.removeDuplicates();

	list.print();
}