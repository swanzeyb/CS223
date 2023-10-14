#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // std::shuffle
#include <random>    // std::default_random_engine
#include <chrono>    // std::chrono::system_clock
#include "AVLTree.h"

using namespace std;

int main()
{
  // Seed our random number generator with current unix time
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();

  // Fix our random numbers not working as expected by using seed
  default_random_engine randomEngine(seed);

  // Get a bunch of random numbers
  vector<int> nums;
  for (int i = 1; i < 100; i += 2)
  {
    nums.push_back(i);
  }

  // Numbers already ascending using this method of generation
  vector<int> ascending = nums;

  // Sort the numbers in descending order
  vector<int> descending = nums;
  sort(descending.begin(), descending.end(), greater<int>());

  // Shuffle the numbers
  vector<int> random = nums;
  shuffle(random.begin(), random.end(), randomEngine);

  return 0;
}
