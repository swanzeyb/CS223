#pragma once
#include "AVLNode.h"

template <typename T>
class AVLTree
{
public:
  AVLNode<T> *root;

  int height();
  void insert(T data);
  bool contains(T data);
  bool validate();

private:
  int getHeight(AVLNode<T> *node);
  int getBalance(AVLNode<T> *node);

  int max(int a, int b)
  {
    return (a > b) ? a : b;
  }

  AVLNode<T> *singleRightRotate(AVLNode<T> *node)
  {
    AVLNode<T> *left = node->left;
    AVLNode<T> *right = left->right;

    // Perform rotation
    left->right = node;
    node->left = right;

    // Update heights
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    left->height = max(getHeight(left->left), getHeight(left->right)) + 1;

    // Return new root
    return left;
  }

  AVLNode<T> *singleLeftRotate(AVLNode<T> *node);
  AVLNode<T> *doubleRightRotate(AVLNode<T> *node);
  AVLNode<T> *doubleLeftRotate(AVLNode<T> *node);
};
