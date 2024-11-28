#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Queue {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int sz = 0;

    void enqueue(int val) {
        Node* newNode = new Node(val);
        sz++;
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void dequeue() {
        if (!head) return;
        sz--;
        Node* deleteNode = head;
        head = head->next;
        if (!head) tail = NULL;
        delete deleteNode;
    }

    int front() {
        return head ? head->val : -1;
    }

    int size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    }
};

int main() {
    Queue taskQueue;

    // Enqueue tasks
    taskQueue.enqueue(101); // Task 101
    taskQueue.enqueue(102); // Task 102
    taskQueue.enqueue(103); // Task 103

    // Process tasks in FIFO order
    while (!taskQueue.empty()) {
        cout << "Processing task: " << taskQueue.front() << endl;
        taskQueue.dequeue();
    }

    return 0;
}
