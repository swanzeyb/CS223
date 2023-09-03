#include "Menu.h"

Menu::Menu() {
  cout << "Menu constructor" << endl;
}

Menu::~Menu() {
  cout << "Menu destructor" << endl;
}

Layout* Menu::render() {
  cout << "Please select an option:" << endl;
  cout << "1. Game Rules" << endl;
  cout << "2. Play Game" << endl;
  cout << "3. Load Previous Game" << endl;
  cout << "4. Add Command" << endl;
  cout << "5. Remove Command" << endl;
  cout << "6. Exit" << endl;

  return nullptr;
}
