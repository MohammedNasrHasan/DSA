/*Data Structure & Algorithms 
Mohammed Nasr Anes Hasan
  */
#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> binaryStack;
    int decimalNum, remainder;

    cout << ":: Decimal-Binary Converter ::" << endl;
    cout << "Enter a decimal number [larger than 0]: ";
    cin >> decimalNum;

    while (decimalNum > 0) {
        remainder = decimalNum % 2;
        binaryStack.push(remainder);
        decimalNum /= 2;
    }

    cout << "Decimal number: " << decimalNum << endl;
    cout << "Binary number : ";

    while (!binaryStack.empty()) {
        cout << binaryStack.top();
        binaryStack.pop();
    }

    cout << endl << "Thank you" << endl;

    return 0;
}