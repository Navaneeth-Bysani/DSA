//using union find data structure

#include<bits/stdc++.h>
using namespace std;

class DisJointSet {
    vector<int> dj;
    int N;
    public:
        DisJointSet(int n) {
            N = n;
            for(int i = 0; i<n; i++) {
                dj.push_back(i);
            }
        }

        int findSet(int x) {
            if(dj[x] == x){
                return dj[x];
            }

            dj[x] = findSet(dj[x]);
            return dj[x];
        }

        void Union(int a, int b) {
            int Pa = findSet(a);
            int Pb = findSet(b);

            dj[Pa] = Pb;
        }
};

class Graph {
    vector<vector<int>> G;
    vector<pair<int,int>> edgeList;
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
            edgeList.push_back(make_pair(a,b));
        }

        void isCyclic() {
            DisJointSet dj(V);

            for(auto e : edgeList) {
                if(dj.findSet(e.first) == dj.findSet(e.second)) {
                    cout << "Graph Contains cycle" << endl;
                    return;
                } else {
                    dj.Union(e.first, e.second);
                }
            }

            cout << "Graph doesn't contain cycle" << endl;
            return;
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