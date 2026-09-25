#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* mergeLinkedList(Node* headOne, Node* headTwo){
    Node* dummy = new Node;
    dummy -> next = NULL;
    Node* head = dummy;

    Node* current = headOne;

    while (current != NULL){
        Node* element = new Node;
        element -> data = current -> data;
        element -> next = NULL;

        dummy -> next = element;
        dummy = dummy -> next;

        current = current -> next;
    }

    current = headTwo;

    while (current != NULL){
        Node* element = new Node;
        element -> data = current -> data;
        element -> next = NULL;

        dummy -> next = element;
        dummy = dummy -> next;

        current = current -> next;
    }

    Node* finalHead = head -> next;
    delete head;
    return finalHead;
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
    
    (*newFirst).data = 60;
    newSecond -> data = 70;
    newThird -> data = 80;
    newForth -> data = 90;
    newFifth -> data = 100;

    newFirst -> next = newSecond;
    newSecond -> next = newThird;
    newThird -> next = newForth;
    newForth -> next = newFifth;
    newFifth -> next = nullptr;

    Node* newHead = newFirst;

    Node* mergedList = mergeLinkedList(head, newHead);

    Node* temp = mergedList;

    while (temp != NULL){
        cout << temp -> data << " --> ";
        temp = temp -> next;
    }

    return 0;
}