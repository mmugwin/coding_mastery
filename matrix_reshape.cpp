#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> reshapeMat(vector<vector<int>> mat, int r, int c) {
    if(r*c != mat.size()*mat[0].size()) return mat;

    vector<vector<int>> mat2(r, vector<int>(c));

    int row;
    int col;
    
    for( int i = 0; i < r*c; i++) {
        row = i/c;
        col = i%c;
        mat2[i/c][i % c] = mat[i/mat[0].size()][i%mat[0].size()];
    }

    return mat2;
}

int main() {
    std::cout << "Hello World\n";
    vector<vector<int>> mat = {{1, 2}, {4, 5}};
    int r = 1;
    int c = 4;

    reshapeMat(mat, r, c);

    return 0;
}