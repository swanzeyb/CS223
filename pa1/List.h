#pragma once

#include <memory>
#include <functional>
#include <initializer_list>

using std::function;
using std::initializer_list;
using std::make_shared;
using std::shared_ptr;

template <typename Type>
class Node
{
public:
  shared_ptr<Node> next;
  Type data;

  Node(){};
  ~Node(){};
};

template <typename Type>
class List
{
private:
  shared_ptr<Node<Type>> head;

  shared_ptr<Node<Type>> _get(int index)
  {
    auto current = head;
    for (int i = 0; i < index; i++)
    {
      if (current == nullptr)
      {
        return nullptr;
      }
      current = current->next;
    }
    return current;
  }

public:
  int length;

  // Constructor and destructor
  List() : head(nullptr), length(0){};
  ~List(){};

  // Copy constructor and assignment operator
  List(const List &other)
  {
    auto current = other.head;
    while (current != nullptr)
    {
      this->push(current->data);
      current = current->next;
    }
  }
  List &operator=(const List &other)
  {
    auto current = other.head;
    while (current != nullptr)
    {
      this->push(current->data);
      current = current->next;
    }
    return *this;
  }

  class Iterator
  {
  private:
    shared_ptr<Node<Type>> _current;

  public:
    Iterator(shared_ptr<Node<Type>> node) : _current(node) {}

    Type operator*()
    {
      return _current->data;
    }

    Iterator &operator++()
    {
      _current = _current->next;
      return *this;
    }

    bool operator!=(const Iterator &other) const
    {
      return _current != other._current;
    }
  };

  Iterator begin()
  {
    return Iterator(head);
  }

  Iterator end()
  {
    return Iterator(nullptr);
  }

  int push(Type data)
  {
    // Make new node and initialize it
    auto node = make_shared<Node<Type>>();
    node->data = data;
    node->next = nullptr;

    // Find where to insert the node
    if (head == nullptr)
    {
      head = node;
    }
    else
    {
      auto current = head;
      while (current->next != nullptr)
      {
        current = current->next;
      }
      current->next = node;
    }

    length++;
    return length;
  }

  template <typename Result>
  List map(function<Result(Type)> func)
  {
    List<Result> results;
    auto current = head;
    while (current != nullptr)
    {
      results.push(func(current->data));
      current = current->next;
    }
    return results;
  }

  Type operator[](int index)
  {
    auto current = head;
    for (int i = 0; i < index; i++)
    {
      if (current == nullptr)
      {
        return Type(); // Return default instance of Type
      }
      current = current->next;
    }
    return current->data;
  }

  int indexOf(Type data)
  {
    int index = 0;
    auto current = head;
    while (current != nullptr)
    {
      if (current->data == data)
      {
        return index;
      }
      current = current->next;
      index++;
    }
    return -1;
  }

  bool includes(Type data)
  {
    return indexOf(data) != -1;
  }

  bool some(function<bool(Type)> func)
  {
    auto current = head;
    while (current != nullptr)
    {
      if (func(current->data))
      {
        return true;
      }
      current = current->next;
    }
    return false;
  }

  List &splice(int start, int deleteCount = 0, initializer_list<Type> newItems = {})
  {
    // Find the start node
    auto pStart = _get(start);
    if (pStart == nullptr)
    {
      return *this;
    }

    // Find the end node
    auto pEnd = _get(start + deleteCount);

    // Remove the nodes
    pStart->next = pEnd->next; // This works because shared_ptr will deleted unused nodes

    // Insert the new nodes
    for (auto item : newItems)
    {
      push(item);
    }

    return *this;
  }
};
