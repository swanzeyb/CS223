//***************************************************************************//
//**
//**  Simple Heap implementation
//**
//***************************************************************************//

#ifndef __HEAP_H
#define __HEAP_H
#include <iostream>
#include <vector>
#include <stdexcept> // std::out_of_range
#include <math.h>		 // pow()
#include <string>
#include <limits>

/**
 *  Declaring Heap class
 */
template <typename T>
class Heap
{

private:
	std::vector<T> _items; // Main vector of elements for heap storage. The first item in the array is a placeholder.

	/*********************************************************************/
	/********************* Start Microassignment zone ********************/

	/**
	 *  Percolates the item specified at by index down
	 *   into its proper location within a heap.
	 *  Used for dequeue operations and array to heap conversions
	 *  MA TODO: Implement percolateDown
	 */
	void percolateDown(unsigned int hole)
	{
		// Find end of heap
		unsigned int end = _items.size() - 1;

		// Start from hole
		unsigned int i = hole;

		// Percolate down while not at end
		while (i * 2 <= end)
		{
			// Find left child
			unsigned int child = i * 2;

			// If right child exists and is less than left child
			if (child != end && _items[child + 1] < _items[child])
			{
				// Goto right child
				child += 1;
			}

			// If child is less than parent
			if (_items[child] < _items[i])
			{
				// Swap child with parent
				std::swap(_items[i], _items[child]);

				// Goto next child
				i = child;
			}
			else
			{
				// Done percolating
				break;
			}
		}
	}

	/**
	 *  Add a new item to the end of the heap and percolate up this item to fix heap property
	 *  Used in inserting new nodes into the heap
	 *  MA TODO: Implement percolateUp
	 */
	void percolateUp(T item)
	{
		// Insert item at end of vector
		_items.push_back(item);

		// Start from newly inserted item
		unsigned int i = _items.size() - 1;

		// Percolate up while not at root and item is less than parent
		while (i > 1 && _items[i] < _items[i / 2])
		{
			// Swap item with it's parent
			std::swap(_items[i], _items[i / 2]);

			// Goto next parent's index
			i /= 2;
		}
	}

	/********************** End Microassigment zone *********************/

public:
	/**
	 *  Default empty constructor
	 */
	Heap()
	{
		_items.push_back(std::numeric_limits<T>::min()); // Push a placeholder for the first item in the array
	}

	/**
	 *  Adds a new item to the heap
	 */
	void push(T item)
	{
		percolateUp(item);
	}

	/**
	 *  Removes minimum value from heap
	 */
	T pop()
	{
		long unsigned int last_index = _items.size() - 1; // Calc last item index
		int root_index = 1;																// Root index (for readability)

		if (size() == 0)
		{
			throw std::out_of_range("pop() - No elements in heap");
		}

		T minItem = _items[root_index];

		_items[root_index] = _items[last_index]; // Move last item to root
		_items.pop_back();											 // Erase last element entry

		if (size() > 0)
		{										// Only runs if the heap isn't empty now
			percolateDown(1); // Fix heap property
		}
		return minItem;
	}

	/**
	 *  Returns true if heap is empty, else false
	 *  Consider the first placeholder in the array
	 */
	bool empty() const
	{
		if (_items.size() == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 *  Returns current quantity of elements in heap (N)
	 *  Consider the first placeholder in the array
	 */
	long unsigned int size() const
	{
		return _items.size() - 1;
	}

	/**
	 *  Return heap data in order from the _items vector
	 */
	std::string to_string() const
	{
		std::string ret = "";
		for (unsigned int i = 1; i < _items.size(); i++)
		{
			ret += std::to_string(_items[i]) + " ";
		}
		return ret;
	}
};

#endif
