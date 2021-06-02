#include <iostream>
#include <vector>
using namespace std;

//Question - find the minimum element of an array which is sorted and then rotated at some pivot(unknown)
//0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2
//https://www.interviewbit.com/problems/rotated-array/

//exceptions - array must not contain any duplicate values
int main() {
    vector<int> A = {15,22,23,28,31,38,5,6,8,10,12};
    int n = A.size();
    int l = 0, h = n-1, mid;
    while(l<=h) {
        if(A[l] < A[h]) {
            cout << A[l] << endl;
            return 0;
        }
        mid = l + (h-l)/2;
        int next = (mid+1)%n, prev = (mid+n-1)%n;
        if(A[mid] < A[next] && A[mid] < A[prev]) {
            cout << A[mid] << endl;
            return 0;
        }
        if(A[mid] <= A[h]) {
            h = mid-1;
        } else if(A[mid] >= A[l]) {
            l = mid+1;
        }
    }
}

//This problem can also be asked as:
//1
//Find how many times an array has been right rotated
//Example - 0 1 2 3 4 5 6 7
//After first rotation - 7 0 1 2 3 4 5 6        (min element idx = 1)
//After second rotation - 6 7 0 1 2 3 4 5       (min element idx = 2)
//..........
//We can observe that, the number of times the array has been rotated is equal to the index of the minimum element in the rotated array
//Therefore the same approach can be used

//2
//Find an element in this type of sorted rotated array
//first, find the pivot element index. Pivot element is the element that is the minimum of all, (i.e., the element at which 
// the array has been rotated)
//then compare the required element with pivot element and last element to determine in which part of the array (either 0 to pivot-1 or 
// pivot to n-1)
//then apply binary search on that part of the array (either left or right to pivot)
//https://www.interviewbit.com/problems/rotated-sorted-array-search/