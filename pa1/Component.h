#pragma once

#include <iostream>
#include <memory>
#include "ncurses/ncurses.h"
#include "Layout.h"

using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;

class Component {
  public:
    virtual Layout render() = 0;
    virtual ~Component() {};
};
