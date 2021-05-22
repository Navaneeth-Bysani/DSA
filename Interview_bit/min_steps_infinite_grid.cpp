#include <bits/stdc++.h>
using namespace std;

//Question - https://www.interviewbit.com/problems/min-steps-in-infinite-grid/
int coverPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int steps = 0;
    for(int i = 1; i<n; i++) {
        steps += max(abs(A[i]-A[i-1]),abs(B[i]-B[i-1]));
    }
    return steps;
}

int main() {
    vector<int> A = {0,1,1};
    vector<int> B = {0,1,2};
    cout << coverPoints(A,B) << endl;
}

