#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class BST
{

    struct node
    {
        int data;
        node* left;
        node* right;
    };

    node* root;

    // deleting all tree
    node* makeEmpty(node* t)
    {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    // adding new element
    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    // find minimum data
    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    // find maximum data
    node* findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    // remove element that contains input data
    node* remove(int x, node* t)
    {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    // store all elements in sorted order
    void inorder(node* t, vector<node*> &nodes)
    {
        if(t == NULL)
            return;
        inorder(t->left, nodes);
        nodes.push_back(t);
        inorder(t->right, nodes);
    }

    // print tree by level
    void bylevel(node* t, int lvl)
    {
        if(t == NULL)
            return;
        bylevel(t->right, lvl+1);
        for(int i = 0; i < lvl; ++i)
            cout << "   ";
        cout << t->data << endl;
        bylevel(t->left, lvl+1);
    }

    // find elemnt that contents input data
    node* find(node* t, int x)
    {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }

    // build tree from vector
    node* BuildSimp(vector<node*> &nodes, int start, int end)
    {
        if (start > end)
            return NULL;
        int mid = (start + end) / 2;
        node* root = nodes[mid];
        root->left  = BuildSimp(nodes, start, mid-1);
        root->right = BuildSimp(nodes, mid+1, end);
        return root;
    }

    // build balanced tree
    node* BuildPwp(node* t)
    {
        vector<node*> nodes;
        inorder(t, nodes);
        int n = nodes.size();
        return BuildSimp(nodes, 0, n-1);
    }

    int MaxHeight(node* t)
    {
        if (t == NULL)
            return 0;
        if (t->left == NULL && t->right == NULL)
            return 1;
        if (t->left == NULL)
            return MaxHeight(t->right) + 1;
        if (t->right == NULL)
            return MaxHeight(t->left) + 1;
        return max(MaxHeight(t->right), MaxHeight(t->left)) + 1;
    }

    int MinHeight(node* t)
    {
        if (t == NULL)
            return 0;
        if (t->left == NULL && t->right == NULL)
            return 1;
        if (t->left == NULL)
            return MinHeight(t->right) + 1;
        if (t->right == NULL)
            return MinHeight(t->left) + 1;
        return min(MinHeight(t->right), MinHeight(t->left)) + 1;
    }

    bool IsBalanced (node* t)
    {
        if (t == NULL)
            return true;
        if (MaxHeight(t->right) - MinHeight(t->left) > 1 || MaxHeight(t->left) - MinHeight(t->right) > 1)
            return false;
        return true;
    }

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        root = makeEmpty(root);
    }

    node* getright()
    {
        return root->right;
    }

    node* getleft()
    {
        return root->left;
    }

    int getdata()
    {
        return root->data;
    }

    void insert(int x)
    {
        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }

    void display(int lvl)
    {
        bylevel(root, lvl);
        cout << endl;
    }

    void search(int x)
    {
        root = find(root, x);
    }

    void balance()
    {
        root = BuildPwp(root);
    }

    int maxh()
    {
        return MaxHeight(root);
    }

    int minh()
    {
        return MinHeight(root);
    }

    int maxhLEFT()
    {
        return MaxHeight(root->left)+2;
    }

    int minhLEFT()
    {
        return MinHeight(root->left)+1;
    }

    int maxhRIGHT()
    {
        return MaxHeight(root->right)+1;
    }

    int minhRIGHT()
    {
        return MinHeight(root->right)+1;
    }

    bool isbalanced()
    {
        return IsBalanced(root);
    }
};

#endif // BINARY_SEARCH_TREE_H
