#ifndef C_LAB2_2_CLASS_H
#define C_LAB2_2_CLASS_H

#include <iostream>
#include <vector>
#include <clocale>
#include <Windows.h>
#include <string>

using namespace std;

class Pathes{
private:
    string value;
public:
    //конструктор
    Pathes(string val);
    //возвращает строку
    string geter()const {return value;}
    //Возвращает тип пути файл/директория
    string getPathType();
    //разделяет путь на вектор с названиями
    vector<string> Split_Path(string &str);
    //возвращает имя файла
    string return_name(string typ);
    //перегрузка []
    string operator[](int index);
    //преегрузка <<
    friend ostream& operator<<(ostream& os, const Pathes& arr);
    //перегрузка +, +=
    string operator+(const Pathes& other);
    Pathes operator+=(const Pathes& other);
    //перегрузка ==
    bool operator==(const Pathes& other);
    //перегрузка =
    Pathes operator=(const Pathes& other);
    //перегрузка == co string
    bool operator==(string strok);
    //перегрузка приведения к string
    operator string();
};
#endif
