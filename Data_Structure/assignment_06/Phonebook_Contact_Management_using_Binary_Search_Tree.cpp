#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string name;
    string phone;
    Node *left;
    Node *right;

    Node(string name, string phone)
    {
        this->name = name;
        this->phone = phone;
        this->left = NULL;
        this->right = NULL;
    }
};

class Phonebook
{
public:
    Node *root;

    Phonebook()
    {
        root = NULL;
    }

    Node *insert(Node *current, string name, string phone)
    {
        if (current == NULL)
        {
            return new Node(name, phone);
        }
        if (name < current->name)
        {
            current->left = insert(current->left, name, phone);
        }
        else if (name > current->name)
        {
            current->right = insert(current->right, name, phone);
        }
        return current;
    }

    void addContact(string name, string phone)
    {
        root = insert(root, name, phone);
    }

    Node *search(Node *current, string name)
    {
        if (current == NULL || current->name == name)
        {
            return current;
        }
        if (name < current->name)
        {
            return search(current->left, name);
        }
        else
        {
            return search(current->right, name);
        }
    }

    void searchContact(string name)
    {
        Node *result = search(root, name);
        if (result != NULL)
        {
            cout << "Contact found: " << result->name << " (" << result->phone << ")" << endl;
        }
        else
        {
            cout << "Contact not found!" << endl;
        }
    }

    void preorderTraversal(Node *current)
    {
        if (current == NULL)
            return;
        cout << current->name << " (" << current->phone << ")" << endl;
        preorderTraversal(current->left);
        preorderTraversal(current->right);
    }

    void inorderTraversal(Node *current)
    {
        if (current == NULL)
            return;
        inorderTraversal(current->left);
        cout << current->name << " (" << current->phone << ")" << endl;
        inorderTraversal(current->right);
    }

    void postorderTraversal(Node *current)
    {
        if (current == NULL)
            return;
        postorderTraversal(current->left);
        postorderTraversal(current->right);
        cout << current->name << " (" << current->phone << ")" << endl;
    }

    void displayPreorder()
    {
        cout << "\nPreorder Traversal (Contacts as entered):" << endl;
        preorderTraversal(root);
    }

    void displayInorder()
    {
        cout << "\nInorder Traversal (Contacts in alphabetical order):" << endl;
        inorderTraversal(root);
    }

    void displayPostorder()
    {
        cout << "\nPostorder Traversal (Safe deletion order):" << endl;
        postorderTraversal(root);
    }
};

int main()
{
    Phonebook phonebook;
    int n;
    cout << "Enter number of contacts: ";
    cin >> n;
    cin.ignore(); // Consume the newline character

    for (int i = 0; i < n; i++)
    {
        string name, phone;
        cout << "Enter contact " << i + 1 << " name: ";
        getline(cin, name);
        cout << "Enter contact " << i + 1 << " phone number: ";
        getline(cin, phone);
        phonebook.addContact(name, phone);
    }

    phonebook.displayPreorder();
    phonebook.displayInorder();
    phonebook.displayPostorder();

    string searchName;
    cout << "\nEnter a name to search for: ";
    getline(cin, searchName);
    phonebook.searchContact(searchName);

    return 0;
}
