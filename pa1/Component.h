#pragma once

#include <iostream>
#include "ncurses/ncurses.h"
#include "Layout.h"

using std::cout;
using std::endl;

class Component {
  public:
    virtual Layout* render() = 0;
    virtual ~Component() {};
};
