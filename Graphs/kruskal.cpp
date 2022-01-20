#include <bits/stdc++.h>
using namespace std;

typedef struct Edge {
    int A;
    int B;
    int w;
} Edge;

bool comparator(Edge A, Edge B) {
    return A.w<B.w;
}

class DisjointSet {
    public:
    int *arr;
    int V;
    DisjointSet(int v) {
        V = v;
        arr = new int[v];
        for(int i = 0; i<V; i++) {
            arr[i] = -1;
        }
    } 
    int findSet(int a) {
        int i = a;
        while(arr[i] != -1) {
            i = arr[i];
        }
        return i;
    }
    int Union(int a, int b) {
        int pA = findSet(a);
        int pB = findSet(b);
        arr[pB] = pA;
        return pA;
    }

};

int kruskal(Edge A[], int V, int E) {
    
    sort(A, A+E, comparator);
    int minWeight = 0;
    DisjointSet Dj(V);
    cout << "Path is: ";
    for(int i = 0; i<E; i++) {
        int a = A[i].A;
        int b = A[i].B;
        if(Dj.findSet(a) != Dj.findSet(b)) {
            Dj.Union(a, b);
            minWeight += A[i].w;
            cout << a << "-" << b << " ";
        }
    }
    cout << endl;
    return minWeight;
}
int main() {
    int V, E;
    cin >> V >> E;
    Edge A[E];
    int a, b, w;
    for(int i = 0; i<E; i++) {
        cin >> a >> b >> w;
        A[i].A = a;
        A[i].B = b;
        A[i].w = w;
    }
    int MinWeight = kruskal(A,V,E);
    cout << "MinWeight: " << MinWeight << endl; 
}