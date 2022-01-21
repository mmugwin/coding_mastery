/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). 
The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes 
a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge,
 and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source 
to destination, or false otherwise.
*/

#include <vector>
#include <iostream>
#include <stack>

// dfs using a stack

using namespace std;

bool validPath(int n, vector<vector<int>> &edges, int start, int end){
    vector<vector<int>> adjacency_list(n);
    for(vector<int> edge: edges){
        adjacency_list[edge[0]].push_back(edge[1]);
        adjacency_list[edge[1]].push_back(edge[0]);
    }

    std::cout << "Here is the adjacency list: \n";
    for(int i = 0; i < adjacency_list.size(); i++){
        for(int j = 0; j<adjacency_list[i].size(); j++)
            std::cout << adjacency_list[i][j] << " ";
        std::cout << "\n";
    }

    stack<int> st;
    st.push(start);
    vector<bool> seen(n);

    while(!st.empty()){
        // Get current node
        int node = st.top();
        st.pop();

        // Check if we have reached the target node
        if(node == end){
            return true;
        }

        // Check if we have already visited the node
        if(seen[node]){
            continue;
        }

        seen[node] = true;

        for(int neighbor : adjacency_list[node]) {
            st.push(neighbor);
        }
    }
    return false;
}

int main(){

// test 1
    // int graphsize = 3;
    // int source = 0;
    // int destination = 2;
    // vector<vector<int>> edgelist = {{0,1}, {1,2}, {2,0}};

// test 2
    int graphsize = 6;
    int source = 0;
    int destination = 5;
    vector<vector<int>> edgelist = {{0,1}, {0,2}, {3,5}, {5,4}, {4,3}};

    std::cout << "Check if path exists returned: " << validPath(graphsize, edgelist, source, destination) << "\n";

    return 0;
}