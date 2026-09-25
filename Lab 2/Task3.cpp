#include <iostream>

using namespace std;

struct Node {
    Node* next;
    int data;
};

int findOccurances(Node* head, int target){
    int i = 0;

    while (head != nullptr){
        if (head -> data == target){
            ++i;
        }

        head = head -> next;
    }

    return i;
}

int main(){
    Node* first = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* forth = new Node;
    Node* fifth = new Node;
    
    (*first).data = 10;
    second -> data = 20;
    third -> data = 40;
    forth -> data = 40;
    fifth -> data = 50;

    first -> next = second;
    second -> next = third;
    third -> next = forth;
    forth -> next = fifth;
    fifth -> next = nullptr;

    Node* head = first;

    int target = -1;
    cout << "Enter number to find occurances: ";
    cin >> target;

    cout << "The Number: " << target << " appeared " << findOccurances(head, target) << " times.";

    return 0;
}