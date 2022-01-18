#include <vector>
#include <utility>
#include <unordered_map>
#include <deque>
#include <unordered_set>

using namespace std;

// utility does the magic of including the pair, you dig. 

class BinaryTree{
    public: 
        int value;
        BinaryTree* left = nullptr;
        BinaryTree* right = nullptr;
        BinaryTree(int value) {
            this->value = value;
        }
};

// this here is a level order traversal son
vector<int> bfsNodesDistanceK(BinaryTree* targetNode, int k, 
                              unordered_map<int, BinaryTree*> nodesMap){
    deque<pair<BinaryTree*, int>> queue = {pair<BinaryTree*, int> (targetNode, 0)};
    unordered_set<int> seen = {targetNode->value};
    while(queue.size()>0){
        auto currentNode = queue.front().first;
        auto distFromTarget = queue.front().second;

        queue.pop_front();

        if(distFromTarget == k) {
            vector<int> nodesDistanceK;
            for(auto item: queue){
                nodesDistanceK.push_back(item.first->value);
            }
            nodesDistanceK.push_back(currentNode->value);
            return nodesDistanceK;
        }

        vector<BinaryTree* > connectedNodes = {
            currentNode->left,
            currentNode->right,
            nodesMap[currentNode->value]
        };

        for(auto node: connectedNodes){
            if(!node)
                continue;
            
            if(seen.find(node->value) != seen.end())
                continue;

            seen.insert(node->value);
            queue.push_back(pair<BinaryTree*, int>(node, distFromTarget + 1));
        }
    }
    return {};
}

BinaryTree *getNode(int value, BinaryTree* root, unordered_map<int, 
                    BinaryTree*> &nodesMap){
    if(root->value == value)
        return root;

    auto node = nodesMap[value];
    if (node->left && node->left->value == value)
        return node->left;

    return node->right;
}

// this is a modified inorder traversal that quieries a map with keys as the values of the binary tree
// and the values as the pointers to the node
void populateNodesMap(BinaryTree *node, unordered_map<int, BinaryTree*> &nodesMap,
                            BinaryTree *root){
    if(node){
        nodesMap[node->value] = root;
        populateNodesMap(node->left, nodesMap, node);
        populateNodesMap(node->right, nodesMap, node);
    }

}

// solution
vector<int> findNodesDistanceK(BinaryTree* node, int target, int k){
    unordered_map<int, BinaryTree *> nodesMap;
    populateNodesMap(node, nodesMap, nullptr);          // use an inorder travesal to do this
    auto targetNode = getNode(target, node, nodesMap);  // 
    return bfsNodesDistanceK(targetNode, k, nodesMap);
}
