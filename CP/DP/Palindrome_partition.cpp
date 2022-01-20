#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    s = "AAAXACC";
    n = s.length();
    int P[n][n], C[n];
    int j,C[n];
    for(int l = 0; l<n; l++) {
        for(int i = 0; i<n-l; i++) {
            j = i+l;
            if(s[i] == s[j] && j-i < 2)
                P[i][j] = 1;
            else if(s[i] == s[j] && j-i > 1)
                P[i][j] = P[i+1][j-1];
            else 
                P[i][j] = 0;
        }
    }
    C[0] = 0;
    for(int i = 0; i<n; i++) {
        C[i] = n-1;
        if(P[0][i] == 1) {
            C[i] = 0;
        } else {
            for(int j = i; j>0; j--) {
                if(P[j][i] == 1 && C[i] > C[j-1] + 1) {
                    C[i] = 1 + C[j-1];
                }
            }
        }
    }
    cout << C[n-1] << endl;
}