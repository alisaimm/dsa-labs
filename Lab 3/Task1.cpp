#include <iostream>

using namespace std;

struct Node {
    Node* next;
    int data;
};

void printReverse(Node* current){
    
    if (current != nullptr){
        printReverse(current -> next);

        cout << current -> data << " --> ";
    }
}

void reverseAndDisplay(Node* head){
    Node* current = head;
    Node* prev = NULL;
    Node* realNext = NULL;

    while (current != NULL){
        realNext = current -> next;

        current -> next = prev;

        prev = current;

        current = realNext;
    }

    current = prev;

    while (current != NULL){
        cout << current -> data << " --> ";

        current = current -> next;
    }

}

int main(){
    Node* first = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* forth = new Node;
    Node* fifth = new Node;
    
    
    (*first).data = 10;
    second -> data = 20;
    third -> data = 30;
    forth -> data = 40;
    fifth -> data = 50;

    first -> next = second;
    second -> next = third;
    third -> next = forth;
    forth -> next = fifth;
    fifth -> next = nullptr;

    Node* head = first;

    cout << "PRINT REVERSE BY RECURSION:\n";
    printReverse(head);

    cout << "\n\n";

    cout << "PRINT REVERSE BY LOOP:\n";
    reverseAndDisplay(head);

    return 0;
}