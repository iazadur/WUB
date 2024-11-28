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
    Queue ticketQueue;

    // Add tickets to the queue
    ticketQueue.enqueue(1); // Ticket 1
    ticketQueue.enqueue(2); // Ticket 2
    ticketQueue.enqueue(3); // Ticket 3

    // Process tickets in FIFO order
    while (!ticketQueue.empty()) {
        cout << "Processing ticket: " << ticketQueue.front() << endl;
        ticketQueue.dequeue();
    }

    return 0;
}
