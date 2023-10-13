#include <iostream>
#include "AVLTree.h"

using namespace std;

int main()
{
  AVLTree<int> tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.insert(50);
  tree.insert(25);

  return 0;
}
