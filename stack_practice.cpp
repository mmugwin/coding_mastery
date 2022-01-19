#include <stack>
#include <string>
#include <iostream>
#include <vector>


using namespace std;

vector<int> getMax(vector<string> operations) {
    stack<int> storage;
    vector<int> return_value;
    int prev = 0;
    string curr;
    int val_to_add;
    
    for(int i = 0; i<operations.size(); i++){
        curr = operations[i];
            
        if(curr[0] == '1'){
            val_to_add = std::stoi(curr.substr(2));
            if (storage.empty()){
                storage.push(val_to_add);
            }
            else if(val_to_add > prev){ 
                storage.push(val_to_add);
            } 
            prev = val_to_add;
                       
        } else if(curr[0] == '2'){
            // if(!storage.empty())
                storage.pop();

        } else{
            int a = storage.top();
            return_value.push_back(a);
        }
    }
    
    
    return return_value;
    
}

int main(){
    vector<std::string> ops = {"1 97", "2", "1 20", "2", "1 26", "1 20", "2", "3", "1 91", "3"};
    vector<int> res = getMax(ops);

    return 0;
}