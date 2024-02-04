/*Data Structure & Algorithms 
Mohammed Nasr Anes Hasan
  */


#include <iostream>
#include <vector>
using namespace std;

struct Data{
    string name;
    float salary;
};

struct Node{
    string name;
    float salary;
    Node *next;
};

void filterRecord(vector<Data>& staff, Node** head){
    for (auto it = staff.begin(); it != staff.end(); ++it) {
        if (it->salary > 5000) {
            Node* n = new Node();
            n->name = it->name;
            n->salary = it->salary;
            n->next = *head;
            *head = n;
        }
    }
}

void display(Node* head){
    cout << "\n:: Staff Record With Salary > RM5k ::" << endl;
    for (Node* p = head; p != NULL; p = p->next) {
        cout << "Name: " << p->name << ", Salary: RM" << p->salary << endl;
    }
}

int main()
{
    vector<Data> staff = {{"Mei Ling", 12000}, {"Rajesh", 4000}, {"Husin", 7500}};
    Data temp;
    Node* head = NULL;

    cout << ":: New Record ::" << endl;
    cout << "Enter name: ";
    getline(cin, temp.name);
    cout << "Enter salary: RM";
    cin >> temp.salary;
    staff.push_back(temp);

    cout << "\n:: All Staff Record ::" << endl;
    for (auto it = staff.begin(); it != staff.end(); ++it) {
        cout << "Name: " << it->name << ", Salary: RM" << it->salary << endl;
    }

    filterRecord(staff, &head);
    display(head);
    cout << "End of Program"; 
    return 0;
}