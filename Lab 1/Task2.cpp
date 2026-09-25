#include <iostream>

using namespace std;

int main(){
    int arr[5] = {2, 4, 1, 3, 5};
    int max = arr[0], min = arr[0], maxIndex = 0, minIndex = 0;
    
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
        if (arr[i] > max){
            max = arr[i];
            maxIndex = i;
        }

        if (arr[i] < min){
            min = arr[i];
            minIndex = i;
        }
    }

    cout << "Max: " << max << ", at Index: " << maxIndex << "\n";
    cout << "Min: " << min << ", at Index: " << minIndex << "\n";


    return 0;
}