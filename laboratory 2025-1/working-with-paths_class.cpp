#include "working-with-paths_class.h"

Pathes::Pathes(string val) : value(val){}

string Pathes::getPathType(){
    if (value.back() == '/') {
        return "DIRECTORY";
    }
    return "FILE";
}

vector<string> Pathes::Split_Path(string &str){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    vector<string> components_str;
    int start = 0;
    for (int i = 0; i <= str.size(); i++) {
        if (i == str.size() || str[i] == '/') {
            if (start != i) {
                components_str.push_back(str.substr(start, i - start));
            }
            start = i + 1;
        }
    }
    return components_str;
}

string Pathes::return_name(string typ){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    if (typ == "FILE"){
        return Split_Path(value).back();
    }
    return "Ошибка так как не является файлом";
}

string Pathes::operator[](int index){
    vector<string> arr_name_dir = Split_Path(value);
    if (index >= arr_name_dir.size()) {
        cout << ("Индекс выходит за пределы массива");
    }
    return arr_name_dir[index];
}

ostream& operator<<(ostream& os, const Pathes& strok){
    os << "Путь ";
    os << strok.geter();
    return os;
}

string Pathes::operator+(const Pathes& other){
    string result = value + other.value.substr(1, other.value.size());
    return result;
}

Pathes Pathes::operator+=(const Pathes& other){
    this->value += other.value.substr(1, other.value.size());
    return *this;
}

bool Pathes::operator==(const Pathes& other){
    return value == other.value;
};

bool Pathes::operator==(string strok){
    return value == strok;
};

Pathes Pathes::operator=(const Pathes& other){
    this->value = other.value;
    return *this;
};

Pathes::operator string() {
    return value;
};
