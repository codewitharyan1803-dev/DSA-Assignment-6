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

Node* head = nullptr;

Node* split_list(Node* head){
    
    Node* slow = head;
    Node* fast = head;
    int length = 0;

    while (slow->next != head && fast->next->next != head){
        slow = slow->next;
        fast = fast->next->next;
        length++;

    }
    if (fast->next->next == head){
        fast = fast->next;
    }

    Node* head1_ref = head;
    if (head->next != head)
        Node* head2_ref = slow->next;

    fast->next = slow->next;
    slow->next = head;
}

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

int main(){
    Node* newnode;
}