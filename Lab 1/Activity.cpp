#include <iostream>

using namespace std;

int main(){

    char name[50];
    int age = 0;

    cout << "Enter your name: ";
    cin.get(name, 50);
    
    cout << "Enter your age: ";
    cin >> age;

    cout << "Hey " << name << ", you are " << age << " years old.";


    return 0;
}