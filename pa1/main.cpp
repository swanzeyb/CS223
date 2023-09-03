#include <iostream>
#include <string>
#include <memory>

#include "Menu.h"
#include "Layout.h"
#include "Lifecycle.h"

using std::cout;
using std::endl;
using std::shared_ptr;

int main(int, char**) {
  Menu* menu = new Menu();
  Lifecycle lifecycle = { menu };
}
