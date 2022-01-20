#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

int LCS(string s1, int n1, string s2, int n2) {
    if(n1 == 0 || n2 == 0) return 0;
    if(s1[n1-1] == s2[n2-1]) {
        return (1 + LCS(s1,n1-1,s2,n2-1));
    }

    return (max(LCS(s1,n1-1,s2,n2), LCS(s1,n1,s2, n2-1))); 
}

int LCS_Tabulation(string s1, string s2) {
    int n1 = s1.length(), n2 = s2.length();
    vector<vector<int>> dp;
    for(int i = 0; i<=n1; i++) {
        dp.push_back({});
        for(int j = 0; j<=n2; j++) {
            dp[i].push_back(0);
        }
    }

    for(int i = 1; i<=n1; i++) {
        for(int j = 1; j<=n2; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n1][n2];
}

int LCS_Memoization_Util(string s1, int n1, string s2, int n2, vector<vector<int>> &dp) {

    if(dp[n1][n2] != -1) {
        return dp[n1][n2];
    }

    if(n1 == 0 || n2 == 0) {
        dp[n1][n2] = 0;
        return dp[n1][n2];
    }
    
    if(s1[n1-1] == s2[n2-1]) {
        dp[n1][n2] = 1 + (LCS_Memoization_Util(s1,n1-1,s2,n2-1, dp));
    } else {
        dp[n1][n2] = max(LCS_Memoization_Util(s1,n1-1,s2,n2,dp), LCS_Memoization_Util(s1,n1,s2,n2-1,dp));
    }

    return dp[n1][n2];
}

int LCS_Memoization(string s1, string s2) {
    int n1 = s1.length(), n2 = s2.length();
    vector<vector<int>> dp;
    for(int i = 0; i<=n1; i++) {
        dp.push_back({});
        for(int j = 0; j<=n2; j++) {
            dp[i].push_back(-1);
        }
    }
    return LCS_Memoization_Util(s1,n1,s2,n2, dp);
}

int LCS_Memory_Optimised(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp;
    for(int i = 0; i<2; i++) {
        dp.push_back({});
        for(int j = 0; j<=n1; j++) {
            dp[i].push_back(0);
        }
    }
    int i = 1;
    while(i<=n1) {
        if(i%2 == 0) {
            int j = 1;
            while(j<=n2) {
                if(s1[i-1] == s2[j-1]) {
                    dp[0][j] = 1 + dp[1][j-1];
                } else {
                    dp[0][j] = max(dp[1][j], dp[0][j-1]);
                }
                j++;
            }
        } else {
            int j = 1;
            while(j<=n2) {
                if(s1[i-1] == s2[j-1]) {
                    dp[1][j] = 1 + dp[0][j-1];
                } else {
                    dp[1][j] = max(dp[0][j], dp[1][j-1]);
                }
                j++;
            }
        }
        i++;
    }

    if(n1%2 == 0) {
        return dp[0][n2];
    } else {
        return dp[1][n2];
    }

}

int LCS_Memory_Further_Optimised(string s1, string s2) {
    //space complexity O(n2) With slight modification while calling this function, we can always pass min length string as second argument, 
    // to make space complexity equal to O(min(n1,n2))
    int n1 = s1.length(), n2 = s2.length();
    vector<int> dp(n2+1, 0);
    int prev;

    for(int i = 1; i<=n1; i++) {
        prev = dp[0];
        for(int j = 1; j<=n2; j++) {
            int backup = dp[j];
            if(s1[i-1] == s2[j-1]) {
                dp[j] = 1 + prev;
            } else {
                dp[j] = max(dp[j], dp[j-1]);
            }
            prev = backup;
        }
    }

    return dp[n2];
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    // string s1 = "ABCDGHF";
    // string s2 = "AEDFHR";
    // string s1 = "ABC";
    // string s2 = "GDH";
    int n1 = s1.length();
    int n2 = s2.length();

    int ans = LCS(s1,n1,s2,n2);
    cout << ans << endl;
    int ans1 = LCS_Tabulation(s1,s2);
    cout << ans1 << endl;
    int ans2 = LCS_Memoization(s1,s2);
    cout << ans2 << endl;
    int ans3 = LCS_Memory_Optimised(s1,s2);
    cout << ans3 << endl;
    int ans4 = LCS_Memory_Further_Optimised(s1,s2);
    cout << ans4 << endl;
}