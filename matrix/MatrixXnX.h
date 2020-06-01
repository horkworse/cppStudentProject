#pragma once
class MatrixXnX
{
public:
    MatrixXnX(const int iDim);
    ~MatrixXnX();

    const int element(const int i, const int j);
    void setElement(const int i, const int j, const int value);
    void fillRandomElements(const int minVal, const int maxVal);
    void print();
    const int sumPrincipalDiag();
    const int sumSecondaryDiag();
    const int productPrincipalDiag();
    const int productSecondaryDiag();
    const int sumRow(const int iRow);
    const int minColumn(const int iCol);
    const int maxColumn(const int iCol);

private:
    int** values;
    int size;
};


