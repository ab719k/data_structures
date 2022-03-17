#include <vector>
#include <string>
#include <iostream>


#ifndef _TREE_H
#define _TREE_H

using namespace std;

struct Node {
    string name;
    int cnt;
    struct Node *l;
    struct Node *r;
    struct Node *p;
    
    Node(string val)
    {
        name = val;
        cnt = 0;
        l = NULL;
        r = NULL;
        p = NULL;
    }

};


class Tree {
private:    
    Node *H;
    Node* insert(Node* p, Node *q);
    void print(Node* p);
    bool find(Node *p, string name);
    void inorder(Node* root);
public:    
    Tree() {
        H = NULL;
    }
    Tree(string first);
    void insert(string name);
    bool find(string name);
    void remove(string name);

    // Print with default as inorder, 
    void print(int order=0);
};

#endif