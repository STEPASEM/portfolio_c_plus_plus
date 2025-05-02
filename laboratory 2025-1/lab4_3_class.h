#ifndef C_LAB43_H
#define C_LAB43_H

#include <iostream>
#include <clocale>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct PhoneRecord {
    string fullName;
    string number;
    string address;
};

class account {
private:
    vector<PhoneRecord> records;
    string filename;
public:

    // Конструктор
    account(string filename) : filename(filename) {}

    //заполнить из файла вектор
    void fillFromTextFile(string nam);

    //очищение вектора
    void clearvector(){
        records.clear();
    }

    // Шифрование и дешифрование (одна и та же функция)
    string xorEncryptDecrypt(const string &data, char key);

    //перенос в конец и удаление последнего
    void delete_back_id(int id);

    //гетер
    vector<PhoneRecord> getvector(){
        return records;
    }

    // Вывод записи
    void printRecord(PhoneRecord record);

    // Запись данных в бинарный файл
    void writeToFile();

    // Прочитать данны из бинарного файла
    void readFromFile();

    // Фильтруем номера начинающиеся с первых 3 цифр
    void filterPhoneNumbers(string fileName, string firstThreeDigits);

    // Удалить сведения о владельцах телефонов, которые начинаются с заданной цифры.
    void deletenumber(string fileName, string firstDigit);

    // Чтение данных из текстового файла
    void readFromTextFile(string fileName);
};

#endif //C_LAB43_H