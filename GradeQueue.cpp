/*Data Structure & Algorithms 
Mohammed Nasr Anes Hasan
  */



#include<iostream>

using namespace std;

struct Data {
    float mark;
    Data *next;
};

void push(Data *&front, Data *&rear, float mark) {
    Data *n = new Data;
    n->mark = mark;
    n->next = NULL;
    if (rear == NULL) {
        front = rear = n;
    } else {
        rear->next = n;
        rear = n;
    }
}

void grading(Data *front) {
    int totalPass = 0, totalFail = 0;
    Data *temp = front;
    cout << "::Grading::" << endl;
    while (temp != NULL) {
        if (temp->mark >= 50) {
            cout << temp->mark << " : Pass" << endl;
            totalPass++;
        } else {
            cout << temp->mark << " : Fail" << endl;
            totalFail++;
        }
        temp = temp->next;
    }
    cout << "Total Pass: " << totalPass << endl;
    cout << "Total Fail: " << totalFail << endl;
}

void pop(Data *&front, Data *&rear) {
    if (front == NULL) {
        return;
    }
    Data *temp = front;
    front = front->next;
    delete temp;
    if (front == NULL) {
        rear = NULL;
    }
}

int main() {
    Data *front = NULL, *rear = NULL;
    int size;
    float mark;
                  
    cout << "Enter total data to insert: ";
    cin >> size;
    for (int i = 1; i <= size; i++) {
        cout << "Enter mark : ";
        cin >> mark;
        cout << endl;
        push(front, rear, mark);  // to insert marks into the queue
    }
    
    grading(front);  // to display pass/fail 
    
    while (front != NULL) {
        pop(front, rear);  // to remove marks from the queue
    }
    
    cout << "\nEnd of program";
return 0;
}