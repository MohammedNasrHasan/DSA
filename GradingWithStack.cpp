/*Data Structure & Algorithms 
Mohammed Nasr Anes Hasan
  */

#include<iostream>
#include<stack>

using namespace std;

void grading(stack<float> s){
    int totalPass = 0, totalFail = 0;
    while(!s.empty()){
        float mark = s.top();
        if(mark >= 50){
            cout << mark << " : Pass" << endl;
            totalPass++;
        } else {
            cout << mark << " : Fail" << endl;
            totalFail++;
        }
        s.pop();
    }
    cout << "Total Pass: " << totalPass << endl;
    cout << "Total Fail: " << totalFail << endl;
}

int main() {
    stack<float> marks;
    int size; float mark;
                  
    cout << "Enter total data to insert: ";
    cin >> size;
    for(int i = 1; i <= size; i++){
        cout << "Enter mark : ";
        cin >> mark;
        marks.push(mark);                  //   to insert marks into the stack
    }
    
    grading(marks);                        //   to display pass/fail 
    
    while(!marks.empty()){ 
        marks.pop();                       //  to remove all marks
    }

    cout << "\nEnd of program";
    return 0;
}
