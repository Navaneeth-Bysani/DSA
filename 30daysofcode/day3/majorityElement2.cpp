#include <bits/stdc++.h>
using namespace std;

//Question - https://leetcode.com/problems/majority-element-ii/submissions/

void majorityElement2(vector<int> A) {
    int cnt1 = 0, cnt2 = 0, el1 = -1, el2 = -1;
    int n = A.size();

    for(auto num : A) {
        if(num == el1) {
            cnt1++;
        } else if(num == el2) {
            cnt2++;
        } else if(cnt1 == 0) {
            el1 = num;
            cnt1++;
        } else if(cnt2 == 0) {
            el2 = num;
            cnt2++;
        } else {
            cnt1--;
            cnt2--;
        }
    }

    int count1 = 0, count2 = 0;
    for(auto num : A) {
        if(num == el1) count1++;
        else if(num == el2) count2++;
    }

    vector<int> Ans;
    if(count1 > n/3) Ans.push_back(el1);
    if(count2 > n/3) Ans.push_back(el2);

    for(auto v :Ans) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    vector<int> A = {1,1,1,3,3,2,2,2};

    //O(N) Two pass solution S(n) --> O(1)
    //Uses Boyer Moore algorithm in slightly modified fashion
    majorityElement2(A);
    return 0;
}