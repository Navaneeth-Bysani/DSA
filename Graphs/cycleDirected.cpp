#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/rKQaZuoUR4M
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#

class Graph {
    int V;
    int E;
    vector<vector<int>> G;
public:
    Graph(int v, int e) {
        V = v;
        E = e;
        for(int i = 0; i<V; i++) {
            G.push_back({});
        }
    }

    void addEdge(int a, int b) {
        G[a].push_back(b);
    }

    vector<int> adjList(int i) {
        return G[i];
    }
    void printMap(map<int,int> M) {
        for(auto m : M) {
            cout << m.first << " " << m.second << endl;
        }
    }

    bool isCyclic() {
        vector<bool> visited(V, false);
        vector<bool> visiting(V, false);
        map<int,int> M;
        for(int i = 0; i<V; i++) {
            if(visited[i] == false) {
                M[i] = -1;
                if(isCyclicUtil(i, visited, visiting, M)) {
                    cout << "Found a cycle" << endl;
                    // printMap(M);
                    
                    return true;
                }
            }
        }
        cout << "Didn't find cycle" << endl;
        printMap(M);
        return false;
    }
    bool isCyclicUtil(int i, vector<bool> &visited, vector<bool> &visiting, map<int,int> &M) {
        visited[i] = visiting[i] = true;
        for(auto c : G[i]) {
            if(visited[c] == false) {
                M[c] = i;
                if(isCyclicUtil(c, visited, visiting, M)) {
                    return true;
                }
            } else if(visiting[c] == true) {
                cout << "Path is: " << endl;
                cout << i << "-" << c <<endl;
                int x = i;
                while(M[x] != -1 && x != c) {
                        cout << M[x] << "-" << x << endl;
                        x = M[x];
                }
                return true;
            }
        }
        visiting[i] = false;
        return false;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    Graph G(V,E);
    int a,b;
    for(int i = 0; i<E; i++) {
        cin >> a >> b;
        G.addEdge(a,b);
    }

    G.isCyclic();
    return 0;
}