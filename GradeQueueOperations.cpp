/*Data Structure & Algorithms 
Mohammed Nasr Anes Hasan
  */



#include <iostream>
#include <queue>

using namespace std;

void grading(queue<float> marks) {
    int totalPass = 0, totalFail = 0;
    cout << "::Grading::" << endl;
    while (!marks.empty()) {
        float mark = marks.front();
        marks.pop();
        if (mark >= 50) {
            cout << mark << " : Pass" << endl;
            totalPass++;
        } else {
            cout << mark << " : Fail" << endl;
            totalFail++;
        }
    }
    cout << "Total Pass: " << totalPass << endl;
    cout << "Total Fail: " << totalFail << endl;
}

int main() {
    queue<float> marks;
    int size;
    float mark;

    cout << "Enter total data to insert: ";
    cin >> size;
    for (int i = 1; i <= size; i++) {
        cout << "Enter mark : ";
        cin >> mark;
        cout << endl;
        marks.push(mark);
    }

    grading(marks);

    while (!marks.empty()) {
        marks.pop();
    }

    cout << "\nEnd of program";
return 0;
}