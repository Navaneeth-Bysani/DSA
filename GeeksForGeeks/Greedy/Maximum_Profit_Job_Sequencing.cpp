#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//Question - https://www.geeksforgeeks.org/job-sequencing-problem/

bool Sort_(pair<int,int> a, pair<int,int> b) {
    return (a.second > b.second);
}
void solve() {
    vector<pair<int,int>> V;
    pair<int,int> X;
    int N;
    cin >> N;
    int max_Deadline = 0;
    for(int i = 0; i<N; i++) {
        cin >> X.first >> X.second;
        if(max_Deadline < X.first) {
            max_Deadline = X.first;
        }
        V.push_back(X);
    }
    int S[max_Deadline+1];
    sort(V.begin(),V.end(),Sort_);
    for(int i = 0; i<max_Deadline+1; i++) {
        S[i] = -1;
    }
    
    int profit = 0;
    for(int i = 0; i<N; i++) {
        for(int j = V[i].first; j>=1; j--) {
            if(S[j] == -1) {
                S[j] = i;
                profit += V[i].second;
                break;
            }
        }
    }
    
    cout << "Maximum Profit is: " << profit << endl;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}