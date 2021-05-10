#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//Question - https://www.geeksforgeeks.org/greedy-algorithm-egyptian-fraction/#:~:text=Every%20positive%20fraction%20can%20be,was%20used%20by%20ancient%20Egyptians.

void solve() {
    int a,b; //a/b
    cin >> a >> b;
    while(1) {
        if(a == 0 || b == 0) {
            return;
        }
        if(b%a == 0) {
            cout << "1/" << b/a << " ";
            cout << endl;
            return;
        }
        if(a%b == 0) {
            cout << a/b << " ";
            cout << endl;
            return;
        }
       int x = b/a + 1;
       cout << "1/" << x << " ";
       a = a*x-b;
       b = b*x;
    }
    cout << endl;
    return;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}