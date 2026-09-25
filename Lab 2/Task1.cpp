#include <iostream>

using namespace std;

struct Node {
    Node* next;
    int data;
};

void printReverse(Node* current){
    
    if (current != nullptr){
        printReverse(current -> next);

        cout << current -> data << " ";
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

    printReverse(head);

    return 0;
}