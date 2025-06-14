#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char operation;
    bool validOperation = true;

    // Welcome message
    cout << "===== Simple Calculator =====" << endl;
    cout << "This calculator can perform basic operations:" << endl;
    cout << "(+) Addition, (-) Subtraction, (*) Multiplication, (/) Division" << endl << endl;

    // Input first number
    cout << "Enter the first number: ";
    cin >> num1;

    // Input second number
    cout << "Enter the second number: ";
    cin >> num2;

    // Input operation choice
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    // Perform the selected operation
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Error: Cannot divide by zero!" << endl;
                validOperation = false;
            }
            break;
        default:
            cout << "Error: Invalid operation selected!" << endl;
            validOperation = false;
    }

    // Display result if operation was valid
    if (validOperation) {
        cout << endl << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << endl;
    }

    cout << "===== Thank you for using the calculator! =====" << endl;
    return 0;
}
