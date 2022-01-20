#include<bits/stdc++.h>
using namespace std;

//Question - https://leetcode.com/problems/sort-colors/
int main() {
    vector<int> A = {2,0,2,1,1,0};
    //sort array using regular sorting techniques - O(n*logn)
    //counting sort - Count number of 0s, 1s, 2s in O(n) time, then populate the array based on those numbers - O(n) but two pass
    //Best approach, O(n) one pass

    int low = 0, mid = 0, high = A.size()-1;
    while(mid<=high) {
        switch(A[mid]) {
            case 0: {
                swap(A[low], A[mid]);
                mid++;
                low++;
                break;
            }
            case 1: {
                mid++;
                break;
            }
            case 2: {
                swap(A[mid], A[high]);
                high--;
                break;
            }
        }
    }
    cout << "Sorted array is: ";
    
    for(auto el : A) {
        cout << el << " ";
    }
}