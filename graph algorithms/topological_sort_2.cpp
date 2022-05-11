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
#include <algorithm>

using namespace std;

// define the graph
class JobNode{
    public:
        int job;
        vector<JobNode*> deps;
        int numOfPrereqs;

        //constructor
        JobNode(int job){
            this->job = job;
            deps = {};
            numOfPrereqs = 0;
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
        void addDep(int job, int dep);
        void addNode(int job);
        JobNode* getNode(int job);
};

// graph class functions
void JobGraph::addDep(int job, int dep){
    JobNode *jobNode = getNode(job);
    JobNode *depNode = getNode(dep);
    jobNode->deps.push_back(depNode);
    depNode->numOfPrereqs++;
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
        graph -> addDep(dep[0], dep[1]);
    }
    return graph;
}

void removeDeps(JobNode* node, vector<JobNode*> *nodesWithNoPrereqs){
    while(node->deps.size()){
        JobNode *dep = node->deps.back();
        node->deps.pop_back();
        dep->numOfPrereqs--;
        if(!dep->numOfPrereqs) nodesWithNoPrereqs->push_back(dep);
    }
}

vector<int> getOrderedJobs(JobGraph *graph){
    vector<int> orderedJobs = {};
    vector<JobNode *> nodesWithNoPrereqs(graph->nodes.size());

    //syntactic judo that I haven't seen before here
    auto it = copy_if(graph->nodes.begin(), graph->nodes.end(),
                nodesWithNoPrereqs.begin(), [](JobNode *node) {return node->numOfPrereqs == 0;});
    nodesWithNoPrereqs.resize(distance(nodesWithNoPrereqs.begin(), it));
    while(nodesWithNoPrereqs.size()){
        JobNode *node = nodesWithNoPrereqs.back();
        nodesWithNoPrereqs.pop_back();
        orderedJobs.push_back(node->job);
        removeDeps(node, &nodesWithNoPrereqs);
    }

    bool graphHasEdges = false;
    for (JobNode *node : graph->nodes){
        if(node->numOfPrereqs){
            graphHasEdges = true;
        }
    }
    return graphHasEdges ? vector<int>{} : orderedJobs;
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