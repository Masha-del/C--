// Name.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>
#include <windows.h>
#include <vector>

using namespace std;

struct Pet {
    string owner;
    string type;
    string name;
    int age;
};

vector <Pet> readPetsFromFile(const string& filename) {
    vector<Pet> pets;
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Не удалось открыть файл " << filename << endl;
        return pets;
    }

    while (getline(file, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);

        if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) {
            cerr << "Некорректный формат строки: " << line << endl;
            continue;
        }

        Pet pet;
        pet.owner = line.substr(0, pos1);
        pet.type = line.substr(pos1 + 1, pos2 - pos1 - 1);
        pet.name = line.substr(pos2 + 1, pos3 - pos2 - 1);

        try {
            pet.age = stoi(line.substr(pos3 + 1));
        }
        catch (const invalid_argument& e) {
            cerr << "Некорректный возраст в строке: " << line << endl;
            continue;
        }

        pets.push_back(pet);
    }

    file.close();
    return pets;
}

void countDistinctPetTypesPerOwner(const vector<Pet>& pets) {
    map<string, set<string>> ownerToTypes;

    for (const auto& pet : pets) {
        ownerToTypes[pet.owner].insert(pet.type);
    }

    cout << "Количество различных видов животных у каждого владельца:" << endl;
    for (const auto& entry : ownerToTypes) {
        cout << entry.first << ": " << entry.second.size() << endl;
    }
}


void findOwnersAndNamesByType(const vector<Pet>& pets) {
    string type;
    cout << "Введите вид животного: ";
    cin.ignore();
    getline(cin, type);

    set<pair<string, string>> ownerNamePairs;

    for (const auto& pet : pets) {
        if (pet.type == type) {
            ownerNamePairs.insert({ pet.owner, pet.name });
        }
    }

    if (ownerNamePairs.empty()) {
        cout << "Животных такого вида не найдено." << endl;
        return;
    }

    cout << "Владельцы и клички для вида '" << type << "':" << endl;
    for (const auto& pair : ownerNamePairs) {
        cout << "Владелец: " << pair.first << ", Кличка: " << (pair.second.empty() ? "нет клички" : pair.second) << endl;
    }
}
void countTypesWithGivenName(const vector<Pet>& pets) {
    string name;
    cout << "Введите кличку: ";
    cin.ignore();
    getline(cin, name);

    set<string> types;

    for (const auto& pet : pets) {
        if (pet.name == name) {
            types.insert(pet.type);
        }
    }

    cout << "Количество видов животных с кличкой '" << name << "': " << types.size() << endl;
}

void printOldestAndYoungestByType(const vector<Pet>& pets) {
    map<string, pair<int, int>> typeToAge; // first - min age, second - max age

    for (const auto& pet : pets) {
        if (typeToAge.find(pet.type) == typeToAge.end()) {
            typeToAge[pet.type] = { pet.age, pet.age };
        }
        else {
            typeToAge[pet.type].first = min(typeToAge[pet.type].first, pet.age);
            typeToAge[pet.type].second = max(typeToAge[pet.type].second, pet.age);
        }
    }

    cout << "Самый молодой и самый старый возраст для каждого вида:" << endl;
    for (const auto& entry : typeToAge) {
        cout << entry.first << ": самый молодой - " << entry.second.first
            << ", самый старый - " << entry.second.second << endl;
    }
}


void DisplayMenu()
{
    cout << "---------------------------------------------------------------------" << endl;
    cout << "1. Посчитать количество различных видов животных у каждого владельца." << endl;
    cout << "2. Для конкретного вида животного вывести всех его владельцев и клички" << endl;
    cout << "3. Определить, сколько видов животных носит определённую кличку." << endl;
    cout << "4. Вывести информацию о возрасте самого старого и самого молодого животного каждого вида." << endl;
    cout << "Выберите операцию, которую хотите совершить, нажмите цифру нужной операции (для выхода - любой другой ввод): ";
}

int main()
{
    setlocale(LC_ALL, "Rus");

    SetConsoleOutputCP(CP_UTF8);


    vector <Pet> pets = readPetsFromFile("data.txt");

    int oper;
    while (true)
    {
        DisplayMenu();
        cin >> oper;
        switch (oper)
        {
        case 1:
            countDistinctPetTypesPerOwner(pets);
            break;
        case 2:
            findOwnersAndNamesByType(pets);
            break;
        case 3:
            countTypesWithGivenName(pets);
            break;
        case 4:
            printOldestAndYoungestByType(pets);
            break;
        default: exit(1);
        }

    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
