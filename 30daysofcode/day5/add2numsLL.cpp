#include <bits/stdc++.h>
using namespace std;

//Question - https://leetcode.com/problems/add-two-numbers/

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode ans(INT_MIN);
        ListNode *head;
        head = &ans;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry) {
            int x = l1 ? l1->val : 0;            
            int y = l2 ? l2->val : 0;

            head->next = new ListNode((x + y + carry)%10);
            carry = (x + y + carry)/10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            head = head->next;
        }
        
        return ans.next;
}

