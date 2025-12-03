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

int main() {
    Node* head = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(30);

    head->next = second;
    second->next = third;
    third->next = head; 

    displayCircularList(head);

    return 0;
}
