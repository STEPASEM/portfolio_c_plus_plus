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

    // �����������
    account(string filename) : filename(filename) {}

    //��������� �� ����� ������
    void fillFromTextFile(string nam);

    //�������� �������
    void clearvector(){
        records.clear();
    }

    // ���������� � ������������ (���� � �� �� �������)
    string xorEncryptDecrypt(const string &data, char key);

    //������� � ����� � �������� ����������
    void delete_back_id(int id);

    //�����
    vector<PhoneRecord> getvector(){
        return records;
    }

    // ����� ������
    void printRecord(PhoneRecord record);

    // ������ ������ � �������� ����
    void writeToFile();

    // ��������� ����� �� ��������� �����
    void readFromFile();

    // ��������� ������ ������������ � ������ 3 ����
    void filterPhoneNumbers(string fileName, string firstThreeDigits);

    // ������� �������� � ���������� ���������, ������� ���������� � �������� �����.
    void deletenumber(string fileName, string firstDigit);

    // ������ ������ �� ���������� �����
    void readFromTextFile(string fileName);
};

#endif //C_LAB43_H