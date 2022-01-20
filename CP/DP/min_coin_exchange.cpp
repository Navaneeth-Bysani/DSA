#include<bits/stdc++.h>
using namespace std;

int minimum(int a, int b, int c) {
    if(a>b) {
        if(b>c) {
            return c;
        } else {
            return b;
        }
    } else {
        if(a>c) {
            return c;
        } else {
            return a;
        }
    }
}

int coin_change(int C[], int dp[], int R) {
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    for(int i = 6; i<=R; i++) {
        dp[i] = 1 + minimum(dp[i-1],dp[i-4],dp[i-5]);
    }

    cout << dp[R] << endl;
    return dp[R];
}

int min_coin_change(int C[]) {
    int R;
    cin >> R;
    int dp[R+1];
    fill_n(dp,R+1,-1);
    return coin_change(C,dp,R);
}

int main() {
    int C[] = {1,4,5};
    min_coin_change(C);
}