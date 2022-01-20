#include<bits/stdc++.h>
using namespace std;

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* sortAbsArray(Node* head) {
    // if(head == NULL) return head;
    
    // Node* curr = (head)->next;
    // Node* prev = head;
    // while(curr != NULL) {
    //     if(curr->data < prev->data) {
    //         prev->next = curr->next;
    //         curr->next = head;
    //         head = curr;
    //         curr = prev;
    //     } else {
    //         prev = curr;
    //     }
        
    //     curr = curr->next;
    // }
    if(head == NULL) return head;
    Node *prev = head;
    Node *curr = head->next;

    while(curr != NULL) {
        if(curr->data < 0) {
            prev->next = curr->next;
            curr->next = head;
            head = curr;
            curr = prev;
        } else {
            prev = curr;
        }
        curr = curr->next;
    }

    return head;
}

int main() {
    vector<int> nums = {1,-4,5,-8,9,10,-12,-14,-20,21};
    Node* head = new Node();
    head->data = nums[0];
    head->next = NULL;
    int n = nums.size();
    Node *curr = head;
    for(int i = 1; i<n; i++) {
        Node* newNode = new Node();
        newNode->data = nums[i];
        newNode->next = NULL;
        curr->next = newNode;
        curr = curr->next;
    }

    Node* start = sortAbsArray(head);
    while(start != NULL) {
        cout << start->data << " ";
        start = start->next;
    }
}