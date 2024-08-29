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

Node* merge(Node* listA, Node* listB) {
    Node* dummy = new Node(-1);
    Node* temp = dummy;

    Node* ta = listA;
    Node* tb = listB;

    while (ta != nullptr && tb != nullptr) {
        if (ta->data <= tb->data) {
            temp->next = new Node(ta->data);
            ta = ta->next;
        }
        else {
            temp->next = new Node(tb->data);
            tb = tb->next;
        }
        temp = temp->next;
    }

    if (ta != nullptr)
        temp->next = ta;
    else
        temp->next = tb;

    return dummy->next;
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
    Node* listA = new Node(2);
    listA->next = new Node(4);
    listA->next->next = new Node(8);
    listA->next->next->next = new Node(10);

    Node* listB = new Node(1);
    listB->next = new Node(3);
    listB->next->next = new Node(3);
    listB->next->next->next = new Node(6);
    listB->next->next->next->next = new Node(11);
    listB->next->next->next->next->next = new Node(14);

    Node* merged = merge(listA, listB);
    printList(merged);

    return 0;
}