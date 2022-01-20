#include <bits/stdc++.h>
using namespace std;

//Question - https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/

void method1(vector<int> A1, vector<int> A2) {
    int i = 0;
    int n1 = A1.size(), n2 = A2.size();
    while(i<n1) {
        if(A1[i] < A2[0]) {
            i++;
            continue;
        }
        swap(A1[i], A2[0]);
        int j = 0;
        while(j<n2-1) {
            if(A2[j]>A2[j+1]) {
                swap(A2[j], A2[j+1]);
            } else {
                break;
            }
            j++;
        }
        i++;
    }

    cout << "sorted order: ";
    for(auto v : A1) {
        cout << v << " ";
    }

    for(auto v : A2) {
        cout << v << " ";
    }
    cout << endl;
}

int nextGap(int n) {
    if(n <= 1) {
        return 0;
    }

    return n/2 + n%2;
}
void method2(vector<int> A1, vector<int> A2) {
    int n1 = A1.size(), n2 = A2.size();
    int gap = n1+n2;
    int i = 0, j = 0;
    for(gap = nextGap(gap); gap>0; gap = nextGap(gap)) {
        for(i = 0; i + gap < n1; i++) {
            if(A1[i] > A1[i+gap]) {
                swap(A1[i], A1[i+gap]);
            }
        }

        for(j = (gap > n1) ? gap-n1 : 0; i < n1 && j < n2; i++, j++) {
            if(A1[i] > A2[j]) {
                swap(A1[i], A2[j]);
            }
        }

        if(j<n2) {
            for(j = 0; j+gap < n2; j++) {
                if(A2[j] > A2[j+gap]) {
                    swap(A2[j], A2[j+gap]);
                }
            }
        }
    }
    cout << "Sorted order: ";
    for(auto v : A1) {
        cout << v << " ";
    }

    for(auto v : A2) {
        cout << v << " ";
    }
    cout << endl;
}

void method3(vector<int> A1, vector<int> A2) {
    int n1 = A1.size(), n2 = A2.size();
    int n = n1+n2;
    int i = 0, j = 0, k = 0;
    int Max = INT_MIN;
    for(auto el : A1) {
        Max = max(Max, el);
    }
    for(auto el : A2) {
        Max = max(Max, el);
    }
    Max++;
    while(i < n1 && j < n2 && k < n) {
        int e1 = A1[i]%Max;
        int e2 = A2[j]%Max;

        if(e1<=e2) {
            if(k<n1) {
                A1[k] += (e1*Max);
            } else {
                A2[k-n1] += (e1*Max);
            }
            i++;
            k++;
        } else {
            if(k<n1) {
                A1[k] += (e2*Max);
            } else {
                A2[k-n1] += (e2*Max);
            }
            j++;
            k++;
        }
    }

    while(i<n1) {
        int e1 = A1[i]%Max;
        if (k < n1)
            A1[k] += (e1 * Max);
        else
            A2[k - n1] += (e1 * Max);
        i++;
        k++;
    }
    while(j<n2) {
        int e2 = A2[j]%Max;
        if (k < n1)
            A1[k] += (e2 * Max);
        else
            A2[k - n1] += (e2 * Max);
        j++;
        k++;
    }

    for(int i = 0; i<n1; i++) {
        A1[i] = A1[i]/Max;
    }
    for(int j = 0; j<n2; j++) {
        A2[j] = A2[j]/Max;
    }
    cout << "Sorted Order: ";
    for(auto x : A1) {
        cout << x << " ";
    }
    for(auto x : A2) {
        cout << x << " ";
    }
}

int main() {
    vector<int> A1 = {3, 27, 38, 43};
    vector<int> A2 = {9, 10, 82};

    //Naive approach is to create an array of length n1+n2 and insert all the elements of both the arrays into that array and then sort
    //the array. --> O(n1+n2 log(n1+n2)) + O(n1+n2) + O(n1+n2) & Space complexity --> O(n1+n2)

    //Second approach is to leverage the fact that the arrays are already sorted --> O(n1*n2) Space --> O(1)
    method1(A1,A2);
    

    //Third approach is called the gap method, --> O((n1+n2)*log(n1+n2)) space --> O(1)
    method2(A1,A2);


    //Fourth approach --> O(n1+n2)
    method3(A1, A2);
}