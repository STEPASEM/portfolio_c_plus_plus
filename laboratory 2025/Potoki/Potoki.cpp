/*
 * � ��������� ������������ �������� ��� ������, �����������
��������� �������:
����� 1 ������ ������� ���������� ��������� ����� � ���������� ��� �
������ ���� 1 (text_1.txt).
����� 2 ����������� ������ � ������ ����� ���� 1 (text_1.txt) � �����
���������� ������ ������� ����� ���������� �� ����� �� ������ ����
���� 2 (text_2.txt).
����� 3 ����������� ������ �� ������ ����� ���� 2 (text_2.txt) � �����
���������� ������ ���� ����� ���������� �� �������� � ������ ���� ����
3 (text_3.txt).
����� 4 ����������� ������ � ������� ����� ���� 3 (text_3.txt) � �����
���������� ������ ���� ����� ���������� �� �������� � ������ ���� ����
1 (text_1.txt).
��� ����, ���� ����� 1 ������� � ���� 1 �����, � ������ �������� �����
�� ������ 4, �� ����� 2 ������������ ����������.
 */

#include <iostream>
#include <clocale>
#include <fstream>
#include <thread>
#include <chrono>
#include <random>
#include <deque>

using namespace std;

// ������� ��� ��������� ���������� �����
int generate_random_number() {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dis(1, 100);
    return dis(gen);
}

// ����� 1: ��������� ��������� ����� � ���� 1
void thread1_func() {
    while (true) {
        int num = generate_random_number();

        ofstream file1("text_1.txt", ios::app);
        file1 << num << endl;
        cout << "����� 1 ������� �����: " << num << " � ���� 1" << endl;
        file1.close();

        this_thread::sleep_for(chrono::seconds(1));
    }
}

// ����� 2: ������������ ������ 4 ����� �� ����� 1 � ���� 2
void thread2_func() {
    deque<int> numbers;
    int line_count = 0;

    while (true) {
        ifstream in_file1("text_1.txt");
        string line;

        // ������ ����� ������ �� ����� 1
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
                    cout << "����� 2 ������� �����: " << sum << " � ���� 2" << endl;
                    file2.close();
                }
            }
        }
        in_file1.close();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

// ����� 3: �������� ������ 2 ����� �� ����� 2 � ���� 3
void thread3_func() {
    deque<int> numbers;
    int line_count = 0;

    while (true) {
        ifstream in_file2("text_2.txt");
        string line;

        // ������ ����� ������ �� ����� 2
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
                    cout << "����� 3 ������� ��������: " << diff << " � ���� 3" << endl;
                    file3.close();
                }
            }
        }
        in_file2.close();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

// ����� 4: �������� ������ 2 ����� �� ����� 3 � ���� 1
void thread4_func() {
    deque<int> numbers;
    int line_count = 0;

    while (true) {
        ifstream in_file3("text_3.txt");
        string line;

        // ������ ����� ������ �� ����� 3
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
                    cout << "����� 4 ������� ��������: " << diff << " � ���� 1" << endl;
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
    
    // ������� ����� ����� ������� ������
    ofstream("text_1.txt", ios::trunc).close();
    ofstream("text_2.txt", ios::trunc).close();
    ofstream("text_3.txt", ios::trunc).close();

    // ������� � ��������� ������
    thread t1(thread1_func);
    thread t2(thread2_func);
    thread t3(thread3_func);
    thread t4(thread4_func);

    // ���� ���������� �������
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}