#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Node{
    public:
        int val;
        vector<Node*> neighbors;
        Node(){
            val = 0;
            neighbors = vector<Node*>();
        }

        Node(int _val){
            val = _val;
            neighbors = vector<Node*>();
        }

        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
};

// dfs
class Solution{
    private:
        unordered_map<Node*, Node*> visited;

    public:
        Node* cloneGraph(Node* node){
            // base cases (null node or node has already been visited)
            if(!node) return node;
            if(visited[node]) return visited[node];

            Node* cloned = new Node(node->val);
            visited[node] = cloned;

            for(auto neighbor: node->neighbors){
                cloned->neighbors.push_back(cloneGraph(neighbor));                
            }
            return cloned;
        }

};


// bfs
Node* cloneGraphBFS(Node* node){
    if(!node) return node;
    unordered_map<Node*, Node*> visited;
    queue<Node*> Q;
    Q.push(node);
    visited[node] = new Node(node->val);

    while(!Q.empty()){
        int n = Q.size();
        Node* curr = Q.front();
        Q.pop();
        for(auto neighbor: curr->neighbors){
            if(!visited[neighbor]){
                visited[neighbor] = new Node(neighbor->val);
                Q.push(neighbor);
            }
            visited[curr]->neighbors.push_back(visited[neighbor]);
        }
    }
    return visited[node];
}


int main(){
    vector<vector<int>> adj = {{2,4}, {1,3}, {2,4}, {1,3}};

    return 0;
}