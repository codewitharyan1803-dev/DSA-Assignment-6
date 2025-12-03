#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void correctRandomPointer(Node*& head) {
    if (!head || !head->next)
        return;

    Node* temp = head;

    while (temp && temp->next) {
        if (temp->next->prev != temp) {
            cout << "\nError detected between nodes: "
                 << temp->data << " and " << temp->next->data << endl;

            Node* correctNext = temp->next;
            Node* nextNode = correctNext->prev; 
            
            if (nextNode && nextNode->next == temp) {
                temp->next = nextNode;
                nextNode->prev = temp;
                cout << "Pointers swapped and corrected.\n";
            } else {
                correctNext->prev = temp;
                cout << "Prev pointer corrected.\n";
            }
            return;
        }
        temp = temp->next;
    }

    cout << "\nNo broken link found — list already consistent.\n";
}

int main() {
    Node* head = nullptr;

    for (int i = 1; i <= 5; i++)
        insertEnd(head, i);

    cout << "Original Doubly Linked List:\n";
    printList(head);

    Node* temp = head->next->next; 
    temp->prev = head;             

    cout << "\nList with random pointer error introduced.\n";
    correctRandomPointer(head);

    cout << "\nCorrected List (Forward Traversal):\n";
    printList(head);

    return 0;
}
