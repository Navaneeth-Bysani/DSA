#include <bits/stdc++.h>
using namespace std;

void solve(int x) {
    int A[3][3];
    
    cin >> A[0][0] >> A[0][1] >> A[0][2];
    cin >> A[1][0] >> A[1][2];
    cin >> A[2][0] >> A[2][1] >> A[2][2];
    
    int total = 0;
    if(A[0][0]+A[0][2] == 2*A[0][1]) total++;
    if(A[2][0]+A[2][2] == 2*A[2][1]) total++;
    if(A[0][0]+A[2][0] == 2*A[1][0]) total++;
    if(A[0][2]+A[2][2] == 2*A[1][2]) total++;
    map<int,int> M;

    if((A[0][0]+A[2][2])%2 == 0) M[(A[0][0]+A[2][2])/2]++;
    if((A[2][0]+A[0][2])%2 == 0) M[(A[2][0]+A[0][2])/2]++;
    if((A[1][0]+A[1][2])%2 == 0) M[(A[1][0]+A[1][2])/2]++;
    if((A[0][1]+A[2][1])%2 == 0) M[(A[0][1]+A[2][1])/2]++;
    
    int Max = 0;
    for(auto itr = M.begin(); itr != M.end(); itr++) {
        Max = max(Max, itr->second);
    }

    total += Max;
    cout << "Case #" << x+1 << ": " << total << endl;
}

int main() {
    int x = 0, T;
    cin >> T;
    while(x<T) {
        solve(x);
        x++;
    }
}