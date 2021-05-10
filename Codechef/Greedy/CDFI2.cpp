#include <iostream>
using namespace std;
//Question - https://www.codechef.com/problems/CDFI2
void solve() {
    int p;
    cin >> p;
    int total = 0;
    if(p<=2048) {
      while(p!=0) {
        total += p%2;
        p = p/2;
      }  
    } else {
        while(p>2048) {
            total += 1;
            p = p-2048;   
        }
        while(p!=0) {
            total += p%2;
            p = p/2;
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
