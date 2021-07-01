#include<bits/stdc++.h>
using namespace std;

void DFS_visit(vector<vector<int>> G, vector<bool> &isVisited, int idx) {
    cout << idx << " ";
    isVisited[idx] = true;
    for(auto c : G[idx]) {
        if(isVisited[c] == false) {
            DFS_visit(G, isVisited, c);
        }
    }
}

void DFS(vector<vector<int>> G) {
    int V = G.size();
    vector<bool> isVisited(V, false);
    for(int i = 0; i<V; i++) {
        if(isVisited[i] == false) {
            DFS_visit(G, isVisited, i);
        }
    }
}
int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> G;
    G.resize(V);
    cout << "Enter edges: " << endl;
    int x, y;
    for(int i = 0; i<E; i++) {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    DFS(G);
}