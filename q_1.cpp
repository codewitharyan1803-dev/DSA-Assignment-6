#include <iostream>
using namespace std;

// DOUBLY LINKED LIST
struct DNode {
    int data;
    DNode *prev, *next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    DNode* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Node not found.\n";
            return;
        }
        DNode* newNode = new DNode(val);
        newNode->next = temp->next;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Node not found.\n";
            return;
        }
        DNode* newNode = new DNode(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(int key) {
        if (!head) return;
        DNode* temp = head;

        if (head->data == key) {
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            return;
        }

        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Node not found.\n";
            return;
        }

        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;
        delete temp;
    }

    void searchNode(int key) {
        DNode* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found.\n";
    }

    void display() {
        DNode* temp = head;
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// CIRCULAR LINKED LIST
struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
    CNode* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        CNode* newNode = new CNode(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        CNode* newNode = new CNode(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAfter(int key, int val) {
        if (!head) return;
        CNode* temp = head;
        do {
            if (temp->data == key) {
                CNode* newNode = new CNode(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found.\n";
    }

    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        CNode* temp = head;
        CNode* prev = nullptr;
        do {
            if (temp->data == key) {
                CNode* newNode = new CNode(val);
                newNode->next = temp;
                prev->next = newNode;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found.\n";
    }

    void deleteNode(int key) {
        if (!head) return;

        if (head->data == key) {
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }
            CNode* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = head->next;
            delete head;
            head = temp->next;
            return;
        }

        CNode* temp = head;
        CNode* prev = nullptr;
        do {
            if (temp->data == key) {
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "Node not found.\n";
    }

    void searchNode(int key) {
        if (!head) return;
        CNode* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node not found.\n";
    }

    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        CNode* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }
};


int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, val, key, type;

    while (true) {
        cout << "\nChoose List Type:\n1. Doubly Linked List\n2. Circular Linked List\n3. Exit\nEnter choice: ";
        cin >> type;
        if (type == 3) break;

        cout << "\nMenu:\n"
             << "1. Insert at Beginning\n"
             << "2. Insert at End\n"
             << "3. Insert After a Node\n"
             << "4. Insert Before a Node\n"
             << "5. Delete a Node\n"
             << "6. Search a Node\n"
             << "7. Display\n"
             << "8. Back to List Selection\n"
             << "Enter choice: ";
        cin >> choice;

        if (choice == 8) continue;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                (type == 1) ? dll.insertAtBeginning(val) : cll.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                (type == 1) ? dll.insertAtEnd(val) : cll.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter key and value: ";
                cin >> key >> val;
                (type == 1) ? dll.insertAfter(key, val) : cll.insertAfter(key, val);
                break;
            case 4:
                cout << "Enter key and value: ";
                cin >> key >> val;
                (type == 1) ? dll.insertBefore(key, val) : cll.insertBefore(key, val);
                break;
            case 5:
                cout << "Enter key to delete: ";
                cin >> key;
                (type == 1) ? dll.deleteNode(key) : cll.deleteNode(key);
                break;
            case 6:
                cout << "Enter key to search: ";
                cin >> key;
                (type == 1) ? dll.searchNode(key) : cll.searchNode(key);
                break;
            case 7:
                (type == 1) ? dll.display() : cll.display();
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}
