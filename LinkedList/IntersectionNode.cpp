#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}
};

int findDifferenceInLength(Node* listA, Node* listB) {
    int lenA = 0;
    while (listA != nullptr) {
        lenA++;
        listA = listA->next;
    }

    int lenB = 0;
    while (listB != nullptr) {
        lenB++;
        listB = listB->next;
    }

    return lenA - lenB;
}

Node* findIntersection(Node* listA, Node* listB) {
    int diff = findDifferenceInLength(listA, listB);

    if (diff > 0)
        while (diff--)
            listA = listA->next;
    else
        while (diff++)
            listB = listB->next;

    while (listA != nullptr) {
        if (listA == listB)
            return listA;

        listA = listA->next;
        listB = listB->next;
    }

    return listA;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* listA = new Node(1);
    listA->next = new Node(3);
    listA->next->next = new Node(1);
    listA->next->next->next = new Node(2);
    listA->next->next->next->next = new Node(4);

    Node* listB = new Node(3);
    listB->next = listA->next->next->next;

    printList(listA);
    printList(listB);

    Node* ans = findIntersection(listA, listB);
    cout << ans->val << endl;

    return 0;
}