#include "tree.h"

#define DBG_PRINT 0

Tree::Tree(string first)
{
    this->H = new Node(first);
}


Node* Tree::insert(Node* p, Node *q) 
{
    auto cmp=q->name.compare(p->name);
#if DBG_PRINT
    cout << "Compare " << p->name << "," << q->name << " = " << cmp << endl;
#endif   
    if(!cmp) {
#if DBG_PRINT
        cout << "The two names are equal (" << q->name << ")" << endl;
#endif
        p->cnt++;    
        delete q;
    }
    if (cmp < 0) {
        // Name to add is smaller than current node
#if DBG_PRINT
        cout << "insert to left of " << p->name << endl;
#endif
        if(p->l) {
#if DBG_PRINT
            cout << "goint to " << p->l->name << endl;
#endif
            p->l=insert(p->l, q);
        } else {
#if DBG_PRINT
            cout << q->name << "<-" << p->name << endl;          
#endif
            p->l = q;
            return p;
        }
    } 
    if (cmp > 0) {
#if DBG_PRINT
        cout << "insert to right of " << p->name << endl;
#endif
        if(p->r) {
#if DBG_PRINT
            cout << "going to " << p->r->name << endl;
#endif
            p->r=insert(p->r, q);
        } else {
#if DBG_PRINT
            cout << p->name << "->" << q->name << endl;          
#endif
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