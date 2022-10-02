#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *left;
    node *right;
    int data;
};

node *createnode(int number) // for creating the node
{
    node *root = new node;
    root->data = number;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void InOrderTraversal(node *root)
{
    if (root != NULL)
    {
        InOrderTraversal(root->left);
        cout<<root->data<<endl;
        InOrderTraversal(root->right);
    }
}

int main()
{
    node *head = createnode(5);
    node *p1 = createnode(3);
    node *p2 = createnode(6);
    node *p3 = createnode(1);
    node *p4 = createnode(4);

    // created  the binary search tree.
    head->left = p1;
    head->right = p2;

    p1->left = p3;
    p1->right = p4;

    InOrderTraversal(head);

    return 0;


}