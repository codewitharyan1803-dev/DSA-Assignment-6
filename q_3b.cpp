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

int getSize(Node* head) {
    if (head == nullptr) {
        return 0;
    }

    int count = 1; 
    Node* temp = head->next;

    while (temp != head) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    Node* head = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(30);

    head->next = second;
    second->next = third;
    third->next = head; 

    cout << "Size of Circular Linked List: " << getSize(head) << endl;

    return 0;
}
