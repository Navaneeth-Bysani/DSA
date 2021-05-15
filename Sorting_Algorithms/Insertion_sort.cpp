#include <iostream>
#include <vector>
using namespace std;

vector<int> insertion_sort(vector<int> A) {
    int value;
    int n = A.size();
    for(int i = 1; i<n; i++) {
        value = A[i];
        int j = i-1;
        while(j>=0 && A[j] > value) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = value;
    }
    cout << "Array sorted using Insertion sort: ";
    for(int i = 0; i<n; i++) {
        cout << A[i] << " ";
    }
    
    return A;
}
int main() {
	// insertion sort
	vector<int> A;
	A = {23,13,14,29,3};
	insertion_sort(A);
	return 0;
}
