#pragma once

#include <iostream>
#include <memory>
#include "ncurses/ncurses.h"
#include "Layout.h"

using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;

class Component
{
public:
  Component(){};
  virtual ~Component(){};
  virtual Layout render() = 0;
};
