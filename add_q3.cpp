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

Node* reverseInGroups(Node* head, int k) {
    if (!head || k <= 1)
        return head;

    Node* current = head;
    Node* newHead = nullptr;
    Node* groupPrevTail = nullptr;

    while (current) {
        Node* groupHead = current;
        Node* prev = nullptr;
        int count = 0;

        while (current && count < k) {
            Node* nextNode = current->next;
            current->next = prev;
            current->prev = nextNode;
            prev = current;
            current = nextNode;
            count++;
        }

        if (!newHead)
            newHead = prev;

        if (groupPrevTail) {
            groupPrevTail->next = prev;
            prev->prev = groupPrevTail;
        }

        groupPrevTail = groupHead;
    }

    return newHead;
}

int main() {
    Node* head = nullptr;
    int n, k;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertEnd(head, val);
    }

    cout << "Enter group size k: ";
    cin >> k;

    cout << "\nOriginal List: ";
    printList(head);

    head = reverseInGroups(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
