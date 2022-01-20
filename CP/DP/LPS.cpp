#include<iostream>
using namespace std;

//LPS - Longest Palindromic Subsequence
int Max(int a, int b) {
    return (a>b ? a : b);
}

//1. Recursion
int LPS_rec(string X, int i, int j) {
    if(i == j) {
        return 1;
    }
    if(X[i] == X[j] && j == i+1) {
        return 2;
    }
    if(X[i] == X[j]) {
        return 2 + LPS_rec(X,i+1,j-1);
    } else {
        return Max(LPS_rec(X,i+1,j), LPS_rec(X,i,j-1));
    }
}

//2. Memoization
int LPS[300][300];

int LPS_Memo(string X, int i, int j) {

    if(LPS[i][j] != -1)
        return LPS[i][j];

    if(i == j) {
        LPS[i][j] = 1;
        return LPS[i][j];
    }

    if(X[i] == X[j] && j == i+1) {
        LPS[i][j] = 2;
        return LPS[i][j];
    }

    if(X[i] == X[j]) {
        return LPS[i][j] = 2 + LPS_Memo(X,i+1,j-1);
    } else {
        return LPS[i][j] = Max(LPS_Memo(X,i+1,j),LPS_Memo(X,i,j-1));
    }

}

int LPS_Tab(string X, int m) {
    int dp[m][m];
    for(int i = 0; i<m; i++) {
        dp[i][i] = 1;
    }

    for(int l = 1; l<m; l++) {
        for(int i = 0; i<m-l; i++) {
            if(X[i] == X[i+l]) {
                if(i+1 <= i+l-1) {
                    dp[i][i+l] = 2 + dp[i+1][i+l-1]; 
                } else {
                    dp[i][i+l] = 2;
                }
            }else {
                dp[i][i+l] = Max(dp[i+1][i+l], dp[i][i+l-1]);
            }
        }
    }
    return dp[0][m-1];
}
int main() {
    string X;
    cin >> X;
    int m = X.length();

    for(int i = 0; i<300; i++) {
        for(int j = 0; j<300; j++) {
            LPS[i][j] = -1;
        }
    }

    cout << "Length of Longest Palindromic Subsequence using recursion: " << LPS_rec(X,0,m-1) << endl;
    cout << "Length of Longest Palindromic Subsequence using Memoization DP: " << LPS_Memo(X,0,m-1) << endl;
    cout << "Length of Longest Palindromic Subsequence using Tabulation DP: " << LPS_Tab(X,m) << endl;
}