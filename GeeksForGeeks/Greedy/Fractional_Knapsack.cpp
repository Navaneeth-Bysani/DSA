#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Question - https://www.geeksforgeeks.org/fractional-knapsack-problem/

//The following code only runs when the Value/Weight ratio for each item is an integer. Else we will have to change the data types.
bool Sort_Ratio(pair<int,int> a, pair<int,int> b) {
    return(a.second/a.first > b.second/b.first);
}

void solve() {
    vector<pair<int,int> >V;
    int N,W;
    cin >> N >> W;
    pair<int,int> X;
    for(int i = 0; i<N; i++) {
        cin >> X.first >> X.second;
        V.push_back(X);
    }
    sort(V.begin(),V.end(),Sort_Ratio);
    int total = 0;
    for(int i = 0; i<N; i++) {
        if(W>V[i].second) {
            total += V[i].first;
            W -= V[i].second;
        } else {
            total += W*(V[i].first/V[i].second);
            break;
        }
    }
    cout << total << endl;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}