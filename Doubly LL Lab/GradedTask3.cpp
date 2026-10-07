#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Pop {
    int data;
    Pop* next;
    Pop* prev;
};

void convertToDoubly(Node* singlyHead, Pop*& doublyHead){
    if (singlyHead == NULL) return;

    Pop* prevEle = NULL;
    Node* currentEle = singlyHead;
    
    
    while (currentEle != NULL){
        Pop* temp = new Pop;
        temp -> data = currentEle -> data;
        temp -> prev = prevEle;
        temp -> next = NULL;

        if (doublyHead == NULL){
            doublyHead = temp;
        } else {
            prevEle -> next = temp;
        }
        
        prevEle = temp;

        currentEle = currentEle -> next;
    }
}

int main(){


    return 0;
}