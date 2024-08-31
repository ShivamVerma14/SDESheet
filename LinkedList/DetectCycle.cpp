#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

Node *detectCycle(Node *list)
{
    Node *slow = list;
    Node *fast = list;

    bool flag = false;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            flag = true;
            break;
        }
    }

    if (!flag)
        return nullptr;

    fast = list;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main()
{
    Node *list = new Node(1);
    list->next = new Node(2);
    list->next->next = new Node(3);
    list->next->next->next = new Node(4);
    list->next->next->next->next = new Node(5);
    list->next->next->next->next = list->next->next;

    Node *ans = detectCycle(list);
    if (ans != nullptr)
    {
        cout << ans->data << endl;
    }
    else
    {
        cout << "No cycle" << endl;
    }

    return 0;
}