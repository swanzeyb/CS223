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
  
  public:
    int length;

    List(): head(nullptr), length(0) {};
    ~List() {};

    class Iterator {
    private:
      shared_ptr<Node<Type>> _current;
    public:
      Iterator(shared_ptr<Node<Type>> node) : _current(node) {}

      Type operator*() {
        return current->data;
      }

      Iterator& operator++() {
        current = current->next;
        return *this;
      }

      bool operator!=(const Iterator& other) const {
        return current != other.current;
      }
    };

    Iterator begin() {
      return Iterator(head);
    }

    Iterator end() {
      return Iterator(nullptr);
    }

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

      length++;
      return length;
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
