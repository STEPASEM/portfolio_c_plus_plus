#include "lab4_2_class.h"

void Text_menu::createFile(vector<int> values) {
    ofstream outFile(filePath);

    if (!outFile.is_open()) {
        cerr << "Ошибка открытия файла для записи." << endl;
        return;
    }

    for (int value : values) {
        outFile << value << "\n";
    }

    outFile.close();
}

void Text_menu::printFile() {
    ifstream inFile(filePath);

    if (!inFile.is_open()) {
        cerr << "Ошибка открытия файла для чтения." << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

void Text_menu::addToFile(int value) {
    ofstream outFile(filePath, ios::app);

    if (!outFile.is_open()) {
        cerr << "Ошибка открытия файла для записи." << endl;
        return;
    }

    outFile << value << "\n";

    outFile.close();
}

void Text_menu::addToStartFile(string value) {
    ifstream inFile(filePath);

    vector<string> lines;
    string line;
    while (getline(inFile, line)) {
        lines.push_back(line);
    }

    inFile.close();
    ofstream outFile(filePath);

    outFile << value << "\n";

    for (string line : lines) {
        outFile << line << "\n";
    }
    outFile.close();
}