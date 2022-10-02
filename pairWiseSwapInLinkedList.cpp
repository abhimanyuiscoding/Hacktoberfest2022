#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
#define ll long long
#define sc ;
#define tc ll t sc cin >> t sc while (t--)
#define fast ios::sync_with_stdio(false)
#define spyder cin.tie(NULL)

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

Node *pairWiseSwap(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *curr = head->next->next;
    Node *prev = head;
    head = head->next;
    head->next = prev;
    while (curr != NULL && curr->next != NULL)
    {
        prev->next = curr->next;
        prev = curr;
        Node *next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }
    prev->next = curr;
    return head;
}

void printList(Node *head)
{
    if (head == NULL)
        return;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(3);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(23);
    printList(head);
    cout << endl;
    Node *newHead = pairWiseSwap(head);
    printList(newHead);

    return 0;
}