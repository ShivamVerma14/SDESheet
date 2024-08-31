#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int data) : data(data), next(nullptr), child(nullptr) {}
};

Node* merge(Node* head, Node* flattened) {
    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while (head && flattened) {
        if (head->data <= flattened->data) {
            temp->child = head;
            temp = head;
            head = head->child;
        } else {
            temp->child = flattened;
            temp = flattened;
            flattened = flattened->child;
        }

        temp->next = nullptr;
    }

    if (head) {
        temp->child = head;
    } else {
        temp->child = flattened;
    }

    if (dummy->child)
        dummy->child->next = nullptr;

    return dummy->child;
}

Node* flatten(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    
    Node* flattened = flatten(head->next);
    head = merge(head, flattened);
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(3);
    
    head->next = new Node(2);
    head->next->child = new Node(10);

    head->next->next = new Node(1);
    head->next->next->child = new Node(7);
    head->next->next->child->child = new Node(11);
    head->next->next->child->child->child = new Node(12);

    head->next->next->next = new Node(4);
    head->next->next->next->child = new Node(9);

    head->next->next->next->next = new Node(5);
    head->next->next->next->next->child = new Node(6);
    head->next->next->next->next->child->child = new Node(8);

    head = flatten(head);
    printList(head);

    return 0;
}