#pragma once

#include "Component.h"
#include "State.h"
#include "CSV.h"

class Load : public Component
{
public:
  Layout render()
  {
    State *state = State::getInstance();

    // Get the user's name
    printw("What is your name?\n");
    char name[256];
    getstr(name);
    state->userName = string(name);

    // Find the user's save file
    // Temp store current profiles
    List<List<string>> profiles;

    // Open profiles CSV
    CSV read_profiles_csv("../../pa1/profiles.csv");
    bool result = read_profiles_csv.load(std::ios::in);
    if (!result)
    {
      clear();
      refresh();
      printw("Failed to load profiles CSV\n");
      printw("\nPress any key to continue... ");
      getch();
      return Layout();
    }

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
    // If there is a profile with the same name, read their points
    if (state->userName != "")
    {
      for (auto profile : profiles)
      {
        if (profile[0] == state->userName)
        {
          state->userPoints = std::stoi(profile[1]);
          clear();
          refresh();
          printw("Loaded %d points\n", state->userPoints);
          printw("\nPress any key to continue... ");
          getch();
          break;
        }
      }
    }

    return Layout();
  }
};
