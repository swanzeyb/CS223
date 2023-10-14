#pragma once
#include "AVLNode.h"

template <typename T>
class AVLTree
{
public:
  AVLNode<T> *root;

  AVLTree() : root(nullptr){};

  int height()
  {
    return getHeight(root);
  }

  AVLNode<T> *insert(T data)
  {
    AVLNode<T> *node = insertHelper(root, data);
    root = node;
    return node;
  }

  bool contains(T data)
  {
    return containsHelper(root, data);
  }

  bool validate();

private:
  int max(int a, int b)
  {
    return (a > b) ? a : b;
  }

  bool containsHelper(AVLNode<T> *node, T data)
  {
    if (node == nullptr)
      return false; // Not found

    if (data < node->data)
    {
      // Search left tree
      return containsHelper(node->left, data);
    }
    else if (data > node->data)
    {
      // Search right tree
      return containsHelper(node->right, data);
    }
    else
    {
      return true; // Found
    }
  }

  AVLNode<T> *insertHelper(AVLNode<T> *node, T data)
  {
    // Base case
    if (node == nullptr)
    {
      return new AVLNode<T>(data);
    }

    // Insert data
    if (data < node->data)
    {
      node->left = insertHelper(node->left, data);
    }
    else if (data > node->data)
    {
      node->right = insertHelper(node->right, data);
    }
    else
    {
      // No duplicates
      return node;
    }

    // Update height
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    // Check unbalance
    int balance = getBalance(node);

    // Left Case
    if (balance > 1)
    {
      if (data < node->left->data)
      {
        return singleRightRotate(node);
      }
      else if (data > node->left->data)
      {
        return leftRightRotate(node);
      }
    }

    // Right case
    if (balance < -1)
    {
      if (data > node->right->data)
      {
        return singleLeftRotate(node);
      }
      else if (data < node->right->data)
      {
        return rightLeftRotate(node);
      }
    }

    return node;
  }

  int getHeight(AVLNode<T> *node)
  {
    if (node == nullptr)
      return 0;
    return node->height;
  }

  int getBalance(AVLNode<T> *node)
  {
    if (node == nullptr)
      return 0;
    return getHeight(node->left) - getHeight(node->right);
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
