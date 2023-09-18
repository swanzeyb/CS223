#include "Lifecycle.h"

/*
    initscr(); // Initialize ncurses
    printw("Hello, ncurses!"); // Print a message
    refresh(); // Refresh the screen
    getch(); // Wait for user input
    endwin(); // Clean up and close ncurses
*/

Lifecycle::Lifecycle() {}

Lifecycle::Lifecycle(initializer_list<Component*> components) {
  initscr(); // Initialize ncurses

  // First paint
  for (Component* comp : components) {
    comp->render();
  }
  refresh(); // Refresh the screen
}

Lifecycle::~Lifecycle() {
  endwin(); // Clean up and close ncurses
}

void Lifecycle::stop() {
  this->_running = false;
}
