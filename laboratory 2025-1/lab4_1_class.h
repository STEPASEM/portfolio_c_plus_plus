#ifndef C_LAB41_H
#define C_LAB41_H

#include <iostream>
#include <vector>
#include <fstream>
#include <clocale>
#include <Windows.h>

using namespace std;

class Animal {
protected:
    string name;
public:
    // ����������� �� ���������
    Animal() = default;

    // ��������������� �����������
    Animal(string n): name(n) {};

    // ���������� �����������
    Animal(Animal& other): name(other.name) {};

    // ����������
    ~Animal() {
        cout << "�������� ���������: " << name << endl;
    }

    string getName() const { return name; }

    // ����������� ������� ��� �����������
    virtual void move() = 0;
};

class Bird : public Animal {
public:
    // ����������� �� ���������
    Bird() = default;

    // ��������������� �����������
    Bird(string n): Animal(n) {};

    // ���������� �����������
    Bird(Bird& other): Animal(other) {};

    // ���������������� ������� move()
    void move() override {
        cout << name << " ����� � ����." << endl;
    }
};

class Fish : public Animal {
public:
    // ����������� �� ���������
    Fish() = default;

    // ��������������� �����������
    Fish(string n): Animal(n) {};

    // ���������� �����������
    Fish(Fish& other): Animal(other) {};

    // ���������������� ������� move()
    void move() override {
        cout << name << " ������ � ����." << endl;
    }
};

class Storage{
private:
    vector<Animal*> animals;
public:
    // ����������� �� ���������
    Storage() = default;

    vector<Animal*> getanimal() const { return animals; }

    // ���������� ������ ������� � ���������
    void add(Animal* animal) {
        animals.push_back(animal);
    }

    // �������� ������� �� ���������
    void remove(int index);

    // ���������� ��������� � ����
    void saveToFile(const string& filename) const;

    // �������� ��������� �� �����
    void loadFromFile(const string& filename);

    // ����������
    ~Storage() {
        for (auto animal : animals) {
            delete animal;
        }
        animals.clear();  // ������� �������
    }
};

#endif //C_LAB41_H