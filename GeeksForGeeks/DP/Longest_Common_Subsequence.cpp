#include <iostream>
#include <cmath>
using namespace std;

//Question - https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
void solve() {
    string A, B;
    cin >> A >> B;
    int n1 = A.length();
    int n2 = B.length();
    int L[n1 + 1][n2 + 1]; 
    int i, j; 
    
    for(i = 0; i<=n1; i++) {
        for(int j = 0; j<=n2; j++) {
            if(i == 0 || j == 0) {
                L[i][j] = 0;
            } else if(A[i-1] == B[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
            } else {
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }
    cout << L[n1][n2] << endl;
}

int main() {
    solve();
}