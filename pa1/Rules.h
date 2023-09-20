#pragma once

#include "Component.h"

class Rules : public Component
{
public:
  Rules(){};
  ~Rules(){};
  Layout render()
  {
    printw("Game Rules:\n");
    printw("- Match the linux command with the correct description.\n");
    printw("- Pick the number of commands you want to match.\n");
    printw("- The game starts by printing a linux command and the goal is to match it with the right defintion.\n");
    printw("- Matching the right defintion wins you one point.\n");
    printw("- Matching an incorrect defintion subtracts one point.\n");
    printw("- The goal is to win the most poiints.\n");
    printw("- There are 30 possible commands and defintions.\n");

    printw("\nPress any key to continue...\n");
    getch();

    return Layout();
  }
};
