/*Data Structure & Algorithms 
Mohammed Nasr Anes Hasan
  */
using namespace std;

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
    Node* next;
};

void filterRecord(vector<Data> staff, Node *&head) {
    for (auto i : staff) {
        if (i.salary > 5000) {
  Node* new_node = new Node;
  new_node->name = i.name;
  new_node->salary = i.salary;
  new_node->next = head;
  head = new_node;
        }
    }
}

void display(Node *head){
    cout<<"\n:: Staff Record With Salary > RM5k ::"<<endl;
    while (head != NULL) {
    cout << "Name: " << head->name << ", Salary: RM" << head->salary << endl;
    head = head->next;
    }
}

void insert(Node *&head, string name, float salary, int position) {
    Node* new_node = new Node;
    new_node->name = name;
    new_node->salary = salary;

    if (head == NULL) {
        
        head = new_node;
    } else if (position == 1) {
        
        new_node->next = head;
        head = new_node;
    } else {
       
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

int main()
{
    vector<Data>staff = {{"Mei Ling",12000}, {"Rajesh", 4000}, {"Husin", 7500}};
    Data temp;
    Node *head=NULL;
    cout << ":: New Record ::" << endl;
    cout << "Enter name: ";
    cin >> temp.name;
    cout << "Enter salary: ";
    cin >> temp.salary; 
    
    while (temp.salary < 5000) {
        cout << "Error: Min salary is RM5000. Re-enter salary:Rm5000: ";
        cin >> temp.salary;
    }

    
    int position;
    cout << "Choose position to insert new record (1 for front, 2 for middle, 3 for end): ";
    cin >> position;

    if (position == 2) {
      
        display(head);
    }

   
    insert(head, temp.name, temp.salary, position);

    cout << "\n:: All Staff Record ::" << endl;
    for (auto i : staff) {
        cout << "Name: " << i.name << ", Salary: RM" << i.salary << endl;
    }

    filterRecord(staff,head);
    display(head);
    cout<<"End of Program";

    return 0;
}
