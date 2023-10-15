#include <Bst.hpp>
#include <iostream>
using namespace std;

int main() {
  Bst test;
  test.insert(50);
  test.insert(10);
  test.insert(9);
  test.insert(15);
  test.insert(18);
  test.insert(20);
  test.insert(16);
  // cout<<(b->right)->data<<endl ;
  // cout<<test.x<<endl ;
  // return 0 ;
  // test.display("inorder");
  cout << endl;
  // test.display("preorder");
  // cout << endl;
  // test.display("postorder");
  test.remove(10) ;
  // test.display("inorder");
  // node * nn = test.find(4) ;
  // cout<<(nn->left)<<endl ;
  // test.pr() ;
  // cout<<tedata ;
}