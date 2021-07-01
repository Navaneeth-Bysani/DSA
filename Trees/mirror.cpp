#include<bits/stdc++.h>
using namespace std;

//Find all root to leaf paths
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
void preorder(Node* root) {
    if(root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

Node* Mirror(Node* root) {
    if(root) {
        Mirror(root->left);
        Mirror(root->right);
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return root;
}

int main() {
    Node* root = createNode(5);
    insertNode(root, 6);
    insertNode(root, 7);
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 10);
    insertNode(root, 100);
    cout << "Original preorder: ";
    preorder(root);
    cout << endl;
    cout << "Preorder after Mirroring the tree: ";
    Mirror(root);
    preorder(root);
}