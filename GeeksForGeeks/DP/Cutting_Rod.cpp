#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int price[n];
    for(int i = 0; i<n; i++) {
        cin >> price[i];
    }
    int dp[n+1];
    dp[0] = 0;
    for(int i = 1; i<=n; i++) {
        dp[i] = 0;
        for(int j = 0; j<i; j++) {
            dp[i] = max(dp[i],price[j]+dp[i-j-1]);
        }
    }
    cout << dp[n] << endl;
    return dp[n];
}