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
    // Конструктор по умолчанию
    Animal() = default;

    // Параметрический конструктор
    Animal(string n): name(n) {};

    // Копирующий конструктор
    Animal(Animal& other): name(other.name) {};

    // Деструктор
    ~Animal() {
        cout << "Удаление животного: " << name << endl;
    }

    string getName() const { return name; }

    // Виртуальная функция для перемещения
    virtual void move() = 0;
};

class Bird : public Animal {
public:
    // Конструктор по умолчанию
    Bird() = default;

    // Параметрический конструктор
    Bird(string n): Animal(n) {};

    // Копирующий конструктор
    Bird(Bird& other): Animal(other) {};

    // Переопределенная функция move()
    void move() override {
        cout << name << " летит в небе." << endl;
    }
};

class Fish : public Animal {
public:
    // Конструктор по умолчанию
    Fish() = default;

    // Параметрический конструктор
    Fish(string n): Animal(n) {};

    // Копирующий конструктор
    Fish(Fish& other): Animal(other) {};

    // Переопределенная функция move()
    void move() override {
        cout << name << " плывет в воде." << endl;
    }
};

class Storage{
private:
    vector<Animal*> animals;
public:
    // Конструктор по умолчанию
    Storage() = default;

    vector<Animal*> getanimal() const { return animals; }

    // Добавление нового объекта в хранилище
    void add(Animal* animal) {
        animals.push_back(animal);
    }

    // Удаление объекта из хранилища
    void remove(int index);

    // Сохранение хранилища в файл
    void saveToFile(const string& filename) const;

    // Загрузка хранилища из файла
    void loadFromFile(const string& filename);

    // Деструктор
    ~Storage() {
        for (auto animal : animals) {
            delete animal;
        }
        animals.clear();  // Очистка вектора
    }
};

#endif //C_LAB41_H