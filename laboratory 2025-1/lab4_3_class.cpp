#include "lab4_3_class.h"

void account::fillFromTextFile(string nam) {
    ifstream file(nam);
    string line;
    while (getline(file, line)) {
        PhoneRecord record;
        record.fullName = line;
        getline(file, line);
        record.number = line;
        getline(file, line);
        record.address = line;
        records.push_back(record);
    }
    file.close();
}

string account::xorEncryptDecrypt(const std::string &data, char key)  {
    string result = data;
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] = data[i] ^ key;  // Применяем XOR к каждому символу
    }
    return result;
}

void account::delete_back_id(int id){
    PhoneRecord record = records[id];
    records.erase(records.begin() + id);
    records.push_back(record);
    records.pop_back();
}

void account::printRecord(PhoneRecord record) {
    cout << "ФИО: " << record.fullName << endl;
    cout << "Номер телефона: " << record.number << endl;
    cout << "Адрес: " << record.address << endl;
}

void account::writeToFile() {
    ofstream file(filename, ios::binary);
    for (PhoneRecord record : records) {
        file.write(xorEncryptDecrypt(record.fullName, 'K').c_str(), record.fullName.size() + 1);
        file.write(xorEncryptDecrypt(record.number, 'K').c_str(), record.number.size() + 1);
        file.write(xorEncryptDecrypt(record.address, 'K').c_str(), record.address.size() + 1);
    }
    file.close();
}

void account::readFromFile() {
    ifstream file(filename, ios::binary);
    char buffer[1024];
    while (!file.eof()) {
        PhoneRecord record;
        file.getline(buffer, sizeof(buffer), '\0'); // Терминатор строки - '\0'
        record.fullName = xorEncryptDecrypt(buffer, 'K');

        file.getline(buffer, sizeof(buffer), '\0');
        record.number = xorEncryptDecrypt(buffer, 'K');

        file.getline(buffer, sizeof(buffer), '\0');
        record.address = xorEncryptDecrypt(buffer, 'K');

        records.push_back(record);
    }
    records.pop_back();
    file.close();
}

void account::filterPhoneNumbers(std::string fileName, std::string firstThreeDigits) {
    ofstream file(fileName);
    for(PhoneRecord record : records) {
        if(record.number.substr(2, 3) == firstThreeDigits) {
            file << record.fullName << "\n";
        }
    }
    file.close();
}

void account::deletenumber(std::string fileName, std::string firstDigit) {
    ifstream infile(fileName);

    vector<string> names;
    string line;
    while (getline(infile, line)) {
        names.push_back(line);
    }

    infile.close();
    ofstream file(fileName);

    for(PhoneRecord record : records) {
        if(record.number.substr(1, 1) != firstDigit) {
            if (find(names.begin(), names.end(), record.fullName) != names.end()
                && !record.fullName.empty()) {
                file << record.fullName << "\n";
            }
        }
    }
    file.close();
}

void account::readFromTextFile(std::string fileName) {
    ifstream file(fileName);
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}