#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool containsDuplicate(vector<int>& nums) {

    sort(nums.begin(), nums.end());
    int curr = nums[0];
    for(int i = 1; i<nums.size(); i++){
        if(nums[i]==curr){
            return true;
        } else{
            curr = nums[i];
        }
    }
    return false;
}

int main() {
    std::vector<int> nums = {1,2,3,1};
    std::cout << "The output is " << containsDuplicate(nums) << std::endl;
    return 0;
}