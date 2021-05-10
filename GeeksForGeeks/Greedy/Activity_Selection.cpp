#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//Question - https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/

bool Sort(pair<int,int> a, pair<int,int> b) {
    return(a.second < b.second);
}
void solve() {
   int N;
   vector <pair<int,int>> V;
   pair<int,int> X;
   cin >> N;
   for(int i = 0; i<N; i++) {
       cin >> X.first >> X.second;
       V.push_back(X);
   }
   sort(V.begin(), V.end(), Sort);
   int last_task_end = V[0].second;
   int tasks = 1;

   for(int i = 1; i<N; i++) {
       if(V[i].first>=last_task_end) {
           tasks+=1;
           last_task_end = V[i].second;
       }
   }
   cout << tasks << endl;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}