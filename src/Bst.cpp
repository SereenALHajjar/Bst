#include <Bst.hpp>
#include <iostream>
using namespace std;

Bst::Bst() { root = NULL; }
node *Bst::insert(int value) {
  if (root == NULL) {
    root = new node;
    root->data = value;
    root->left = NULL;
    root->right = NULL;
    return root;
  } else
    return insert(root, value);
}
node *Bst::insert(node *current, int value) {

  if (value < current->data) {
    if (current->left != NULL)
      insert(current->left, value);
    else {
      node *newNode = new node;
      newNode->left = newNode->right = NULL;
      newNode->data = value;
      current->left = newNode;
    }
  }
  if (value > current->data) {
    if (current->right != NULL)
      insert(current->right, value);
    else {
      node *newNode = new node;
      newNode->left = newNode->right = NULL;
      newNode->data = value;
      current->right = newNode;
    }
  }
  // TODO(Sereen): Why does insert return a value?
  return current;
}
node *Bst::find(node *current, int value) {
  if (current->data == value)
    return current;
  node *ans = NULL;
  if (current->data > value && current->left != NULL)
    ans = find(current->left, value);
  if (current->data < value && current->right != NULL)
    ans = find(current->right, value);
  return ans;
}
node *Bst::find(int value) { return find(root, value); }
void Bst::inorder(node *current) {
  if (current == NULL)
    return;
  inorder(current->left);
  cout << current->data << " ";
  inorder(current->right);
}
void Bst::postorder(node *current) {
  if (current == NULL)
    return;
  postorder(current->left);
  postorder(current->right);
  cout << current->data << " ";
}
void Bst::preorder(node *current) {
  if (current == NULL)
    return;
  cout << current->data << " ";
  preorder(current->left);
  preorder(current->right);
}
void Bst::display(string type) {
  if (type == "preorder")
    preorder(root);
  if (type == "postorder")
    postorder(root);
  if (type == "inorder")
    inorder(root);
}

