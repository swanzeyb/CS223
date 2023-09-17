#include <iostream>
#include <string>
#include <memory>

#include "Menu.h"
#include "Layout.h"
#include "Lifecycle.h"
#include "List.h"
// #include "Store.h"
#include "CSV.h"

using std::string;
using std::cout;
using std::endl;
using std::shared_ptr;

int main(int, char**) {
  // Menu* menu = new Menu();
  // Lifecycle lifecycle = { menu };

  // Store<int, int> store;

  CSV csv("../../pa1/commands.csv");
  bool result = csv.load();

  string line = csv.read();
  while (line != "") {
    cout << line << endl;
    line = csv.read();
  }

  List<int> list1;
  list1.push(1);
  list1.push(2);
  list1.push(3);

  List<int> list2 = list1.map<int>([](int x) { return x * 2; });
}
 