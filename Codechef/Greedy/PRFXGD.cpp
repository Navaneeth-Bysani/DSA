#include <iostream>
#include <string>
#include <map>
using namespace std;
//Question - https://www.codechef.com/problems/PRFXGD
void solve() {
    string S;
    int K,X;
    cin >> S;
    cin >> K >> X;
    int n = S.length();
    map<char,int> M;
    int total = 0;
    for(int i = 0; i<n; i++) {
        auto itr = M.find(S[i]);
        if(itr == M.end()) {
            M.insert({S[i],1});
            total++;
            continue;
        }
        if(itr->second < X) {
            itr->second++;
            total++;
        } else {
            if(K == 0) {
                break;
            }
            K--;
        }
    }
    cout << total << endl;
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
