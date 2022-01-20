//Union/Find data structure by rank and using path compression
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent;
    vector<int> rank;

    public:
        DisjointSet(int N) {
            for(int i = 0; i<N; i++) {
                parent.push_back(i);
                rank.push_back(0);
            }
        }

        int findSet(int i) {
            if(parent[i] == i) {
                return i;
            }
            parent[i] = findSet(parent[i]);
            return parent[i];
        }

        void Union(int a, int b) {
            int Pa = findSet(a);
            int Pb = findSet(b);
            if(Pa == Pb) return;
            if(rank[Pa] == rank[Pb]) {
                parent[Pb] = Pa;
                rank[Pa] = rank[Pa]+1;
            } else if(rank[Pa] > rank[Pb]) {
                parent[Pb] = Pa;
                rank[Pa] += rank[Pb];
            } else {
                parent[Pa] = Pb;
                rank[Pb] += rank[Pa];
            }
        }
};

int main() {
    DisjointSet dj(6);
    cout << dj.findSet(5) << endl;
    dj.Union(0,1);
    cout << dj.findSet(1) << endl;
    dj.Union(2,3);
    dj.Union(4,5);
    cout << dj.findSet(5) << endl;
    dj.Union(2,5);
    cout << dj.findSet(5) << endl;
    cout << dj.findSet(2) << endl;
    dj.Union(0,5);
    cout << dj.findSet(0) << endl;
    cout << dj.findSet(5) << endl;
}