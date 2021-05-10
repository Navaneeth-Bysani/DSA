#include <iostream>
#include <string>
#include <stack>
using namespace std;
//Question - https://www.codechef.com/problems/TINDER
void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int groups = 0;
    stack <char> st;
    st.push(S[0]);
    for(int i = 1; i<N; i++) {
        if(st.empty() == 1 || st.top() == S[i]) {
            st.push(S[i]);
        } else {
            st.pop();
        }
        if(st.empty() == 1) {
            groups++;
        }
    }
    cout << groups << endl;
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
