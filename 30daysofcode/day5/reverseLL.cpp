#include <bits/stdc++.h>
using namespace std;

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

 ListNode* reverseList(ListNode* head) {
    ListNode* curr;
    ListNode* Next;
    ListNode* prev = NULL;
    curr = head;
    while(curr != NULL) {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
        
    return prev;
}
