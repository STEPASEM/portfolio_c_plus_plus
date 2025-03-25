/*
Разработать программу для упрощения работы с путем (Path) к файлу в файловой системе.
Привязку к реальному диску делать не нужно. Реализовать:
a.	функцию потокового вывода пути для консоли (операция <<);
b.	перегруженную операцию присваивания с другим путем;
c.	перегруженную операцию доступа по индексу (операция []), которая возвращает часть пути между косыми чертами;
d.	перегруженные операции сложения (+, +=), которые выполняют слияние двух путей и возвращает новое
    (например, слияние “C:/abc/” и “/homework/skyrim.exe” даст “C:/abc/homework/skyrim.exe”).
e.	перегруженные операции сравнения с другим путем и string.
f.  перегрузить операцию приведения к string.
*/

#include "working-with-paths_class.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    string strok_1, strok_2, typ;
    int i_ch = 3;

    //Выводит тип пути и отдельно название файла и перегрузка <<
    //cout << "Введите путь: ";
    //cin >> strok_1; //"C:/abc/homework/skyrim.exe"
    Pathes path1("C:/abc/homework/skyrim/");
    typ = path1.getPathType();
    cout << path1 << " является: " << typ << endl;//1
    cout << "Название файла: " << path1.return_name(typ) << endl;//2

    //перегрузка []
    //cout << "Введите путь и i-ую часть: ";
    //cin >> strok_1 >> i_ch;
    Pathes path2("C:/abc/homework/skyrim.exe");
    cout << i_ch <<" элемент " << path2[i_ch-1] << endl;

    //перегрузка +, +=, ==
    Pathes path3("C:/abc/shdshdsgdskd/");
    Pathes path4("/homework/skyrim.exe");
    cout<< path3 << " 1 часть" << endl;
    cout<< path4 << " 2 часть" << endl;
    Pathes result = path3 + path4;//+
    cout<< result << " +" << endl;
    path3 += path4;               //+=
    cout << path3 << " +=" << endl;
    bool t_f = (path3==result);   //==
    cout << t_f << " ==" << endl;
    result = path4;               //=
    cout << result << " =" << endl;

    //перегрузка string
    t_f = (path3=="C:/abc/homework/skyrim.exe");
    cout << t_f << " == string" << endl;

    cout << strok_2 << " = strok_2" << endl;//пустой
    strok_2 = path3;
    cout << strok_2 << " strok_2 = path3";

    return 0;
}