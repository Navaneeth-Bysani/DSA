#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &A, int i, int j) {
    int t = A[j];
    A[j] = A[i];
    A[i] = t;
    return;
}

int partition(vector<int> &A, int start, int end) {
    int pivot, index, i;
    index = start;
    pivot = end;
    for(int i = start; i<end; i++) {
        if(A[i]<A[pivot]) {
            swap(A,i,index);
            index++;
        }
    }
    swap(A,pivot,index);
    return index;
}
void Quick_sort(vector<int> &A, int start, int end) {
    if(start>=end) {
        return;
    }
    int p_index = partition(A,start,end);
    Quick_sort(A,start,p_index-1);
    Quick_sort(A,p_index+1,end);
    return;
}

int main() {
	//Quick-Sort
	vector<int> A = {4,2,3,10,30,25,90,1,2};
	int n = A.size();
	
	Quick_sort(A,0,n-1);
	for(int i = 0; i<n; i++) {
	    cout << A[i] << " ";
	}
	return 0;
}
