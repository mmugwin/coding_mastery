# Binary Trees

## Basic Concepts

### Definition of a binary tree

#### Class

```c++
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
```

#### Struct

```c++
struct TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode left, TreeNode right) : val(x), left(left), right(right) {}
};
```

### Applying Recursion to Binary Trees

- As a programmer using recursion, you should picture a binary tree as a root node with left and right subtrees of unknown and unconsidered structure.
- To employ the BRI. We will make recursive function calls and assume they return correct results without worrying about how the recursive process solves the overall problem.

To answer a question Q for tree T:

1. If tree T is of minimal size, directly assign a default value. Otherwise . . .
2. Make a recursive call to answer Q for the left subtree of T.
3. Make a recursive call to answer Q for the right subtree of T.
4. Inspect the value in the root node of T.
5. Use the results of the previous three steps to answer Q for all of T.

#### Example
Write a function that, when given a binary tree where each node holds an integer, returns the largest integer in the tree.

#### Solution

##### Plan

Applying the general plan to this specific problem results in the following
steps:
1. If the root of the tree has no children, return the value in the root.
Otherwise . . .
2. Make a recursive call to find the largest value in the left subtree.
3. Make a recursive call to find the largest value in the right subtree.
4. Inspect the value in the root node.
5. Return the largest of the values in the previous three steps.

##### Implementation

```c++
int maxValue(TreeNode* root) {
    if (root == nullptr) return 0;
    if (root -> right == nullptr && root -> left == nullptr)
        return root -> data;
    int leftMax = maxValue(root -> left);
    int rightLeft = maxValue(root -> right);
    int maxNum = root -> data;
    if(leftMax > maxNum) maxNum = leftMax;
    if(rightMax > maxNum) maxNum = rightMax;
    return maxNum;
}
```

#### Example

For a class that implements a binary tree, add a publicly accessible method that returns the number of leaves (nodes without children) in the tree. The counting of leaves should be performed using recursion.

#### Solution

##### Plan

1. If the root of the tree has no children, then the tree has one node total.
That node is a leaf by definition, so return 1. Otherwise . . .
2. Make a recursive call to count the leaves in the left subtree.
3. Make a recursive call to count the leaves in the right subtree.
4. In this case, there is no need to inspect the root node because if we get to
this step, there is no way the root is a leaf. So . . .
5. Return the sum of steps 2 and 3.

##### Implementation

```c++
class binaryTree {
    public:
        int publicCountLeaves();
    private:
        struct binaryTreeNode {
            int data;
            binaryTreeNode * left;
            binaryTreeNode * right;
        };
        typedef binaryTreeNode * treePtr;
        treePtr _root;
        int privateCountLeaves(treePtr rootPtr);
};

int binaryTree::privateCountLeaves(treePtr rootPtr) {
    if (rootPtr == NULL) return 0;
    if (rootPtr->right == NULL && rootPtr->left == NULL)
        return 1;
    int leftCount = privateCountLeaves(rootPtr->left);
    int rightCount = privateCountLeaves(rootPtr->right);
    return leftCount + rightCount;
}

int binaryTree::publicCountLeaves() {
    return privateCountLeaves(_root);
}
```

##### Iterative implementation using a stack

```c++
int binaryTree::stackBasedCountLeaves() {
    if (_root == NULL) return 0;
    int leafCount = 0;
    stack<binaryTreeNode *> nodes;
    nodes.push(_root);
    while (!nodes.empty()) {
        treePtr currentNode = nodes.top();
        nodes.pop();
        if (currentNode->left == NULL && currentNode->right == NULL)
            leafCount++;
        else {
            if (currentNode->right != NULL) nodes.push(currentNode->right);
            if (currentNode->left != NULL) nodes.push(currentNode->left);
        }
    }
    return leafCount;
}
```

### Tree traversals

Preorder

```c++
void preOrder(Node *root) {
    //base case
    if (root == nullptr)  return;

    // shout        
    std::cout << root->data << " ";
    std::cout << "\nroot stuff: " << (root->left);

    //left traversal
    preOrder(root->left);

    //right traversal
    preOrder(root->right);        
}
```

Post Order Traversal

```c++
void postOrder(Node *root) {
    //base case
    if(root == nullptr) return;

    if(root != nullptr){
        // left traversal
        postOrder(root ->left);

        // right traversal
        postOrder(root->right);

        // shout
        std::cout << root->data << " ";
    }
}
```

In Order Traversal

```c++
void inOrder(Node *root) {
    if(root == nullptr) return;

    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}
```

Level Order Traversal


```c++
void levelOrder(Node * root) {
    queue<Node*> tmp;
    tmp.push(root);

    while(!tmp.empty()) {
        Node* curr = tmp.front();
        if(curr->left) tmp.push(curr->left);
        if(curr->right) tmp.push(curr->right);
        curr = tmp.front();
        std::cout << curr->data << " ";
        tmp.pop();            
    }
}
```

## Basic Tree Checks Examples

### Qu: Same Tree

Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

### Ans

```c++
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;

        if(!p || !q) return false;

        if(p->val != q->val) return false;

        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    }
};
```

