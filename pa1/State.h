#pragma once

#include <memory>
#include "string.h"
#include "List.h"

using std::string;

// enum Scenes
// {
//   MENU,
//   RULES,
//   GAME,
//   LOAD,
//   ADD,
//   REMOVE,
//   EXIT,
// };

// Singleton global game state
class State
{
private:
  State() {}

  // Delete the copy and assigment operators so the class cannot be copied
  State(const State &) = delete;
  State &operator=(const State &) = delete;

  // Static pointer to the current state
  static State *_instance;

public:
  // Member variables
  List<string> commands;
  List<string> descriptions;

  string userName = "";
  int userPoints = 0;
  size_t rounds = 0;

  // Destructor
  ~State() {}

  // Static method to get the current state
  static State *getInstance()
  {
    if (_instance == nullptr)
    {
      _instance = new State();
    }
    return _instance;
  }
};

State *State::_instance = nullptr;
