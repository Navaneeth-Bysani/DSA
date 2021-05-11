#include <iostream>
#include <vector>
using namespace std;

//Question - https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

//Recursive approach
// int knapsack(vector<pair<int,int>>A, int N, int V) {
//     if(N == 0) {
//         return 0;
//     }
//     if(V <= 0) {
//         return 0;
//     }
    
//     if(A[N-1].first > V) {
//         return knapsack(A,N-1,V);
//     }
//     return max(knapsack(A,N-1,V), A[N-1].second + knapsack(A,N-1,V-A[N-1].first));
// }

int knapsack(vector<pair<int,int>> A, int N, int V) {
    //dp[i][j] i - N, j - V;
    int dp[N+1][V+1];
    for(int i = 0; i<=N; i++) {
        dp[i][0] = 0;
    }
    for(int j = 0; j<=V; j++) {
        dp[0][j] = 0;
    }

    for(int i = 1; i<=N; i++) {
        for(int j = 1; j<=V; j++) {
            if(A[i-1].first > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], A[i-1].second + dp[i-1][j-A[i-1].first]);
            }
        }
    }
    
    return dp[N][V];
}

void solve() {
    int V,N;
    vector<pair<int,int>> A;
    pair<int,int> X;
    cin >> N >> V;
    //first - volume second - cost
    for(int i = 0; i<N; i++) {
        cin >> X.first >> X.second;
        A.push_back(X);
    }
    int ans = knapsack(A,N,V);
    cout << ans << endl;
}

int main() {
    solve();
}