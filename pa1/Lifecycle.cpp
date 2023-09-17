#include "Lifecycle.h"

Lifecycle::Lifecycle() {}

Lifecycle::Lifecycle(initializer_list<Component*> components) {
    initscr(); // Initialize ncurses
    printw("Hello, ncurses!"); // Print a message
    refresh(); // Refresh the screen
    getch(); // Wait for user input
    endwin(); // Clean up and close ncurses
  // for (Component* comp : components) {
  //   comp->render();
  // }

  initscr();
  // while ()
}

Lifecycle::~Lifecycle() {
  std::cout << "Lifecycle destructor" << std::endl;
}
