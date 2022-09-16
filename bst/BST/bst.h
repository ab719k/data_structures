#include <vector>
#include <string>
#include <iostream>


#ifndef _TREE_H
#define _TREE_H

using namespace std;

typedef struct node_t Node;
struct node_t {
    int v;
    int cnt;
    Node *l;
    Node *r;
    Node *p;
};
/*
    Node(int val)
    {
        v = val;
        cnt = 0;
        l = NULL;
        r = NULL;
        p = NULL;
    }

*/



class BST {
private:    
    Node *H; // Head Node
    Node* insert(Node* p, Node *q);
    void print(Node* p);
    bool exists(Node *p, int v);
    void inorder(Node* root);
    void remove(Node *root);
    Node* get_node(Node *h, int v);
    Node* get_parent(int v, bool *found);
    bool is_leaf(Node *N);
    Node* delete_node(Node *p);
    Node *delete_node(int v); // delete if exist
public:    
    BST() {
        H = NULL;
    }
    BST(int v);
    void insert(int v);
    bool find(int v);
    void remove(int v);
    void print(int order=0);   // Print with default as inorder,
};

#endif