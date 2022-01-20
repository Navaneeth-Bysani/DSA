#include <bits/stdc++.h>
using namespace std;

//Question - https://leetcode.com/problems/unique-paths/

int method1(int l, int r, int m, int n) {
    if(l >=m || r >= n) {
        return 0;
    }

    if(l == m-1 && r == n-1) {
        return 1;
    }

    return method1(l+1,r,m,n) + method1(l,r+1,m,n);
}

int method2(int l, int r, int m, int n, vector<vector<int>> &dp) {
    if(l >= m || r >= n) {
        return 0;
    }

    if(l == m-1 && r == n-1) {
        return 1;
    }

    if(dp[l][r] != -1) {
        return dp[l][r];
    }

    dp[l][r] = method2(l+1,r,m,n,dp) + method2(l,r+1,m,n,dp);
    return dp[l][r];
}

int method3(int m, int n) {
    int x = (m-1 + n-1);
    int r = min(m,n)-1;

    //we need to compute (x)C(r)
    double res = 1;
    for(int i = 1; i<=r; i++) {
        res = res * (x-r+i)/i;
    }

    return (int)res;
}

int main() {
    int m = 23;
    int n = 12;

    //Method1 is a naive recursive approach
    //Time complexity is exponential & space complexity for recursive stack is also exponential
    cout << method1(0,0,m,n) << endl;

    //Better approach is to use dp T(n) -> O(n*m) S(n) -> O(n*m)
    vector<vector<int>> dp(m, vector<int>(n));

    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) {
            dp[i][j] = -1;
        }
    }

    cout << method2(0,0,m,n,dp) << endl;

    //even better approach is to use combinations  --> Take only O(min(m,n))
    cout << method3(m,n) <<endl;
}