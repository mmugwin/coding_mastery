#include <iostream>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int fib(int n){
    if (n==0 || n==1) return 1;
    return fib(n-1) + fib(n-2);
}

int fib_d(int n, map<int, int> fib_map){
    if(n<=1) return 1;
    auto it = fib_map.find(n);
    if(it!=fib_map.end()) return it->second;
    return fib_map[n] = fib_d(n-1, fib_map) + fib_d(n-2, fib_map);
}

    bool isValid(string s) {
        stack<char> A;
        A.push(s[0]);
        int i = 1;
        while(!A.empty()) {
            if(s[i] == '(' || s[i]=='{' || s[i]=='['){
                A.push(s[i]);
            } else if(s[i] == ')' && A.top() == '(') {
                A.pop();
            } else if(s[i] == ']' && A.top() == '[') {
                A.pop();
            } else if(s[i] == '}' && A.top() == '{}') {
                A.pop();
            } else {
                return false;
            }
            i++;
        }
        
        return A.empty();
        
    }

int main(){
    
    std::map<int, int> values;
    std::cout<<"The fibonacci number with memoization is: " << fib_d(7, values) << "\n";
    std::cout<<"The fibonacci number is: " << fib(7) << "\n";

    return 0;
}