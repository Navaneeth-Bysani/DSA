#include<iostream>
#include<vector>
using namespace std;

int main() {
    int v,e;
    cout << "Enter Number of vertices:  ";
    cin >> v;
    cout << "Enter Number of Edges: ";
    cin >> e;
    vector<int> V[v];
    int x,y;
    for(int i = 0; i<e; i++) {
        cin >> x >> y;
        V[x].push_back(y);
    }

    BFS(V,v);
}