#include <iostream>

using namespace std;

int add (int a, int b){
    return a + b;
}

int subtract (int a, int b){
    return a - b;
}

int multiply (int a, int b){
    return a * b;
}

int divide (int a, int b){
    return a / b;
}

int main(){
    cout << "Enter first number: ";
    int num1 = 0;
    cin >> num1;

    cout << "Enter second number: ";
    int num2 = 0;
    cin >> num2;

    cout << "\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\nSelect Operation: ";
    int choice = 0;
    cin >> choice;

    switch (choice){
        case 1:{
            cout << "Result: " << add(num1, num2);
            break;
        }

        case 2:{
            cout << "Result: " << subtract(num1, num2);
            break;
        }

        case 3:{
            cout << "Result: " << multiply(num1, num2);
            break;
        }

        case 4:{
            cout << "Result: " << divide(num1, num2);
            break;
        }

        default: {
            cout << "Wrong choice.";
        }
    }
    


    return 0;
}