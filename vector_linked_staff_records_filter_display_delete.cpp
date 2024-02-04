/*Data Structure & Algorithms 
Mohammed Nasr Anes Hasan
  */
  
#include <iostream>
#include <vector>
using namespace std;

struct Data {
    string name;
    float salary;
};

struct Node {
    string name;
    float salary;
    Node *next;
};

void filterRecord(vector<Data> staff, Node *&head, Node *&tail) {
    head = NULL;
    tail = NULL;
    
    for (auto it = staff.begin(); it != staff.end(); ++it) {
        if (it->salary > 5000) {
            Node *n = new Node;
            n->name = it->name;
            n->salary = it->salary;
            n->next = NULL;
            
            if (head == NULL) {
                head = n;
                tail = n;
            } else {
                tail->next = n;
                tail = n;
            }
        }
    }
}

void display(Node *head) {
    cout << "\n:: Staff Record With Salary > RM5k ::" << endl;
    
    if (head == NULL) {
        cout << "No record found." << endl;
    } else {
        cout << "Name\tSalary" << endl;
        cout << "------------------" << endl;
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->name << "\t" << temp->salary << endl;
            temp = temp->next;
        }
    }
}

void deleteRecord(Node *&head, Node *&tail) {
    if (head == NULL) {
        cout << "No record found." << endl;
        return;
    }

    display(head);

    string name;
    cout << "Enter staff name to delete: ";
    cin >> name;

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL && temp->name != name) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Record not found." << endl;
        return;
    }

    cout << "Record found: " << temp->name << "\t" << temp->salary << endl;

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    if (temp == tail) {
        tail = prev;
    }

    delete temp;
    cout << "Record deleted." << endl;
    display(head);
}

int main() {
    vector<Data> staff = {{"Mei Ling", 12000}, {"Rajesh", 6500}, {"Husin", 7500},{"Raymond",7500}};
    Data temp;
    Node *head = NULL;
    Node *tail = NULL;

    cout << ":: New Record ::" << endl;
    cout << "Enter staff name (or q to quit): ";
    cin >> temp.name;

    while (temp.name != "q") {
        cout << "Enter salary: ";
        cin >> temp.salary;
        staff.push_back(temp);
        cout << "Enter staff name (or q to quit): ";
        cin >> temp.name;
    }

    cout << "\n:: All Staff Record ::" << endl;
    cout << "Name\tSalary" << endl;
    cout << "------------------" << endl;
    for (auto it = staff.begin(); it != staff.end(); ++it) {
        cout << it->name << "\t" << it->salary << endl;
    }

    filterRecord(staff, head, tail);
    display(head);

    deleteRecord(head, tail);

    cout << "End of Program";
}