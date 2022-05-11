#include <iostream>
#include <map>
#include <iostream>

using namespace std;

bool search2dMatrix(vector<vector<int>>& A, int target){
    // https://icarus.cs.weber.edu/~dab/cs1410/textbook/7.Arrays/row_major.html
    // https://leetcode.com/problems/search-a-2d-matrix/discuss/26219/Binary-search-on-an-ordered-matrix
    
    int row = A.size();
    int col = A[0].size();

    int left = 0;
    int right = row*col-1;

    while(left != right) {
        int mid = (left + right)/2;

        // if( A[mid] < target){
        if(A[mid / row][mid % row] < target)
            left = mid + 1;
        } else{
            right = mid;
        }

    }

    return target == A[right / m][right % m];
}


int main() {

    return 0;
}