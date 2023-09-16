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

  List<int> list1;
  list1.push(1);
  list1.push(2);
  list1.push(3);

  List<int> list2 = list1.map<int>([](int x) { return x * 2; });
  auto list3 = list1.map<int>([](int x) { return x * 2; });
}
