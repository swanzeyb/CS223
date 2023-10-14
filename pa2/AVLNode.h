#pragma once

template <typename T>
class AVLNode
{
public:
  T data;
  AVLNode<T> *left;
  AVLNode<T> *right;
  int height;

  AVLNode(T data)
  {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
  };
  ~AVLNode(){};
};
