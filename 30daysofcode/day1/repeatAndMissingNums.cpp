#include<bits/stdc++.h>
using namespace std;
// Question - https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/
// Question - https://leetcode.com/problems/set-mismatch/
int main() {
    vector<int> A = {4,3,6,2,1,1};
    //One way is to sort the array and see for all valid indices i, if A[i] == A[i+1] for finding duplicate --> O(n*logn)
    //Using count sort technique, create an array temp of size n+1, intial values 0, and if encounter value v, then make temp[v]++ --> O(N), 
    // two pass
    //We can create a map, and while inserting into a map, if we find that the element to be inserted already exists, then that is the repeating
    //number. And we can go one more pass, from 1 to N to see if they exist. If we find something doesn't exist, that is the missing number
    //Another approach is:
    //S1 = (A[0]+A[1]+....A[n-1]) - (1+2+3+4+5...n) = x - y, x is the duplicate element and y is missing element
    //S2 = (A[0]*A[0]+A[1]*A[1]+A[2]*A[2]+...) - (1*1+2*2+3*3...) = x^2 - y^2
    //x-y = S1; x+y = S2/S1
    //solve x and y
    //Limitation: since we are working with squares, it may result int overflow, so we may use long long etc

    //Approach using XOR
    int xor1 = 0;
    int n = A.size();

    for(int i = 0; i<n; i++) {
        xor1 = xor1 ^ A[i];
    }

    for(int i = 1; i<=n; i++) {
        xor1 = xor1 ^ i;
    }

    int x = 0, y = 0;
    
    int set_bit_no = xor1 & ~(xor1-1);
    for(int i = 0; i<n; i++) {
        if(A[i] & set_bit_no) {
            x = x^A[i];
        } else {
            y = y^A[i];
        }
    }

    for(int i = 1; i<=n; i++) {
        if(i & set_bit_no) {
            x = x^i;
        } else {
            y = y^i;
        }
    }

    cout << "Missing element & repeating element are: " << x << "&" << y << endl;
    //In this approach we don't know which element is missing and which element is repeating. We may have to do one more pass to find that out

}