### Qu: Maximum Depth of a Binary Tree
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

### Ans

```c++
class Solution {
public:
  int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;
 
    vector<pair<int, TreeNode*>> my_stack;
    my_stack.push_back(pair<int, TreeNode*>(1, root));
      
    int max_depth = 0;
      
    while (!my_stack.empty()) {
      pair<int, TreeNode*> my_pair = my_stack.back();
      int c_depth = my_pair.first;
      TreeNode* c_node = get<1>(my_pair);
      max_depth = max(max_depth, c_depth);
      my_stack.pop_back();
        
      if (c_node->left != NULL)
        my_stack.push_back(pair<int, TreeNode*>(c_depth + 1, c_node->left));
        
      if (c_node->right != NULL)
        my_stack.push_back(pair<int, TreeNode*>(c_depth + 1, c_node->right));
    }
    return max_depth;
  }
};
 
```

Or

```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right)); 
    }
};
```

### Qu: Minimum Depth of a Binary Tree
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.

### Ans

```c++
class Solution {
public:
    int min_depth = INT_MAX;
    
    void calcDepth(TreeNode* root, int depth){
        if(!root) return;
        
        if(!root -> left && !root->right){
            min_depth = min(depth, min_depth);
            return;
        }
        
        calcDepth(root->left, depth + 1);
        calcDepth(root->right, depth + 1);
    }
    
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        calcDepth(root, 0);
        return min_depth + 1;
    }
};

```

### Qu: Maximum Depth of an N-ary Tree

Given a n-ary tree, find its maximum depth.

```c++
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
 
    Node() {}
 
    Node(int _val) {val = _val;}
 
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
```

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value

```c++
    Input: root = [1,null,3,2,4,null,5,6]
    Output: 3

    Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
    Output: 5
```

### Ans

```c++
class Solution {
public:
    
    int maxDepth(Node* root) {
        if (root == nullptr) 
            return 0;
        
        queue<Node*> q; 
        q.push(root);
        int depth = 0;
        
        while (!q.empty()) {
            depth += 1;
            int breadth = q.size();
            for (int _ = 0; _ < breadth; ++_) {
                auto node = q.front(); 
                q.pop();
                for (auto child : node->children) 
                    if (child) 
                        q.push(child);
            }
        }
        return depth;
    }
    
    int maxDepth1(Node* root) {
            
        if(!root) {
            return 0;
        }       
        int depth = 0;
        for(auto child: root->children){
            depth = max(depth, maxDepth(child));
        }        
        return 1 + depth;
    }
};
```

## Qu: Sum of Left Leaves

Given the root of a binary tree, return the sum of all left leaves.

## Ans

```c++
class Solution {
public:
    int sum = 0;
    
    int sumLeaves(TreeNode* node, bool isLeft){
        if(!node) return 0;
        if(!node->left && !node->right)
            return isLeft ? node->val : 0;
            
        return sumLeaves(node->left, true) + sumLeaves(node->right, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return sumLeaves(root, false);
    }
};
```

## Qu: Univalued Tree

A binary tree is uni-valued if every node in the tree has the same value.
Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

## Ans

```c++
class Solution {
public:
    vector<int> out;
    
    void preOrder(TreeNode * node){
        if(!node) return;
        out.push_back(node->val);
        
        preOrder(node->left);
        preOrder(node->right);    
    }
    
    bool isUnivalTree1(TreeNode* root) {
        if(!root) return false;
        preOrder(root);
        
        for(int i = 0; i < out.size()-1; i++){
            if(out[i] != out[i+1])
                return false;
        }        
        return true;
    }
    
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        
        if(root->left){
            if(root->val != root->left->val)
                return false;
        }
        
        if(root->right)
            if(root->val != root->right->val)
                return false;
        
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
```

## Qu: Diameter of Binary Tree
Given the ```root``` of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the ```root```.

The length of a path between two nodes is represented by the number of edges between them.

```
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
```

## Ans

```c++
class Solution {
public:   
    int dfs(TreeNode* node, int& diameter) {
        if(!node) return 0;
        
        int leftPath = dfs(node->left, diameter);
        int rightPath = dfs(node->right, diameter);
        
        diameter = max(diameter, leftPath + rightPath);
        cout << "Current diameter: " << diameter << endl;
        
        return max(leftPath, rightPath) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }
};
```

## Qu: Binary Tree Zigzag Level Order Traversal

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

## Ans

Sweet details [here](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/discuss/33825/c%2B%2B-5ms-version%3A-one-queue-and-without-reverse-operation-by-using-size-of-each-level)

```c++
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(!root) return {};

    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> out;

    bool leftToRight = true;

    while(!q.empty()) {
        int size = q.size();
        vector<int> row(size);

        for(int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();

            int index = leftToRight ? i : (size - 1 - i);
            row[index] = curr->val;

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right); 

        }
        leftToRight = !leftToRight;
        out.push_back(row);
    }

    return out;
}
``` 

<!-- ## Qu: 

## Ans

```c++

```

## Qu: 

## Ans

```c++

``` -->
