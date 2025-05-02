/*
 * В программе одновременно запущены три потока, действующих
следующим образом:
Поток 1 каждую секунду генерирует случайное число и записывает его в
первый Файл 1 (text_1.txt).
Поток 2 отслеживает записи в первом файле Файл 1 (text_1.txt) и после
добавления каждых четырех чисел записывает их сумму во второй файл
Файл 2 (text_2.txt).
Поток 3 отслеживает записи во втором файле Файл 2 (text_2.txt) и после
добавления каждых двух чисел записывает их разность в третий файл Файл
3 (text_3.txt).
Поток 4 отслеживает записи в третьем файле Файл 3 (text_3.txt) и после
добавления каждых двух чисел записывает их разность в первый файл Файл
1 (text_1.txt).
При этом, если Поток 1 добавил в Файл 1 число, а следом приходит число
из Потока 4, то Поток 2 отрабатывает аналогично.
 */

#include <iostream>
#include <clocale>
#include <fstream>
#include <thread>
#include <chrono>
#include <random>
#include <deque>

using namespace std;

// Функция для генерации случайного числа
int generate_random_number() {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dis(1, 100);
    return dis(gen);
}

// Поток 1: Генерация случайных чисел в файл 1
void thread1_func() {
    while (true) {
        int num = generate_random_number();

        ofstream file1("text_1.txt", ios::app);
        file1 << num << endl;
        cout << "Поток 1 записал число: " << num << " в файл 1" << endl;
        file1.close();

        this_thread::sleep_for(chrono::seconds(1));
    }
}

// Поток 2: Суммирование каждых 4 чисел из файла 1 в файл 2
void thread2_func() {
    deque<int> numbers;
    int line_count = 0;

    while (true) {
        ifstream in_file1("text_1.txt");
        string line;

        // Читаем новые данные из файла 1
        while (getline(in_file1, line)) {
            if (!line.empty()) {
                int num = stoi(line);
                numbers.push_back(num);
                line_count++;

                if (line_count % 4 == 0) {
                    int sum = 0;
                    for (int i = 0; i < 4; ++i) {
                        sum += numbers.front();
                        numbers.pop_front();
                    }

                    ofstream file2("text_2.txt", ios::app);
                    file2 << sum << endl;
                    cout << "Поток 2 записал сумму: " << sum << " в файл 2" << endl;
                    file2.close();
                }
            }
        }
        in_file1.close();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

// Поток 3: Разность каждых 2 чисел из файла 2 в файл 3
void thread3_func() {
    deque<int> numbers;
    int line_count = 0;

    while (true) {
        ifstream in_file2("text_2.txt");
        string line;

        // Читаем новые данные из файла 2
        while (getline(in_file2, line)) {
            if (!line.empty()) {
                int num = stoi(line);
                numbers.push_back(num);
                line_count++;

                if (line_count % 2 == 0) {
                    int num1 = numbers.front(); numbers.pop_front();
                    int num2 = numbers.front(); numbers.pop_front();
                    int diff = num1 - num2;

                    ofstream file3("text_3.txt", ios::app);
                    file3 << diff << endl;
                    cout << "Поток 3 записал разность: " << diff << " в файл 3" << endl;
                    file3.close();
                }
            }
        }
        in_file2.close();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

// Поток 4: Разность каждых 2 чисел из файла 3 в файл 1
void thread4_func() {
    deque<int> numbers;
    int line_count = 0;

    while (true) {
        ifstream in_file3("text_3.txt");
        string line;

        // Читаем новые данные из файла 3
        while (getline(in_file3, line)) {
            if (!line.empty()) {
                int num = stoi(line);
                numbers.push_back(num);
                line_count++;

                if (line_count % 2 == 0) {
                    int num1 = numbers.front(); numbers.pop_front();
                    int num2 = numbers.front(); numbers.pop_front();
                    int diff = num1 - num2;

                    ofstream file1("text_1.txt", ios::app);
                    file1 << diff << endl;
                    cout << "Поток 4 записал разность: " << diff << " в файл 1" << endl;
                    file1.close();
                }
            }
        }
        in_file3.close();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    // Очищаем файлы перед началом работы
    ofstream("text_1.txt", ios::trunc).close();
    ofstream("text_2.txt", ios::trunc).close();
    ofstream("text_3.txt", ios::trunc).close();

    // Создаем и запускаем потоки
    thread t1(thread1_func);
    thread t2(thread2_func);
    thread t3(thread3_func);
    thread t4(thread4_func);

    // Ждем завершения потоков
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}