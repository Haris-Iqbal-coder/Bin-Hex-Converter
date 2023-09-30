//========================================================
// Muhammad Haris Iqbal
// bst.cpp
//========================================================
#include <sstream>
#include <string>
#include <queue>

//========================================================
// Default constructor
// Precondition: None
// Postcondition: A new empty BST is created.
//========================================================
template <class T, class U> 
	BST<T,U>::BST (void)
{
    root = NULL;
}

//========================================================
// Destructor
// Precondition: None
// Postcondition: Deallocate the memory of the BST.
//========================================================
template <class T, class U> 
    BST<T,U>::~BST (void)
{
    deallocate(root);
}

//========================================================
// empty
// Checks if the BST is empty
// Precondition: None
// Postcondition: Return true if BST is empty, false otherwise.
//========================================================
template <class T, class U> 
bool    BST<T,U>::empty (void) const
{
    return (root == NULL);
}

//========================================================
// insert
// Inserts a new item to the BST.
// Precondition: d and k are data and key of Node.
// Postcondition: item is inserted.
//========================================================
template <class T, class U>
void    BST<T,U>::insert (T d, U k)
{
    // Create new Node
    Node *qtr;
	qtr = new Node;
    qtr->data = d;
    qtr->key = k;
    qtr->left = NULL;
    qtr->right = NULL;

    // Find position
    Node *ptr = NULL;
    Node *trav = root;
    while (trav != NULL)
    {
        ptr = trav;
        if (k < trav->key)
            trav = trav->left;
        else
            trav = trav->right;
    }

    // Insert Node
    qtr->p = ptr;
    if (ptr == NULL)
        root = qtr;
    else if (k < ptr->key)
        ptr->left = qtr;
    else
        ptr->right = qtr;
}

