#include <map>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

class Graph {
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    void addEdge(int v, int w);
    void DFS(int v);
};

void Graph::addEdge(int v, int w){
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS(int v){
    // Mark the current node as visited and print it
    visited[v] = true;
    std::cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

// Driver code
int main(){
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    int start = 1;
    cout << "\nFollowing is Depth First Traversal\n";
    cout << "Starting vertex: " << start << "\n";
    cout << "Output: \n";

    g.DFS(start);
    cout << "\n\n";

    return 0;
}