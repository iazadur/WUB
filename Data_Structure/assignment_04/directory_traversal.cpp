#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string val;
    Node* next;
    Node* prev;

    Node(string val) {
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

    void push(string val) {
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

    string top() {
        return tail ? tail->val : "Empty"; // Return "Empty" if stack is empty
    }

    int size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    }
};

int main() {
    Stack backStack, forwardStack;

    // Start in root directory
    backStack.push("root");
    cout << "Current directory: " << backStack.top() << endl;

    // Move to /home
    backStack.push("/home");
    cout << "Moved to directory: " << backStack.top() << endl;

    // Move to /home/user
    backStack.push("/home/user");
    cout << "Moved to directory: " << backStack.top() << endl;

    // Go back
    if (!backStack.empty()) {
        forwardStack.push(backStack.top());
        backStack.pop();
        cout << "Went back to directory: " << backStack.top() << endl;
    }

    // Go forward
    if (!forwardStack.empty()) {
        backStack.push(forwardStack.top());
        forwardStack.pop();
        cout << "Went forward to directory: " << backStack.top() << endl;
    }

    return 0;
}
