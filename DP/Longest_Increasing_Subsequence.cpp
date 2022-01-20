#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int> A, int n, int* Max) {
    if(n == 1) {
        return 1;
    }    
    int res, max_ending_here = 1;
    for(int i = 1; i<n; i++) {
        res = LIS(A, i, Max);
        if(A[i-1] < A[n-1]) {
            max_ending_here = max(res + 1, max_ending_here);
        }
    }

    if(*Max < max_ending_here) {
        *Max = max_ending_here;
    }
    return max_ending_here;
}

int LIS_Recurse(vector<int> A, int n) {
    int Max = 1;
    LIS(A, n, &Max);
    return Max;
}

int LIS_Tabulation(vector<int> A) {
    int n = A.size();
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    for(int i = 1; i<=n; i++) {
        int Max = 0;
        for(int j = 0; j<i; j++) {
            if(A[j] < A[i-1]) {
                Max = max(Max, dp[j+1]);
            }
        }
        dp[i] = 1+Max;
    }
    
    return *max_element(dp.begin(), dp.end());
}

int LIS_Memoization_Util(vector<int> A, int n, vector<int> &dp) {
    if(n == 0) {
        dp[n] = 0;
        return dp[n];
    }

    if(dp[n] != -1) {
        return dp[n];
    }
    
    int Max = 0;
    for(int i = 0; i<n; i++) {
        int res = LIS_Memoization_Util(A,i,dp);
        if(A[i-1] < A[n-1]) {
            Max = max(Max, res);
        }
    }

    dp[n] = 1 + Max;
    return dp[n];
}

int LIS_Memoization(vector<int> A) {
    int n = A.size();
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    LIS_Memoization_Util(A,n,dp);
    return *max_element(dp.begin(), dp.end());
}

int ceilIndex(vector<int> tail, int l, int r, int x) {
    while(r-l>1) {
        int mid = l + (r-l)/2;
        if(tail[mid] >= x) {
            r = mid;
        } else {
            l = mid;
        }
    }

    return r;
}
int LIS_BS(vector<int> A) {
    if(A.size() == 0)
        return 0;
    
    vector<int> tail(A.size(), 0);
    int length = 1;
    tail[0] = A[0];

    for(int i = 1; i<A.size(); i++) {
        if(A[i] < tail[0]) {
            tail[0] = A[i];
        } else if(A[i] > tail[length-1]) {
            tail[length] = A[i];
            length++;
        } else {
            tail[ceilIndex(tail, -1, length-1, A[i])] = A[i];
        }
    }

    return length;
}

int main() {
    // vector<int> A = {99, 80, 77, 45, 43, 42,43,50};
    vector<int> A = {10,22,9,33,21,50,4};
    int n = A.size();
    int ans = LIS_Recurse(A,n);
    cout << ans << endl;
    int ans1 = LIS_Tabulation(A);
    cout << ans1 << endl;
    int ans2 = LIS_Memoization(A);
    cout << ans2 << endl;
    int ans3 = LIS_BS(A);
    cout << ans3 << endl;
}

// There is another approach to solve this problem using longest common subsequence.
// We have to create another sorted array with the same elements as this (but each element should be there only once)
// and then we need to pass the original array and the sorted array into longest common subsequence problem.