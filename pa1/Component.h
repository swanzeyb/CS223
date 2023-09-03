#pragma once

#include <iostream>
#include "Layout.h"

using std::cout;
using std::endl;

class Component {
  public:
    virtual Layout* render() = 0;
    virtual ~Component() {};
};
