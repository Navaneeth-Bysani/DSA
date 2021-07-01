#include<bits/stdc++.h>
using namespace std;

//Find maximum element
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
void preorder(Node* root, int* Max) {
    if(root) {
        *Max = max(*Max,root->data);
        preorder(root->left, Max);
        preorder(root->right, Max);
    }
}
int find_max(Node* root) {
    int rmax,lmax,root_value, Max = INT_MIN;
    if(root != NULL) {
        root_value = root->data;
        rmax = find_max(root->right);
        lmax = find_max(root->left);
        Max = max({rmax,lmax,root_value});
    }
    return Max;
}

int find_max_iterative(Node* root) {
    int Max = INT_MIN;
    if(!root) return -1;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        Max = max(Max,temp->data);
        if(temp->left) {
            q.push(temp->left);
        } 
        
        if(temp->right) {
            q.push(temp->right);
        }
    }
    return Max;
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

    cout << "Preorder Traversal is: ";
    int Max = INT_MIN;
    preorder(root, &Max);
    cout << "Maximum element using preorder traversal: " << Max;
    cout << endl;
    int MaxNode = find_max(root);
    cout << "Maximum element in the tree is(using max in left sub tree and right sub tree): " << MaxNode << endl;
    int Max_iter = find_max_iterative(root);
    cout << "Maximum element using iterative approach (level order traversal): " << Max_iter << endl;
}