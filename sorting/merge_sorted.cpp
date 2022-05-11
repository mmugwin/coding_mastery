#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& A, int m, vector<int>& B, int n) {
    int i = 0, j = 0, counter = 0;
    vector<int> newList;
    while(j < n && counter < m) {
        if(A[i]<=B[j] && A[i+1]>A[i]) {
            newList.push_back(A[i]);
            i++;
        } else if (B[j] <= A[i]) {
            newList.push_back(B[j]);
            j++;
        }
        counter++;
    }

    while(i < m && A[i] > A[i+2]) {
        newList.push_back(A[i]);
        i++;
    }

    while(j<n) {
        newList.push_back(B[j]);
        j++;
    }
}

void merge2(vector<int> &A, int m, vector<int> &B, int n) {
    int i = 2;
    int j = n-1;
    int k = i+j+1;

    while(i>=0 && j >= 0) {
        if(A[i] >= B[j]){
            A[k] = A[i];
            i--;
        }else{
            A[k] = B[j];
            j--;
        }
        k--;
    }
    while(j>=0 && k>=0){
        A[k] = B[j];
        j--;
        k--;
    }
}

int main() {
    vector<int> A = {1,2,3,0,0,0};
    vector<int> B = {2,5,6};
    int m = A.size();
    int n = B.size();
    merge2(A, m, B, n);

    return 0;
}


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1,j=n-1,k=m+n-1;
    while(i>=0 and j>=0)
    {
            if(nums1[i]<nums2[j])
            {
                    nums1[k--]=nums2[j--];
            }
            else
            {
                    nums1[k--]=nums1[i--];
            }
    }
        
    while(j>=0)
    {
            nums1[k--]=nums2[j--];
    }
       
    while(i>=0)
    {
            nums1[k--]=nums1[i--];
    }
}