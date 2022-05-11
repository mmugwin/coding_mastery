/*
You are given a list of ints that represents jobs that need to be completed.
You are also given a list of dependencies. A dependency is represented by a pair of jobs.
First listed job is the prerequisite of the second. 

Write a function that takes in a list of jobs and a list of dependencies and returns a list
containing a valid order in which the given jobs should be completed. If no such list exists (i.e.
there is a cycle in the graph) return an empty array.
*/

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// define the graph
class JobNode{
    public:
        int job;
        vector<JobNode*> prereqs;
        bool visited;
        bool visiting;

        //constructor
        JobNode(int job){
            this->job = job;
            prereqs = {};
            visited = false;
            visiting = false;
        }
};

class JobGraph{
    public:
        vector<JobNode *> nodes;
        unordered_map<int, JobNode*> graph;
        
        // constructor
        JobGraph(vector<int> jobs){
            nodes = {};
            for(int job: jobs){
                addNode(job);
            }
        }
        void addPrereq(int job, int prereq);
        void addNode(int job);
        JobNode* getNode(int job);
};

// graph class functions
void JobGraph::addPrereq(int job, int prereq){
    JobNode *jobNode = getNode(job);
    JobNode *prereqNode = getNode(prereq);
    jobNode->prereqs.push_back(prereqNode);
}

void JobGraph::addNode(int job){
    graph[job] = new JobNode(job);
    nodes.push_back(graph[job]);
}

JobNode* JobGraph::getNode(int job){
    if(graph.find(job) == graph.end()){
        addNode(job);
    }
    return graph[job];
}

JobGraph *createJobGraph(vector<int> jobs, vector<vector<int>> deps){
    JobGraph *graph = new JobGraph(jobs);
    for(vector<int> dep: deps){             // deps and dep are dependencies
        graph -> addPrereq(dep[1], dep[0]);
    }
    return graph;
}

bool dfs(JobNode *node, vector<int> *orderedJobs){
    if(node->visited) return false;
    if(node->visiting) return true;
    node->visiting = true;
    
    for(JobNode* prereqNode: node->prereqs) {
        bool containsCycle = dfs(prereqNode, orderedJobs);
        if (containsCycle) return true;
    }

    node->visited = true;
    node->visiting =  false;
    orderedJobs->push_back(node->job);
    std::cout << "Current job: " << node->job << "\n";
    return false;
}

vector<int> getOrderedJobs(JobGraph *graph){
    vector<int> orderedJobs = {};
    vector<JobNode*> nodes = graph->nodes;
    while(nodes.size()){
        JobNode *node = nodes.back();
        nodes.pop_back();
        bool containsCycle = dfs(node, &orderedJobs);
        if(containsCycle) return {};
    }
    return orderedJobs;
}

// solution O(V+E) time and space

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps){
    JobGraph *jobGraph = createJobGraph(jobs, deps);
    return getOrderedJobs(jobGraph);
}

int main(){
    vector<int> jobs = {1,2,3,4};
    vector<vector<int>> deps = {{1,2}, {1,3}, {3,2}, {4,2}, {4,3}};

    vector<int> topSort = topologicalSort(jobs, deps);

    std::cout << "Topological sort is: \n";
    for(int i = 0; i < topSort.size(); i++){
        cout << topSort[i] << " ";
    }
    cout << "\n";

    return 0;
}