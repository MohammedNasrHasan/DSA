/*Data Structure & Algorithms 
Mohammed Nasr Anes Hasan
  */
 

#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> binaryStack;
    int decimalNum, remainder;
    int num; 

    cout << ":: Decimal-Binary Converter ::\n" << endl;
    cout << "Enter a decimal number [larger than 0]: \n";
    cin >> decimalNum;
    while (decimalNum <= 0) {
        cout<< "Error: The number must be larger than 0." << endl;
        cout<< "Re-enter a decimal number [larger than 0] : ";
        cin>> decimalNum;
    }
    num = decimalNum; 

    while (decimalNum > 0) {
        remainder = decimalNum % 2;
        binaryStack.push(remainder);
        decimalNum /= 2;
    }

    cout << "Decimal number: " << num << endl;
    cout << "Binary number : "; 

    while (!binaryStack.empty()) {
        cout << binaryStack.top();
        binaryStack.pop();
    }

    cout << endl << "Thank you" << endl;

    return 0;
}