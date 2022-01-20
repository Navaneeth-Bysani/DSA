#include <bits/stdc++.h>
using namespace std;
//Question - https://www.codechef.com/LTIME98B/problems/LGSEG
void solve() {
    int N, K, S;
    cin >> N >> K >> S;
    vector<long long int> A(N+1,0);
    
    for(int i = 1; i<=N; i++) {
        cin >> A[i];
        A[i] += A[i-1];
    }
    
    vector<int> go(N+2), ans(N+2);
    
    for(int i = 1; i<=N+1; i++) {
        go[i] = upper_bound(A.begin(), A.end(), A[i-1]+S)-A.begin();
        ans[i] = i;
    }
    
    for(int bit = 0; bit < 20; bit++) {
        if((K>>bit) & 1ll) {
            for(int i = 1; i<=N+1; i++) {
                ans[i] = go[ans[i]];
            }
        }
        
        for(int i = 1; i<=N+1; i++) {
            go[i] = go[go[i]];   
        }
    }
    int MaxLen = 0;
    for(int i = 1; i<=N+1; i++) {
        MaxLen = max(MaxLen, ans[i]-i);
    }
    cout << MaxLen << endl;
}

int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--) {
	    solve();
	}
	return 0;
}
