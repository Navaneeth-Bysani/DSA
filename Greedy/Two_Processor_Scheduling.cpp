#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool Sort_(pair<int, int> a, pair<int,int> b) {
    return(a.second-a.first < b.second-b.first);
}

void solve() {
    int n;
    vector<pair<int,int>> V;
    pair<int,int> X;
    cin >> n;
    //first - Processor 1 time      second - Processor 2 time second
    int total = 0;
    for(int i = 0; i<2*n; i++) {
        cin >> X.first >> X.second;
        total += X.first;
        V.push_back(X);
    }
    
    sort(V.begin(), V.end(), Sort_);
    for(int i = 0; i<n; i++) {
        total += (V[i].second-V[i].first);
    }
    cout << total << endl;
}
int main() {
    solve();
}

//Question
// •Given n jobs {a1, a2, …, a2n} having execution time {t1, t2, …, t2n} respectively on processor 1 and 
//  execution time {e1, e2, …, e2n} respectively on processor 2.
// •Each processor is a uni-processor.
// •Task: Divide the jobs equally (n) among the processors such that the total execution time is minimized.