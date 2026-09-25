#include <iostream>

using namespace std;

int main(){

    int start = 0, end = 0, sum = 0;

    cout << "Enter the starting value: ";
    cin >> start;

    cout << "Enter the end value: ";
    cin >> end;

    for (int i = start; i <= end; i++){
        sum += (i * i);
    }

    cout << "Result: " << sum;

    return 0;
}