#include <iostream>
using namespace std;
//Question - https://www.codechef.com/problems/CASH
void solve() {
    int N,K;
    cin >> N >> K;
    int A[N];
    long long int sum = 0;
    for(int i = 0; i<N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    cout << sum%K << endl;
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
