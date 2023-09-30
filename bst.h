//========================================================
// Muhammad Haris Iqbal
// bst.h
//========================================================
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#ifndef BST_H
#define BST_H

template <class T, class U>
class BST
{
private:
    // struct for Node for BST
    struct Node
    {
        T       data;
        U       key;
        Node 	*p;     // pointer to parent
        Node    *left;  // pointer to left child
        Node    *right; // pointer to right child
    };

    Node    *root;  // pointer to root of the tree
    Node*   search      (Node *ptr, U k);
    Node*   min         (Node *ptr);
    Node*   max         (Node *ptr);
    void    transplant  (Node *u, Node *v);
    void    deallocate  (Node *ptr);
    void    order_trav  (stringstream &stream, Node *ptr);
    Node*   trim_recur  (Node *ptr, U low, U high);

public: 
        BST         (void);
        ~BST        (void);
bool    empty       (void) const;
void    insert      (T d, U k);
T       get         (U k);
void    remove      (U k);
T       max_data    (void);
U       max_key     (void);
T       min_data    (void);
U       min_key     (void);
U       successor   (U k);
string  in_order    (void);
void    trim        (U low, U high);
string  to_string   (void);
};

#include "bst.cpp"

#endif
