#include <iostream>
#include <algorithm>
using namespace std;

//Question - https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/#:~:text=Find%20the%20largest%20denomination%20that,becomes%200%2C%20then%20print%20result.

void solve() {
    int N, R;
    cin >> N >> R;
    int D[N];
    for(int i = 0; i<N; i++) {
        cin >> D[i];
    }
    sort(D,D+N,greater<int>());
    int total = 0;
    for(int i = 0; i<N; i++) {
        total += R/D[i];
        R = R%D[i];
        if(R == 0) {
            cout << total << endl;
            return;
        }
    }
    cout << "Can't be changed" << endl;
    return;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}