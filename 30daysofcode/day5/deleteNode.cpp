#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

//Question - https://leetcode.com/problems/delete-node-in-a-linked-list/

void deleteNode(ListNode* node) {
    *node = *(node->next);
}