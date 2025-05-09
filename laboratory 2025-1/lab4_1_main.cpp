/*
I.	����������� ������ �������� �������� � �������� � ���:
�	�����������, ������� �������������� ���� ������ ������� ����������;
�	�����������, � �����������, ������� �������������� ���� ������ �����������  ����������;
�	���������� �����������;
�	����������, ���������� �� �������� �������;
�	������� ����� ���������� � ������������ ���������� � �������� ������� ������;
�	����������� ���������� ��������� � ����.
II.	����������� ���������� � ��������� ������������ ���� �������.

�������� ������� ����� Animal � ����������� �������� move().
�������� ����������� ������ Bird � Fish, ���������������� ��� ������� ��� �������� �� ������� � ���� ��������������.
 */

#include "lab4_1_class.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    // �������� ���������
    Storage storage;

    // ��������� ������� � ���������
    storage.add(new Bird("���"));
    storage.add(new Fish("�����"));
    storage.add(new Fish("������"));

    // ������������ ������ move()
    for (auto animal : storage.getanimal()) {
        animal->move();
    }

    // ��������� ������ � ����
    storage.saveToFile("lab41.txt");

    // ������� ���������
    storage.remove(0);
    storage.remove(0);
    storage.remove(0);

    // �������� ��������� ���������
    for (auto animal : storage.getanimal()) {
        animal->move();
    }

    // ��������� ������ �� ����� �������
    storage.loadFromFile("lab41.txt");

    // �������� ����������� ������
    for (auto animal : storage.getanimal()) {
        animal->move();
    }

    return 0;
}
