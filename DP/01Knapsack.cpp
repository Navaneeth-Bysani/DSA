#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

int Knapsack(vector<int> Value, vector<int> Weight, int W, int idx) {
    //normal recursion
    if(idx == Value.size() || W == 0)
        return 0;
    if(Weight[idx] > W) 
        return Knapsack(Value, Weight, W, idx+1);

    return max(Knapsack(Value, Weight, W, idx+1), Value[idx] + Knapsack(Value, Weight, W-Weight[idx], idx+1));  
}

int Knapsack_Tabulation(vector<int> Value, vector<int> Weight, int W) {
    int n = Value.size();
    int dp[n+1][W+1];
    for(int i = 0; i<= n; i++) {
        for(int j = 0; j<=W; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 0;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=W; j++) {
            if(Weight[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j-Weight[i-1]]+Value[i-1], dp[i-1][j]);
            }
        }
    }

    return dp[n][W];
}

int Knapsack_Memoization_Util(vector<int> Value, vector<int> Weight, int W, int n, vector<vector<int>> &dp) {
    if(W == 0 || n == 0) {
        dp[n][W] = 0;
        return dp[n][W];
    }
    if(dp[n][W] != -1) {
        return dp[n][W];
    }

    if(Weight[n-1] > W) {
        dp[n][W] = Knapsack_Memoization_Util(Value, Weight, W, n-1, dp);
        return dp[n][W];
    }
    dp[n][W] = max(Value[n-1] + Knapsack_Memoization_Util(Value, Weight, W-Weight[n-1], n-1, dp), 
        Knapsack_Memoization_Util(Value, Weight, W, n-1, dp));
    return dp[n][W];
}

int Knapsack_Memoization(vector<int> Value, vector<int> Weight, int W) {
    vector<vector<int>> dp;
    int n = Value.size();
    for(int i = 0; i<=n; i++) {
        dp.push_back({});
        for(int j = 0; j<=W; j++) {
            dp[i].push_back(-1);
        }
    }

    return Knapsack_Memoization_Util(Value, Weight, W, n, dp);
}

int Knapsack_DP_Space_Optimised(vector<int> Value, vector<int> Weight, int W) {
    //Space complexity - O(2*W)
    vector<vector<int>> dp;
    for(int i = 0; i<2; i++) {
        dp.push_back({});
        for(int j = 0; j<=W; j++) {
            dp[i].push_back(0);
        }
    }
    int n = Value.size();
    for(int i = 0; i<n; i++) {
        if(i%2 == 0) {
            int j = 0;
            while(j<=W) {
                if(j<Weight[i]) {
                    dp[0][j] = dp[1][j];
                } else {
                    dp[0][j] = max(dp[1][j], Value[i] + dp[1][j-Weight[i]]);
                }
                j++;
            }
        } else {
            int j = 0;
            while(j<=W) {
                if(j<Weight[i]) {
                    dp[1][j] = dp[0][j];
                } else {
                    dp[1][j] = max(dp[0][j], Value[i] + dp[0][j-Weight[i]]);
                }
                j++;
            }
        }
    }

    if(n%2 == 0) {
        return dp[1][W];
    } else {
        return dp[0][W];
    }
}

int Knapsack_DP_Space_Further_Optimised(vector<int> Value, vector<int> Weight, int W) {
    //Space Complexity - O(W)
    vector<int> dp(W+1, 0);
    int n = Value.size();

    for(int i = 0; i<n; i++) {
        for(int j = W; j>=Weight[i]; j--) {
            dp[j] = max(dp[j], Value[i] + dp[j-Weight[i]]);
        }
    }

    return dp[W];
}

int main() {
    vector<int> Value = {60, 100, 120};
    vector<int> Weight = {10,20,30};
    int W = 50;
    int ans = Knapsack(Value, Weight, W, 0);
    cout << ans << endl;
    int ans1 = Knapsack_Tabulation(Value, Weight, W);
    cout << ans1 << endl;
    int ans2 = Knapsack_Memoization(Value, Weight, W);
    cout  << ans2 << endl;
    int ans3 = Knapsack_DP_Space_Optimised(Value, Weight, W);
    cout << ans3 << endl;
    int ans4 = Knapsack_DP_Space_Further_Optimised(Value, Weight, W);
    cout << ans4 << endl;
    return 0;
}