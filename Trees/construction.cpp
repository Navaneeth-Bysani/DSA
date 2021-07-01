#include<bits/stdc++.h>
using namespace std;

//Given a tree with a special property where leaves are represented with ‘L’ and
// internal node with ‘I’. Also, assume that each node has either 0 or 2 children. Given
// preorder traversal of this tree, construct the tree.

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


Node* construct(vector<char> A, int &i) {
    Node* newNode = new Node();
    newNode->data = A[i] == 'L' ? 0 : 1;
    newNode->left = newNode->right = NULL;
    if(&A == NULL) return NULL;
    if(A[i] == 'L') return newNode;

    i++;
    newNode->left = construct(A, i);
    i++;
    newNode->right = construct(A, i);
    return newNode;
}

void preorder(Node* root) {
    if(root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main() {
    vector<char> A = {'I','L','I','L','L'};
    int index = 0;
    Node* root = construct(A,index);
    preorder(root);
}