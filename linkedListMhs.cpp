#include <iostream>
using namespace std;

struct Student {
    string nim;
    string name;
    string birth;
    Student* next;
};

Student* head = nullptr;

void insertHead(string nim, string name, string birth) {
    Student* newNode = new Student;
    newNode->nim = nim;
    newNode->name = name;
    newNode->birth = birth;
    newNode->next = head;
    head = newNode;
}

void insertLast(string nim, string name, string birth) {
    Student* newNode = new Student;
    newNode->nim = nim;
    newNode->name = name;
    newNode->birth = birth;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Student* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteHead() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Student* temp = head;
    head = head->next;
    delete temp;
}

void deleteLast() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Student* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

int main() {
    return 0;
}