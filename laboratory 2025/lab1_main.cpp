/*
Реализовать класc в отдельном модуле.
Включить в класс методы:
•	конструктор по умолчанию;
•	конструктор с параметрами;
•	копирующий конструктор и деструктор, если используется динамическая память для представления данных;
•	методы заполнения полей класса;
•	методы, определенные в варианте.
Перегрузить операцию (во всех вариантах):
•	операцию >> для вывода экземпляров класса в поток ostream;
•	дополнительные операции, указанные в задании варианта.

Класс -	Динамический одномерный массив целых чисел	Сортировка массива
Методы - Определить вхождение значения в массив (бинарный поиск)
Дополнительные операции (для перегрузки) - [] индексация элемента массива + Слияние двух массивов
*/

#include "lab1_main.h"

int main(){
    setlocale(LC_ALL, "Russian");

    //сортировка и заполнение
    darray arr1(5);
    cout << "Заполнение первого массива:\n";
    arr1.fill();
    arr1.sorted();
    cout << "Первый массив после сортировки: " << arr1 << endl;

    //копирующий конструктор
    darray coparr(arr1);
    cout << endl << "Копирующий конструктор " << coparr<<endl;

    // Создание и заполнение второго массива
    darray arr2(3);
    cout << "Заполнение второго массива:\n";
    arr2.fill();
    arr2.sorted();
    cout << "Второй массив после сортировки: " << arr2 << endl;

    // Слияние массивов
    darray arr3 = arr1 + arr2;
    cout << "Объединенный массив: " << arr3 << endl;

    // Поиск значения в объединенном массиве
    int value;
    cout << "Введите значение для поиска: ";
    cin >> value;
    arr3.sorted();
    cout << "Третий массив после сортировки: " << arr3 << endl;
    if (arr3.binarySearch(value)) {
        cout << "Значение " << value << " найдено в массиве.\n";
    } else {
        cout << "Значение " << value << " не найдено в массиве.\n";
    }
    return 0;
}