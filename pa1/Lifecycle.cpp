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
  while (true) {
    for (Component* comp : components) {
      _render(comp->render());
    }
  }
}

Lifecycle::~Lifecycle() {
  endwin(); // Clean up and close ncurses
}

void Lifecycle::_render(Layout layout) {
  clear(); // Clear the screen
  refresh();
  for (Component* comp : layout.components()) {
    Layout result = comp->render();
    if (result.components().length > 0) {
      _render(result);
    }
  }
  refresh(); // Refresh the screen
}

void Lifecycle::stop() {
  this->_running = false;
}
