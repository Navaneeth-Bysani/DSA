#include<bits/stdc++.h>
using namespace std;

int rod_cut(int n, int c[]) {
    int rod[n+1];
    rod[0] = 0;
    int max;
    for(int i = 1; i<=n; i++) {
        max = 0;
        for(int j = 0; j<i; j++) {
            if(max < c[j] + rod[i-j-1]) {
                max = c[j] + rod[i-j-1];
            }
        }
        rod[i] = max;
    }
    cout << rod[n] << endl;
    return rod[n];
}

int main() {
    int n = 5;
    int c[] = {2,7,5,12,7};
    rod_cut(n,c);
}