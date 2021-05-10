#include <iostream>
#include <vector>
using namespace std;
//Question - https://www.codechef.com/problems/DWW19C
void solve() {
    string A,B;
    cin >> A;
    cin >> B;
    int n1 = A.length(), n2 = B.length();
    int A_c[26], B_c[26];
    char a;
    for(int i = 0; i<26; i++) {
        A_c[i] = 0;
        B_c[i] = 0;
    }
    
    for(int i = 0; i<n1; i++) {
       A_c[A[i]-'A']++; 
    }
    for(int i = 0; i<n2; i++) {
        B_c[B[i]-'A']++;
    }
    int cost = 0;
    
    for(int i = 0; i<26; i++) {
        if(B_c[i] > A_c[i]) {
            cost+= B_c[i] - A_c[i];
        }
    }
    cout << cost << endl;
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
