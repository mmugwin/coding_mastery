#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};
int result =  INT_MAX;

void compute(TreeNode* root, int depth){
    if(!root){
        return;
    }

    if(root->left == nullptr && root->right == nullptr) {
        result = min(result, depth);
    }

    compute(root->left, depth + 1);
    compute(root->right, depth + 1);

}

int minDepth(TreeNode* root){
    compute(root, 0);
    if(!root) {
        return 0;
    }
    return result + 1;
}


int main(){

    return 0;
}