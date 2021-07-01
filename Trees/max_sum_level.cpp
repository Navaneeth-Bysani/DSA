#include<bits/stdc++.h>
using namespace std;

//Find the level with maximum sum of elements
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

int max_level_sum(Node* root) {
    int maxSum = 0, currSum = 0;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int currLevel = 0, maxLevel = 0;
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL) {
            if(currSum > maxSum) {
                maxSum = currSum;
                maxLevel = currLevel;
            }
            if(!q.empty()) {
                q.push(NULL);
            }
            currLevel++;
            currSum = 0;
        } else {
            currSum += temp->data;
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }

    cout << "Max sum is: " << maxSum << " occurred at level: " << maxLevel << endl;
    return maxLevel;
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
    
    int sum = max_level_sum(root);
}