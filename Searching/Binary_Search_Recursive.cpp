#include <iostream>
#include <vector>
using namespace std;

int Binary_Search_Recursive(vector<int> A, int element, int l, int h) {
    if(l>h) {
        return -1;
    } else {
        int mid = l + (h-l)/2;
        if(A[mid] == element) {
            return mid;
        } else if(A[mid] < element) {
            return Binary_Search_Recursive(A,element,mid+1,h);
        } else {
            return Binary_Search_Recursive(A,element,l,mid-1);
        }
    }
}

int main() {
    vector<int> A = {1,5,7,10,12,16,19,25,100,300,600,700};
    int element = 300;
    int n = A.size();
    int index = Binary_Search_Recursive(A,element,0,n-1);
    if(index == -1) {
        cout << "element not found" << endl;
    } else {
        cout << "element found at: " << index << endl;
    }
}

//Common Errors:
//1. considering mid = (l+h)/2 -> This is not incorrect, but if l and h are considerable large values, 
//   then l+h may become even large and cause an integer overflow
//2. Not incrementing value of l and h correctly