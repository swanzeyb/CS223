/*
  ADVANTAGES/DISADVANTAGES LINKED LIST:
  Advantage: Easy to add new commands to the front of the list.
  Disadvantage: Indexing certain positions takes forever because it has to iterate the entire list.
  ADVANTAGES/DISADVANTAGES ARRAY:
  Advantage: We can get info at any position quicker than linked list.
  Disadvantage: It only supports homogenous data types.
*/

#include <iostream>
#include <string>
#include <memory>

#include "Scene.h"
#include "Menu.h"
#include "Layout.h"
#include "Lifecycle.h"
#include "List.h"
#include "CSV.h"

using std::cout;
using std::endl;
using std::shared_ptr;
using std::string;

int main(int, char **)
{
  // Load the available commands
  CSV csv("../../pa1/commands.csv");
  bool result = csv.load();

  if (!result)
  {
    cout << "Failed to load commands CSV" << endl;
    return 1;
  }

  // Grab the global state
  State *state = State::getInstance();

  // Store our commands and descriptions
  // Skip the header
  csv.skip(2);

  // Read the commands and descriptions
  string line = csv.read();
  int index = 1;
  while (line != "")
  {
    // Place the command and description into the appropriate list
    if (index % 2 == 0)
    {
      state->descriptions.push(line);
    }
    else
    {
      state->commands.push(line);
    }

    line = csv.read();
    index += 1;
  }

  // Main scene
  Scene *scene = new Scene();

  // Start our scene manager
  Lifecycle lifecycle({scene});
}
