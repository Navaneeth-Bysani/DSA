#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

int MCM(vector<int> p, int s, int e) {
    if(s == e) return 0;
    
    int Min = INT_MAX;

    for(int k = s; k < e; k++) {
        int count = MCM(p, s, k) + MCM(p, k+1, e) + p[s-1]*p[k]*p[e];
        Min = min(Min, count);
    }

    return Min;
}

int MCM_Tabulation(vector<int> p) {
    int n = p.size();
    vector<vector<int>> dp;
    for(int i = 0; i<n; i++) {
        dp.push_back({});
        for(int j = 0; j<n; j++) {
            dp[i].push_back(0);
        }
    }

    for(int L = 2; L<n; L++) {
        for(int i = 1; i<n-L+1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for(int k = i; k<j; k++) {
                int q = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                dp[i][j] = min(dp[i][j], q);
            }
        }
    }

    return dp[1][n-1];
}

int MCM_Memoization_Util(vector<int> p, int s, int e, vector<vector<int>> dp) {
    if(s == e) {
        return 0;
    }
    if(dp[s][e] != -1) {
        return dp[s][e];
    }

    dp[s][e] = INT_MAX;
    for(int k = s; k<e; k++) {
        dp[s][e] = min(dp[s][e], MCM_Memoization_Util(p,s,k,dp) + MCM_Memoization_Util(p,k+1,e,dp) + p[s-1]*p[k]*p[e]);
    }

    return dp[s][e];
}

int MCM_Memoization(vector<int> p) {
    vector<vector<int>> dp;
    int n = p.size();
    for(int i = 0; i<n; i++) {
        dp.push_back({});
        for(int j = 0; j<n; j++) {
            dp[i].push_back(-1);
        }
    }

    return MCM_Memoization_Util(p, 1, n-1, dp);
}

int main() {
    // vector<int> p = {1,2,3,4,3};
    vector<int> p = {40, 20, 30, 10, 30};
    int n = p.size();

    int ans = MCM(p,1,n-1);
    cout << ans << endl;
    int ans1 = MCM_Tabulation(p);
    cout << ans1 << endl;
    int ans2 = MCM_Memoization(p);
    cout << ans2 << endl;
}