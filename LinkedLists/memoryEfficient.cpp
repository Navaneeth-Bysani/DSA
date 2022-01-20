#include<bits/stdc++.h>
using namespace std;

typedef struct listNode {
    int elem;
    struct listNode *ptrdiff;
} listNode;

listNode* nextNode(listNode *curr, listNode *prevNode) {
    return ((listNode*) ((int)curr->ptrdiff ^ (int)prevNode->ptrdiff));
}

int main() {

}