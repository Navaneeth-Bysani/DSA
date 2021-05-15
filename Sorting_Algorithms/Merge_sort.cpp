#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &A, int s1, int e1, int s2, int e2) {
    int i = s1, j = s2;
    vector<int> Aux;
    while(i<=e1 && j <= e2) {
        if(A[i]<=A[j]) {
            Aux.push_back(A[i]);
            i++;
        } else if(A[i] > A[j]) {
            Aux.push_back(A[j]);
            j++;
        }
    }
    
    while(i<=e1) {
        Aux.push_back(A[i]);
        i++;
    }
    
    while(j<=e2) {
        Aux.push_back(A[j]);
        j++;
    }
    
    for(int i = 0; i<Aux.size(); i++) {
        A[s1+i] = Aux[i];
    }
}
void merge_sort(vector<int> &A, int i, int j) {
    if(i < j) {
        int mid = (i+j)/2;
        merge_sort(A,i,mid);
        merge_sort(A,mid+1,j);
        merge(A,i,mid,mid+1,j);
    }
}
int main() {
	// merge sort
    vector<int> A = {9,5,7,8,4,3,5,5,6,6,2,1};
    int n = A.size();
    
    merge_sort(A,0,n-1);
    for(int i = 0; i<n ;i++) {
        cout << A[i] << " ";
    }
	return 0;
}
