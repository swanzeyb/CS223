#pragma once

#include "Component.h"
#include "State.h"

class Exit : public Component
{
public:
  Layout render()
  {
    printw("Exiting...\n");

    // Save game state
    State *state = State::getInstance();
    state->save();

    return Layout();
  }
};
