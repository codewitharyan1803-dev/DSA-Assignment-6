#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    Node* up;
    Node* down;

    Node(int val) {
        data = val;
        right = left = up = down = nullptr;
    }
};

Node* constructLinkedMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    if (m == 0) return nullptr;
    int n = mat[0].size();

    vector<vector<Node*>> node(m, vector<Node*>(n, nullptr));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            node[i][j] = new Node(mat[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (j + 1 < n)
                node[i][j]->right = node[i][j + 1];

            if (j - 1 >= 0)
                node[i][j]->left = node[i][j - 1];

            if (i + 1 < m)
                node[i][j]->down = node[i + 1][j];

            if (i - 1 >= 0)
                node[i][j]->up = node[i - 1][j];
        }
    }

    return node[0][0];
}

void printLinkedMatrix(Node* head, int m, int n) {
    Node* row = head;

    for (int i = 0; i < m; i++) {
        Node* col = row;
        for (int j = 0; j < n; j++) {
            cout << col->data << " ";
            col = col->right;
        }
        cout << endl;
        row = row->down;
    }
}

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    Node* head = constructLinkedMatrix(mat);

    cout << "\nDoubly Linked Matrix (row-wise):\n";
    printLinkedMatrix(head, m, n);

    return 0;
}
