#include <iostream>

using namespace std;

void insertAtStart(int arr[], int& start, int& last, int SIZE, int value){
    if (start == -1){
        start = 0;
        last = 0;
        arr[0] = value;
        cout << "Stored." << "\n";
        return;
    } else if ((last - start + 1) >= SIZE){
        cout << "No Space Available";
        return;
    } else if (start == 0){
        for (int i = last; i >= start; i--){
            arr[i + 1] = arr[i];
        }

        arr[0] = value;

        last++;

        cout << "Stored." << "\n";

        return;
    } else if (start > 0){
        arr[start - 1] = value;
        start--;

        cout << "Stored." << "\n";

        return;
    }
}

void deleteFromStart(int& start, int& last){
    if (start == -1 || last == -1){
        cout << "List is empty. Unable to delete." << "\n";
        return;
    } else if (start == last){ // only 1 element so start index = last index
        start = -1;
        last = -1;
        cout << "Deleted." << "\n";
        return;
    } else {
        start++;
        cout << "Deleted." << "\n";
    }
}

void insertAtEnd(int arr[], int& start, int& last, int SIZE, int value){
    if (start == -1){
        start = 0;
        last = 0;
        arr[0] = value;
        cout << "Inserted." << "\n";
        return;
    } else if ((last - start + 1) >= SIZE){
        cout << "No Space left." << "\n";
        return;
    } else if (last == (SIZE - 1)) {
        for (int i = start; i <= last; i++){
            arr[i - 1] = arr[i];
        }

        start--;

        arr[last] = value;

        cout << "Inserted." << "\n";
    } else {
        last++;
        arr[last] = value;
        cout << "Inserted." << "\n";
    }
}

void deleteFromEnd(int& start, int& last){
    if (start == -1 || last == -1){
        cout << "List ia already empty." << "\n";
        return;
    } else if (start == last){
        start = -1;
        last = -1;
        cout << "Deleted\n";
        return;
    } else {
        last--;
        cout << "Deleted\n";
        return;
    }
}

void insertAfterSpecificValue(int arr[], int& start, int& last, int SIZE, int currentVal, int value){
    if (start == -1 || last == -1){
        cout << "List is empty. No such value found.\n";
        return;
    } else if ((last - start + 1) >= SIZE){
        cout << "No space is left in list. Cannot insert.\n";
        return;
    } else {
        int indexOfCurrentVal = -1;

        for (int i = start; i <= last; i++){
            if (arr[i] == currentVal){
                indexOfCurrentVal = i;
                break;
            }
        }

        if (indexOfCurrentVal == -1){
            cout << "No such value found. Cannot insert.\n";
            return;
        } else {
            if (last == (SIZE - 1)){
                for (int i = start; i <= indexOfCurrentVal; i++){ // shift elements to left till target value (to insert after that target)
                    arr[i - 1] = arr[i];
                }

                arr[indexOfCurrentVal] = value;

                start--;

                cout << "Inserted.\n";
                return;
            } else {
                for (int i = last; i > indexOfCurrentVal; i--){
                    arr[i + 1] = arr[i];
                }

                arr[indexOfCurrentVal + 1] = value;

                last++;

                cout << "Inserted.\n";
                return;
            }
        }
    }
}

void insertBeforeSpecificValue (int arr[], int& start, int& last, int SIZE, int currentVal, int value){
    if (start == -1 || last == -1){
        cout << "List is empty. Cannot insert.\n";
        return;
    } else if ((last - start + 1) >= SIZE){
        cout << "No space available in list.\n";
        return;
    } else {
        int currentValueIndex = -1;

        for (int i = start; i <= last; i++){
            if (arr[i] == currentVal){
                currentValueIndex = i;
                break;
            }
        }

        if (currentValueIndex == -1){
            cout << "No such value exists. Cannot insert.\n";
            return;
        } else {
            if (start == 0){
                for (int i = last; i >= currentValueIndex; i--){
                    arr[i + 1] = arr[i]; // shift elements to right till the target value.
                }

                last++;

                arr[currentValueIndex] = value;

                cout << "Inserted.\n";
                return;
            } else {
                for (int i = start; i < currentValueIndex; i++){
                    arr[i - 1] = arr[i]; // shift elements to left till before target value.
                }

                start--;

                arr[currentValueIndex - 1] = value;

                cout << "Inserted.\n";

                return;
            }
        }
    }
}

