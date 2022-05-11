#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& A, int target){
    vector<int> idx;
    unordered_map<int, int> umap;

    for (int i =0; i<A.size(); i++){
        if(umap.find(target-A[i]) != umap.end()) {
            // std::cout << "umap[target-A[i]]: " << umap.find(8) << "\n";
            std::cout << "i: " << i << "\n";
            idx = {umap[target-A[i]], i};
            return idx;
        } else {
            umap[A[i]] = i;
        
        } // create the hashmap element
    }
    return idx;

    /*different complicated approach*/
    // unordered_map<int, vector<int>> B;
    // //create the hash table
    // for(int i = 0; i < A.size(); i++) {
    //     B[A[i]].push_back(i);
    // }

    // // sort the input array
    // sort(A.begin(), A.end());

    // // these are the two pointers we are going to use to iterate
    // int left = 0;
    // int right = A.size()-1;

    // while(left<right){
    //     if(A[left]+A[right] == target){

    //         if(A[left] == A[right]){
    //             idx.push_back(B[A[left]][0]);
    //             idx.push_back(B[A[left]][1]);

    //         } else{
    //             idx.push_back(B[A[left]][0]);
    //             idx.push_back(B[A[right]][0]);

    //         }
    //         break;

    //     } else if(A[left]+A[right] < target){
    //         left++;

    //     } else {
    //         right++;
    //     }

    // }

    //check for the sum



    // return idx;
}

int main() {
    vector<int> A = {2, 7, 11, 15};
    int b = 9;
    vector<int> idx = twoSum(A, b);
    for(int i = 0; i < idx.size(); i++)
        std::cout << idx[i]<< " ";
    std::cout << "\n";
    std::cout << "Hello world\n";
    return 0;
}