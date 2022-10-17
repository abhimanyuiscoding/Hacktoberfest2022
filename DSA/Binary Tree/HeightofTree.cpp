#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *left,*right;
    node(int val){
        data=val;
        left=right=NULL;
    }
};
void preorder(struct node *root){
    if(root==NULL)
        return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int height(struct node *p){
    int x,y;
    if(p==NULL)
        return 0;
    else{
        x=height(p->left);
        y=height(p->right);
        return max(x,y)+1;
        // return x+y+p->data;
    }
}
int main()
{
    struct node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node (5);
    root->left->right->left=new node (5);
    root->right->left=new node(7);
    root->right->left->left=new node(11);
    root->right->left->left->left=new node(13);
    root->right->right=new node (8);
    root->right->right->right = new node(9);
    preorder(root);
    cout<<"\nHeight of BT:"<<height(root)<<endl;
    
    return 0;
}
