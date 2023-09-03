#pragma once

#include <iostream>
#include <initializer_list>

class Layout {
  public:
    // Constructor with a variable number of arguments
    template<typename... Args>
    Layout(Args... args) {
      processArguments(args...);
    }

    void processArguments() {
      // Base case for recursion
    }

    template<typename T, typename... Args>
    void processArguments(T arg, Args... args) {
      std::cout << "Argument: " << arg << std::endl;
      processArguments(args...);  // Recurse with remaining arguments
    }
};
