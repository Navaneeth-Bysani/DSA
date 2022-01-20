#include<bits/stdc++.h>
using namespace std;


void merge(long long arr[], long long s1, long long e1, long long s2, long long e2, long long int &inversions) {
    vector<long long> A;
    int i = s1, j = s2;
    while(i<=e1 && j<=e2) {
        if(arr[i]<=arr[j]) {
            A.push_back(arr[i]);
            i++;
        } else {
            A.push_back(arr[j]);
            j++;
            inversions += (e1-i+1);
        }
    }
    
    while(i<=e1) {
        A.push_back(arr[i]);
        i++;
    }
    
    while(j<=e2) {
        A.push_back(arr[j]);
        j++;
    }
    
    for(auto a : A) {
        arr[s1] = a;
        s1++;
    }
    
}
void merge_sort(long long arr[], long long l, long long r, long long int &inversions) {
    if(l < r) {
        int mid = l + (r-l)/2;
        merge_sort(arr, l, mid, inversions);
        merge_sort(arr, mid+1, r, inversions);
        merge(arr, l, mid, mid+1, r, inversions);
    }
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long int inversions = 0;
    merge_sort(arr, 0, N-1, inversions);
    return inversions;
}

int main() {
    long long X[] = {8,4,2,1};
    cout << inversionCount(X, 4) << endl; 
}


