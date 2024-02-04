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
    Node* next;
};

void filterRecord(vector<Data> staff, Node *&head, Node *&tail) {
    for (auto i : staff) {
        if (i.salary > 5000) {
            Node* new_node = new Node;
            new_node->name = i.name;
            new_node->salary = i.salary;
            new_node->next = NULL;
            if (head == NULL) {
                head = new_node;
                tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
    }
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

int main()
{
    vector<Data>staff = {{"Mei Ling",12000}, {"Rajesh", 4000}, {"Husin", 7500}};
    Data temp;
    Node *head=NULL, *tail=NULL;

    cout << ":: New Record ::" << endl;
    cout << "Enter name: ";
    cin >> temp.name;
    cout << "Enter salary: ";
    cin >> temp.salary;
    staff.push_back(temp);

    cout << "\n:: All Staff Record ::" << endl;
    for (auto i : staff) {
        cout << "Name: " << i.name << ", Salary: RM" << i.salary << endl;
    }

    filterRecord(staff,head,tail);
    display(head);
    cout<<"End of Program";

    return 0;
}
