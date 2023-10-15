#pragma once
#include <string>
#include <vector>


struct node {
  node *left;
  node *right;
  int data;
};

enum class Order {
  PREORDER,
  INORDER,
  POSTORDER
};
class Bst {

public:
  Bst();
  ~Bst();

  void insert(int value);

  void insert(node *current, int value);

  void remove(int value) ;

  node * remove(node * current , int value) ;


  std::vector<int> traverse(Order order) const;
  void display(Order order) const;

  int size() const;
  node *find(int value) const;
  void clear();
private:
  int size(node*) const;
  
  node *find(node *current, int value) const;

  void inorder(node *current , std::vector<int> & ) const;

  void postorder(node *current , std::vector<int> &) const;

  void preorder(node *current, std::vector<int>& ) const;
  void clear(node *current);
  node *root;
};

