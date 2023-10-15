#include <Bst.hpp>
#include <iostream>
#include<vector>
using namespace std;

// Bst::Bst() { root = NULL; }
void Bst::insert(int value)
{
  if (root == NULL)
  {
    root = new node;
    root->data = value;
    root->left = NULL;
    root->right = NULL;
  }
  else
    insert(root, value);
}
void Bst::insert(node *current, int value)
{

  if (value < current->data)
  {
    if (current->left != NULL)
      insert(current->left, value);
    else
    {
      node *newNode = new node;
      newNode->left = newNode->right = NULL;
      newNode->data = value;
      current->left = newNode;
    }
  }
  if (value > current->data)
  {
    if (current->right != NULL)
      insert(current->right, value);
    else
    {
      node *newNode = new node;
      newNode->left = newNode->right = NULL;
      newNode->data = value;
      current->right = newNode;
    }
  }
}
node * findMinimum(node * current)
{
  if(current == NULL) 
    return NULL ;
  if(current->left != NULL) 
    return findMinimum(current->left) ;
  else return current ;
}
void Bst ::remove(int value)
{
  remove(root, value);
}
node * Bst ::remove(node *current, int value)
{
  if (current == NULL)
    return NULL ;
  if (value > current->data)
    current->right = remove(current->right, value);
  else if (value < current->data)
    current->left = remove(current->left, value);
  else
  {
    if(current->left == current->right && current->left == NULL)
      delete current ;
    else if(current->right != NULL && current->left !=NULL)
    {
      node * x = findMinimum(current->right) ;
      current->data = x->data ;
      current->right = remove(current->right , current->data) ;
    }
    else 
    {
      node * temp = current ;
      if(current->left == NULL)
        current = current->right ;
      else current = current->left ;
      delete temp ;
    }
  }
  return current ;
}
node *Bst::find(node *current, int value)
{
  if (current->data == value)
    return current;
  node *ans = NULL;
  if (current->data > value && current->left != NULL)
    ans = find(current->left, value);
  if (current->data < value && current->right != NULL)
    ans = find(current->right, value);
  return ans;
}
node *Bst::find(int value)
{
  return find(root, value);
}
void Bst::inorder(node *current , vector<int> & v)
{
  if (current == NULL)
    return;
  inorder(current->left , v);
  v.push_back(current->data) ;
  inorder(current->right , v);
}
void Bst::postorder(node *current , vector<int> & v)
{
  if (current == NULL)
    return;
  postorder(current->left , v);
  postorder(current->right , v);
  v.push_back(current->data) ;
}
void Bst::preorder(node *current, vector<int>& v)
{
  if (current == NULL)
    return;
  v.push_back(current->data);
  preorder(current->left , v);
  preorder(current->right , v);
}
void Bst::display(string type)
{
  vector<int>v ; 
  if (type == "preorder")
    preorder(root, v);
  if (type == "postorder")
    postorder(root , v);
  if (type == "inorder")
    inorder(root , v);
  for(int i=0 ; i<v.size() ; i++) cout<<v[i]<<" " ;
  cout<<endl ;
}
