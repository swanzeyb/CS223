#include <iostream>
#include <string>
#include <memory>

#include "Menu.h"
#include "Layout.h"
#include "Lifecycle.h"
#include "List.h"

using std::cout;
using std::endl;
using std::shared_ptr;

int main(int, char**) {
  // Menu* menu = new Menu();
  // Lifecycle lifecycle = { menu };

  List<int> list;
  list.push(1);
  list.push(2);
  list.push(3);

  auto res1 = list[0];
  auto res2 = list[1];
  auto res3 = list[2];
  auto res4 = list[3];
}
