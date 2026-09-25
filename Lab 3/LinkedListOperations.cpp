#include <iostream>

using namespace std;

struct Student {
    int id;
    Student* next;
};

Student* first = NULL;
Student* last = NULL;

void insertAtStart(int id){
    Student* newRec = new Student;
    newRec -> id = id;

    if (first == NULL){
        first = last = newRec;
        newRec -> next = NULL;
    } else {
        newRec -> next = first;
        first = newRec;
    }

    cout << "Added at start.\n";
}

void insertAtEnd(int id){
    Student* newRec = new Student;
    newRec -> id = id;

    if (first == NULL){
        first = last = newRec;
        newRec -> next = NULL;
    } else {
        last -> next = newRec;
        newRec -> next = NULL;
    }

    last = newRec;
}

void insertAfterSpecific(int id, int target){
    Student* newRec = new Student;
    newRec -> id = id;

    if (first == NULL){
        cout << "List is null. Insertion failed.\n";
        delete newRec;
        return;
    } else {
        Student* temp = first;

        while(temp != NULL && temp -> id != target){
            temp = temp -> next;
        }

        if (temp == NULL){
            cout << "No such specific value exists. Failed.\n";
            delete newRec;
            return;
        }

        newRec -> next = temp -> next;
        temp -> next = newRec;

        if (newRec -> next == NULL){
            last = newRec;
        }

        cout << "Inserted.\n";
    }
}

void insertBeforeSpecific(int id, int target){
    Student* newRec = new Student;
    newRec -> id = id;

    if (first == NULL){
        cout << "List is Empty. Insertion Failed.\n";
        delete newRec;
        return;
    } else {
        Student* prev = NULL;
        Student* current = first;

        while (current != NULL && current -> id != target){
            prev = current;
            current = current -> next;
        }

        if (current == NULL){
            cout << "No such specific value exists. Insertion failed.\n";
            delete newRec;
            return;
        }

        if (prev == NULL){
            newRec -> next = first;
            first = newRec;
            cout << "Value inserted.\n";
        } else {
            newRec -> next = current;
            prev -> next = newRec;
            cout << "Value inserted.\n";
        }
    }
}

void deleteSpecific(int target){
    if (first == NULL){
        cout << "List is empty.\n";
        return;
    }

    Student* current = first;
    Student* prev = NULL;

    while (current != NULL && current -> id != target){
        prev = current;
        current = current -> next;
    }

    if (current == NULL){
            cout << "No such specific value exists. Deletion failed.\n";
            return;
        }

    if (prev == NULL){ // deleting first node
        Student* newHead = current -> next;
        delete current;
        first = newHead;

        if (first == NULL){
            last = NULL;
        }

        cout << "Object deleted.\n";
    } else {
        if (current -> next == NULL){ // deleting last node
            prev -> next = NULL;
            delete current;
            last = prev;

            cout << "Object deleted.\n";
        } else { // deleting any mid node
            Student* toDelete = current;
            prev -> next = current -> next;
            delete toDelete;
        }
    }

}

void deleteAtEnd(){
    if (first == NULL){
        cout << "List is empty.\n";
        return;
    }

    if (first == last){ // only single node
        delete first;
        first = last = NULL;
        return;
    }

    Student *current = first;

    while (current -> next -> next != NULL){
        current = current -> next;
    }

    delete current -> next;
    current -> next = NULL;
    last = current;

    cout << "Last deleted.\n";
}

void deleteAtStart(){
    if (first == NULL){
        cout << "List is empty.\n";
        return;
    }

    if (first == last){ // only 1 object
        delete first;
        first = last = NULL;

        cout << "Deleted.\n";
        return;
    }

    Student* newHead = first -> next;
    delete first;
    first = newHead;
    cout << "Deleted.\n";
}

void display(){
    if (first == NULL){
        cout << "List is empty.\n";
        return;
    }

    Student* current = first;

    cout << "===DISPLAYING LIST===\n";

    while (current != NULL){
        cout << current -> id << " --> ";
        current = current -> next;
    }

    cout << "\n";
}

int main(){
    int choice = -1;
    int value = -1;
    int targetVal = -1;

    do {
        cout << "\n===LINKED LIST OPERATIONS===\n1. Insert at Start\n2. Insert at End\n3. Insert After Specific Value\n4. Insert Before Specific Value\n5. Delete Specific Value\n6. Delete from Start\n7. Delete from End\n8. Display\n0. Exit\nEnter your Choice: ";
        cin >> choice;

        switch (choice){
            case 0:{
                break;
            }

            case 1:{
                cout << "Enter value to insert at Start: ";
                cin >> value;

                insertAtStart(value);

                break;
            }

            case 2:{
                cout << "Enter value to insert at End: ";
                cin >> value;

                insertAtEnd(value);

                break;
            }

            case 3:{
                cout << "Enter value to insert: ";
                cin >> value;

                cout << "Enter target value to insert after it: ";
                cin >> targetVal;

                insertAfterSpecific(value, targetVal);

                break;
            }

            case 4:{
                cout << "Enter value to insert: ";
                cin >> value;

                cout << "Enter target value to insert before it: ";
                cin >> targetVal;

                insertBeforeSpecific(value, targetVal);

                break;
            }

            case 5:{
                cout << "Enter a value to delete it: ";
                cin >> value;

                deleteSpecific(value);

                break;
            }

            case 6:{
                deleteAtStart();

                break;
            }

            case 7:{
                deleteAtEnd();

                break;
            }

            case 8:{
                display();

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
