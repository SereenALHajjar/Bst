#include <Bst.hpp>
#include <iostream>
using namespace std;

int main() {
  Bst test;
  test.insert(10);
  test.insert(2);
  test.insert(1);
  test.insert(4);
  test.insert(13);
  test.insert(20);
  // cout<<(b->right)->data<<endl ;
  // cout<<test.x<<endl ;
  // return 0 ;
  test.display("inorder");
  cout << endl;
  test.display("preorder");
  cout << endl;
  test.display("postorder");
  // node * nn = test.find(4) ;
  // cout<<(nn->left)<<endl ;
  // test.pr() ;
  // cout<<tedata ;
}