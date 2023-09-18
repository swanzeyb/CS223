#pragma once

#include <iostream>
#include <initializer_list>
#include "Component.h"
#include "List.h"

using std::initializer_list;

class Component;

class Layout {
  private:
    List<Component*> _components;

  public:
    // Constructor with a variable number of arguments
    Layout(initializer_list<Component*> components) {
      for (Component* comp : components) {
        this->_components.push(comp);
      }
    }
    Layout() {}

    List<Component*>& components() {
      return this->_components;
    }
};
