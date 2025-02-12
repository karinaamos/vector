#include <iostream>
#include "Matrix.h"
#include "Vector.h"

int main(){
    Vector<int> vec1 = Vector<int>(3);
    vec1[0] = 3;
    Vector<int> vec2 = Vector<int>(3, 1);
    vec2[1] = 5;
    Vector<int> vec3 = Vector<int>(3, 0);
    vec3[0] = 1;
    vec3 = vec1 + vec2;
    std::cout<<vec1<<vec2<<vec3<<"\n";
    Matrix<int> matr1 = Matrix<int>(3);
    matr1[0][1] = 1;
    matr1[0][2] = 2;
    matr1[1][1] = 3;
    std::cout<<matr1<<"\n";
    Matrix<int> matr2 = Matrix<int>(3);
    matr2[0][1] = 4;
    matr2[0][2] = 5;
    matr2[1][1] = 6;
    std::cout<<matr2;
    Matrix<int> matr3 = matr1 * matr2;
    std::cout<<"\n"<<matr3;

    
   


    return 0;
}