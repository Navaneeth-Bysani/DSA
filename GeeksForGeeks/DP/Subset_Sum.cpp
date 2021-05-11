#include <iostream>
using namespace std;

//Question - https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

//Recursive approach
// bool subset(int A[], int N, int X) {
//     if(X == 0) {
//         return 1;
//     }
//     if(N <= 0 || X<0) {
//         return 0;
//     }

//     return subset(A,N-1,X) || subset(A,N-1,X-A[N-1]);
// }

bool subset(int A[], int N, int X) {
    bool dp[N+1][X+1];
    for(int i = 0; i<=N; i++) {
        for(int j = 0; j<=X; j++) {
            dp[i][j] = -1;
        }
    }
    for(int j = 1; j <= X; j++) {
        dp[0][j] = 0;
    }
    for(int i = 1; i <= N; i++) {
        dp[i][0] = 1;
    }
    dp[0][0] = 1;

    for(int i = 1; i<=N; i++) {
        for(int j = 1; j<=X; j++) {
            if(j < A[i-1]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
            }
        }
    }

    // cout << dp[N][X] << endl;
    return dp[N][X];
}

void solve() {
    int X,N;
    cin >> N;
    int A[N];
    for(int i = 0; i<N; i++) {
        cin >> A[i];
    }
    cin >> X;
    
    cout << (subset(A,N,X) == 1? "YES" : "NO") << endl;
}

int main() {
    solve();
}