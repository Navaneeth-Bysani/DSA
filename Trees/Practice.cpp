#include <bits/stdc++.h>
using namespace std;

struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

struct BinaryTreeNode createNode(int data) {
    struct BinaryTreeNode newNode;
    newNode.data = data;
    newNode.left = NULL;
    newNode.right = NULL;
    return newNode;
}

void preorder(struct BinaryTreeNode* root) {
    if(root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main() {
    struct BinaryTreeNode root = createNode(1);
    cout << root.data << endl;
    root.left = &createNode(2);
    root.right = &createNode(3);
    struct BinaryTreeNode *temp = root.left;
    temp->left = &createNode(4);
    temp->right = &createNode(5);

    temp = root.right;
    temp->left = &createNode(6);
    temp->right = &createNode(7);

    preorder(&root);
    cout << endl;
}