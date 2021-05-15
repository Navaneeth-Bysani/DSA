#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &A, int i, int j) {
    int t = A[i];
    A[i] = A[j];
    A[j] = t;
    return;
}

void selection_sort(vector<int> &A, int n) {
    for(int i = 0; i<n; i++) {
        int min_idx = i;
        for(int j = i + 1; j<n; j++) {
            if(A[j]<A[min_idx]) {
                min_idx = j;
            }
        }
        swap(A,i,min_idx);
    }
}
int main() {
	// Selection sort 
	vector<int> A = {3,4,1,2,50,6,2,3,7,8};
	int n = A.size();
	selection_sort(A,n);
	for(int i = 0; i<n; i++) {
	    cout << A[i] << " ";
	}
	return 0;
}
