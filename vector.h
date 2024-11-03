#include <iostream>
//матрица - вектор строк

template <class T>
class Vector{
protected:
    T* _array;//динамич массив
    size_t _size;
    size_t _startIndex;//первый индекс с которого начинается матрица
public:
    Vector(size_t size, size_t startIndex = 0){
        _size = size;
        _array = new T[_size];
        _startIndex = startIndex;
    }
    Vector() : Vector(0, 0) {}
    //рассмотреть выделение памяти, проконтролить чтобы старт идекс был не больше размера, размер не 0
    Vector(const Vector& tmp) : _size(tmp._size), _startIndex(tmp._startIndex) {
        _array = new T[_size];
        for (size_t i = 0; i < _size; ++i) {
            _array[i] = tmp._array[i];
        }
    }
    //контруктор перемещения РАЗОБРАТЬСЯ САМИ 
    Vector(Vector&& moved) : _size(moved._size), _startIndex(moved._startIndex) {
        _array = moved._array;
        moved._array = nullptr;
        moved._size = 0;
    }
    ~Vector() {
        delete[] _array;
    } 
    size_t Getize() const{
        return _size;
    }
    size_t GetsizeIndex() const{
        return _startIndex;
    }
    T& At(size_t pos){
        if (pos < _startIndex || pos >= _startIndex + _size) {
            throw std::out_of_range("Индекс вне допустимого диапазона");
        }
        return _array[pos - _startIndex];
    }
    T& operator[](size_t pos){
        return _array[pos - _startIndex];
    }
    Vector& operator=(const Vector& tmp){//оператор присваивания ЗНАТЬ РАССКАЗЫВАТЬ БУДЕМ
    if (this == &tmp) {
            return *this;
    }
    delete[] _array;
    _size = tmp._size;
    _startIndex = tmp._startIndex;
    _array = new T[_size];
    for (size_t i = 0; i < _size; ++i) {
            _array[i] = tmp._array[i];
        }
        return *this;
    } 
    Vector operator+(const T& tmp){
        Vector result(_size, _startIndex);
        for (size_t i = 0; i < _size; ++i) {
            result._array[i] = _array[i] + tmp;
        }
        return result;
    }
    Vector operator-(const T& tmp){
        Vector result(_size, _startIndex);
        for (size_t i = 0; i < _size; ++i) {
            result._array[i] = _array[i] - tmp;
        }
        return result;
    }
    T operator*(const Vector tmp){
        if (_size != tmp._size || _startIndex != tmp._startIndex) {
            throw std::invalid_argument("Несовместимые размеры векторов.");
        }
        T sum = 0;
        for (size_t i = 0; i < _size; ++i) {
            sum += _array[i] * tmp._array[i];
        }
        return sum;
    }
    friend std::ostream& operator<<(std::ostream& os, const Vector& vect){
        os<<"(";
        for(int i=0; i<vect._size;i++){
            if(vect._startIndex>i)
            os<<0<<", ";
            else{
            os<<vect._array[i];
            if(i+1!=vect._size)
                os<<", ";
            }
        }
        os<<")";
        return os;
    }

     friend std::istream& operator>>(std::istream& istr, Vector& vec){
        T current;
        vec._startIndex=0;
        for (size_t i=0;i< vec._size;i++){
            std::cout<<"elem n"<<i<<": ";
            istr>>current;
            if (current==0)
            vec._startIndex++;
            else
            vec._array[i]=current;

        }
        return istr;
    }
};