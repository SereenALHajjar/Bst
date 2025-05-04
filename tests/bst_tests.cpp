#include "doctest/doctest.h"

#include "Bst.hpp"

TEST_CASE("Basic")
{
  Bst bst;
  for (auto i : std::vector<int>{10, 10, 2, 1, 4, 13, 20})
  {
    bst.insert(i);
  }
  REQUIRE(bst.size() == 6);
  CHECK(bst.find(10)->data == 10);
  CHECK(bst.find(2)->data == 2);
  CHECK(bst.find(1)->data == 1);
  CHECK(bst.find(4)->data == 4);
  CHECK(bst.find(13)->data == 13);
  CHECK(bst.find(20)->data == 20);
  CHECK(bst.find(100) == nullptr);
  CHECK(bst.find(0) == nullptr);
  CHECK(bst.find(-1) == nullptr);
  REQUIRE(bst.size() == 6);
}

TEST_CASE("Remove")
{
  Bst bst;
  for (auto i : std::vector<int>{10, 10, 2, 1, 4, 13, 20, 10})
  {
    bst.insert(i);
  }
  REQUIRE(bst.size() == 6);
  CHECK(bst.find(10)->data == 10);
  bst.remove(10);
  CHECK(bst.find(10) == nullptr);
  REQUIRE(bst.size() == 5);

  bst.remove(10);
  REQUIRE(bst.size() == 5);

  bst.remove(1);
  REQUIRE(bst.size() == 4);
}

TEST_CASE("Empty tree")
{
  Bst bst;
  CHECK(bst.find(0) == nullptr);
  CHECK(bst.find(1) == nullptr);
  CHECK(bst.size() == 0);
  bst.remove(0);
  CHECK(bst.size() == 0);
}
TEST_CASE("Travesal")
{
  Bst bst;
  for (auto i : std::vector<int>{10, 10, 2, 1, 4, 13, 20, 10})
  {
    bst.insert(i);
  }
  std::vector<int> expected{1, 2, 4, 10, 13, 20};
  std::vector<int> actual = bst.traverse(Order::INORDER);

  CHECK(expected == actual);

  expected = {10, 2, 1, 4, 13, 20};
  actual = bst.traverse(Order::PREORDER);
  CHECK(expected == actual);

  expected = {1, 4, 2, 20, 13, 10};
  actual = bst.traverse(Order::POSTORDER);
  CHECK(expected == actual);
}


TEST_CASE("Clear")
{
  Bst bst;
  for (auto i : std::vector<int>{10, 10, 2, 1, 4, 13, 20, 10})
  {
    bst.insert(i);
  }
  bst.clear();
  CHECK(bst.size() == 0);
  CHECK(bst.find(10) == nullptr);
  CHECK(bst.find(2) == nullptr);
  CHECK(bst.find(1) == nullptr);
  CHECK(bst.find(4) == nullptr);
  CHECK(bst.find(13) == nullptr);
  CHECK(bst.find(20) == nullptr);
  CHECK(bst.find(100) == nullptr);
  CHECK(bst.find(0) == nullptr);
  CHECK(bst.find(-1) == nullptr);
  REQUIRE(bst.size() == 0);
}