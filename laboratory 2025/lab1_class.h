#ifndef PORTFOLIO_C_PLUS_PLUS_LAB1_CLASS_H
#define PORTFOLIO_C_PLUS_PLUS_LAB1_CLASS_H

#include <iostream>
#include <clocale>
#include <algorithm>

using namespace std;

class darray{
private:
    int len_array;
    int *arr;
public:
    //конструктор по умолчанию
    darray() = default;
    //конструктор с параметрами
    darray(int len_arr);
    //копирующий конструктор
    darray(const darray& other);
    //деструктор
    ~darray(){delete[] arr;}
    //метод заполнения
    void fill();
    //метод сортировки массива
    void sorted();
    //метод бинарного поиска
    bool binarySearch(int value) const;
    //опретор [] для вывода по индексу
    int& operator[](int index);
    // оператор + для слияния массивов
    darray operator+(const darray& other);
    //оператор <<
    friend ostream& operator<<(ostream& os, const darray& arr);
};

#endif //PORTFOLIO_C_PLUS_PLUS_LAB1_CLASS_H
