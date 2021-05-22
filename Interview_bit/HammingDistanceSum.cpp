#include <bits/stdc++.h>
using namespace std;

//Question - https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/
int hamming_sum(vector<int> A) {
    int n = A.size();
    int total = 0;
    bool allZero = 0;
    vector<int> B(n);
    for(int i = 0; i<n; i++) {
        B[i] = A[i];
    }
    int j = 0;
    while(j<=31) {
        int zeroes = 0, ones = 0;
        for(int i = 0; i<n; i++) {
            if(B[i]%2 == 0) {
                zeroes++;
            } else {
                allZero = 0;
                ones++;
            }
            B[i] = B[i]/2;
        }
        total = ((total%1000000007) + (2*ones*zeroes%1000000007))%1000000007;
        j++;
    }
    return total%1000000007;
}
int main() {
    vector<int> A = {2,4,6};
    int sum = hamming_sum(A);
    cout << sum;
}