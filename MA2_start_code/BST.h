#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
#include <queue>
using namespace std;

/*
 *  Data structure for a single tree node
 */
template <typename T>
struct Node
{
public:
	T value;
	Node *left;
	Node *right;

	Node(T val)
	{
		this->value = val;
		this->left = nullptr;
		this->right = nullptr;
	}

	~Node()
	{
		this->value = 0;
		this->left = nullptr;
		this->right = nullptr;
	}
};

/*
 * Binary Search Tree (BST) class implementation
 */
template <typename T>
class BST
{

protected:
	Node<T> *_root; // Root of the tree nodes

	/* Add new T val to the tree */
	void addHelper(Node<T> *root, T val)
	{
		if (root->value > val)
		{
			if (!root->left)
			{
				root->left = new Node<T>(val);
			}
			else
			{
				addHelper(root->left, val);
			}
		}
		else
		{
			if (!root->right)
			{
				root->right = new Node<T>(val);
			}
			else
			{
				addHelper(root->right, val);
			}
		}
	}

	/* Print tree out in inorder (A + B) */
	void printInOrderHelper(Node<T> *root)
	{
		if (!root)
			return;
		printInOrderHelper(root->left);
		cout << root->value << ' ';
		printInOrderHelper(root->right);
	}

	/* Return number of nodes in tree */
	int nodesCountHelper(Node<T> *root)
	{
		if (!root)
		{
			return 0;
		}
		else
		{
			return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
		}
	}

	/* Return height of tree (root == nullptr -> 0) */
	int heightHelper(Node<T> *root)
	{
		if (!root)
		{
			return -1;
		}
		else
		{
			return 1 + max(heightHelper(root->left), heightHelper(root->right));
		}
	}

	/* Delete a given <T> value from tree */
	bool deleteValueHelper(Node<T> *parent, Node<T> *current, T value)
	{
		if (!current)
			return false;
		if (current->value == value)
		{
			if (current->left == nullptr || current->right == nullptr)
			{
				Node<T> *temp = current->left;
				if (current->right)
					temp = current->right;
				if (parent)
				{
					if (parent->left == current)
					{
						parent->left = temp;
					}
					else
					{
						parent->right = temp;
					}
				}
				else
				{
					this->_root = temp;
				}
			}
			else
			{
				Node<T> *validSubs = current->right;
				while (validSubs->left)
				{
					validSubs = validSubs->left;
				}
				T temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return deleteValueHelper(current, current->right, temp);
			}
			delete current;
			return true;
		}
		return deleteValueHelper(current, current->left, value) ||
					 deleteValueHelper(current, current->right, value);
	}

	void deleteSubTree(Node<T> *root)
	{
		if (root == nullptr)
			return; // Nothing to delete
		deleteSubTree(root->left);
		deleteSubTree(root->right);
		delete root; // Delete the root after deleting all other trees
	}

	bool containsHelper(Node<T> *root, T value)
	{
		if (root == nullptr)
		{
			return false;
		}
		if (root->value == value)
		{
			return true;
		}
		if (root->value > value) // Value is less than root value, so go left
		{
			return containsHelper(root->left, value);
		}
		else
		{
			return containsHelper(root->right, value);
		}
	}

	/********************************* PUBLIC API *****************************/
public:
	BST() : _root(nullptr) {} // Basic initialization constructor

	/**
	 * Destructor - Needs to free *all* nodes in the tree
	 * TODO: Implement Destructor
	 */
	~BST()
	{
		deleteSubTree(this->_root); // Delete the root on destruction
	}

	/* Public API */

	/**
	 * Find if the BST contains the value
	 */
	bool contains(T value)
	{
		return containsHelper(this->_root, value);
	}

	void add(T val)
	{
		if (this->_root)
		{
			this->addHelper(this->_root, val);
		}
		else
		{
			this->_root = new Node<T>(val);
		}
	}

	void print()
	{
		printInOrderHelper(this->_root);
	}

	/**
	 * Print the nodes level by level, starting from the root
	 * TODO: Implement printLevelOrder
	 */
	void printLevelOrder()
	{
		if (!this->_root)
			return; // Nothing to print

		// Initialize queue with root
		queue<Node<T> *> q;
		q.push(this->_root);

		while (!q.empty())
		{
			Node<T> *current = q.front();
			q.pop();
			cout << current->value << ' '; // Print current level

			// Add our next node to print
			if (current->left)
				q.push(current->left);
			if (current->right)
				q.push(current->right);
		}
	}

	int nodesCount()
	{
		return nodesCountHelper(this->_root);
	}

	int height()
	{
		return heightHelper(this->_root);
	}

	/**
	 * Print the maximum path in this tree
	 * TODO: Implement printMaxPath
	 */
	void printMaxPath()
	{
		cout << "TODO: Implement printMaxPath" << endl;
	}

	bool deleteValue(T value)
	{
		return this->deleteValueHelper(nullptr, this->_root, value);
	}
};

#endif
