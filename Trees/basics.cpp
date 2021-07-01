#include <bits/stdc++.h>
using namespace std;

//BASIC OPERATIONS OF TREE
//insertion in levelOrder form
//Traversals:
//1. PreOrder
//2. InOrder
//3. PostOrder
//4. LevelOrder
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

Node* createNode(int data) {
    Node *newNode = new Node();
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

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if(temp-> left != NULL) {
            q.push(temp->left);
        } else {
            temp -> left = createNode(data);
            return root;
        }

        if(temp-> right != NULL) {
            q.push(temp->right);
        } else {
            temp -> right = createNode(data);
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

void preorderIterative(Node* root) {
    if(root == NULL) {
        return;
    }
    stack<Node*> s;
    s.push(root);
    while(!s.empty()) {
        Node* temp = s.top();
        s.pop();
        cout << temp->data << " ";
        if(temp->right != NULL) {
            s.push(temp->right);
        }
        if(temp->left != NULL) {
            s.push(temp->left);
        }   
    }
}

void inorder(Node* root) {
    if(root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void inorderIterative(Node* root) {
    stack<Node*> s;
    Node* temp = root;
    while(temp != NULL || !s.empty()) {
        while(temp != NULL) {
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        cout << temp->data << " ";
        temp = temp->right;
    }
}

void postorder(Node* root) {
    if(root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void postorderIterative(Node* root) {
    stack<Node*> s1, s2;
    Node* temp = root;
    if(root == NULL) return;
    s1.push(root);
    while(!s1.empty()) {
        temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left) {
            s1.push(temp->left);
        }
        if(temp->right) {
            s1.push(temp->right);
        }
    }

    while(!s2.empty()) {
        temp = s2.top();
        s2.pop();
        cout << temp->data << " ";
    }
}

void levelorderIterative(Node* root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp;
        temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int height(Node *root) {
    if(root == NULL) {
        return 0;
    } else {
        int lheight = height(root->left);
        int rheight = height(root->right);
        if(lheight>rheight) {
            return lheight+1;
        } else {
            return rheight+1;
        }
    }
}

void printlevel(Node* root, int level) {
    if(root == NULL) return ;
    if(level == 1) {
        cout << root->data << " ";
    } else if(level > 1){
        printlevel(root->left,level-1);
        printlevel(root->right, level-1);
    }
}
void levelorder(Node* root) {
    int h = height(root);
    for(int i = 1; i<=h; i++) {
        printlevel(root,i);
    }
}
int main() {
    Node* root;
    root = createNode(1); 
    root->left = createNode(2);
    root->right = createNode(3);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,6);
    insertNode(root,7);
    insertNode(root,8);
    cout << "PreOrder traversal(using recursion): ";
    preorder(root);
    cout << endl;
    cout << "PreOrder traversal(using iterative): ";
    preorderIterative(root);
    cout << endl;
    cout << "------------------------------------------------" << endl;
    cout << "InOrder traversal(using recursion): ";
    inorder(root);
    cout << endl;
    cout << "InOrder traversal(using iterative): ";
    inorderIterative(root);
    cout << endl;
    cout << "------------------------------------------------" << endl;
    cout << "PostOrder traversal(using recursion): ";
    postorder(root);
    cout << endl;
    cout << "PostOrder traversal(using iterative): ";
    postorderIterative(root);
    cout << endl;
    cout << "------------------------------------------------" << endl;
    cout << "LevelOrder traversal(using recursion): ";
    levelorder(root);
    cout << endl;
    cout << "LevelOrder traversal(using iterative): ";
    levelorderIterative(root);
}

//Print reverse level order traversal
//if asked to print for a reverse level order traversal, if LOT is 1 2 3 4 5 6, then print 6 5 4 3 2 1. We can use a stack to store data.
//Then we can perform regular level order traversal while storing element in stack instead of printing

//For deleting an element, we can find the rightmost leaf node, and then replace the value of the element to be deleted by that value, and 
//then delete that right most element