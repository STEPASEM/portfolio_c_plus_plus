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
    //�����������
    Pathes(string val);
    //���������� ������
    string geter()const {return value;}
    //���������� ��� ���� ����/����������
    string getPathType();
    //��������� ���� �� ������ � ����������
    vector<string> Split_Path(string &str);
    //���������� ��� �����
    string return_name(string typ);
    //���������� []
    string operator[](int index);
    //���������� <<
    friend ostream& operator<<(ostream& os, const Pathes& arr);
    //���������� +, +=
    string operator+(const Pathes& other);
    Pathes operator+=(const Pathes& other);
    //���������� ==
    bool operator==(const Pathes& other);
    //���������� =
    Pathes operator=(const Pathes& other);
    //���������� == co string
    bool operator==(string strok);
    //���������� ���������� � string
    operator string();
};
#endif
