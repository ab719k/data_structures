# Tree

Unlike Arrays, Linked Lists, Stack and queues, which are linear data structures, trees are hierarchical data structures. The topmost node is called root of the tree. The elements that are directly under an element are called its children. The element directly above something is called its parent. 

```
struct Node {
    string value;
    Node *l, *r;
}
```

One reason to use trees might be because you want to store information that naturally forms a hierarchy.

Depth First Traversals: 
(a) Inorder (Left, Root, Right) : 4 2 5 1 3 
(b) Preorder (Root, Left, Right) : 1 2 4 5 3 
(c) Postorder (Left, Right, Root) : 4 5 2 3 1
Breadth-First or Level Order Traversal: 1 2 3 4 5 


Reference 
[Tree](https://www.geeksforgeeks.org/binary-tree-set-1-introduction/)
