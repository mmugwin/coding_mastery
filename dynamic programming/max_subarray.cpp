#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int max_sub_array(vector<int> &nums){
    int overall_sum = nums[0];
    int curr_sum = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        if(curr_sum < 0){
            curr_sum = nums[i];
        } else{
            curr_sum += nums[i];
        }
        if(curr_sum > overall_sum){
            overall_sum = curr_sum;
        }
    }


    return overall_sum;
}

int main() {
    //Kadane's algorithm (used in computer vision)
    std::vector<int> nums = {1,2,3,4,7,8};
    std::cout << max_sub_array(&nums) << std::endl;
}