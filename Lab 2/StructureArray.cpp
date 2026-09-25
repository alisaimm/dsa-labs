#include <iostream>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    double cgpa;

};

Student students[100];
int SIZE = 100;
int start = -1;
int last = -1;

void insertAtStart(int id, string name, int age, double cgpa){
    if (start == -1){
        start = 0;
        last = 0;
        students[0] = {id, name, age, cgpa};
        cout << "Student Stored." << "\n";
        return;
    } else if ((last - start + 1) >= SIZE){
        cout << "No Space Available";
        return;
    } else if (start == 0){
        for (int i = last; i >= start; i--){
            students[i + 1] = students[i];
        }

        students[0] = {id, name, age, cgpa};

        last++;

        cout << "Student Stored." << "\n";

        return;
    } else if (start > 0){
        students[start - 1] = {id, name, age, cgpa};
        start--;

        cout << "Student Stored." << "\n";

        return;
    }
}

void deleteFromStart(){
    if (start == -1 || last == -1){
        cout << "Students are empty. Unable to delete." << "\n";
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

void insertAtEnd(int id, string name, int age, double cgpa){
    if (start == -1){
        start = 0;
        last = 0;
        students[0] = {id, name, age, cgpa};
        cout << "Student Inserted." << "\n";
        return;
    } else if ((last - start + 1) >= SIZE){
        cout << "No Space left." << "\n";
        return;
    } else if (last == (SIZE - 1)) {
        for (int i = start; i <= last; i++){
            students[i - 1] = students[i];
        }

        start--;

        students[last] = {id, name, age, cgpa};

        cout << "Student Inserted." << "\n";
    } else {
        last++;
        students[last] = {id, name, age, cgpa};
        cout << "Student Inserted." << "\n";
    }
}

void deleteFromEnd(){
    if (start == -1 || last == -1){
        cout << "Students are already empty." << "\n";
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

void insertAfterSpecificStudent(int targetStudent, int id, string name, int age, double cgpa){
    if (start == -1 || last == -1){
        cout << "Students List is empty. No such value found.\n";
        return;
    } else if ((last - start + 1) >= SIZE){
        cout << "No space is left in list. Cannot insert.\n";
        return;
    } else {
        int indexOfCurrentStudent = -1;

        for (int i = start; i <= last; i++){
            if (students[i].id == targetStudent){
                indexOfCurrentStudent = i;
                break;
            }
        }

        if (indexOfCurrentStudent == -1){
            cout << "No such Student found. Cannot insert.\n";
            return;
        } else {
            if (last == (SIZE - 1)){
                for (int i = start; i <= indexOfCurrentStudent; i++){ // shift elements to left till target value (to insert after that target)
                    students[i - 1] = students[i];
                }

                students[indexOfCurrentStudent] = {id, name, age, cgpa};

                start--;

                cout << "Inserted.\n";
                return;
            } else {
                for (int i = last; i > indexOfCurrentStudent; i--){
                    students[i + 1] = students[i];
                }

                students[indexOfCurrentStudent + 1] = {id, name, age, cgpa};

                last++;

                cout << "Student Inserted.\n";
                return;
            }
        }
    }
}

void insertBeforeSpecificValue(int targetStudent, int id, string name, int age, double cgpa){
    if (start == -1 || last == -1){
        cout << "Students List is empty. Cannot insert.\n";
        return;
    } else if ((last - start + 1) >= SIZE){
        cout << "No space available in list.\n";
        return;
    } else {
        int currentValueIndex = -1;

        for (int i = start; i <= last; i++){
            if (students[i].id == targetStudent){
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
                    students[i + 1] = students[i]; // shift elements to right till the target value.
                }

                last++;

                students[currentValueIndex] = {id, name, age, cgpa};

                cout << "Student Inserted.\n";
                return;
            } else {
                for (int i = start; i < currentValueIndex; i++){
                    students[i - 1] = students[i]; // shift elements to left till before target value.
                }

                start--;

                students[currentValueIndex - 1] = {id, name, age, cgpa};

                cout << "Student Inserted.\n";

                return;
            }
        }
    }
}

void deleteSpecificValue(int targetStudent){
    if (start == -1 || last == -1){
        cout << "Student List is already empty\n";
        return;
    } else {
        int indexToDelete = -1;

        for (int i = start; i <= last; i++){
            if (targetStudent == students[i].id){
                indexToDelete = i;
                break;
            }
        }

        if (indexToDelete == -1){
            cout << "No such student exists in list.\n";
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
                students[i] = students[i + 1]; // shift values to left to override target value.
            }

            last--;

            cout << "Deleted\n";
            return;
        }
    }
}

void display(){
    if (start == -1 || last == -1){
        cout << "Students List is empty.\n";
        return;
    }

    for (int i = start; i <= last; i++){
        cout << "\n--STUDENT--\n";
        cout << "ID: " << students[i].id << "\nName: " << students[i].name << "\nAge: " << students[i].age << "\nCGPA: " << students[i].cgpa << "\n";
    }

}

void search(int targetId){
    if (start == -1 || last == -1){
        cout << "List Empty. Value not found.\n";
        return;
    }

    int index = -1;

    for (int i = start; i <= last; i++){
        if (students[i].id == targetId){
            index = i;
            break;
        }
    }

    if (index != -1){
        cout << "\n---STUDENT FOUND---\n";
        cout << "ID: " << students[index].id << "\nName: " << students[index].name << "\nAge: " << students[index].age << "\nCGPA: " << students[index].cgpa << "\n";
        return;
    } else {
        cout << "Value not found.\n";
    }
}

int main(){
    
    int choice = -1;
    int id = -1;
    int age = -1;
    int targetId = -1;
    double cgpa = 0.0;
    string name;

    do {
        cout << "\n===ARRAY OPERATIONS===\n1. Insert at Start\n2. Insert at End\n3. Insert After Specific Value\n4. Insert Before Specific Value\n5. Delete Specific Value\n6. Delete from Start\n7. Delete from End\n8. Display\n9. Search\n0. Exit\nEnter your Choice: ";
        cin >> choice;

        switch (choice){
            case 0:{
                break;
            }

            case 1:{
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter student ID: ";
                cin >> id;
                cout << "Enter student age: ";
                cin >> age;
                cout << "Enter student CGPA: ";
                cin >> cgpa;

                insertAtStart(id, name, age, cgpa);

                break;
            }

            case 2:{
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter student ID: ";
                cin >> id;
                cout << "Enter student age: ";
                cin >> age;
                cout << "Enter student CGPA: ";
                cin >> cgpa;

                insertAtEnd(id, name, age, cgpa);

                break;
            }

            case 3:{
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter student ID: ";
                cin >> id;
                cout << "Enter student age: ";
                cin >> age;
                cout << "Enter student CGPA: ";
                cin >> cgpa;

                cout << "Enter student ID to insert after: ";
                cin >> targetId;

                insertAfterSpecificStudent(targetId, id, name, age, cgpa);

                break;
            }

            case 4:{
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter student ID: ";
                cin >> id;
                cout << "Enter student age: ";
                cin >> age;
                cout << "Enter student CGPA: ";
                cin >> cgpa;

                cout << "Enter student ID to insert before: ";
                cin >> targetId;

                insertBeforeSpecificValue(targetId, id, name, age, cgpa);

                break;
            }

            case 5:{
                cout << "Enter student ID to delete: ";
                cin >> targetId;

                deleteSpecificValue(targetId);

                break;
            }

            case 6:{
                deleteFromStart();

                break;
            }

            case 7:{
                deleteFromEnd();

                break;
            }

            case 8:{
                display();

                break;
            }

            case 9:{
                cout << "Enter student ID to search: ";
                cin >> targetId;

                search(targetId);

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
