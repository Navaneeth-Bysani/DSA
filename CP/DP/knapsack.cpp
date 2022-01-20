#include<bits/stdc++.h>
using namespace std;

int Maximum(int a, int b) {
    return a>b ? a : b;
}

int bounded(int N, int V, int C[], int P[]) {
    int K[N+1][V+1];
    for(int j = 0; j<V+1; j++)
        K[0][j] = 0;
    for(int i = 0; i<N+1; i++)
        K[i][0] = 0;
    
    for(int i = 1; i<N+1; i++) {
        for(int j = 1; j<V+1; j++) {
            if(C[i-1] <= j)
                K[i][j] = Maximum(K[i-1][j], P[i-1] + K[i-1][j-C[i-1]]);
            else
                K[i][j] = K[i-1][j];
        }
    }
    return K[N][V];
}

int unbounded(int N, int V, int C[], int P[]) {
    //Just a variation of coin change problem
    //Unbounded means, each item is available infinitely
    int T[V+1];
    fill_n(T,V+1,INT_MIN);
    T[0] = 0;
    // for(int i = 1; i<=V; i++) {
    //     for(int j = 0; j<N; j++) {
    //         if(C[j] <= i && T[i-C[j]] + P[j] > T[i]) {
    //             T[i] = T[i-C[j]] + P[j];
    //         }
    //     }
    // }
    int max;
    for(int i = 1; i<=V; i++) {
        max = 0;
        for(int j = 0; j<N; j++) {
            if(C[j] <= i) {
                if(max < P[j] + T[i-C[j]]) {
                    max = P[j] + T[i-C[j]];
                }
            }
        }
        T[i] = max;
    }
    return T[V];
}

int main() {
    //N - Number of items
    //V - Volume of the Knapsack
    //C - Volume of ith item
    //P - Price of ith item

    //
    int N = 4, V = 6;
    int C[] = {1,2,3,4};
    int P[] = {2,1,3,5};
    cout << "Output in Bounded case:  " << bounded(N,V,C,P) << endl;
    cout << "Output of Unbounded case:  " << unbounded(N,V,C,P) << endl;
}