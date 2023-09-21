#pragma once

#include <string>
#include "Component.h"
#include "State.h"

using std::string;

class Game : public Component
{
private:
  string getRandomCommand()
  {
    State *state = State::getInstance();
    return (state->commands)[rand() % state->descriptions.length];
  }

  string getRandomDescription()
  {
    State *state = State::getInstance();
    return (state->descriptions)[rand() % state->descriptions.length];
  }

public:
  Game(){};
  ~Game(){};
  Layout render()
  {
    State *state = State::getInstance();

    // Get the user's name
    printw("What is your name?\n");
    char name[256];
    getstr(name);
    state->userName = string(name);

    // Get the number of rounds
    printw("How many matching rounds would you like, %s?\n", state->userName.c_str());
    char rounds[256];
    getstr(rounds);
    state->rounds = atoi(rounds);

    // Play the game
    while (state->rounds > 0)
    {
      state->rounds -= 1;
      clear();
      refresh();

      // Get our random picks for this round
      List<List<string>> picks;
      for (size_t i = 0; i < 3; i++)
      {
        List<string> pick;

        // Get random command
        string command = getRandomCommand();

        // Dedupe
        while (picks.some([command](List<string> other)
                          { return other.includes(command); }))
        {
          command = getRandomCommand();
        }

        // Lookup the commands description
        string description = state->descriptions[state->commands.indexOf(command)];

        pick.push(command);
        pick.push(description);
        picks.push(pick);
      }

      // Pick a random one to quiz them on
      size_t answer = rand() % picks.length;

      // Print command
      printw("Which description matches the command?\n");
      printw("\nCommand: %s\n", picks[answer][0].c_str());

      // Print descriptions
      for (size_t i = 0; i < picks.length; i++)
      {
        printw("%lu. %s\n", i + 1, picks[i][1].c_str());
      }

      // Get the user's answer
      printw("\nAnswer: ");

      /*
        Find the int value by subtracting ASCII value of
        '0' (which is 48) from the ASCII value of the character returned by getch().
        This works because the ASCII value of '0' is 48, '1' is 49, and so on.
      */
      int choice = (getch() - '0') - 1; // Minus 1 to account for 0-based index

      // Blank slate
      clear();
      refresh();

      // Check if the user's answer is correct
      if (answer == choice)
      {
        state->userPoints += 1;
        printw("Correct! You now have %d points.\n", state->userPoints);
      }
      else
      {
        state->userPoints -= 1;
        printw("Incorrect! You now have %d points.\n", state->userPoints);
        printw("\n%s: %s\n", picks[answer][0].c_str(), picks[answer][1].c_str());
      }
      printw("\nPress any key to continue... ");
      getch();
    }

    return Layout();
  }
};
