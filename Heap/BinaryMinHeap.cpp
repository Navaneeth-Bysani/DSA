#include<bits/stdc++.h>
using namespace std;

class BinaryMinHeap {
    public:
        int size;
        int capacity;
        int *harr;
        BinaryMinHeap(int cap) {
            capacity = cap;
            size = 0;
            harr = new int[cap];
        }
        int parent(int i) {
            return (i-1)/2;
        }
        int left(int i) {
            return (2*i+1);
        }
        int right(int i) {
            return (2*i+2);
        }
        int getMin() {
            return harr[0];
        }
        void swap(int *a, int *b) {
            int temp = *a;
            *a = *b;
            *b = temp;
        }
        void insertKey(int k) {
            if(size == capacity) {
                cout << "Overflow of memory occured" << endl;
            }
            size++;
            int i = size-1;
            harr[i] = k;
            while(i != 0 && harr[parent(i)]>harr[i]) {
                swap(&harr[i], &harr[parent(i)]);
                i = parent(i);
            }
        }
        void decreaseKey(int i, int val) {
            harr[i] = val;
            while(i != 0 && harr[i]>harr[parent(i)]) {
                swap(&harr[i], &harr[parent(i)]);
                i = parent(i);
            }
        }
        void MinHeapify(int i) {
            int l = left(i);
            int r = right(i);
            int smallest = i;
            if(l<size && harr[l]<harr[smallest]) {
                smallest = l;
            }
            if(r<size && harr[r]<harr[smallest]) {
                smallest = r;
            }
            if(smallest != i) {
                swap(&harr[i], &harr[smallest]);
                MinHeapify(smallest);
            }
        }
        int extractMin() {
            if(size<=0) {
                cout << "No more elements exist" << endl;
                return INT_MAX;
            }
            if(size == 1) {
                size--;
                return harr[0];
            }
            int root = harr[0];
            harr[0] = harr[size-1];
            size--;
            MinHeapify(0);
            return root;
        }
        void deleteKey(int i) {
            decreaseKey(i, INT_MIN);
            extractMin();
        }

};