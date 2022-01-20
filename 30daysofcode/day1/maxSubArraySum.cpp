#include <bits/stdc++.h>
using namespace std;


//Question - https://leetcode.com/problems/maximum-subarray/

void method1(vector<int> A) {
    int n = A.size();
    int MaxSum = INT_MIN;
    for(int i = 0; i<n; i++) {
        for(int j = i; j<n; j++) {
            int sum = 0;
            for(int k = i; k<= j; k++) {
                sum += A[k];
            }
            MaxSum = max(MaxSum, sum);
        }
    }

    cout << MaxSum << endl;
}

void method2(vector<int> A) {
    int n = A.size();
    int MaxSum = INT_MIN;

    for(int i = 0; i<n; i++) {
        int sum = 0;
        for(int j = i; j<n; j++) {
            sum += A[j];
            MaxSum = max(MaxSum, sum);
        }
    }

    cout << MaxSum << endl;
}

void method3(vector<int> A) {
    int n = A.size();
    int MaxSum = INT_MIN;
    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += A[i];
        MaxSum = max(MaxSum, sum);
        if(sum < 0) {
            sum = 0;
        }
    }

    cout << MaxSum << endl;
}

int main() {
    vector<int> A = {-2,1,-3,4,-1,2,1,-5,4};

    //Method 1 is a naive approach that uses three for loops, and takes O(N^3) Time
    method1(A);

    //Method 2 is a improved version of Method 1, where we remove the inner most loop, so T(n) --> O(N^2)
    method2(A);

    //Method 3 is called as Kadane's Algorithm, this performs the task in O(N) time
    method3(A);
}