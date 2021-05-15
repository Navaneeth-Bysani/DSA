#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &A, int i, int j) {
    int t = A[i];
    A[i] = A[j];
    A[j] = t;
    return;
}
void Bubble_sort(vector<int> &A, int n) {
    bool done = false;
    while(!done) {
        done = true;
        int i = 0;
        while(i<n-1) {
            if(A[i] > A[i+1]) {
                swap(A,i,i+1);
                done = false;
            }
            i++;
        }
    }
    for(int i = 0; i<n; i++) {
        cout << A[i] << " ";
    }
}
int main() {
	// Bubble sort 
	vector<int> A = {23,13,14,29,3,13,30};
	int n = A.size();
	Bubble_sort(A,n);
	return 0;
}
