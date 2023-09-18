#pragma once

#include "Component.h"
#include "Menu.h"

class Scene : public Component {
  public:
    Scene() {};
    ~Scene() {};
    Layout render() {
      Menu* menu = new Menu();

      return Layout({ menu });
    }
};
