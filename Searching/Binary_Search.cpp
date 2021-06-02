#include <iostream>
#include <vector>

using namespace std;

//This Algorithm works only on non-decreasing sorted array
int Binary_Search(vector<int> A, int element) {
    int n = A.size();
    int l = 0, h = n-1, mid;
    while(l<=h) {
        mid = l + (h-l)/2;
        if(A[mid] == element) {
            return mid;
        } else if(A[mid] < element) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> A = {1,5,7,10,12,16,19,25,100,300,600,700};
    int element = 300;
    int index = Binary_Search(A, element);
    if (index == -1) {
        cout << "element not found" << endl;
    } else {
        cout << "element found at Index : " << index << endl;
    }
}

//Common Errors:
//1. considering mid = (l+h)/2 -> This is not incorrect, but if l and h are considerable large values, 
//   then l+h may become even large and cause an integer overflow
//2. Not incrementing value of l and h correctly