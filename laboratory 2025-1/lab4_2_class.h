#ifndef C_LAB42_H
#define C_LAB42_H

#include <iostream>
#include <clocale>
#include <Windows.h>
#include <fstream>
#include <vector>

using namespace std;

class Text_menu{
private:
    string filePath;
public:

    // Конструктор
    Text_menu(string filePath) : filePath(filePath) {}

    // Создание текстового файла с числовыми значениями
    void createFile(vector<int> values);

    // Вывод строк из текстового файла
    void printFile();

    // Добавление в конец файла
    void addToFile(int value);

    // Добавление в начало файла когда в нем уже есть значения
    void addToStartFile(string value);
};

#endif //C_LAB42_H
