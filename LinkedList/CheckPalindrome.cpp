#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr) {
        Node* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    return prev;
}

bool isPalindrome(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* newHead = reverse(slow->next);
    Node* temp = newHead;

    while (temp) {
        if (head->data != temp->data) {
            reverse(newHead);
            return false;
        }

        temp = temp->next;
        head = head->next;
    }

    return true;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);

    if (isPalindrome(head)) 
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

    return 0;
}