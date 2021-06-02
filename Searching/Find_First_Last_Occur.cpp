#include <iostream>
#include <vector>

using namespace std;

//Find first occurrence or last occurrence of an element in an array
int main() {
    vector<int> A = {1,5,7,10,12,16,16,19,19,25,25,25,25,25,25,100,300,600,700};
    bool searchingFirst;
    //if searching for first occurence put seachingFirst as true, and if searching for last Occurence put searchinFirst as false
    searchingFirst = false;
    int n = A.size();
    int l = 0, h = n-1;
    int mid;
    int ele = 25;
    int index = -1;
    while(l<=h) {
        mid  = l + (h-l)/2;
        if(A[mid] == ele) {
            index = mid;
            if(searchingFirst) {
                h = mid-1;
            } else {
                l = mid+1;
            }
        } else if(A[mid] < ele) {
            l = mid+1;
        } else {
            h = mid-1;
        }
    }
    if(index == -1) {
        cout << "element not found" << endl;
        return 0;
    }
    if(searchingFirst) {
        cout << "first occurence of element is at: " << index << endl;
    } else {
        cout << "last occurence of element is at: " << index << endl;
    }
    return 0;
}

//Applications
//1. Find number of occurrences of an element in an array -> last_occurence-first_occurence+1