#include <bits/stdc++.h>
using namespace std;

//Question - https://leetcode.com/problems/majority-element/

int majorityElement(vector<int>& nums) {
    //boyer-Moore voting algorithm
    int n = nums.size();
    int count = 0, el = 0;
        
    for(int i = 0; i<n; i++) {
        if(count == 0) {
            el = nums[i];
        }
        if(nums[i] == el) {
            count++;
        } else {
            count--;
        }
    }

    //if it is given that there will be a mojority element for sure, then we can print the answer dorectly.
    //else we should iterate once more to check if the 'el' is the majority element
    
    cout << el << endl;
    return el;
}

int main() {
    vector<int> A = {2,2,1,1,1,2,2};

    //There is an algorithm called Moore's algorithm to solve this
    majorityElement(A);
}