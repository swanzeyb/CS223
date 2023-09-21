#pragma once

#include "Component.h"
#include "State.h"
#include <cstdlib>

class Exit : public Component
{
public:
  Layout render()
  {
    printw("Exiting...\n");

    // Save game state
    State *state = State::getInstance();
    if (state->save())
    {
      printw("Game saved.\n");
    }
    else
    {
      printw("Game not saved.\n");
    }
    printw("\nPress any key to continue... ");
    getch();

    // Hacky way to exit for now
    exit(0);

    return Layout();
  }
};
