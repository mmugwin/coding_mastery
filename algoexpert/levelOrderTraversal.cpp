#include <queue>
#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *n = q.front();

        if (n->left != nullptr)
            q.push(n->left);

        if (n->right != nullptr)
            q.push(n->right);

        cout << n->data << " ";
        q.pop();
    }
}