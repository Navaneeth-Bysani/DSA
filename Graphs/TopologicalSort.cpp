#include<bits/stdc++.h>
using namespace std;

void TopSortUtil(map<int,vector<int>> M, int X, vector<int> A, set<int> &Visited, stack<int> &Ans) {
    Visited.insert(X);
    for(int i = 0; i<A.size(); i++) {
        if(Visited.find(A[i]) != Visited.end()) {
            continue;
        }
        TopSortUtil(M, A[i], M[A[i]], Visited, Ans);
    }
    Ans.push(X);
}

void TopSort(map<int,vector<int>> M, int V, int E) {
    set<int> Visited;
    stack<int> Ans;
    for(auto itr = M.begin(); itr != M.end(); itr++) {
        if(Visited.find(itr->first) != Visited.end()) {
            continue;
        }
        TopSortUtil(M,itr->first, itr->second,Visited, Ans);
    }

    while(Ans.empty() == 0) {
        cout << Ans.top() << " ";
        Ans.pop();
    }
}


int main() {
    map<int, vector<int>> M;
    int V, E;
    cin >> V >> E;
    int a, b;
    for(int i = 0; i<E; i++) {
        cin >> a >> b;
        M[a].push_back(b);
    }

    TopSort(M, V, E);
}