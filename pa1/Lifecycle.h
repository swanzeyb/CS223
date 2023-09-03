#pragma once

#include <iostream>
#include <initializer_list>
#include "ncurses/ncurses.h"
#include "Component.h"

using std::initializer_list;

class Component;

class Lifecycle {
  public:
    Lifecycle();
    Lifecycle(initializer_list<Component*> components);
    ~Lifecycle();
  private:
    static void clearScreen();
};
