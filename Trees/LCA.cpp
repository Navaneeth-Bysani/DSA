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

Node* LCA(Node* root, Node* A, Node* B) {
    Node *left, *right;
    if(root == NULL) return root;
    if(root == A || root == B) return root;
    left = LCA(root->left, A, B);
    right = LCA(root->right, A, B);
    if(left && right) {
        return root;
    }  else {
        return (left?left:right);
    }
}
bool All_Ancestors(Node* root, Node* node) {
    if(root == NULL) return 0;
    if(root->left == node || root->right == NULL  || All_Ancestors(root->left, node) || All_Ancestors(root->right, node)) {
        cout << root->data << " ";
        return 1;
    }
    return 0;
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
    Node* A = root->left->left->right;
    Node* B = root->right->left;
    Node* Common_Ancestor = LCA(root,A,B);
    cout << "Common Ancestor is: " << Common_Ancestor->data << endl;
    Node* node = root->left->left->left;
    cout << "All ancestors of given Node: ";
    All_Ancestors(root,node);
}