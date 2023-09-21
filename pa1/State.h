#pragma once

#include <memory>
#include "string.h"
#include "List.h"
#include "CSV.h"
#include "Lifecycle.h"

using std::string;

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

  bool stop = false;

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

  static State *reset()
  {
    if (_instance != nullptr)
    {
      delete _instance;
    }
    _instance = new State();
    return _instance;
  }

  static bool save()
  {
    // Grab the global state
    State *state = State::getInstance();

    // Open commands CSV
    CSV commands_csv("../../pa1/commands.csv");
    bool result = commands_csv.load(std::ios::out);
    if (!result)
    {
      return false;
    }

    // Store our commands and descriptions
    commands_csv.write(false, "Command");
    commands_csv.write(true, "Description");
    for (int i = 0; i < state->commands.length; i++)
    {
      commands_csv.write(false, state->commands[i]);
      commands_csv.write(true, state->descriptions[i]);
    }

    commands_csv.close();

    // Open profiles CSV
    CSV read_profiles_csv("../../pa1/profiles.csv");
    result = read_profiles_csv.load(std::ios::in);
    if (!result)
    {
      return false;
    }

    // Temp store current profiles
    List<List<string>> profiles;

    // Read the names and points
    string line = read_profiles_csv.read();
    while (line != "")
    {
      List<string> profile;
      profile.push(line);
      line = read_profiles_csv.read();
      profile.push(line);
      profiles.push(profile);
      line = read_profiles_csv.read();
    }

    read_profiles_csv.close();

    // Store the current profile
    // If there is a profile with the same name, overwrite it
    if (state->userName != "")
    {
      for (auto profile : profiles)
      {
        if (profile[0] == state->userName)
        {
          profile[1] = std::to_string(state->userPoints);
          break;
        }
      }
    }

    // Store updated profiles
    for (int i = 0; i < profiles.length; i++)
    {
      // Open profiles CSV
      CSV write_profiles_csv("../../pa1/profiles.csv");
      result = write_profiles_csv.load(std::ios::out);
      if (!result)
      {
        return false;
      }

      // Store our profiles
      for (int i = 0; i < profiles.length; i++)
      {
        write_profiles_csv.write(false, profiles[i][0]);
        write_profiles_csv.write(true, profiles[i][1]);
      }

      write_profiles_csv.close();
    }

    return true;
  }
};

State *State::_instance = nullptr;
