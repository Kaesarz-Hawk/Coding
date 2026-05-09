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

Node *minNode(Node *root)
{
    while (root->left != nullptr)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int val)
{
    if (root == nullptr)
        return nullptr;

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else
    {
        if (root->left == nullptr)
        {
            Node *t = root->right;
            delete root;
            return t;
        }
        if (root->right == nullptr)
        {
            Node *t = root->left;
            delete root;
            return t;
        }

        Node *successor = minNode(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }

    return root;
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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

    cout << "Before: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, root->data);

    cout << "After:  ";
    inorder(root);
    cout << endl;

    return 0;
}