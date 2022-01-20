#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

int minCoinChange(vector<int> coins, int n, int target) {
    if(target == 0) return 0;

    int ans = INT_MAX;
    for(int i = 0; i<n; i++) {
        if(coins[i] <= target) {
            int x = minCoinChange(coins, n, target-coins[i]);
            if(x != INT_MAX && x+1 < ans) {
                ans = x + 1;
            }
        }
    }

    return ans;
}

int MCC_Tabulation(vector<int> coins, int target) {
    int n = coins.size();
    int dp[target+1];
    dp[0] = 0;
    for(int i = 1; i<=target; i++) {
        dp[i] = INT_MAX;
    }
    for(int i = 1; i<=target; i++) {
        for(int j = 0; j<n; j++) {
            if(coins[j] <= i) {
                int res = dp[i-coins[j]];
                if(res != INT_MAX && res+1<dp[i]) {
                    dp[i] = res+1;
                }
            }
        }
    }

    if(dp[target] == INT_MAX) return -1;

    return dp[target];
}

int MCC_Memoization_Util(vector<int> coins, int target, int n, vector<int> &dp) {
    if(target == 0) {
        dp[target] = 0;
        return dp[target];
    }

    if(dp[target] != -1) {
        return dp[target];
    }

    int res = INT_MAX;
    for(int i = 0; i<n; i++) {
        if(target >= coins[i]) {
            int x = MCC_Memoization_Util(coins, target-coins[i], n, dp);
            if(x != INT_MAX) {
                res = min(res,x+1);
            }
        }
    }

    dp[target] = res;
    return dp[target];
}

int MCC_Memoization(vector<int> coins, int target) {
    int n = coins.size();
    vector<int> dp;
    for(int i = 0; i<=target; i++) {
        dp.push_back(-1);
    }
    dp[0] = 0;

    int ans = MCC_Memoization_Util(coins, target, n, dp);
    if(ans == INT_MAX) return -1;
    return ans;
}

int main() {
    vector<int> coins = {9, 6, 5};
    int target = 70;
    int n = coins.size();

    int ans = minCoinChange(coins, n, target);
    cout << ((ans ==INT_MAX) ? -1 : ans) << endl;
    int ans1 = MCC_Tabulation(coins, target);
    cout << ans1 << endl;
    int ans2 = MCC_Memoization(coins, target);
    cout << ans2 << endl;
}