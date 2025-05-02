/*
I.	Подготовить тестовые данные в текстовом файле с кодировкой ASCII.
II.	Разработайте структуру записи двоичного файла согласно варианту задания.
III.	Разработать функции для выполнения операций:
•	преобразование тестовых данных в двоичный файл
•	отображение всех записей двоичного файла
•	манипулирование записями в двоичном файле: согласно операций определенных в варианте
•	Удаление записи производить путем замены на последнюю запись
IV.	Разработать приложение и выполнить тестирование всех операций.
V.	Усложнение. Добавить шифрование файла любым методом и его дешифровку

СТРУКТУРА ЗАПИСИ:
Владелец телефона: номер телефона – последовательность символов, адрес, ФИО
ДОП ОПЦИИ:
1.	Сформировать текстовый файл из фамилий владельцев, чьи номера начинаются с введенных первых трех цифр(например, 434)
2.	Удалить сведения о владельцах телефонов, которые начинаются с заданной цифры.
 */

#include "lab4_3_class.h"

int main() {
    setlocale(LC_ALL, "Russian");

    //исходные данные
    string first_data = "phone_records_first.txt";

    // Имя файла для бинарных данных
    string filename = "phone_records.txt";

    // Создание экземпляра класса account
    account acc(filename);

    // Заполнить из файла
    acc.fillFromTextFile(first_data);

    // Вывод исходных данных
    cout << "Исходные данные:" << endl;
    for (PhoneRecord record : acc.getvector()) {
        acc.printRecord(record);
    }

    // Запись данных в бинарный файл
    acc.writeToFile();

    //Удаление данных из records
    acc.clearvector();

    // Чтение данных из бинарного файла
    acc.readFromFile();

    // Вывод данных из файла
    cout << endl << "Данные из файла:" << endl;
    for (PhoneRecord record : acc.getvector()) {
        acc.printRecord(record);
    }

    //Удаление данных из records с помощью перемещения элемента
    acc.delete_back_id(2);

    // Вывод данных после удаления
    cout << endl << "Данные после удаления '2' элемента:" << endl;
    for (PhoneRecord record : acc.getvector()) {
        acc.printRecord(record);
    }

    // Отфильтровать номера, начинающиеся с '434'
    acc.filterPhoneNumbers("filtered_phone_numbers.txt", "434");
    cout << endl << "Отфильтрованы владельцы с номерами, начинающимися с '434': " << endl;
    acc.readFromTextFile("filtered_phone_numbers.txt");

    // Удалить записи с номером, начинающимся с цифры '4'
    acc.deletenumber("filtered_phone_numbers.txt", "4");
    cout << endl << "Оставшиеся записи после удаления номеров, начинающихся с '4': " << endl;
    acc.readFromTextFile("filtered_phone_numbers.txt");

    return 0;
}