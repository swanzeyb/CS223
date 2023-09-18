#include <iostream>
#include <string>
#include <memory>

#include "Scene.h"
#include "Menu.h"
#include "Layout.h"
#include "Lifecycle.h"
#include "List.h"
#include "CSV.h"

using std::string;
using std::cout;
using std::endl;
using std::shared_ptr;

int main(int, char**) {
  // Load the available commands
  CSV csv("../../pa1/commands.csv");
  bool result = csv.load();

  if (!result) {
    cout << "Failed to load commands CSV" << endl;
    return 1;
  }

  // Store our commands and descriptions
  List<string> commands;
  List<string> descriptions;

  // Skip the header
  csv.skip(2);

  // Read the commands and descriptions
  string line = csv.read();
  int index = 1;
  while (line != "") {
    // Place the command and description into the appropriate list
    if (index % 2 == 0) {
      descriptions.push(line);
    } else {
      commands.push(line);
    }

    line = csv.read();
    index += 1;
  }

  // Main scene
  Scene* scene = new Scene();

  // Start our scene manager
  Lifecycle lifecycle = { scene };
}
 