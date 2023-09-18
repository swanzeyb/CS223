#include "Menu.h"

Menu::Menu() {
  cout << "Menu constructor" << endl;
}

Menu::~Menu() {
  cout << "Menu destructor" << endl;
}

Layout Menu::render() {
  printw("Please select an option:\n");
  printw("1. Game Rules\n");
  printw("2. Play Game\n");
  printw("3. Load Previous Game\n");
  printw("4. Add Command\n");
  printw("5. Remove Command\n");
  printw("6. Exit\n");

  return Layout();
}
