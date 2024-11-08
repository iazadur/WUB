#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string title;
    string artist;
    int duration; // in seconds
    Node *next;
    Node *prev;
    Node(string title, string artist, int duration) {
        this->title = title;
        this->artist = artist;
        this->duration = duration;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_playlist_normal(Node *head) {
    Node *temp = head;
    if (temp == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }
    cout << "Playlist (Normal Order):\n";
    while (temp != NULL) {
        cout << "Title: " << temp->title << ", Artist: " << temp->artist 
             << ", Duration: " << temp->duration << " sec\n";
        temp = temp->next;
    }
    cout << endl;
}

void print_playlist_reverse(Node *tail) {
    Node *temp = tail;
    if (temp == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }
    cout << "Playlist (Reverse Order):\n";
    while (temp != NULL) {
        cout << "Title: " << temp->title << ", Artist: " << temp->artist 
             << ", Duration: " << temp->duration << " sec\n";
        temp = temp->prev;
    }
    cout << endl;
}

void add_song(Node *&head, Node *&tail, string title, string artist, int duration) {
    Node *newSong = new Node(title, artist, duration);
    if (head == NULL) {
        head = tail = newSong;
    } else {
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }
    cout << "Song added: " << title << " by " << artist << "\n";
}

void delete_song(Node *&head, Node *&tail, string title) {
    Node *temp = head;
    while (temp != NULL && temp->title != title) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        cout << "Song not found: " << title << "\n";
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; // Head node case
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev; // Tail node case
    }

    delete temp;
    cout << "Song deleted: " << title << "\n";
}

void move_song(Node *&head, Node *&tail, string title, int newPos) {
    Node *temp = head;
    int pos = 1;
    
    while (temp != NULL && temp->title != title) {
        temp = temp->next;
        pos++;
    }
    
    if (temp == NULL || newPos <= 0) {
        cout << "Song not found or invalid position.\n";
        return;
    }

    // Remove the node from its current position
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev;
    }

    // Insert at new position
    Node *insertPos = head;
    for (int i = 1; insertPos != NULL && i < newPos - 1; i++) {
        insertPos = insertPos->next;
    }

    if (insertPos == NULL) { // Move to end
        tail->next = temp;
        temp->prev = tail;
        temp->next = NULL;
        tail = temp;
    } else if (newPos == 1) { // Move to beginning
        temp->next = head;
        head->prev = temp;
        head = temp;
        temp->prev = NULL;
    } else { // Insert in between
        temp->next = insertPos->next;
        if (insertPos->next != NULL) {
            insertPos->next->prev = temp;
        }
        temp->prev = insertPos;
        insertPos->next = temp;
        if (temp->next == NULL) tail = temp; // Update tail if needed
    }

    cout << "Song moved to position " << newPos << ": " << title << "\n";
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    add_song(head, tail, "Song A", "Artist 1", 210);
    add_song(head, tail, "Song B", "Artist 2", 180);
    add_song(head, tail, "Song C", "Artist 3", 240);
    
    cout << "\n";
    print_playlist_normal(head);
    print_playlist_reverse(tail);
    cout << "\n";

    delete_song(head, tail, "Song B");

    cout << "\n";
    print_playlist_normal(head);
    print_playlist_reverse(tail);
    cout << "\n";

    move_song(head, tail, "Song C", 1);

    cout << "\n";
    print_playlist_normal(head);
    print_playlist_reverse(tail);

    return 0;
}
