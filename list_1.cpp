// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    explicit Node(int val) : value(val), next(nullptr) {}
};

void append(Node*& head, int val) {
    Node** current = &head;
    while (*current) current = &((*current)->next);
    *current = new Node(val);
}

void printList(const Node* node) {
    while (node) {
        cout << node->value;
        if (node->next) cout << " - ";
        node = node->next;
    }
    cout << endl;
}

int getLength(const Node* node) {
    int count = 0;
    while (node) node = node->next, ++count;
    return count;
}

Node* reverseList(Node* start) {
    Node* prev = nullptr;
    while (start) {
        Node* next = start->next;
        start->next = prev;
        prev = start;
        start = next;
    }
    return prev;
}

void reflectFromTail(Node*& head, int k) {
    int n = getLength(head);
    if (!head || k <= 0 || k >= n) return;

    Node* current = head;
    for (int i = 1; i < n - k; ++i)
        current = current->next;

    current->next = reverseList(current->next);
}

void clearList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    for (int x : {1, 2, 3, 4, 5}) append(head, x);

    int k = 4;
    printList(head);          
    reflectFromTail(head, k);
    printList(head);          

    clearList(head);
    return 0;
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
