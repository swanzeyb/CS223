#pragma once

/*
      printw("1. Game Rules\n");
      printw("2. Play Game\n");
      printw("3. Load Previous Game\n");
      printw("4. Add Command\n");
      printw("5. Remove Command\n");
      printw("6. Exit\n");
*/

enum Scenes {
  MENU,
  RULES,
  GAME,
  LOAD,
  ADD,
  REMOVE,
  EXIT,
};

static struct State {
  bool running = true;
  Scenes active_scene = MENU;
};