//========================================================
// search
// Searchs for the Node key k is in the BST root at ptr.
// Precondition: ptr is root of subtree and k is the key.
// Postcondition: Returns pointer point to key k
//========================================================
template <class T, class U>
typename BST<T,U>::Node*    BST<T,U>::search (Node *ptr, U k)
{
    while (ptr != NULL && k != ptr->key)
    {
        if (k < ptr->key)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return ptr;
}

//========================================================
// get 
// returns data of Node in BST with key k
// Precondition: k is the key.
// Postcondition: Returns the data at key k, T() if not found.
//========================================================
template <class T, class U>
T   BST<T,U>::get (U k)
{
    Node *ptr = search(root, k);

    if (ptr != NULL)
        return ptr->data;
    return T();
}

//========================================================
// transplant
// replaces one subtree as a child of its parent with another subtree.
// Precondition: u and v are root of subtree in BST
// Postcondition: replaces the subtree rooted at node u with
// the subtree rooted at node v.
//========================================================
template <class T, class U>
void    BST<T,U>::transplant (Node *u, Node *v)
{
    if (u->p == NULL) 
        root = v;
    else if (u == u->p->left)
        u->p->left = v;
    else
        u->p->right = v;

    if (v != NULL)
        v->p = u->p;
}

//========================================================
// remove
// Removes an Node with key k from the BST.
// Precondition: k is key of Node in the BST
// Postcondition: Node with key k is removed.
//========================================================
template <class T, class U>
void    BST<T,U>::remove (U k)
{
    Node *ptr = search(root, k);

    if (ptr != NULL)
    {
        if (ptr->left == NULL)
            transplant (ptr, ptr->right);
        else if (ptr->right == NULL)
            transplant (ptr, ptr->left);
        else
        {
            Node *successor = min(ptr->right);
            if (successor->p != ptr)
            {
                transplant (successor, successor->right);
                successor->right = ptr->right;
                successor->right->p = successor;
            }
            transplant (ptr, successor);
            successor->left = ptr->left;
            successor->left->p = successor;
        }
        delete ptr;  
    }
}

//========================================================
// max
// Searchs for Node with max key in the BST root at ptr.
// Precondition: ptr is root of subtree.
// Postcondition: Returns pointer point to max key
//========================================================
template <class T, class U>
typename BST<T,U>::Node*    BST<T,U>::max (Node *ptr)
{
    if (ptr != NULL)
        while (ptr->right != NULL)
            ptr = ptr->right;
    return ptr;
}

//========================================================
// min
// Searchs for Node with min key in the BST root at ptr.
// Precondition: ptr is root of subtree.
// Postcondition: Returns pointer point to min key
//========================================================
template <class T, class U>
typename BST<T,U>::Node*    BST<T,U>::min (Node *ptr)
{
    if (ptr != NULL)
        while (ptr->left != NULL)
            ptr = ptr->left;
    return ptr;
}

//========================================================
// max_data
// returns data of Node in BST with max key
// Precondition: None
// Postcondition: Returns data at Node with max key
//========================================================
template <class T, class U>
T   BST<T,U>::max_data (void)
{
    if (empty())
        return T();
    
    Node *ptr = max(root);
    return ptr->data;
}

//========================================================
// max_key
// returns the max key in BST
// Precondition: None
// Postcondition: returns the max key in BST
//========================================================
template <class T, class U>
U   BST<T,U>::max_key (void)
{
    if (empty())
        return U();
    
    Node *ptr = max(root);
    return ptr->key;
}

//========================================================
// min_data
// returns data of Node in BST with min key
// Precondition: None
// Postcondition: Returns data at Node with min key
//========================================================
template <class T, class U>
T   BST<T,U>::min_data (void)
{
    if (empty())
        return T();
    
    Node *ptr = min(root);
    return ptr->data;
}

//========================================================
// min_key
// returns the min key in BST
// Precondition: None
// Postcondition: returns the min key in BST
//========================================================
template <class T, class U>
U   BST<T,U>::min_key (void)
{
    if (empty())
        return U();
        
    Node *ptr = min(root);
    return ptr->key;
}


//========================================================
// successor
// returns the successor key in BST for the key k.
// Precondition: k is key of Node in the BST
// Postcondition: return the smallest key in BST that is larger than k.
//========================================================
template <class T, class U>
U   BST<T,U>::successor (U k)
{
    Node *ptr = search(root,k);

    // Return U() if key k has no successor
    if (ptr == NULL)
        return U();
    
    // Return min of right subtree
    if (ptr->right != NULL)
    {
        ptr = min(ptr->right);
        return ptr->key;
    }

    Node *s = ptr->p;
    while (s != NULL && ptr == s->right)
    {
        ptr = s;
        if (s->p == NULL)
            return U();
        s = s->p;
    }
    return s->key;
}

//========================================================
// trim
// trim the BST that every keys are in the interval [low, high]
// Precondition: low and high are keys closed interval.
// Postcondition: the BST is trimmed.
//========================================================
template <class T, class U>
void    BST<T,U>::trim (U low, U high)
{
    if (low <= high)
        trim_recur (root, low, high);
}

//========================================================
// trim_rec
// trim the BST root at ptr
// Precondition: ptr is root of subtree; low and high are keys interval.
// Postcondition: the subtree root at ptr is trimmed and
// return the root of subtree.
//========================================================
template <class T, class U>
typename BST<T,U>::Node*    BST<T,U>::trim_recur (Node *ptr, U low, U high)
{
    if (ptr == NULL)
        return NULL;
    
    // If key<low, keep the right subtree only
    if (ptr->key < low)
    {
        deallocate(ptr->left);
        transplant(ptr, ptr->right);
        delete ptr;
        return trim_recur(ptr->right, low, high);
    }

    // If key>high, keep the left subtree only
    if (ptr->key > high)
    {
        deallocate(ptr->right);
        transplant(ptr, ptr->left);
        delete ptr;
        return trim_recur(ptr->left, low, high);
    }
            
    // Recursively trim the left and right subtree
    ptr->left = trim_recur(ptr->left, low, high);
    ptr->right = trim_recur(ptr->right, low, high);
    return ptr;
}

//========================================================
// order_trav
// Recursively traverse through BST in ascending order
// Precondition: ptr is root of subtree; reference to stringstream stream
// Postcondition: push the keys of BST to the stream in ascending order.
//========================================================
template <class T, class U>
void    BST<T,U>::order_trav (stringstream &stream, Node *ptr)
{
    if (ptr != NULL)
    {
        order_trav (stream, ptr->left);
        stream << ptr->key << " ";
        order_trav (stream, ptr->right);
    }
}

//========================================================
// in_order
// Precondition: None
// Postcondition: Print a string of keys in BST in 
// ascending order separated by a single space.
//========================================================
template <class T, class U>
string  BST<T,U>::in_order (void)
{
    stringstream stream;
    order_trav (stream, root);
	string ret = stream.str();
    if (!ret.empty())
        ret.pop_back();
    return ret;
}

//========================================================
// to_string
// Precondition: None
// Postcondition: Print a string of keys in the BST 
// ordered from root to leaves and left to right.
//========================================================
template <class T, class U>
string  BST<T,U>::to_string (void)
{
    stringstream stream;
    if (root != NULL)
    {
        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            for (int i=0; i<size; i++) 
            {
                Node *ptr = q.front();
                q.pop();
                stream << ptr->key << " ";

                if (ptr->left != NULL)
                    q.push(ptr->left);
                if (ptr->right != NULL)
                    q.push(ptr->right);
            }
        }
    }

    string ret = stream.str();
    if (!ret.empty())
        ret.pop_back();
    return ret;
}

//========================================================
// deallocate
// Precondition: ptr is root of subtree
// Postcondition: Deallocate the memory of the BST root at ptr.
//========================================================
template <class T, class U>
void    BST<T,U>::deallocate (Node *ptr)
{
    if (ptr != NULL)
    {
        deallocate(ptr->left);
        deallocate(ptr->right);
        delete ptr;
    }
}
