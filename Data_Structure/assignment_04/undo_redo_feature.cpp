#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Stack {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int sz = 0;

    void push(int val) {
        Node* newNode = new Node(val);
        sz++;
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void pop() {
        if (!tail) return;
        sz--;
        Node* deleteNode = tail;
        tail = tail->prev;
        if (tail) tail->next = NULL;
        else head = NULL;
        delete deleteNode;
    }

    int top() {
        return tail ? tail->val : -1; // Return -1 if stack is empty
    }

    int size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    }
};

int main() {
    Stack undo, redo;

    // Perform write actions
    undo.push(1); // Write action 1
    undo.push(2); // Write action 2
    cout << "Performed actions: 1, 2\n";

    // Undo the last action
    if (!undo.empty()) {
        int action = undo.top();
        undo.pop();
        redo.push(action);
        cout << "Undo action: " << action << endl;
    }

    // Redo the last undone action
    if (!redo.empty()) {
        int action = redo.top();
        redo.pop();
        undo.push(action);
        cout << "Redo action: " << action << endl;
    }

    return 0;
}
 