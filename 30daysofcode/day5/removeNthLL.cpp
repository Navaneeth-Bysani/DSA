#include <bits/stdc++.h>
using namespace std;

//Question - https://leetcode.com/problems/remove-nth-node-from-end-of-list/

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) {
            return head;
        }
        
        ListNode dummy(INT_MIN);
        dummy.next = head;
        ListNode *fast, *slow;
        fast = slow = &dummy;
        int i = 0;
        while(i<=n) {
            fast = fast->next;
            i++;
        }
        
        while(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy.next;
}