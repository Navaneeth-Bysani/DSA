#include<bits/stdc++.h>
using namespace std;

int subSetSum(vector<int> set, int sum, int n) {
    if(sum == 0) return true;
    if(n == 0) return false;
    if(set[n-1] > sum) {
        return subSetSum(set, sum, n-1);
    }

    return subSetSum(set, sum, n-1) || subSetSum(set, sum-set[n-1], n-1);

}

bool subSetSum_Tabulation(vector<int> set, int sum) {
    int n = set.size();
    vector<vector<bool>> dp;
    for(int i = 0; i<=n; i++) {
        dp.push_back({});
        for(int j = 0; j<=sum; j++) {
            dp[i].push_back(false);
        }
    }
    //dp[n+1][sum+1]
    for(int i = 0; i<=n; i++) {
        dp[i][0] = true;
    }

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=sum; j++) {
            if(j<set[i-1]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
            }
        }
    }

    return dp[n][sum];


}

int subSetSum_Memoization_Util(vector<int> set, int sum, int n, vector<vector<int>> &dp) {
    if(sum == 0) {
        dp[n][sum] = 1;
        return dp[n][sum];
    }
    if(n == 0) {
        dp[n][sum] = 0;
        return dp[n][sum];
    }
    if(dp[n][sum] != -1) {
        return dp[n][sum];
    }

    if(sum < set[n-1]) {
        dp[n][sum] = subSetSum_Memoization_Util(set, sum, n-1, dp);
        return dp[n][sum];
    }

    dp[n][sum] = subSetSum_Memoization_Util(set, sum, n-1, dp) || subSetSum_Memoization_Util(set, sum-set[n-1], n-1, dp);
    return dp[n][sum];
}

int subSetSum_Memoization(vector<int> set, int sum) {
    int n = set.size();
    vector<vector<int>> dp;
    for(int i = 0; i<=n; i++) {
        dp.push_back({});
        for(int j = 0; j<=sum; j++) {
            dp[i].push_back(-1);
        }
    }

    return subSetSum_Memoization_Util(set, sum, n, dp);
}
int subSetSum_Space_Optimised(vector<int> set, int sum) {
    int n = set.size();
    vector<bool> dp(sum+1, false);
    dp[0] = true;
    for(int i = 1; i<=n; i++) {
        for(int j = sum; j >= 0; j--) {
            if(j >= set[i-1]) {
                dp[j] = dp[j-set[i-1]] || dp[j];
            }
        }
    }

    return dp[sum];
}

int main() {
    vector<int> set = {3, 34, 4, 12, 5, 2};
    int n = set.size();
    int sum = 13;
    int ans = subSetSum(set, sum, n);
    cout  << ans << endl;
    int ans1 = subSetSum_Tabulation(set, sum);
    cout << ans1 << endl;
    int ans2 = subSetSum_Memoization(set, sum);
    cout << ans2 << endl;
    int ans3 = subSetSum_Space_Optimised(set, sum);
    cout << ans3 << endl;
}