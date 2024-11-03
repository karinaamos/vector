#include "vector.h"

template <class T>
class Matrix: public Vector<Vector<T>>{
public: 
    Matrix(size_t n):Vector<Vector<T>>(n, 0){
        for(size_t i=0; i<n;i++){
            this -> At(i) = Vector<T>(n-i, i);//n-i-размер,  i-startIndex
        }
    }
    Matrix(const Matrix& mt):Vector<Vector<T>>(mt){//конструктор копирования 
        for (size_t i = 0; i < this->Getsize(); ++i) {
            this->At(i) = mt.At(i);
        }
    }
    Matrix(const Vector<Vector<T>>& mt):  Vector<Vector<T>>(mt) {}
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
        Matrix result(this->Getsize());
        for (size_t i = 0; i < this->Getsize(); ++i) {
            for (size_t j = 0; j < this->Getsize(); ++j) {
                result[i][j] = 0;
                for (size_t k = 0; k < this->Getsize(); ++k) {
                    result[i][j] += this->At(i)[k] * mt.At(k)[j];
                }
            }
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