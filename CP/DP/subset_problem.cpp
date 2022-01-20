#include<bits/stdc++.h>
using namespace std;

bool SS(int A[], int n, int x) {
    if(n == 0) {
        if(x == 0)
            return 1;
        else
            return 0;
    }
    if(x == 0) {
        return 1;
    }
    return SS(A,n-1,x-A[n-1]) || SS(A,n-1,x);
}

int main() {
    int n,x;
    n = 4;
    int A[] = {3,4,12,5};
    cin >> x;
    bool z;
    z = SS(A,n,x);
    if(z) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}