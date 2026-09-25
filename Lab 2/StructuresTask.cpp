#include <iostream>

using namespace std;

struct Student {
    string name;
    int age;
    double cgpa;

};

int main(){
    Student s1 = {"Ali Saim", 18, 3.9};

    cout << s1.name << "\n";
    cout << s1.age;

    return 0;
}