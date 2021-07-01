#include<bits/stdc++.h>
using namespace std;

//Given preOrder and inOrder traversals create a Binary Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if(root == NULL) {
        root = createNode(data);
        return root;
    }
    Node* temp = root;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node*temp = q.front();
        q.pop();
        if(temp->left != NULL) {
            q.push(temp->left);
        } else {
            temp->left = createNode(data);
            return root;
        }
        if(temp->right != NULL) {
            q.push(temp->right);
        } else {
            temp->right = createNode(data);
            return root;
        }
    }
    return root;
}

int Search(vector<int> inOrder, int inorderstart, int inorderend, int val) {
    for(int i = inorderstart; i<=inorderend; i++) {
        if(inOrder[i] == val) return i;
    }
    return -1;
}

Node* construct(vector<int> inorder, vector<int> preorder, int inorderstart, int inorderend, int &preorderIDX) {
    Node* newNode = new Node();
    newNode->data = preorder[preorderIDX];
    preorderIDX++;
    if(inorderstart>inorderend) return NULL;
    if(inorderstart == inorderend) return newNode;
    int inorderIDX = Search(inorder, inorderstart, inorderend, newNode->data);
    newNode->left = construct(inorder,preorder,inorderstart,inorderIDX-1, preorderIDX);
    newNode->right = construct(inorder,preorder,inorderIDX+1,inorderend, preorderIDX);
    return newNode;
}

Node* constructBinaryTree(vector<int> inOrder, vector<int> preOrder) {
    int inorderstart = 0, inorderend = inOrder.size()-1, preorderIDX = 0;
    Node* root = construct(inOrder, preOrder, inorderstart, inorderend, preorderIDX);
    return root;
}

void preorder(Node* root) {
    if(root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main() {
    // Node* root = createNode(5);
    // insertNode(root, 6);
    // insertNode(root, 7);
    // insertNode(root, 1);
    // insertNode(root, 2);
    // insertNode(root, 3);
    // insertNode(root, 4);
    // insertNode(root, 10);
    // insertNode(root, 100);
    vector<int> inOrder = {3,1,4,0,5,2};
    vector<int> preOrder = {0,1,3,4,2,5};
    Node* root = constructBinaryTree(inOrder, preOrder);
    preorder(root);
}