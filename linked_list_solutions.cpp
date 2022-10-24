// C++ program to merge two sorted 
// linked lists in-place.
#include <bits/stdc++.h>
using namespace std;
  
struct Node 
{
    int data;
    struct Node* next;
};
  
// Function to create newNode in 
// a linkedlist
struct Node* newNode(int key)
{
    struct Node* temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
  
// A utility function to print 
// linked list
void printList(struct Node* node)
{
    while (node != NULL) 
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}
  
// Merges two lists with headers as h1 
// and h2. It assumes that h1's data is 
// smaller than or equal to h2's data.
struct Node* mergeUtil(struct Node* h1,
                       struct Node* h2)
{
    // If only one node in first list
    // simply point its head to second list
    if (!h1->next) 
    {
        h1->next = h2;
        return h1;
    }
  
    // Initialize current and next pointers 
    // of both lists
    struct Node *curr1 = h1, 
                *next1 = h1->next;
    struct Node *curr2 = h2, 
                *next2 = h2->next;
  
    while (next1 && curr2) 
    {
        // if curr2 lies in between curr1 
        // and next1 then do curr1->curr2->next1
        if ((curr2->data) >= (curr1->data) && 
            (curr2->data) <= (next1->data)) 
        {
            next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;
  
            // now let curr1 and curr2 to point
            // to their immediate next pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else 
        {
            // if more nodes in first list
            if (next1->next) 
            {
                next1 = next1->next;
                curr1 = curr1->next;
            }
  
            // else point the last node of 
            // first list to the remaining 
            // nodes of second list
            else 
            {
                next1->next = curr2;
                return h1;
            }
        }
    }
    return h1;
}
  
// Merges two given lists in-place. 
// This function mainly compares head 
// nodes and calls mergeUtil()
struct Node* merge(struct Node* h1,
                   struct Node* h2)
{
    if (!h1)
        return h2;
    if (!h2)
        return h1;
  
    // start with the linked list
    // whose head data is the least
    if (h1->data < h2->data)
        return mergeUtil(h1, h2);
    else
        return mergeUtil(h2, h1);
}
  
// Driver code
int main()
{
    struct Node* head1 = newNode(1);
    head1->next = newNode(3);
    head1->next->next = newNode(5);
  
    // 1->3->5 LinkedList created
    struct Node* head2 = newNode(0);
    head2->next = newNode(2);
    head2->next->next = newNode(4);
  
    // 0->2->4 LinkedList created
    struct Node* mergedhead = merge(head1, head2);
  
    printList(mergedhead);
    return 0;
}

// Iterative C++ program to reverse a linked list
#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
 
struct LinkedList {
    Node* head;
    LinkedList() { head = NULL; }
 
    /* Function to reverse the linked list */
    void reverse()
    {
        // Initialize current, previous and next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
 
    /* Function to print linked list */
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
 
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};
 
/* Driver code*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
 
    cout << "Given linked list\n";
    ll.print();
 
    ll.reverse();
 
    cout << "\nReversed linked list \n";
    ll.print();
    return 0;
}

// C++ program to detect loop in a linked list
#include <bits/stdc++.h>
using namespace std;
  
/* Link list node */
struct Node {
    int data;
    struct Node* next;
};
  
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new Node;
  
    /* put in the data  */
    new_node->data = new_data;
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
  
// Returns true if there is a loop in linked list
// else returns false.
bool detectLoop(struct Node* h)
{
    unordered_set<Node*> s;
    while (h != NULL) {
        // If this node is already present
        // in hashmap it means there is a cycle
        // (Because you we encountering the
        // node for the second time).
        if (s.find(h) != s.end())
            return true;
  
        // If we are seeing the node for
        // the first time, insert it in hash
        s.insert(h);
  
        h = h->next;
    }
  
    return false;
}
  
/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
  
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
  
    /* Create a loop for testing */
    head->next->next->next->next = head;
  
    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
  
    return 0;
}
