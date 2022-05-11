/* 
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, 
find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can 
visit from node i (i.e., there is a directed edge from node i to node 
graph[i][j]).
*/

#include <iostream>
#include <vector>

using namespace std;

// DFS
void dfs(vector<vector<int>> &graph, int node, vector<int> &path, vector<vector<int>> &paths){
    path.push_back(node);
    if(node == graph.size()-1){
        paths.emplace_back(path);
    }

    vector<int> nextNodes = graph[node];

    for(int nextNode: nextNodes) {
        dfs(graph, nextNode, path, paths);
        path.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> paths;
    if(graph.size() == 0){
        return paths;
    }
    vector<int> path;
    dfs(graph, 0, path, paths);
    return paths;
}


int main(){
    vector<vector<int>> graph = {{1,2}, {3}, {3}, {}};
    vector<vector<int>> allPaths;
    allPaths = allPathsSourceTarget(graph);
    for (int i = 0; i < allPaths.size(); i++){
        for(int j = 0; j < allPaths[0].size(); j++){
            std::cout<< allPaths[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}