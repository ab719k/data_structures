#include "tree.h"

Tree::Tree(string first)
{
    this->H = new Node(first);
}


Node* Tree::insert(Node* p, Node *q) 
{
    auto cmp=q->name.compare(p->name);
    cout << "Compare " << p->name << "," << q->name << " = " << cmp << endl;
    if(!cmp) {
        cout << "The two names are equal (" << q->name << ")" << endl;
        p->cnt++;    
        delete q;
    }
    if (cmp < 0) {
        // Name to add is smaller than current node
        cout << "insert to left of " << p->name << endl;
        if(p->l) {
            cout << "goint to " << p->l->name << endl;
            p->l=insert(p->l, q);
        } else {
            cout << q->name << "<-" << p->name << endl;          
            p->l = q;
            return p;
        }
    } 
    if (cmp > 0) {
        cout << "insert to right of " << p->name << endl;
        if(p->r) {
            cout << "going to " << p->r->name << endl;
            p->r=insert(p->r, q);
        } else {
            cout << p->name << "->" << q->name << endl;          
            p->r = q;
            return p;
        }
    }
    return p;
}

void Tree::insert(string name)
{
    struct Node *tmp = new Node(name);
    if ( H == NULL) {
        H=tmp;
        return;
    }
    this->H = this->insert(this->H, tmp);
}


bool Tree::find(Node *p, string name)
{
    if(!p) {
        return false;
    }
    if(p->name == name) {
        return true;
    }
    return (find(p->l,name) || find(p->r, name));
}

bool Tree::find(string name)
{
    return find(this->H, name);
}

void Tree::remove(string name)
{


}

void Tree::print(Node* p) 
{
    if(!p) return;
    cout << p->name << endl;
    this->print(p->l);
    this->print(p->r);
    return;
}

// A utility function to do
// inorder traversal of BST
void Tree::inorder(Node* root)
{
    if (root != NULL) {
        inorder(root->l);
        cout << root->name;
        inorder(root->r);
    }
} 

// Print with default as inorder, 
void Tree::print(int order)
{
    //while(this->)
    //cout << "not yet" << endl;
    cout << order << endl;
    print(this->H);
    return;
}