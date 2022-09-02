#include "tree.h"

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

bool Tree::exists(Node *p, string name)
{
    if(!p) {
        return false;
    }
    if(p->name == name) {
        return true;
    }
    return (exists(p->l,name) || exists(p->r, name));
}

bool Tree::find(string name)
{
    return exists(H, name);
}


Node* Tree::delete_node(Node *p, string name) {
    if(!p) {
        return NULL;
    }
    return p;
}

void Tree::remove(string name)
{
    Node *t;
    Node *q;
    Node *p = this->H;
    if(!p)
        return;

    auto cmp=p->name.compare(name);
    if(!cmp) {
        // Found the node to delete
        //delete t;
    }
    if (cmp < 0) {
        // Name to add is smaller than current node
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
            // Delete this?
        }
    } 
    if (cmp > 0) {
        if(p->r) {
            p->r=insert(p->r, q);
        } else {
            p->r = q;
            // Delete this
        }
    }
    return ;    

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
#if DBG_PRINT   
    cout << order << endl;
#endif
    cout << "--- BEGIN TREE ---" << endl;
    print(this->H);
    cout << "--- END TREE ---" << endl;
    return;
}


void Tree::remove(Node *root)
{
    return;
}

Node* Tree::get_parent(string name, bool *found)
{
    Node *p=this->H;
    bool cont = true;
    
    *found=false;
    if(!this->H) {
        return NULL;
    }
    int cmp = name.compare(p->name);
    if(cmp == 0) {
        *found=true;
        cont = false;
        return NULL;
    }

    while(cont) {
        if(p->l)
        {
            cmp = name.compare(p->l->name);
            if(cmp == 0) {
                *found=true;
                cont = false;
                return NULL;
            } else if (cmp > 0) { // name  "a".compare("b") is <0 and "b".compare("a") >0
                // name > p, i.e. search left.
                p=p->l;
                cont=true;
            } else if (cmp > 0) { 
                p=p->r;
            }
        }
    }
    
    return p;
}

bool Tree::is_leaf(Node *node)
{
    if (!(node->l) && !(node->r)) {
       return true; 
    }
    return false;
}
