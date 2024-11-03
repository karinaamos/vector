#include <iostream>
#include "matrix.h"

int main() {
    Vector<int> vec1=Vector<int>(3);
    std::cout << "Введите элементы вектора: " << std::endl;
    std::cout<<vec1<<std::endl;
    std::cin>>vec1;
    std::cout << "Вектор: " << std::endl;
    std::cout<<vec1<<std::endl;

    Matrix<int> mat1 = Matrix<int>(3); 
    std::cout << "Введите элементы матрицы: " << std::endl;
    std::cin >> mat1;
    std::cout << "Матрица: " << std::endl;
    std::cout << std::endl << mat1 << std::endl;

    return 0;
}