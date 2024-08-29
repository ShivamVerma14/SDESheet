#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* reverse(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
        
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    return prev;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    printList(head);
    head = reverse(head);
    printList(head);

    return 0;
}