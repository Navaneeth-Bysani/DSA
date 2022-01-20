#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

//Question - https://leetcode.com/problems/merge-two-sorted-lists/

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *h1, *h2;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val < l2->val) {
            h1 = l1;
            h2 = l2;
        } else {
            h1 = l2;
            h2 = l1;
        }
        ListNode *res = h1;
        while(h1 != NULL && h2 != NULL) {
            ListNode *temp = NULL;
            while(h1 && h1->val <= h2->val) {
                temp = h1;
                h1 = h1->next;
            }
            temp->next = h2;
            swap(h1,h2);   
        }
        
        return res;
}