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

  // Create some test trees and fill them with the numbers
  AVLTree<int> ascendingTree;
  AVLTree<int> descendingTree;
  AVLTree<int> randomTree;

  for (int i = 0; i < nums.size(); i++)
  {
    ascendingTree.insert(ascending[i]);
    descendingTree.insert(descending[i]);
    randomTree.insert(random[i]);
  }

  // cout the heights of the trees, validate the trees
  cout << "Height of Tree 1 (ascending): " << ascendingTree.height() << endl;
  cout << "Height of Tree 2 (descending): " << descendingTree.height() << endl;
  cout << "Height of Tree 3 (random): " << randomTree.height() << endl;
  cout << "Validation for Tree 1 (ascending): " << ascendingTree.validate() << endl;
  cout << "Validation for Tree 2 (descending): " << descendingTree.validate() << endl;
  cout << "Validation for Tree 3 (random): " << randomTree.validate() << endl;

  // Testing contains
  for (int i = 1; i < 100; i += 2)
  {
    bool containsInTree1 = ascendingTree.contains(i);
    bool containsInTree2 = descendingTree.contains(i);
    bool containsInTree3 = randomTree.contains(i);

    if (i % 2 == 1 && (!containsInTree1 || !containsInTree2 || !containsInTree3))
    {
      cout << "My AVL tree implementation is wrong" << endl;
      break;
    }
    else if (i % 2 == 0 && (containsInTree1 || containsInTree2 || containsInTree3))
    {
      cout << "My AVL tree implementation is wrong" << endl;
      break;
    }
  }

  return 0;
}
