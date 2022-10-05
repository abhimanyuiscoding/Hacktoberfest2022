//Hacktoberfest2022

/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

*/


class Solution {
public:
    int check(TreeNode* root){
        if(root == NULL) return 0;
        
        int lh = check(root->left);
        if(lh == -1) return -1; // checking if the left subree at anypoint has diff -1
        
        int rh = check(root->right);
        if(rh == -1) return -1; // checking if the right subree at anypoint has diff -1
        
        // Returning -1 when the difference between a right subtree and left subtree is more than 1 then its not balance.
        if(abs(lh - rh) > 1) return -1;
        return 1+max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        return check(root) == -1 ? false : true;
    }
};


/*
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
*/
