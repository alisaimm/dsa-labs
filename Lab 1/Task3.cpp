#include <iostream>

using namespace std;

int findGcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    int num1 = 0, num2 = 0, num3 = 0;

    cin >> num1;
    cin >> num2;
    cin >> num3;

    int gcd1 = findGcd(num1, num2);
    int finalGcd = findGcd(gcd1, num3);

    cout << gcd1 << "\n";
    cout << finalGcd;

    return 0;
}