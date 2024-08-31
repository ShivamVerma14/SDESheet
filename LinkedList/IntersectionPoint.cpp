#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

int diffInLength(Node *listA, Node *listB)
{
    int countA = 0;
    while (listA != nullptr)
    {
        countA++;
        listA = listA->next;
    }

    int countB = 0;
    while (listB != nullptr)
    {
        countB++;
        listB = listB->next;
    }

    return countA - countB;
}

Node *findIntersectionNode(Node *listA, Node *listB)
{
    int diff = diffInLength(listA, listB);

    if (diff > 0)
        while (diff--)
            listA = listA->next;
    else
        while (diff++)
            listB = listB->next;

    while (listA != nullptr)
    {
        if (listA == listB)
            return listA;

        listA = listA->next;
        listB = listB->next;
    }

    return nullptr;
}

int main()
{
    Node *listA = new Node(1);
    listA->next = new Node(3);
    listA->next->next = new Node(3);
    listA->next->next->next = new Node(2);
    listA->next->next->next->next = new Node(4);

    Node *listB = new Node(6);
    listB->next = listA->next->next->next;

    Node *ans = findIntersectionNode(listA, listB);
    cout << ans->data << endl;

    return 0;
}