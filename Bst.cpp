#include <iostream>
using namespace std ; 

struct node 
{
    node * left ;
    node * right ;
    int data ; 
} ;
class Bst
{
    private : node * root ; 
    public : 
    int x ;
    Bst()
    {
        root = NULL ;
    }
    node * insert(int value)
    {
        if(root == NULL)
        {
            root = new node ;
            root->data = value ;
            root->left = NULL ;
            root->right = NULL ;
            return root ;
        }
        else return insert(root , value) ;
    }
    node * insert(node * current , int value)
    {
        if(value < current->data)
        {
            if(current->left != NULL)
                insert(current->left , value) ;
            else 
            {
                node * newNode = new node ;
                newNode->left = newNode->right = NULL ;
                newNode->data = value ;
                current->left = newNode ;
            }
        }
        if(value > current->data)
        {
            if(current->right != NULL)
                insert(current->right , value) ;
            else 
            {
                node * newNode = new node ;
                newNode->left = newNode->right = NULL ;
                newNode->data = value ;
                current->right = newNode ;
            }
        }
    }
    node * find(node * current , int value)
    {
        if(current->data == value)
            return current ;
        node * ans = NULL ; 
        if(current->data > value && current->left != NULL)
            ans = find(current->left , value) ;
        if(current->data < value && current->right != NULL)
            ans = find(current->right , value) ;
        return ans ;
    }
    node * find(int value)
    {
        return find(root , value) ;
    }
    void inorder(node * current)
    {
        if(current == NULL)
            return ;
        inorder(current->left) ;
        cout<<current->data<<" " ;
        inorder(current->right) ;
    }
    void postorder(node * current)
    {
        if(current == NULL)
            return ;
        postorder(current->left) ;
        postorder(current->right) ;
        cout<<current->data<<" " ;
    }
    void preorder(node * current)
    {
        if(current == NULL)
            return ;
        cout<<current->data<<" " ;
        preorder(current->left) ;
        preorder(current->right) ;
    }
    void display(string type)
    {
        if(type == "preorder")
            preorder(root) ;
        if(type == "postorder")
            postorder(root) ;
        if(type == "inorder")
            inorder(root) ;
    }
    
} ;


int main()
{
    Bst test ;
    test.insert(10) ;
    test.insert(2) ;
    test.insert(1) ;
    test.insert(4) ;
    test.insert(13) ;
    test.insert(20) ;
    // cout<<(b->right)->data<<endl ;
    // cout<<test.x<<endl ;
    // return 0 ;
    test.display("inorder") ;
    cout<<endl ;
    test.display("preorder") ;
    cout<<endl ;
    test.display("postorder") ;
    // node * nn = test.find(4) ;
    // cout<<(nn->left)<<endl ;
    // test.pr() ;
    // cout<<tedata ;
}