#include "lab4_1_class.h"

void Storage::remove(int index) {
    if (index >= 0 && index < animals.size()) {
        delete animals[index];  // Уничтожается объект
        animals.erase(animals.begin() + index);  // Удаляется ссылка из вектора
    }
}

void Storage::saveToFile(const std::string &filename) const {
    ofstream file(filename);

    for (const Animal* animal : animals) {
        file << typeid(*animal).name() << " ";
        file << animal->getName() << "\n";
    }
    file.close();
}

void Storage::loadFromFile(const std::string &filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    while (!file.eof()) {
        string typeName;
        string name;

        file >> typeName >> name;

        if (typeName == typeid(Bird).name()) {
            animals.push_back(new Bird(name));
        } else if (typeName == typeid(Fish).name()) {
            animals.push_back(new Fish(name));
        }
    }

    file.close();
}