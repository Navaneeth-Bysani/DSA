#include <bits/stdc++.h>
using namespace std;

int maxArr(vector<int> &A) {
    int n = A.size();
    int Max1 = INT_MIN, Min1 = INT_MAX, Max2 = INT_MIN, Min2 = INT_MAX;
    for(int i = 0; i<n; i++) {
        Max1 = max(Max1,A[i]+i);
        Min1 = min(Min1,A[i]+i);
        Max2 = max(Max2,A[i]-i);
        Min2 = min(Min2,A[i]-i);
    }
    return max(abs(Max1-Min1),abs(Max2-Min2));
}

//Question - https://www.interviewbit.com/problems/maximum-absolute-difference/
