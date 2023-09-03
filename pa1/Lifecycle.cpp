#include "Lifecycle.h"

void Lifecycle::clearScreen() {
  std::cout << "test" << std::endl;
  std::cout << "\033[2J\033[1;1H";
}

Lifecycle::Lifecycle() {}

Lifecycle::Lifecycle(initializer_list<Component*> components) {
  clearScreen();
  for (Component* comp : components) {
    comp->render();
  }
}

Lifecycle::~Lifecycle() {
  std::cout << "Lifecycle destructor" << std::endl;
}
