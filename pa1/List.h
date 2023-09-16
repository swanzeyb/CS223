#pragma once

#include <memory>

using std::shared_ptr;
using std::make_shared;

template <typename Type>
class Node {
  public:
    shared_ptr<Node> next;
    Type data;

    Node() {};
    ~Node() {};
};

template <typename Type>
class List {
  private:
    shared_ptr<Node<Type>> head;
    int size;
  
  public:
    List(): head(nullptr), size(0) {};
    ~List() {};

    int push(Type data) {
      // Make new node and initialize it
      auto node = make_shared<Node<Type>>();
      node->data = data;
      node->next = nullptr;

      // Find where to insert the node
      if (head == nullptr) {
        head = node;
      } else {
        auto current = head;
        while (current->next != nullptr) {
          current = current->next;
        }
        current->next = node;
      }

      size++;
      return size;
    }

    template <typename Result>
    List map(Result (*func)(Type)) {
      List<Result> results;
      auto current = head;
      while (current != nullptr) {
        results.push(func(current->data));
        current = current->next;
      }
      return results;
    }

    Type* operator[](int index) {
      auto current = head;
      for (int i = 0; i < index; i++) {
        if (current == nullptr) {
          return nullptr; // Return null if index is out of bounds
        }
        current = current->next;
      }
      return &(current->data);
    }
};
