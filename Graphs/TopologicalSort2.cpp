#include <bits/stdc++.h>
using namespace std;

class Graph {
    vector<vector<int>> G;

    int E;
    int V;

    public:
        Graph(int v) {
            V = v;
            E = 0;
            for(int i = 0; i<v; i++) {
                G.push_back({});
            }
        }

        void addEdge(int a, int b) {
            G[a].push_back(b);
            E++;
        }

        void TopSort() {
            vector<int> inDegree(V, 0);
            for(int i = 0; i<V; i++) {
                for(auto v : G[i]) {
                    inDegree[v]++;
                }
            }

            queue<int> q;
            for(int i = 0; i<V; i++) {
                if(inDegree[i] == 0) q.push(i);
            }

            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                cout << curr << " ";
                for(auto next : G[curr]) {
                    if(--inDegree[next] == 0) q.push(next);
                }
            }
        }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    // g.addEdge(1, 2);
    g.TopSort();
}

// Algorithm

// Initialize a queue, Q to keep a track of all the nodes in the graph with 0 in-degree.
// Iterate over all the edges in the input and create an adjacency list and also a map of node v/s in-degree.
// Add all the nodes with 0 in-degree to Q.
// The following steps are to be done until the Q becomes empty.
//  1. Pop a node from the Q. Let's call this node, N.
//  2. For all the neighbors of this node, N, reduce their in-degree by 1. If any of the nodes' in-degree reaches 0, add it to the Q.
//  3. Add the node N to the list maintaining topologically sorted order.
//  4. Continue from step 4.1.