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

int main() {
    return 0;
}