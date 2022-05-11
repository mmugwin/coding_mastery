#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>>& A) {
    int m = A.size();
    if (m == 0) return;
    if (m == 1) return;

    // https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/770/discuss/18872/A-common-method-to-rotate-the-image
    //clockwise rotate
    // reverse up<->down then swap

    //anticlockwise rotate
    // reverse left<->right then swap

    reverse(A.begin(), A.end());



    for (int i = 0; i < A.size(); i++) {

        for(int j = i+1; j < A[0].size(); j++){
            swap(A[i][j], A[j][i]);
        }

    //converting a 2D array index into a 1 d index
    // M[i][j] = m[i/n][i%n]

    }

}

int main() {
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {8, 9, 1}};
    // vector<vector<int>> B = 
    cout << "original matrix" << endl;

    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A.size(); j++) {
            std::cout<<A[i][j] << " ";
        }
        cout<<endl;
    }

    rotate(A);

    cout<<"\n new matrix" << endl;

    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A.size(); j++) {
            std::cout<<A[i][j] << " ";
        }
        cout<<endl;
    }

    return 0;
}