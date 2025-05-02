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
    string date_of_issue;//дата выдачи
    string date_of_return;//дата возврат
public:
    //конструктор с пустыми параметрами
    Library_Cards() = default;

    //конструктор с параметрами
    Library_Cards(IDType id_, string name_lib_, string name_author_, string date_of_issue_, string date_of_return_);

    //По id вернуть название и дату возврата книги.
    void return_book(IDType id_);

    //Определить один ли автор у двух книг
    bool operator==(Library_Cards& obj);

    //Виртуальный привет
    virtual void hello() {
        cout << "Привет от базового класса!" << endl;
    }

    //деструктор сообщающий об удалении объекта
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

    //конструктор с пустыми параметрами
    Book(IDType id_, string name_lib_, string name_author_, string date_of_issue_, string date_of_return_, string genre_, string parametr_);

    //Определить художественый ли жанр у двух книг
    bool operator==(Book& obj);

    //По id вернуть жанр и параметр.
    void return_book_gen(IDType id_);

    virtual void hello() override{
        cout << "Привет от наследника!" << endl;
    }

    //деструктор
    ~Book() {
        cout << "Object was deleted naslednik" << endl;
    };

};
#endif //C_LAB3_H
