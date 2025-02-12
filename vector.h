#pragma once
#include <iostream>
//матрица - вектор строк

template <class T>
class Vector{
protected:
    T* _array;//динамич массив
    size_t _size;
    size_t _startIndex;//первый индекс с которого начинается матрица
public:
     Vector(size_t size = 10){
        _size = size;
        _startIndex = 0;
        _array = new T[_size];
    }
    Vector(size_t size, size_t startIndex) {
        _size = size;
        _startIndex = startIndex;
        _array = new T[_size]; 
        for (int i = 0; i < size; i++){
            _array[i] = 0;
        }
    }
    //рассмотреть выделение памяти, проконтролить чтобы старт идекс был не больше размера, размер не 0
    Vector(const Vector& tmp) : _size(tmp._size), _startIndex(tmp._startIndex) {
        _array = new T[_size];
        for (size_t i = 0; i < _size; ++i) {
            _array[i] = tmp._array[i];
        }
    }
    //контруктор перемещения РАЗОБРАТЬСЯ САМИ 
    Vector(Vector&& moved) {
        _array = moved._array;
        _size = moved._size;
        _startIndex = moved._startIndex;
        moved._array = nullptr;
        moved._size = 0;
        moved._startIndex = 0;
    }
    ~Vector() {
        delete[] _array;
        _array = nullptr;
    } 
    size_t GetSize() const{
        return _size;
    }
    size_t GetStartIndex() const{
        return _startIndex;
    }
    T& At(size_t pos){
        if(pos>=_size)
        throw"error";
        return _array[pos];
    }
    
    T& operator[](size_t position)const{
        return _array[position];
    }
    Vector& operator=(const Vector& tmp){ //оператор присваивания
        if(_size!=tmp._size){
        delete [] _array;
        _array=new T [tmp._size];
        }
        _size=tmp._size;
        _startIndex=tmp._startIndex;
        for(size_t i=0;i<_size;i++){
            _array[i]=tmp._array[i];
        }
        return *this;
    } 

    // со скаляром
    Vector operator+(const T& tmp){
        Vector result(*this);
        for (size_t i = 0; i < _size; ++i) {
            result._array[i] += tmp;
        }
        return result;
    }
    Vector operator-(const T& tmp){
        Vector result(*this);
        for (size_t i = 0; i < _size; ++i) {
            result._array[i] -= tmp;
        }
        return result;
    }
    Vector operator*(const T& tmp){
        Vector result(*this);
        for (size_t i = 0; i < _size; i++) {
            result._array[i] *= tmp;
        }
        return result;
    }

    //вектор и вектор
     Vector operator+(const Vector& tmp){
        if (_size != tmp._size) 
            throw "Error";
        Vector<T> result = Vector<T>(_size, _startIndex);
        for (size_t i = 0; i < _size; ++i) {
            result._array[i] = _array[i] + tmp._array[i];
        }
        return result;

    }
    Vector operator-(const Vector& tmp){
        if (_size != tmp._size) 
            throw "Error";
        Vector<T> result = Vector<T>(_size, _startIndex);
        for (size_t i = 0; i < _size; ++i) {
            result._array[i] = _array[i] - tmp._array[i];
        }
        return result;
    }

    T operator* (const Vector* tmp){ //скалярное пр
        if (_size != tmp._size) 
            throw "Error";
        T res = 0;
        for (size_t i = _startIndex; i < _size; ++i) {
            res += _array[i] * tmp._array[i];
        }
        return res;
    }

    friend std::ostream& operator<<(std::ostream& ostr, Vector& v){
        for (int i = 0; i < v._startIndex; i++){
            std::cout<<"0 ";
        }
        for (int i = 0; i < v._size - v._startIndex; i++){
            std::cout<<v._array[i]<<" ";
        }
        std::cout<<"\n";
        return ostr;
    }
};