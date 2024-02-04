/*Data Structure & Algorithms 
Mohammed Nasr Anes Hasan
  */

#include <iostream>
using namespace std;

struct Employee {
    string name;
    float salary;
    int service;
    Employee* next;
};

Employee* front = NULL;
Employee* rear = NULL;

void insert(string name[], float salary[], int service[], int n) {
    for (int i = 0; i < n; i++) {
        Employee* newEmployee = new Employee;
        newEmployee->name = name[i];
        newEmployee->salary = salary[i];
        newEmployee->service = service[i];
        newEmployee->next = NULL;
        if (front == NULL) {
            front = newEmployee;
            rear = newEmployee;
        } else {
            rear->next = newEmployee;
            rear = newEmployee;
        }
    }
}

void update(string name) {
    if (front == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }
    Employee* current = front;
    Employee* previous = NULL;
    while (current != NULL && current->name != name) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        cout << "Employee not found." << endl;
        return;
    }
    if (previous == NULL) {
        
        return;
    }
    previous->next = current->next;
    current->next = front;
    front = current;
}

void display() {
    int i=0;
    if (front == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }
    Employee* current = front;
    while (current != NULL) {
        ++i;
        cout <<i<< ". Staff Name: " << current->name << ", Salary: " << current->salary << ", Year of Service: " << current->service << endl;
        current = current->next;
    }
}

int main() {
    string name[] = {"Ahmad", "Siew Mun", "Ravi", "John", "Mohammad", "Jennifer"};
    float salary[] = {12000.0, 4800.0, 8000.0, 5500.0, 14000.0, 11000.0};
    int service[] = {10, 4, 9, 7, 6, 5};
    char x;

    insert(name, salary, service, 6);

    cout << "\n # Menu : Current Record # " << endl;
    display();
    cout << "\n # Menu : Update Record # " << endl;
    string nameToUpdate;
    cout << "Enter name to be updated as 1st record: ";
    cin >> nameToUpdate;
    cout<<"You need to move the first 3 record(s) to the end."<<endl;
    cout<<"press Y to proceed: ";
    cin>>x;
    do{
    update(nameToUpdate);
    cout << "\n # Menu : Updated Record # " << endl;
    display();
    break;
    }while(x=='y'||x=='Y');
    cout << "\n End of program";
return 0;
}