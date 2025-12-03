#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void displayCircularList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);  
    cout << head->data << endl;
}

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

Node* head = nullptr;

Node* parity_check(Node* head){

    Node* temp = head;

    while (temp-> next != nullptr){
        
        int i = temp-> data;
        while(i > 0){
            
        }
    }
}
