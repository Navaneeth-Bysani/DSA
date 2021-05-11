#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Question - https://www.geeksforgeeks.org/job-sequencing-problem-loss-minimization/
bool Sort_(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) {
    return((float)a.first.second/(float)a.first.first > (float)b.first.second/(float)b.first.first);
}

//second - loss  first - time
void solve() {
    int N;
    cin >> N;
    vector<pair<pair<int,int>,int>> A;
    pair<pair<int,int>,int> X;
    for(int i = 0; i<N; i++) {
        cin >> X.first.first >> X.first.second;
        X.second = i+1;
        A.push_back(X);
    }
    sort(A.begin(), A.end(), Sort_);
    cout << "Optimised Job Sequence: ";
    for(int i = 0; i<N; i++) {
        cout << A[i].second << " ";
    }
}

int main() {
    solve();
}