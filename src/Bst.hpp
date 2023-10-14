#include <string>

struct node {
  node *left;
  node *right;
  int data;
};

class Bst {

public:
  Bst();
  node *insert(int value);

  node *insert(node *current, int value);

  node *find(node *current, int value);

  node *find(int value);

  void inorder(node *current);

  void postorder(node *current);

  void preorder(node *current);

  void display(std::string type);

private:
  node *root;
};

