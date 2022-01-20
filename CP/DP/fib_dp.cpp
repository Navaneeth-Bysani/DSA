#include<bits/stdc++.h>
using namespace std;

int fib_memo(int n, int dp[]) {
    if(dp[n] == -1) {
        if(n<=1)
            return n;
        else {
            return dp[n] = fib_memo(n-1,dp) + fib_memo(n-2,dp);
        }
    }
    else return dp[n];
}

int fib_1(int n) {
    int dp[n+1];
    fill_n(dp,n+1,-1);
    dp[0] = 1;
    dp[1] = 1;
    return fib_memo(n,dp);
}

int fib_2(int n) {
    int dp[n];
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main() {
    int n;
    cin >> n;
    //memoization
    cout << n << "th Fibonacci number using memoization DP: " << fib_1(n-1) << endl;

    //tabulation
    cout << n << "th Fibonacci number using tabulation DP: " << fib_2(n-1) << endl;
}