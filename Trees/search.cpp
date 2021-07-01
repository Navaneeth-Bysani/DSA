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

bool Search(Node* root, int key) {
    if(!root) return 0;
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if(temp->data == key) {
            return 1;
        }
        if(temp->left) {
            q.push(temp->left);
        }
        if(temp->right) {
            q.push(temp->right);
        }
    }
    return 0;
}

bool Search_recurse(Node* root, int key) {
    if(!root) return 0;
    Node* temp = root;
    if(temp->data == key) {
        return 1;
    } else {
        int val = Search_recurse(root->left, key);
        if(val != 0) return val;
        else return Search_recurse(root->right, key);
    }
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

    int key = 4;
    bool Exist = Search(root, key);
    cout << "Using Iteration: " << endl;
    if(Exist) {
        cout << "Found the key value" << endl;
    } else {
        cout << "Couldn't find the given key value" << endl;
    }
    bool Exist2 = Search_recurse(root, key);
    cout << "Using recursion: " << endl;
    if(Exist2) {
        cout << "Found the key value" << endl;
    } else {
        cout << "Couldn't find the given key value" << endl;
    }
}