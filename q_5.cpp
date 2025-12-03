#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

bool isCircular(Node* head) {
    if (head == nullptr) return true; 

    Node* temp = head->next;
    while (temp != nullptr && temp != head) {
        temp = temp->next;
    }

    return (temp == head);
}

int main() {
    Node* head = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(30);

    head->next = second;
    second->next = third;
    third->next = head; 

    if (isCircular(head)) {
        cout << "The linked list is circular." << endl;
    } else {
        cout << "The linked list is NOT circular." << endl;
    }

    return 0;
}
