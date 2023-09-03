#pragma once

#include <iostream>
#include "Component.h"

class Menu : public Component {
  public:
    Menu();
    ~Menu();
    Layout* render();
};
