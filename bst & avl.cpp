#include <bits/stdc++.h>
using namespace std;

struct Elem 
{
KEY key;
T data;
Elem *left;
Elem *right;
bool lthread;
bool rightThread; //normal right child link or a threadlink
};
Elem *_root; // a dummy root sentinel
int _size;
// helper method for inserting record into tree.
bool insert(Elem *& root, const KEY &key, const T &data, Elem *lastLeft);
void printTree(ostream& out, int level, Elem *p) const;
 void destructCode(Elem *& p);

bool insert(Elem *& root, const KEY &key, const T &data, Elem *lastLeft)
{
    // Searching for a Elem with given value
    Elem *ptr = root;
    Elem *par = NULL; // Parent of key to be inserted
    while (ptr != NULL)
    {
        // If key already exists, return
        if (key == (ptr->data))
        {
            printf("Duplicate Key !\n");
            return root;
        }
 
        par = ptr; // Update parent pointer
 
        // Moving on left subtree.
        if (key < ptr->data)
        {
            if (ptr -> lthread == false)
                ptr = ptr -> left;
            else
                break;
        }
 
        // Moving on right subtree.
        else
        {
            if (ptr->rightThread == false)
                ptr = ptr -> right;
            else
                break;
        }
    }
 
    // Create a new Elem
    Elem *tmp = new Elem;
    tmp -> data = key;
    tmp -> lthread = true;
    tmp -> rightThread = true;
 
    if (par == NULL)
    {
        root = tmp;
        tmp -> left = NULL;
        tmp -> right = NULL;
    }
    else if (key < (par -> data))
    {
        tmp -> left = par -> left;
        tmp -> right = par;
        par -> lthread = false;
        par -> left = tmp;
    }
    else
    {
        tmp -> left = par;
        tmp -> right = par -> right;
        par -> rightThread = false;
        par -> right = tmp;
    }
 
    return root;
}
 
struct Elem *inorderSuccessor(struct Elem *p)
{
    // If rightThread is set, we can quickly find
    if (p -> rightThread == true)
        return p->right;
 
    // Else return leftmost child of right subtree
    p = p -> right;
    while (p -> lthread == false)
        p = p -> left;
    return p;
}
 
// Printing the threaded tree

void printTree(ostream& out, int level, Elem *p) 
{
    if (out == NULL)
        printf("Tree is empty");
 
    // Reach leftmost Elem
    struct Elem *p = out;
    while (p -> lthread == false)
        p = p -> left;
 
    // One by one print successors
    while (p != NULL)
    {
        printf("%d ",p ->level);
        p = inorderSuccessor(p);
    }
}
 
 void destructCode(Elem *& p)
{  
    if (p == NULL) 
    return;  
  
    /* first delete both subtrees */
    destructCode(p->left);  
    destructCode(p->right);  
      
    /* then delete the Elem */
    cout << "\n Deleting Elem: " << p->data;  
    delete p; 
}  
#include <bits/stdc++.h>
using namespace std;

struct Elem 
{
Elem():left(0), right(0), height(-1), rightThread(false) {}
KEY key;
T data;
Elem *left;
Elem *right;
int height;
bool rightThread; //normal right child link or a threadlink
};
Elem *_root; // a dummy root sentinel
int _size;
// helper method for inserting record into tree.
bool insert(Elem *& root, const KEY &key, const T &data, Elem *lastLeft);
void printTree(ostream& out, int level, Elem *p) const;
 void destructCode(Elem *& p);

bool insert(Elem *& root, const KEY &key, const T &data, Elem *lastLeft)
{
    // Searching for a Elem with given value
    Elem *ptr = root;
    Elem *par = NULL; // Parent of key to be inserted
    while (ptr != NULL)
    {
        // If key already exists, return
        if (key == (ptr->data))
        {
            printf("Duplicate Key !\n");
            return root;
        }
 
        par = ptr; // Update parent pointer
 
        // Moving on left subtree.
        if (key < ptr->data)
        {
            if (ptr -> lthread == false)
                ptr = ptr -> left;
            else
                break;
        }
 
        // Moving on right subtree.
        else
        {
            if (ptr->rightThread == false)
                ptr = ptr -> right;
            else
                break;
        }
    }
 
    // Create a new Elem
    Elem *tmp = new Elem;
    tmp -> data = key;
    tmp -> lthread = true;
    tmp -> rightThread = true;
 
    if (par == NULL)
    {
        root = tmp;
        tmp -> left = NULL;
        tmp -> right = NULL;
    }
    else if (key < (par -> data))
    {
        tmp -> left = par -> left;
        tmp -> right = par;
        par -> lthread = false;
        par -> left = tmp;
    }
    else
    {
        tmp -> left = par;
        tmp -> right = par -> right;
        par -> rightThread = false;
        par -> right = tmp;
    }
 
    return root;
}
 
struct Elem *inorderSuccessor(struct Elem *p)
{
    // If rightThread is set, we can quickly find
    if (p -> rightThread == true)
        return p->right;
 
    // Else return leftmost child of right subtree
    p = p -> right;
    while (p -> lthread == false)
        p = p -> left;
    return p;
}
 
// Printing the threaded tree

void printTree(ostream& out, int level, Elem *p) 
{
    if (out == NULL)
        printf("Tree is empty");
 
    // Reach leftmost Elem
    struct Elem *p = out;
    while (p -> lthread == false)
        p = p -> left;
 
    // One by one print successors
    while (p != NULL)
    {
        printf("%d ",p ->level);
        p = inorderSuccessor(p);
    }
}
 
 void destructCode(Elem *& p)
{  
    if (p == NULL) 
    return;  
  
    /* first delete both subtrees */
    destructCode(p->left);  
    destructCode(p->right);  
      
    /* then delete the Elem */
    cout << "\n Deleting Elem: " << p->data;  
    delete p; 
}  

ELem* rotateRight(Elem *& node)

    {
        Elem* u = node->left;
        node->left = u->right;
        u->right = node;
        node->height = max(height(node->left), height(node->right))+1;
        u->height = max(height(u->left), node->height)+1;
		cout<<"Right- Rotation";
        return u;
    }
	
Elem* rotateLeft(Elem *& node)

    {
        Elem* u = node->right;
        node->right = u->left;
        u->left = node;
        node->height = max(height(node->left), height(node->right))+1;
        u->height = max(height(node->right), node->height)+1 ;
        return u;
    }	

Elem* doubleRotateRight(Elem *& node)


    {
        node->left = rotateRight(node->left);
        return rotateRight(node);
    }
	
 ELem* doubleRotateLeft(Elem *& node);

    {
        node->right = singleRightRotate(node->right);
        return rotateLeft(node);
    }
	
// Get Balance factor of node N  
int getBalance(Elem *curr)  
{  
    if (curr == NULL)  
        return 0;  
    return height(curr->left) - height(curr->right);  
}


int height(Elem *node)
return (node== NULL ? -1 : node->height);
