#pragma once

#include "Component.h"

class Menu : public Component {
  public:
    Menu() {};
    ~Menu() {};
    Layout render() {
      printw("Please select an option:\n");
      printw("1. Game Rules\n");
      printw("2. Play Game\n");
      printw("3. Load Previous Game\n");
      printw("4. Add Command\n");
      printw("5. Remove Command\n");
      printw("6. Exit\n");

      char choice = getch();
      switch(choice) {
        case '1':
          printw("Game Rules\n");
          break;
        case '2':
          printw("Play Game\n");
          break;
        case '3':
          printw("Load Previous Game\n");
          break;
        case '4':
          printw("Add Command\n");
          break;
        case '5':
          printw("Remove Command\n");
          break;
        case '6':
          printw("Exit\n");
          break;
        default:
          printw("Invalid choice\n");
          break;
      }

      return Layout();
    }
};
