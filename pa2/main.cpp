#include <iostream>
#include <string>
#include "AVLTree.h"

using namespace std;

void printBT(const std::string &prefix, const AVLNode<int> *node, bool isLeft)
{
  if (node != nullptr)
  {
    std::cout << prefix;

    std::cout << (isLeft ? "├──" : "└──");

    // print the value of the node
    std::cout << node->data << std::endl;

    // enter the next tree level - left and right branch
    printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
    printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
  }
}

int main()
{
  AVLTree<int> tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.insert(50);
  tree.insert(25);

  printBT("", tree.root, false);

  bool res1 = tree.contains(10);
  bool res2 = tree.contains(20);
  bool res3 = tree.contains(30);
  bool res4 = tree.contains(40);
  bool res5 = tree.contains(50);
  bool res6 = tree.contains(25);
  bool res7 = tree.contains(100);
  bool res8 = tree.contains(-1);

  return 0;
}
