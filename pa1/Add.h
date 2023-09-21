#pragma once

#include <string>
#include "Component.h"
#include "State.h"

using std::string;

class Add : public Component
{
public:
  Layout render()
  {
    State *state = State::getInstance();
    printw("Adding a command.\n");

    // Command name
    printw("\nName: ");
    char _name[256];
    getstr(_name);
    string name = string(_name);

    // Description
    printw("Description: ");
    char _description[256];
    getstr(_description);
    string description = string(_description);

    // Add to state
    state->commands.push(name);
    state->descriptions.push(description);

    // Confirmation
    clear();
    refresh();

    printw("Added %s.\n", name.c_str());
    printw("\nPress any key to continue... ");
    getch();

    return Layout();
  }
};
