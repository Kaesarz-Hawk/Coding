#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int val)
{
    Node *node = new Node;
    node->data = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node *insert(Node *root, int val)
{
    if (root == nullptr)
        return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int countTotal(Node *root)
{
    if (root == nullptr)
        return 0;
    return 1 + countTotal(root->left) + countTotal(root->right);
}

int countLeaves(Node *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main()
{
    Node *root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Total nodes: " << countTotal(root) << endl;
    cout << "Leaf nodes:  " << countLeaves(root) << endl;

    return 0;
}