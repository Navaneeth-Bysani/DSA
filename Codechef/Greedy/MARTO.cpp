#include <iostream>
#include <algorithm>
using namespace std;

//Question - https://www.codechef.com/problems/MARTO
void solve() {
    int n,k;
    cin >> n >> k;
    int A[n];
    for(int i = 0; i<n; i++) {
        cin >> A[i];
    }
    sort(A,A+n);
    int sum = 0;
    int tot = 0;
    for(int i = 0; i<n; i++) {
        if(sum+A[i] > k) {
            break;
        } else {
            sum = sum + A[i];
            tot++;
        }
    }
    cout << tot << endl;
}

int main() {
	// your code goes here
	int T;
// 	cin >> T;
    T = 1;
	while(T--) {
	    solve();
	}
	return 0;
}
