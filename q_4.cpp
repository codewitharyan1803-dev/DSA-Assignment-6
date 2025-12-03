#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

Node* createNode(char value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

bool isPalindrome(Node* head) {
    if (head == nullptr) {
        return true;
    }

    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    while (head != tail && head->prev != tail) {
        if (head->data != tail->data) {
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    Node* head = createNode('r');
    Node* second = createNode('a');
    Node* third = createNode('d');
    Node* fourth = createNode('a');
    Node* fifth = createNode('r');

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    if (isPalindrome(head)) {
        cout << "The doubly linked list is a palindrome." << endl;
    } else {
        cout << "The doubly linked list is NOT a palindrome." << endl;
    }

    return 0;
}
