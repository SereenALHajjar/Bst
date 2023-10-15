#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "Bst.hpp"

TEST_CASE("Basic") {
  Bst bst;
  bst.insert(10);
  bst.insert(10);
  bst.insert(2);
  bst.insert(1);
  bst.insert(4);
  bst.insert(13);
  bst.insert(20);

  CHECK(bst.find(10)->data == 10);
  CHECK(bst.find(2)->data == 2);
  CHECK(bst.find(1)->data == 1);
  CHECK(bst.find(4)->data == 4);
  CHECK(bst.find(13)->data == 13);
  CHECK(bst.find(20)->data == 20);
  CHECK(bst.find(100) == NULL);
  CHECK(bst.find(0) == NULL);
  CHECK(bst.find(-1) == NULL);
}

TEST_CASE("Empty")
{
 Bst bst;
}