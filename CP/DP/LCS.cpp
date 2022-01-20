#include<bits/stdc++.h>
using namespace std;

//LCS - Longest Common Subsequence of 2 strings

int Max(int a,int b) {
    return (a>b) ? a : b;
}

//1. Recursive
int LCS_recursive(string X,int m, string Y, int n) {
    if(n == 0 || m == 0) {
        return 0;
    }
    if(X[m-1] == Y[n-1]) {
        return 1 + LCS_recursive(X,m-1,Y,n-1);
    } else {
        return Max(LCS_recursive(X,m-1,Y,n), LCS_recursive(X,m,Y,n-1));
    }
}

//2. Memoization
int LCS[300][300];

int memo(string X, int m, string Y, int n) {
    if(m == 0 || n == 0)
        return 0;
    if(LCS[m-1][n-1] != -1) {
        return LCS[m-1][n-1];
    }
    if(X[m-1] == Y[n-1]) {
        LCS[m-1][n-1] = 1 + memo(X,m-1,Y,n-1);
        return LCS[m-1][n-1];
    } else {
        LCS[m-1][n-1] = Max(memo(X,m-1,Y,n),memo(X,m,Y,n-1));
        return LCS[m-1][n-1];
    }
     
    return LCS[m][n];
}

int LCS_memo(string X, int m, string Y, int n) {
    for(int i = 0; i<m+1; i++) {
        for(int j = 0; j<n+1; j++) {
            LCS[i][j] = -1;
        }
    }

    return memo(X,m,Y,n);
}

//3. Tabulation
int LCS_tab(string X, int m, string Y, int n) {
    int dp[m+1][n+1];
    for(int i = 0; i<=m; i++) {
        for(int j = 0; j<=n; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = Max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

//4. Printing LCS
void LCS(string X, int m, string Y, int n) {
    
}

int main() {
    string X,Y;
    cin >> X >> Y;
    int m,n;
    m = X.length();
    n = Y.length();

    
    int Lcs_length = LCS_recursive(X,m,Y,n);
    
    cout << "length of longest common substring:    " << Lcs_length << endl;

    cout << "length of longest common substring using Memoization DP:    " << LCS_memo(X,m,Y,n) << endl;

    cout << "Length of longest common substring using Tabulation DP:    " << LCS_tab(X,m,Y,n) << endl;

    cout << "Longest Common Subsequence is: " << LCS(X,m,Y,n);
}