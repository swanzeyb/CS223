#pragma once

#include <string>
#include "Component.h"
#include "State.h"

using std::string;

class Remove : public Component
{
public:
  Layout render()
  {
    State *state = State::getInstance();
    printw("Removing a command.\n");

    // Command name
    printw("\nName: ");
    char _name[256];
    getstr(_name);
    string name = string(_name);

    // Find the command
    int index = state->commands.indexOf(name);
    if (index == -1)
    {
      clear();
      refresh();
      printw("Command not found.");
      printw("\nPress any key to continue... ");
      getch();
      return Layout();
    }
    else
    {
      index -= 1; // For splice
    }

    // Remove from state
    state->commands.splice(index, 1);
    state->descriptions.splice(index, 1);

    // Confirmation
    clear();
    refresh();

    printw("Removed %s.\n", name.c_str());
    printw("\nPress any key to continue... ");
    getch();

    return Layout();
  }
};
