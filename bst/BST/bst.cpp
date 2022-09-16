#include "bst.h"

using namespace std;

BST::BST(int x)
{
    this->H = new Node;
    this->H->cnt = 1;
    this->H->v = x;
    this->H->l = NULL;
    this->H->r = NULL;
    this->H->p = NULL;
}

inline void set_parent(Node *t) 
{
    if(t->l) 
        t->l->p=t;
    if(t->r) 
        t->r->p=t;
}

Node* insert_node(Node *p, int x) {   
    if(!p) {
        p = new Node;
        p->v =x;
        p->cnt = 1;
        p->l=p->r=NULL;
    } else {
        if(x > p->v) 
            p->r = insert_node(p->r,x);
        else if(x < p->v)
            p->l = insert_node(p->l,x);
        else // p->v == x 
            p->cnt++;
    }
    return p;
}


void BST::insert(int x)
{
    this->H = insert_node(this->H, x);
}


Node *find_node(Node *t, int x)
{
    if(!t || t->v == x) 
        return t;
    
    if(t->v > x) 
        return find_node(t->l, x); 

    return find_node(t->r, x); 
}

bool BST::find(int x)
{
    Node *t = find_node(this->H, x);

    if(t) 
        return true;
    else 
        return false;

}

void inorder_print(Node *p)
{
    if(p==NULL) return;
    printf("%d ", p->v);
    inorder_print(p->l);
    inorder_print(p->r);
}

void preorder_print(Node *p)
{
    if(p==NULL) return;
    printf("%d ", p->v);
    inorder_print(p->l);
    inorder_print(p->r);
}

void postorder_print(Node *p)
{
    if(p==NULL) return;
    printf("%d ", p->v);
    inorder_print(p->l);
    inorder_print(p->r);
}


// from geeksforgeeks
void print2DUtil(Node *root, int space)
{
    int COUNT=10;
    // Base case=
    if (root == NULL)
        return;
    // Increase distance between levels
    space+=COUNT;
    // Process right child first
    print2DUtil(root->r , space);
    // Print current node after space count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->v<<"\n";
    // Process left child
    print2DUtil(root->l, space);
}

void BST::print(int order)
{
    switch(order) {
        default:
        case 0:
            //inorder_print(this->H); 
            print2DUtil(this->H, 0);
            cout<< endl;   
        break;
        case 1:

        break;
        case 2:
        break;
    }
}

Node *minValueNode(Node *p) {
    Node *t = p;
    while(t && t->l != NULL) {
        t = t->l;
    }
    return t;
}

Node *maxValueNode(Node *p) {
    Node *t = p;
    while(t && t->r != NULL) {
        t = t->r;
    }
    return t;
}

Node * remove_node(Node *p, int v)
{
    if(p == NULL) 
        return NULL;

    if (v < p->v) {
        p->l = remove_node(p->l, v);
    } else if (v > p->v) {
        p->r = remove_node(p->r, v);
    } else {
        // node has no child, just deleted this node
        if ((p->l == NULL) && 
                (p->r == NULL)) {
            delete p;
            return NULL;
        } else if (p->l == NULL) {

        } else if (p->r == NULL) {
        
        }
        //
        
    }
    return p;
}
void BST::remove(int v)
{
   this->H =  remove_node(this->H,v);
}
#ifdef TEST_BSD_DEMO
vector<string> menu;

int display_menu()
{
    int choice;
    int item=0;
    printf("\n");
    printf("%d.Quit\n", item++);
    printf("%d.Insert\n", item++);
    printf("%d.Display\n", item++);
    printf("%d.Find minimum and maximum\n", item++);
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    return choice;
}

int main()
{
    BST Head;
    int choice = 255;
    while(choice != 0) {
        display_menu();
        switch(choice) {
            case 0:
            return EXIT_SUCCESS;
            break;
            case 1:
            cout << "Inserting";
            break;
            case 2:
            break;
            default:
            break;
        }
    }
    return EXIT_SUCCESS;
}

#endif