#ifndef C_LAB3_H
#define C_LAB3_H

#include <iostream>
#include <string>
#include <clocale>
#include <Windows.h>

using namespace std;

template<typename IDType>
class Library_Cards{
protected:
    IDType id;
    string name_lib;
    string name_author;
    string date_of_issue;//���� ������
    string date_of_return;//���� �������
public:
    //����������� � ������� �����������
    Library_Cards() = default;

    //����������� � �����������
    Library_Cards(IDType id_, string name_lib_, string name_author_, string date_of_issue_, string date_of_return_);

    //�� id ������� �������� � ���� �������� �����.
    void return_book(IDType id_);

    //���������� ���� �� ����� � ���� ����
    bool operator==(Library_Cards& obj);

    //����������� ������
    virtual void hello() {
        cout << "������ �� �������� ������!" << endl;
    }

    //���������� ���������� �� �������� �������
    ~Library_Cards() {
        cout << "Object was deleted" << endl;
    }
};

template<typename IDType>
class Book : public Library_Cards<IDType> {
private:
    string genre;
    string parametr;
public:
    Book() = default;

    //����������� � ������� �����������
    Book(IDType id_, string name_lib_, string name_author_, string date_of_issue_, string date_of_return_, string genre_, string parametr_);

    //���������� ������������� �� ���� � ���� ����
    bool operator==(Book& obj);

    //�� id ������� ���� � ��������.
    void return_book_gen(IDType id_);

    virtual void hello() override{
        cout << "������ �� ����������!" << endl;
    }

    //����������
    ~Book() {
        cout << "Object was deleted naslednik" << endl;
    };

};
#endif //C_LAB3_H
