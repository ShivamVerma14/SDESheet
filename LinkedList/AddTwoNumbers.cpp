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

Node* add(Node* numA, Node* numB) {
    Node* dummy = new Node(-1);
    Node* temp = dummy;

    Node* ta = numA;
    Node* tb = numB;
    int carry = 0;

    while (ta != nullptr || tb != nullptr || carry) {
        int sum = 0;

        if (ta != nullptr) {
            sum += ta->data;
            ta = ta->next;
        }

        if (tb != nullptr) {
            sum += tb->data;
            tb = tb->next;
        }

        sum += carry;
        carry = sum / 10;
        sum %= 10;

        temp->next = new Node(sum);
        temp = temp->next;
    }

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
    Node* numA = new Node(9);
    numA->next = new Node(9);
    numA->next->next = new Node(9);

    Node* numB = new Node(9);
    numB->next = new Node(9);
    numB->next->next = new Node(9);
    numB->next->next->next = new Node(9);
    numB->next->next->next->next = new Node(9);

    Node* res = add(numA, numB);
    printList(res);

    return 0;
}