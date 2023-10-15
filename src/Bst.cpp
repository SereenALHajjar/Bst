#include <Bst.hpp>
#include <iostream>
#include<vector>
using namespace std;

Bst::Bst() { root = NULL; }

Bst::~Bst()
{
  this->clear(root);
  root = NULL;
}
void Bst::clear()
{
  this->clear(root);
  root = NULL;
}
void Bst::clear(node *current)
{
  if (current == NULL)
    return;
  this->clear(current->left);
  this->clear(current->right);
  delete current;
}

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
int Bst::size() const
{
  return size(this->root);
}
int Bst::size(node * current) const
{
  if(current == NULL)
    return 0 ;
  return size(current->right) + size(current->left) + 1 ;
}
node * findMinimum(node * current)
{
  if(current == NULL) 
    return NULL ;
  if(current->left != NULL) 
    return findMinimum(current->left) ;
  else return current ;
}
void Bst::remove(int value)
{
  remove(root, value);
}
node * Bst::remove(node *current, int value)
{
  if (current == NULL)
    return NULL ;
  if (value > current->data)
    current->right = remove(current->right, value);
  else if (value < current->data)
    current->left = remove(current->left, value);
  else
  {
    if(current->left == NULL && current->right == NULL)
    {
      delete current ;
      current = NULL;
    }
    else if(current->right != NULL && current->left !=NULL)
    {
      node * x = findMinimum(current->right) ;
      current->data = x->data ;
      current->right = remove(current->right , current->data) ;
      // 10 2 1 4 13 20

    //   10 
    //   / \
    //   2  13
    //  / \   \
    //  1  4  20
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
node *Bst::find(node *current, int value) const
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
node *Bst::find(int value) const
{
  if(root == NULL) return NULL ;
  return find(root, value);
}
void Bst::inorder(node *current , vector<int> & v) const
{
  if (current == NULL)
    return;
  inorder(current->left , v);
  v.push_back(current->data) ;
  inorder(current->right , v);
}
void Bst::postorder(node *current , vector<int> & v) const
{
  if (current == NULL)
    return;
  postorder(current->left , v);
  postorder(current->right , v);
  v.push_back(current->data) ;
}
void Bst::preorder(node *current, vector<int>& v) const
{
  if (current == NULL)
    return;
  v.push_back(current->data);
  preorder(current->left , v);
  preorder(current->right , v);
}
void Bst::display(Order order) const
{
  vector<int>v = traverse(order) ;
  for(int i = 0 ; i < v.size() ; i++)
    cout << v[i] << " " ;
  cout << endl ;
}

std::vector<int> Bst::traverse(Order order) const
{
  vector<int>v ; 
  if (order == Order::PREORDER)
    preorder(root, v);
  if (order == Order::POSTORDER)
    postorder(root , v);
  if (order == Order::INORDER)
    inorder(root , v);
  return v ;
}