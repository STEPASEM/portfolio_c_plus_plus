#include "lab2_2_class.h"

/*

 ����������� ������� � ����� lab2_1_main.cpp

 ����������������� ��������� ��� ��������� ������ � ����� (Path) � ����� � �������� �������. �������� � ��������� ����� ������ �������������. �����������:
a.	������� ���������� ������ ���� ��� ������� (�������� <<);
b.	������������� �������� ������������ � ������ �����;
c.	������������� �������� ������� �� ������� (�������� []), ������� ���������� ����� ���� ����� ������ �������;
d.	������������� �������� �������� (+, +=), ������� ��������� ������� ���� ����� � ���������� ����� (��������, ������� �C:/abc/� � �/homework/skyrim.exe� ���� �C:/abc/homework/skyrim.exe�).
e.	������������� �������� ��������� � ������ ����� � string.
����������. ����������� �������� ���������� � string.

 */

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    string strok_1, strok_2, typ;
    int i_ch = 3;

    //������� ��� ���� � �������� �������� ����� � ���������� <<
    //cout << "������� ����: ";
    //cin >> strok_1; //"C:/abc/homework/skyrim.exe"
    Pathes path1("C:/abc/homework/skyrim/");
    typ = path1.getPathType();
    cout << path1 << " ��������: " << typ << endl;//1
    cout << "�������� �����: " << path1.return_name(typ) << endl;//2

    //���������� []
    //cout << "������� ���� � i-�� �����: ";
    //cin >> strok_1 >> i_ch;
    Pathes path2("C:/abc/homework/skyrim.exe");
    cout << i_ch <<" ������� " << path2[i_ch-1] << endl;

    //���������� +, +=, ==
    Pathes path3("C:/abc/shdshdsgdskd/");
    Pathes path4("/homework/skyrim.exe");
    cout<< path3 << " 1 �����" << endl;
    cout<< path4 << " 2 �����" << endl;
    Pathes result = path3 + path4;//+
    cout<< result << " +" << endl;
    path3 += path4;               //+=
    cout << path3 << " +=" << endl;
    bool t_f = (path3==result);   //==
    cout << t_f << " ==" << endl;
    result = path4;               //=
    cout << result << " =" << endl;

    //���������� string
    t_f = (path3=="C:/abc/homework/skyrim.exe");
    cout << t_f << " == string" << endl;

    cout << strok_2 << " = strok_2" << endl;//������
    strok_2 = path3;
    cout << strok_2 << " strok_2 = path3";

    return 0;
}