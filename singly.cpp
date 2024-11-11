#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor to create a new node with given data
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor to initialize an empty list
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at a given position
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Position should be 1 or greater." << endl;
            return;
        }

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position out of bounds." << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete from the beginning
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from the end
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete from a given position
    void deleteFromPosition(int position) {
        if (position < 1) {
            cout << "Position should be 1 or greater." << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of bounds." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, position;

    while (true) {
        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n7. Display List\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert and position: ";
                cin >> value >> position;
                list.insertAtPosition(value, position);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position to delete from: ";
                cin >> position;
                list.deleteFromPosition(position);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
