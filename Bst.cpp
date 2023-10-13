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
    Bst()
    {
        root = NULL ;
    }
    void insert(int value)
    {
        if(root == NULL)
        {
            root = new node ;
            root->data = value ;
            root->left = NULL ;
            root->right = NULL ;
        }
        else insert(root , value) ;
    }
    node * insert(node * current , int value)
    {
        if(current == NULL)
        {   
            node * newNode = new node ;
            newNode->left = newNode->right = NULL ;
            newNode->data = value ;
            return newNode ;
        }
        if(value > current->data)
            current->right = insert(current->right , value) ;
        else
            current->left = insert(current->left , value) ;
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
} ;


int main()
{
    Bst test ;
    test.insert(10) ;
    test.insert(50) ;
    test.insert(5) ;
    node * nn = test.find(4) ;
    cout<<(nn->left)<<endl ;
    // test.pr() ;
    // cout<<tedata ;
}