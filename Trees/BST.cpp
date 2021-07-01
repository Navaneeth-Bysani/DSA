#include <bits/stdc++.h>
using namespace std;

struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

BSTNode* createNode(int data) {
    BSTNode* newNode = new BSTNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BSTNode* insertNode(BSTNode* root, int data) {
    if(root == NULL) {
        root = createNode(data);
    } else {
        BSTNode* temp = root;
        while(temp) {
            if(data < temp->data) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }

        root = createNode(data);
    }

    return root;
}

void inorder(BSTNode* root) {
    if(root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int main() {
    BSTNode* root = new BSTNode();
    root = NULL;
    insertNode(root, 5);
    cout << root->data << endl;
    insertNode(root, 10);
    insertNode(root, 56);
    insertNode(root, 4);
    insertNode(root, 2);
    insertNode(root, 54);
    insertNode(root, 1);
    inorder(root);
}