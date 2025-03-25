#include "lab1_main.h"

//конструктор с параметрами
darray::darray(int len_arr) : len_array(len_arr){
    arr = new int [len_array];
}
//копирующий конструктор
darray::darray(const darray& other):len_array(other.len_array){
    arr = new int [len_array];
    copy(other.arr, other.arr + len_array, arr);
}
//метод заполнения
void darray::fill() {
    for (int i = 0; i < len_array; i++) {
        cout << "Введите элемент " << i << ": ";
        cin >> arr[i];
    }
}
//метод сортировки массива
void darray::sorted() {
    sort(arr, arr + len_array);
}
//метод бинарного поиска
bool darray::binarySearch(int value) const {
    int left = 0, right = len_array, midle;
    while (left <= right)                       // Гоняем в цикле;
    {
        midle = left + (right - left) / 2;
        if (value < arr[midle]) right = midle - 1;
        else if (value > arr[midle]) left = midle + 1;
        else return true;
    }
    return false;
}
//опретор [] для вывода по индексу
int& darray::operator[](int index) {
    if (index >= len_array) {
        cout << ("Индекс выходит за пределы массива");
    }
    return arr[index];
}
// оператор + для слияния массивов
darray darray::operator+(const darray& other){
    darray result(len_array + other.len_array);
    copy(arr, arr + len_array, result.arr);
    copy(other.arr, other.arr + other.len_array, result.arr + len_array);
    return result;
}
//оператор <<
ostream& operator<<(ostream& os, const darray& arr){
    for (int i = 0; i < arr.len_array; i++) {
        os << arr.arr[i] << " ";
    }
    return os;
}
