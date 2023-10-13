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

  AVLNode<T> *singleLeftRotate(AVLNode<T> *node)
  {
    AVLNode<T> *right = node->right;
    AVLNode<T> *left = right->left;

    // Perform rotation
    right->left = node;
    node->right = left;

    // Update heights
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    right->height = max(getHeight(right->left), getHeight(right->right)) + 1;

    // Return new root
    return right;
  }

  AVLNode<T> *leftRightRotate(AVLNode<T> *node)
  {
    node->left = singleLeftRotate(node->left);
    return singleRightRotate(node);
  }

  AVLNode<T> *rightLeftRotate(AVLNode<T> *node)
  {
    node->right = singleRightRotate(node->right);
    return singleLeftRotate(node);
  }
};
