#include <bits/stdc++.h>
using namespace std;

//Question - https://leetcode.com/problems/reverse-pairs/

int method1(vector<int> nums) {
    int n = nums.size();
    int total = 0;

    for(int i = 0; i<n; i++) {
        for(int j = i+1; j<n; j++) {
            if((double)nums[i]/2 > (double)nums[j]) {
                total++;
            }
        }
    }

    return total;
}

void merge(vector<int> &nums, int s1, int e1, int s2, int e2, int &pairs) {
    int i = s1, j = s2;
    while(i<=e1) {
        while(j<=e2 && (nums[i] > 2*(long)nums[j])) {
            j++;
        }

        pairs += (j-s2);
        i++;
    }

    i = s1, j = s2;
    vector<int> temp;
    while(i<=e1 && j<=e2) {
        if(nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } else {
            temp.push_back(nums[j]);
            j++;
        }
    }

    while(i<=e1) {
        temp.push_back(nums[i]);
        i++;
    }
    while(j<=e2) {
        temp.push_back(nums[j]);
        j++;
    }

    for(auto a : temp) {
        nums[s1] = a;
        s1++;
    }
}

void mergeSort(vector<int> &nums, int l, int r, int &pairs) {
    if(l<r) {
        int mid = l + (r-l)/2;

        mergeSort(nums, l, mid, pairs);
        mergeSort(nums, mid+1, r, pairs);
        merge(nums, l, mid, mid+1, r, pairs);
    }
}

int method2(vector<int> nums) {
    int pairs = 0;
    mergeSort(nums, 0, nums.size()-1, pairs);

    return pairs;
}

int main() {
    vector<int> nums = {2,4,3,5,1};

    //Method1 is a brute force approach
    cout << method1(nums) << endl;

    //Method2 uses merge sort technique
    cout << method2(nums) << endl;
}