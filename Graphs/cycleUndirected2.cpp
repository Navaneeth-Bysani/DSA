//using dfs
#include<bits/stdc++.h>
using namespace std;

class Graph {
    vector<vector<int>> G;

    int E;
    int V;

    public:
        Graph(int v, int e) {
            V = v;
            E = e;
            for(int i = 0; i<v; i++) {
                G.push_back({});
            }
        }

        void addEdge(int a, int b) {
            G[a].push_back(b);
            G[b].push_back(a);
        }

        void isCyclic() {
            vector<bool> visited(V, false);

            for(int i = 0; i<V; i++) {
                if(visited[i] == false) {
                    if(isCyclicUtil(visited, i, -1)) {
                        cout << "Graph contains cycle" << endl;
                        return;
                    }
                }
            }
            cout << "Graph doesn't contains cycle" << endl;
        }

        bool isCyclicUtil(vector<bool> &visited, int v, int p) {
            visited[v] = true;
            for(auto x : G[v]) {
                if(visited[x] == false) {
                    if(isCyclicUtil(visited,x,v)) {
                        return true;
                    }
                } else {
                    if(x != p) {
                        return true;
                    }
                }
            }

            return false;
        }
};

int main() {
    Graph G(6, 6);
    G.addEdge(0,1);
    G.addEdge(0,5);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(3,4);
    G.addEdge(4,1);

    G.isCyclic();
}