#include <iostream>
#include <cmath>
using namespace std;

//Question - https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
void solve() {
    string S;
    cin >> S;
    int n = S.length();
    int dp[n][n];

    for(int i = 0; i<n; i++) {
        dp[i][i] = 1;
    }
    for(int cl = 2; cl <=n; cl++) {
        for(int i = 0; i<n-cl+1; i++) {
            int j = i+cl-1;
            if(S[i] == S[j] && cl == 2) {
                dp[i][j] = 2;
            } else if(S[i] == S[j]) {
                dp[i][j] = 2 + dp[i+1][j-1];
            } else {
                dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
}

int main() {
    solve();
}