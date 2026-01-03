using namespace std;
#include <iostream>

int add(int a, int b) {
    return a + b ;
}
int subtract(int a, int b) {
    return a - b ;
}
int multiply(int a, int b) {
    return a * b ;
}
int divide(int a, int b) {
    if (b != 0) {
        return a / b ;
    } else {
        cout << "Error: Division by zero" << endl;
        return 0;
    }
}   
int main() {
    int a, b;
    char op;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> b;

    int *num1 = &a;
    int *num2 = &b;

    switch (op) {
        case '+':
            cout << "Result: " << add(*num1, *num2) << endl;
            break;
        case '-':
            cout << "Result: " << subtract(*num1, *num2) << endl;
            break;
        case '*':
            cout << "Result: " << multiply(*num1, *num2) << endl;
            break;
        case '/':
            cout << "Result: " << divide(*num1, *num2) << endl;
            break;
        default:
            cout << "Error: Invalid operator" << endl;
            break;
    }
    return 0;
}
