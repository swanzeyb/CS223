#pragma once

#include "Component.h"
#include "Rules.h"
#include "Game.h"
#include "Add.h"
#include "Remove.h"
#include "Exit.h"
#include "Load.h"

class Menu : public Component
{
public:
  Layout render()
  {
    printw("Please select an option:\n");
    printw("1. Game Rules\n");
    printw("2. Play Game\n");
    printw("3. Load Previous Game\n");
    printw("4. Add Command\n");
    printw("5. Remove Command\n");
    printw("6. Exit\n");

    char choice = getch();
    switch (choice)
    {
    case '1':
      return Layout({new Rules()});
    case '2':
      return Layout({new Game()});
      break;
    case '3':
      return Layout({new Load()});
      break;
    case '4':
      return Layout({new Add()});
      break;
    case '5':
      return Layout({new Remove()});
      break;
    case '6':
      return Layout({new Exit()});
      break;
    default:
      printw("Invalid choice\n");
      break;
    }

    return Layout();
  }
};
