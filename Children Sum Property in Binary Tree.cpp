//Change the tree to children sum property

#include <bits/stdc++.h> 
void changeTree(BinaryTreeNode < int > * root) {
    if(root==NULL){
        return;
    }
    int child=0;
    if(root->left){
        child+=root->left->data;
    }
    if(root->right){
        child+=root->right->data;
    }

    if(child>=root->data) root->data=child;
    else if(root->left) root->left->data=root->data;
    else if(root->right) root->right->data=root->data;

    changeTree(root->left);
    changeTree(root->right);

    int tot=0;
    if(root->left) tot+=root->left->data;
    if(root->right) tot+=root->right->data;
    if(root->left || root->right) root->data=tot;
}

//checking if tree is following children sum property

class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(root==NULL){
            return false;
        }
        int child=0;
        if(root->left){
            child+=root->left->val;
        }
        if(root->right){
            child+=root->right->val;
        }
        checkTree(root->left);
        checkTree(root->right);
        if(child==root->val){
            return true;
        }
        return false;
    }
};
