#include <iostream>
#include <algorithm>
using namespace std;
//Question - https://www.codechef.com/problems/MIXCOLOR
void solve() {
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i<N; i++) {
        cin >> A[i];
    }
    sort(A,A+N);
    int changes = 0;
    for(int i = 1; i<N; i++) {
        if(A[i] == A[i-1]) {
            changes++;
        }
    }
    cout << changes << endl;
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

//In this problem, we can find the maximum element. We can add this to any other element in the array 
// which leads to a new maximum also a new element in the array. Therefore, we can do the same for all repeated
// elements. So, the thing here is to find how many duplicates had occurred.