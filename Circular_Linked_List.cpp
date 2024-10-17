#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList(){
        head = nullptr;
    }

    void insertEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void deleteNode(int key) {
        if (head == nullptr) return;

        Node *temp = head, *prev = nullptr;

        if (temp->data == key && temp->next == head) {
            head = nullptr;
            delete temp;
            return;
        }

        if (temp->data == key) {
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            delete head;
            head = temp->next;
            return;
        }

        while (temp->next != head && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp->data == key) {
            prev->next = temp->next;
            delete temp;
        }
    }
};

int main() {
    CircularLinkedList cll;
    cout << "1. Insert at end\n2. Display\n3. Delete node\n4. Exit\n";
    while (true) {
        cout<<"Enter your choice: ";
        int choice;
        cin >> choice;
        if(choice==1){
            int value;
            cout << "Enter the value to insert: ";
            cin >> value;
            cll.insertEnd(value);
            cout << "Value inserted successfully.\n";
        }
        else if(choice==2){
            cout << "Circular Linked List: ";
            cll.display();
        }
        else if(choice==3){
            int value;
            cout << "Enter the value to delete: ";
            cin >> value;
            cll.deleteNode(value);
            cout << "Value deleted successfully.\n";
            cout << "After deleting "<< value<< "-> ";
            cll.display();
        }
        else if(choice==4){
            cout << "Exiting...\n";
            break;
        }
        else{
            cout << "Invalid choice. Please try again.\n";
        }
        cout << endl;
    }
    return 0;
}
