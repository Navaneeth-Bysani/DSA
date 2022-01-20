#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/edit-distance-dp-5/

int editDistance(string str1, string str2, int n1, int n2) {
    if(n1 == 0) {
        return n2;
    }

    if(n2 == 0) {
        return n1;
    }

    if(str1[n1-1] == str2[n2-1]) {
        return editDistance(str1, str2, n1-1, n2-1);
    }

    int x1 = editDistance(str1, str2, n1-1, n2);    //Remove
    int x2 = editDistance(str1, str2, n1-1, n2-1);  //Replace
    int x3 = editDistance(str1, str2, n1, n2-1);    //Insert
    return 1 + min({x1,x2,x3});
}

int editDistance_Tabulation(string str1, string str2) {
    int n1 = str1.length();
    int n2 = str2.length();

    vector<vector<int>> dp;
    for(int i = 0; i<=n1; i++) {
        dp.push_back({});
        for(int j = 0; j<=n2; j++) {
            dp[i].push_back(0);
        }
    }

    for(int i = 0; i<=n1; i++) {
        for(int j = 0; j<=n2; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = i+j;
            } else  if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }
        }
    }
    return dp[n1][n2];
}

int editDistance_Memoization_Util(string str1, string str2, int n1, int n2, vector<vector<int>> &dp) {
    if(n1 == 0) {
        dp[n1][n2] = n2;
        return dp[n1][n2];
    }

    if(n2 == 0) {
        dp[n1][n2] = n1;
        return dp[n1][n2];
    }

    if(dp[n1][n2] != -1) {
        return dp[n1][n2];
    }

    if(str1[n1-1] == str2[n2-1]) {
        dp[n1][n2] = editDistance_Memoization_Util(str1, str2, n1-1, n2-1, dp);
        return dp[n1][n2];
    }

    dp[n1][n2] = 1 + min({
        editDistance_Memoization_Util(str1, str2, n1-1,n2, dp), //remove
        editDistance_Memoization_Util(str1, str2, n1, n2-1, dp), //insert
        editDistance_Memoization_Util(str1, str2, n1-1, n2-1, dp) //replace
    });

    return dp[n1][n2];
}

int editDistance_Memoization(string str1, string str2) {
    int n1 = str1.length();
    int n2 = str2.length();

    vector<vector<int>> dp;
    for(int i = 0; i<=n1; i++) {
        dp.push_back({});
        for(int j = 0; j<=n2; j++) {
            dp[i].push_back(-1);
        }
    }

    return editDistance_Memoization_Util(str1, str2, n1, n2, dp);
}

int editDistance_Space_Optimised(string str1, string str2) {
    //should pass smaller string as second argument always
    //Because, it will reduce space complexity to O(min(n1,n2)) from O(n2)
    int n1 = str1.length(), n2 = str2.length();

    vector<int> dp(n2+1, 0);
    int prev, curr;
    dp[0] = 0;
    for(int i = 0; i<=n1; i++) {
        prev = dp[0];
        for(int j = 0; j<=n2; j++) {
            curr = dp[j];
            if(i == 0) {
                dp[j] = j;
            } else if(j == 0) {
                dp[j] = i;
            } else if(str1[i-1] == str2[j-1]) {
                dp[j] = prev;
            } else {
                dp[j] = 1 + min({dp[j], dp[j-1], prev});
            }
            prev = curr;
        }
    }
    
    return dp[n2];
}

int main() {
    string str1 = "sunday";
    string str2 = "saturday";
    // string str1 = "eat";
    // string str2 = "ate";
    int n1 = str1.length();
    int n2 = str2.length();

    int ans = editDistance(str1, str2, n1, n2);
    cout << ans << endl;
    int ans1 = editDistance_Tabulation(str1, str2);
    cout << ans1 << endl;
    int ans2 = editDistance_Memoization(str1, str2);
    cout << ans2 << endl;
    int ans3 = ((n1>=n2) ? editDistance_Space_Optimised(str1, str2) : editDistance_Space_Optimised(str2,str1));
    cout << ans3 << endl;
}