#pragma once
#include <string>
#include <vector>
struct node {
  node *left;
  node *right;
  int data;
};

class Bst {

public:
  Bst()
  {
    root = NULL;
  }

  void insert(int value);

  void insert(node *current, int value);

  void remove(int value) ;

  node * remove(node * current , int value) ;

  node *find(node *current, int value);

  node *find(int value);

  void inorder(node *current , std::vector<int> & );

  void postorder(node *current , std::vector<int> &);

  void preorder(node *current, std::vector<int>& );

  void display(std::string type);

private:
  node *root;
};

