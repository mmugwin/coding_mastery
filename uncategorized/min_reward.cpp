/*
You have an unsorted list of scores and you wish to give the students who earned the scores rewards such that 
1. All students must receive at least one reward
2. Any given student must recieve strictly more rewards that any adjacent student with a lower score and strictly 
fewer rewards than any student with a higher score.

Write a function that takes in a list of scores and returns the minimum number of rewards that you must give out
to students to satisfy the two two rules, assuming all scores are unique
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// naive
// O(n^2) time | O(n) space
int minRewardsNaive(vector<int> scores){
    vector<int> rewards = vector<int>(scores.size(), 1);

    for(int i = 1; i < scores.size(); i++){
        int j = i - 1; // pointer to previous index/score
        if(scores[i] > scores[j]){
            rewards[i] = rewards[j] + 1;
        } else {
            while(j >= 0 && scores[j] > scores[j+1]) {
                rewards[j] = max(rewards[j], rewards[j+1] + 1);
                j--;
            }
        }
    }
    return accumulate(rewards.begin(), rewards.end(), 0);
}


// peaks and valleys
void expandLR(int idx, vector<int> scores, vector<int> *rewards);
vector<int> getLocalMinIdx(vector<int> array);
int minRewardsPeaksAndValleys(vector<int> scores){
    vector<int> rewards = vector<int>(scores.size(), 1);
    vector<int> localMinIdx = getLocalMinIdx(scores);
    
    for(int idx: localMinIdx){
        expandLR(idx, scores, &rewards);
    }

    return(accumulate(rewards.begin(), rewards.end(), 0));
}

vector<int> getLocalMinIdx(vector<int> array){
    if(array.size() == 1){
        return vector<int> {0};
    }
    vector<int> localMinIndx;

    for(int i = 0; i < array.size(); i++){
        if(i == 0 && array[i] < array[i+1]){
            localMinIndx.push_back(i);
        }
        if(i == array.size()-1 && array[i]<array[i-1]){
            localMinIndx.push_back(i);
        }
        if(i == 0 || i == array.size()-1){
            continue;
        }
        if(array[i] < array[i-1] && array[i]<array[i]+1){
            localMinIndx.push_back(i);
        }
    }
    return localMinIndx;
}

void expandLR(int idx, vector<int> scores, vector<int> *rewards){
    // expand to the left
    int leftIdx = idx-1;
    while (leftIdx >=0 && scores[leftIdx] > scores[leftIdx+1]){
        rewards->at(leftIdx) = max(rewards->at(leftIdx), rewards->at(leftIdx + 1)+1);
        leftIdx--;
    }

    //expand to the right
    int rightIdx = idx-1;
    while (rightIdx < scores.size() && scores[rightIdx] > scores[rightIdx - 1]){
        rewards->at(rightIdx) = rewards->at(rightIdx-1)+1;
        rightIdx++;
    }
}

// elegant: L->R sweep; R->L sweep
int minRewardsElegant(vector<int> scores){
    vector<int> rewards(scores.size(), 1);

    for(int i = 1; i < scores.size(); i++){
        if(scores[i] > scores[i-1]){
            rewards[i] = rewards[i-1]+1;
        }
    }

    for(int i = scores.size()-2; i >= 0; i--){
        if(scores[i] > scores[i+1]){
            rewards[i] = max(rewards[i], rewards[i+1]+1);
        }
    }

    return accumulate(rewards.begin(), rewards.end(), 0);
}

int main(){
    vector<int> scores = {8, 4, 2, 1, 3, 6, 7, 9, 5};
    std::cout << "Min rewards, naive: " << minRewardsNaive(scores) << "\n";
    std::cout << "Min rewards, peaks and valleys technique: " << minRewardsNaive(scores) << "\n";
    std::cout << "Min rewards, L<->R sweep (elegant): " << minRewardsElegant(scores) << "\n";

    return 0;
}