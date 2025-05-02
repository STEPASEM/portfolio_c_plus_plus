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

    // �����������
    Text_menu(string filePath) : filePath(filePath) {}

    // �������� ���������� ����� � ��������� ����������
    void createFile(vector<int> values);

    // ����� ����� �� ���������� �����
    void printFile();

    // ���������� � ����� �����
    void addToFile(int value);

    // ���������� � ������ ����� ����� � ��� ��� ���� ��������
    void addToStartFile(string value);
};

#endif //C_LAB42_H
