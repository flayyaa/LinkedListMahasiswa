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
    }
    else {
        Student* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteHead() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Student* temp = head;
    head = head->next;
    delete temp;
    cout << "Delete head berhasil" << endl;
}

void deleteLast() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    }
    else {
        Student* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    cout << "Delete last berhasil" << endl;
}

void printAll() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Student* temp = head;
    while (temp != nullptr) {
        cout << "NIM   : " << temp->nim << endl;
        cout << "Name  : " << temp->name << endl;
        cout << "Birth : " << temp->birth << endl;
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    insertLast("103032500005", "Fadhil Asyam Damanik", "12-04-2008");
    insertLast("103032500041", "Rahsya Iman Dehavilland", "25-03-2007");
    insertLast("103032500144", "Muhammad Fariz Muhtadi", "09-08-2006");
    insertLast("103032500146", "Mahesa Putra Mulyawan", "23-09-2006");
    insertLast("103032500149", "Gyio Rangga Satria Putra", "09-01-2007");
    insertLast("103032500150", "Naufal Nafiz Faturrahman", "13-05-2007");
    insertLast("103032500153", "Fazli Baktiadi", "27-05-2006");
    insertLast("103032500159", "Matthew Glen Abram Pakpahan", "01-05-2011");
    insertLast("103032500176", "Vendra Fausta Andrean", "06-06-2007");
    insertLast("103032500180", "Dzaky Allam Shidiq", "25-02-2006");
    insertLast("103032500191", "Nayla Novtiera Anjani", "18-11-2007");
    insertLast("103032540001", "Fathin Arib Nurhumam", "26-10-2004");
    insertLast("103032540002", "Ida Bagus Harell", "26-06-2008");
    insertLast("103032540003", "Nigel William Pieters", "30-04-2007");
    insertLast("103032540004", "Aqila Fathatulayya", "20-09-2006");
    insertLast("103032540005", "Badriah Nuraini Rahayu", "06-05-2006");
    int choice;
    do {
        cout << "1. Insert Head" << endl;
        cout << "2. Insert Last" << endl;
        cout << "3. Delete Head" << endl;
        cout << "4. Delete Last" << endl;
        cout << "5. Print All" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        string nim;
        string name;
        string birth;
        switch(choice) {
        case 1:
            cout << "NIM: ";
            cin >> nim;
            cin.ignore();
            cout << "Name: ";
            getline(cin, name);
            cout << "Birth: ";
            cin >> birth;
            insertHead(nim, name, birth);
            break;
        case 2:
            cout << "NIM: ";
            cin >> nim;
            cin.ignore();
            cout << "Name: ";
            getline(cin, name);
            cout << "Birth: ";
            cin >> birth;
            insertLast(nim, name, birth);
            break;
        case 3:
            deleteHead();
            break;
        case 4:
            deleteLast();
            break;
        case 5:
            printAll();
            break;
        case 0:
            cout << "Program finished" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
        cout << endl;
    } while(choice != 0);
    return 0;
}