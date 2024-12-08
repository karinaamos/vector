#include "vector.h"

template <class T>
class Matrix: public Vector<Vector<T>>{
public: 
    Matrix(size_t n, bool flag = false) : Vector<Vector<T>>(n){
        if (flag){
            for (size_t i = 0; i < n; i++){
                this->_array[i] = Vector<T>(n, i);
            }
        }
        else{
            for (size_t i = 0; i < n; i++){
                this->_array[i] = Vector<T>(n);
            }
        }
    }
    Matrix(const Matrix& mt):Vector<Vector<T>>(mt){//конструктор копирования 
    }
    Matrix(const Vector<Vector<T>>& mt):  Vector<Vector<T>>(mt) {
    }
    Matrix& operator=(const Matrix& mt){//оператор присваивания
     if (this == &mt) {
            return *this;
        }
        delete[] this->_array; // освобождение памяти старого массива
        this->_size = mt._size; // копирование размеров и индекса начала
        this->_startIndex = mt._startIndex;
        this->_array = new Vector<T>[this->_size]; // выделение памяти для нового массива
        for (size_t i = 0; i < this->_size; ++i) {
            this->_array[i] = mt._array[i]; // копирование элементов из mt
        }
        return *this;
    }
    Matrix operator+(const Matrix& mt){
        return Vector<Vector<T>>::operator+(mt);
    }
    Matrix operator-(const Matrix& mt){
        return Vector<Vector<T>>::operator-(mt);
    }
    Matrix operator*(const Matrix& mt){
        Matrix result=Matrix(this->_size);
        size_t sum=this->_size;
        for (size_t i=0;i<this->_size;i++){//для строк
            for (size_t j=0;j<sum;j++){//для столбцов
                for (size_t z=0;z<j+1;z++){
                    result[i][j]+=this->_array[i][z]*mt[i+z][j-z];
                }
            }
            sum--;
        }
        return result;
    }

   friend std::ostream& operator<<(std::ostream& os, const Matrix& matr){
        os<<"(";
        for(int i=0; i<matr._size;i++){
            for(int j=0; j<matr._size; j++){
                if(matr._startIndex>i)
                os<<0<<", ";
                else{
                os<<matr._array[i][j];
                if(i+1!=matr._size)
                    os<<", ";
                }
            }
        }
        os<<")";
        return os;
    }

     friend std::istream& operator>>(std::istream& istr, Matrix& mat){
        T current;
        mat._startIndex=0;
        for (size_t i=0;i< mat._size;i++){
            for (size_t j=0; j< mat._size; j++){
                std::cout<<"elem n"<<i<<": ";
                std::cout<<"elem m"<<j<<": ";
                istr>>current;
                if (current==0)
                mat._startIndex++;
                else
                mat._array[i][j]=current;
            }
        }
        return istr;
    }
};