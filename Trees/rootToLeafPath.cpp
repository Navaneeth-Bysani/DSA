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
void preorder(Node* root, int* Max) {
    if(root) {
        *Max = max(*Max,root->data);
        preorder(root->left, Max);
        preorder(root->right, Max);
    }
}

void printPath(vector<int> path, int pathLen) {
    for(int i = 0; i<pathLen; i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}

void RootToLeaf(Node* root, vector<int> &path, int pathLen) {
    if(!root) {
        return;
    }
    path[pathLen] = root->data;
    pathLen++;
    if(!root->left && !root->right) {
        printPath(path,pathLen);
    } else {
        RootToLeaf(root->left, path, pathLen);
        RootToLeaf(root->right, path, pathLen);
    }
}

int find_sum(vector<int> path, int pathLen) {
    int sum = 0;
    for(int i = 0; i<pathLen; i++) {
        sum += path[i];
    }
    return sum;
}
bool PathSum(Node* root, vector<int> &path, int pathLen, int sum) {
    if(!root) {
        return 0;
    }    
    path[pathLen] = root->data;
    pathLen++;
    if(sum == find_sum(path, pathLen)) {
        return 1;
    } else {
        PathSum(root->left, path, pathLen, sum);
        PathSum(root->right, path, pathLen, sum);
    }
    // return 0;
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
    vector<int> path(9);
    int pathLen = 0;
    RootToLeaf(root, path, pathLen);
    int sum = 112;
    if(PathSum(root,path,0,sum)) {
        cout << "Path exists" << endl;
    } else {
        cout << "Such Path don't exist" << endl;
    }
}



// class Solution {
// public:
//     vector<vector<int>> pathSum(TreeNode* root, int sum) {
//         vector<vector<int> > paths;
//         vector<int> path;
//         findPaths(root, sum, path, paths);
//         return paths;  
//     }
// private:
//     void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
//         if (!node) return;
//         path.push_back(node -> val);
//         if (!(node -> left) && !(node -> right) && sum == node -> val)
//             paths.push_back(path);
//         findPaths(node -> left, sum - node -> val, path, paths);
//         findPaths(node -> right, sum - node -> val, path, paths);
//         path.pop_back();
//     }
// };