void deleteSpecificValue(int arr[], int& start, int& last, int value){
    if (start == -1 || last == -1){
        cout << "List is already empty\n";
        return;
    } else {
        int indexToDelete = -1;

        for (int i = start; i <= last; i++){
            if (value == arr[i]){
                indexToDelete = i;
                break;
            }
        }

        if (indexToDelete == -1){
            cout << "No such value exists in list.\n";
            return;
        }

        if (start == last){
            start = -1;
            last = -1;

            cout << "Deleted\n";
            return;
        } else if (indexToDelete == start){
            start++;
            cout << "Deleted.\n";
            return;
        } else if (indexToDelete == last){
            last--;
            cout << "Deleted.\n";
            return;
        } else {
            for (int i = indexToDelete; i < last; i++){
                arr[i] = arr[i + 1]; // shift values to left to override target value.
            }

            last--;

            cout << "Deleted\n";
            return;
        }
    }
}

void display(int arr[], int start, int last){
    if (start == -1 || last == -1){
        cout << "List is empty.\n";
        return;
    }

    cout << "[ ";

    for (int i = start; i <= last; i++){
        cout << arr[i] << " ";
    }

    cout << "]";
}

void search(int arr[], int start, int last, int value){
    if (start == -1 || last == -1){
        cout << "List Empty. Value not found.\n";
        return;
    }

    int index = -1;

    for (int i = start; i <= last; i++){
        if (arr[i] == value){
            index = i;
            break;
        }
    }

    if (index != -1){
        cout << "Value " << value << " Found at Array Index: " << index << "\n";
        cout << "It is at Position " << (index - start + 1) << " in the List.\n";
        return;
    } else {
        cout << "Value not found.\n";
    }
}

int main(){
    int arr[100];
    int SIZE = sizeof(arr) / sizeof(arr[0]);
    int start = -1;
    int last = -1;

    
    int choice = -1;
    int value = -1;
    int targetVal = -1;

    do {
        cout << "\n===ARRAY OPERATIONS===\n1. Insert at Start\n2. Insert at End\n3. Insert After Specific Value\n4. Insert Before Specific Value\n5. Delete Specific Value\n6. Delete from Start\n7. Delete from End\n8. Display\n9. Search\n0. Exit\nEnter your Choice: ";
        cin >> choice;

        switch (choice){
            case 0:{
                break;
            }

            case 1:{
                cout << "Enter value to insert at Start: ";
                cin >> value;

                insertAtStart(arr, start, last, SIZE, value);

                break;
            }

            case 2:{
                cout << "Enter value to insert at End: ";
                cin >> value;

                insertAtEnd(arr, start, last, SIZE, value);

                break;
            }

            case 3:{
                cout << "Enter value to insert: ";
                cin >> value;

                cout << "Enter target value to insert after it: ";
                cin >> targetVal;

                insertAfterSpecificValue(arr, start, last, SIZE, targetVal, value);

                break;
            }

            case 4:{
                cout << "Enter value to insert: ";
                cin >> value;

                cout << "Enter target value to insert before it: ";
                cin >> targetVal;

                insertBeforeSpecificValue(arr, start, last, SIZE, targetVal, value);

                break;
            }

            case 5:{
                cout << "Enter a value to delete it: ";
                cin >> value;

                deleteSpecificValue(arr, start, last, value);

                break;
            }

            case 6:{
                deleteFromStart(start, last);

                break;
            }

            case 7:{
                deleteFromEnd(start, last);

                break;
            }

            case 8:{
                display(arr, start, last);

                break;
            }

            case 9:{
                cout << "Enter a value to search: ";
                cin >> value;

                search(arr, start, last, value);

                break;
            }

            default:{
                cout << "Wrong choice. Choose again.\n";
                break;
            }
        }

    } while (choice != 0);

    return 0;
}