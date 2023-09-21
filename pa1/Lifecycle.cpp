#include "Lifecycle.h"

Lifecycle::Lifecycle() {}

Lifecycle::Lifecycle(initializer_list<Component *> components)
{
  initscr(); // Initialize ncurses;

  // First paint
  while (true)
  {
    for (Component *comp : components)
    {
      _render(comp->render());
    }
  }
}

Lifecycle::~Lifecycle()
{
  endwin(); // Clean up and close ncurses
}

void Lifecycle::_render(Layout layout)
{
  clear(); // Clear the screen
  refresh();
  for (Component *comp : layout.components())
  {
    Layout result = comp->render();
    if (result.components().length > 0)
    {
      _render(result);
    }
  }
  refresh(); // Refresh the screen
}
