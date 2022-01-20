#include <bits/stdc++.h>
using namespace std;

//Question - https://leetcode.com/problems/find-the-duplicate-number/solution/

void method1(vector<int> A) {
    int n = A.size();
    for(int i = 0; i<n; i++) {
        if(A[abs(A[i])-1] > 0) {
            A[abs(A[i])-1] *= -1;
        } else {
            cout << abs(A[i]) << endl;
            return;
        }
    }
}

void method2(vector<int> A) {
    int slow = A[0];
    int fast = A[0];

    do {
        slow = A[slow];
        fast = A[A[fast]];
    } while(slow != fast);

    fast = A[0];
    while(slow != fast) {
        slow = A[slow];
        fast = A[fast];
    }

    cout << slow << endl;
}

int main() {
    vector<int> A = {2,5,9,6,9,3,8,9,7,1};

    //Naive approach would be to sort the array and check if there are identical elements in the adjacent positions

    //Another approach
    //This approach works in O(N) time, and O(1) space and doesn't require extra space as well, but will change the value of the vector.
    //In this approach once we visit an element, then we mark the element in the indice value equals to curr-1 as negative.
    method1(A);

    //Another approach -> Hare & Tortoise (fast & slow pointer)
    //T(n) -> O(n) & S(n) = O(1)
    method2(A);
}