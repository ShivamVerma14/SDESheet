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

Node* removeNodeFromEnd(Node* head, int k) {
    int count = 0;

    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    if (count == k) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    int rem = count - k;
    temp = head;
    while (rem != 0) {
        rem--;
        if (rem == 0)
            break;

        temp = temp->next;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
    return head;
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
    head = removeNodeFromEnd(head, 4);
    printList(head);

    return 0;
}