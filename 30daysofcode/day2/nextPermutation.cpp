#include <bits/stdc++.h>
using namespace std;

//Question - https://leetcode.com/problems/next-permutation/

void nextPermutation(vector<int> A) {
    int n = A.size();
    int idx1 = -1;
    for(int i = n-2; i>=0; i--) {
        if(A[i]<A[i+1]) {
            idx1 = i;
            break;
        }
    }

    if(idx1 == -1) {
        sort(A.begin(), A.end());
    }
    int idx2 = -1;
    for(int i = n-1; i>=0; i--) {
        if(A[i]>A[idx1]) {
            idx2 = i;
            break;
        }
    }

    swap(A[idx1], A[idx2]);

    int i = idx1+1;
    int j = n-1;
    while(i<j) {
        swap(A[i],A[j]);
        i++;
        j--;
    }

    for(auto a : A) {
        cout << a << " ";
    }
}

int main() {
    vector<int> A = {1,3,5,4,2};

    nextPermutation(A);
}