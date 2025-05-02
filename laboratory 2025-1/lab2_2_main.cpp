#include "lab2_2_class.h"

/*

 »«Ќј„јЋ№Ќќ≈ «јƒјЌ»≈ ¬ ‘ј…Ћ≈ lab2_1_main.cpp

 ”совершенствовать программу дл€ упрощени€ работы с путем (Path) к файлу в файловой системе. ѕрив€зку к реальному диску делать необ€зательно. –еализовать:
a.	функцию потокового вывода пути дл€ консоли (операци€ <<);
b.	перегруженную операцию присваивани€ с другим путем;
c.	перегруженную операцию доступа по индексу (операци€ []), котора€ возвращает часть пути между косыми чертами;
d.	перегруженные операции сложени€ (+, +=), которые выполн€ют сли€ние двух путей и возвращает новое (например, сли€ние УC:/abc/Ф и У/homework/skyrim.exeФ даст УC:/abc/homework/skyrim.exeФ).
e.	перегруженные операции сравнени€ с другим путем и string.
”сложнение. ѕерегрузить операцию приведени€ к string.

 */

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    string strok_1, strok_2, typ;
    int i_ch = 3;

    //¬ыводит тип пути и отдельно название файла и перегрузка <<
    //cout << "¬ведите путь: ";
    //cin >> strok_1; //"C:/abc/homework/skyrim.exe"
    Pathes path1("C:/abc/homework/skyrim/");
    typ = path1.getPathType();
    cout << path1 << " €вл€етс€: " << typ << endl;//1
    cout << "Ќазвание файла: " << path1.return_name(typ) << endl;//2

    //перегрузка []
    //cout << "¬ведите путь и i-ую часть: ";
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