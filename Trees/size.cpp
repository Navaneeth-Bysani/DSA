#include<bits/stdc++.h>
using namespace std;

//Search for an element
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

int find_size(Node* root) {
    if(!root) return 0;
    int lheight = find_size(root->left);
    int rheight = find_size(root->right);
    return lheight + rheight + 1;
}

int size_recursion(Node* root) {
    if(!root) return 0; 
    int size = 0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        size++;
        if(temp->left) {
            q.push(temp->left);
        }
        if(temp->right) {
            q.push(temp->right);
        }
    }
    return size;
}

int main() {
    Node* root = createNode(5);
    insertNode(root, 6);
    insertNode(root, 7);
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);
    insertNode(root, 7);
    insertNode(root, 8);
    int size = find_size(root);
    cout << "size using recursion: ";
    cout << size << endl;
    int size_no_recur = size_recursion(root);
    cout << "size without recursion: ";
    cout << size_no_recur << endl;
}