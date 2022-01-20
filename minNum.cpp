#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int> A, int l, int r) {
    if(l == r) return A[l];
    if(l == r+1) return min(A[l], A[r]);
    int mid = l + (r-l)/2;
    return min(findMin(A,l,mid),findMin(A,mid+1,r));
}


int main() {
    vector<int> A = {6,4,5,8,2,10};
    int l = 0;
    int r = A.size()-1;
    int ans = findMin(A,l,r);
    cout << ans << endl;
}


