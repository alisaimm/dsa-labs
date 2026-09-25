#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* mergeLinkedList(Node* headOne, Node* headTwo){
    Node* current = headOne;
    Node* newHead = new Node;
    Node* newCurrent = newHead;

    while (current != nullptr){
        newCurrent -> data = current -> data;

        newCurrent -> next = new Node;
        newCurrent = newCurrent -> next;

        current = current -> next;
    }

    current = headTwo;

    while (current != nullptr){
        newCurrent -> data = current -> data;

        newCurrent -> next = new Node;
        newCurrent = newCurrent -> next;

        current = current -> next;
    }

    return newHead;
}

int main(){

    // FIRST LINKED LIST
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

    // SECOND LINKED LIST
    Node* newFirst = new Node;
    Node* newSecond = new Node;
    Node* newThird = new Node;
    Node* newForth = new Node;
    Node* newFifth = new Node;
    
    (*newFirst).data = 10;
    newSecond -> data = 20;
    newThird -> data = 30;
    newForth -> data = 40;
    newFifth -> data = 50;

    newFirst -> next = second;
    newSecond -> next = third;
    newThird -> next = forth;
    newForth -> next = fifth;
    newFifth -> next = nullptr;

    Node* newHead = first;



    return 0;
}