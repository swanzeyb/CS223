#pragma once

#include <iostream>
#include <initializer_list>
#include "ncurses/ncurses.h"
#include "Component.h"

using std::initializer_list;

class Component;

class Lifecycle
{
private:
  void _render(Layout layout);

public:
  Lifecycle();
  Lifecycle(initializer_list<Component *> components);
  ~Lifecycle();
};
