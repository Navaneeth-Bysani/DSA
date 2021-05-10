#include <iostream>
#include <algorithm>
using namespace std;
//Question - https://www.codechef.com/problems/EID
void solve() {
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i<N; i++) {
        cin >> A[i];
    }
    sort(A,A+N);
    int diff = A[1]-A[0];
    for(int i = 2; i<N; i++) {
        if(A[i]-A[i-1] < diff) {
            diff = A[i]-A[i-1];
        }
        if(diff == 0) {
            cout << 0 << endl;
            return;
        }
    }
    cout << diff << endl;
    return;
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
