/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

// Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::list;
using std::pair;
using std::vector;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//
template <typename K, typename V>
class ChainingHash : public Hash<K, V>
{
private:
public:
    ChainingHash(int n = 11)
    {
        _currentSize = 0;
        _bucketCount = findNextPrime(n); // Prime bucket count for better distribution
        _store.resize(_bucketCount);
    }

    ~ChainingHash()
    {
        this->clear();
    }

    int size()
    {
        return _currentSize;
    }

    V operator[](const K &key)
    {
        int index = hash(key);
        pair<K, V> *pair = find(key, index);
        if (pair == nullptr)
        {
            throw std::out_of_range("Key not found");
        }
        return pair->second;
    }

    bool insert(const std::pair<K, V> &pair)
    {
        int index = hash(pair.first);
        if (find(pair.first, index) != nullptr) // Check if key already exists
        {
            return false;
        }

        _store[index].push_front(pair); // Newly inserted items are more likely to be queried
        _currentSize += 1;
        return true;
    }

    void erase(const K &key)
    {
        int index = hash(key);
        pair<K, V> *pair = find(key, index);
        if (pair == nullptr)
        {
            return;
        }
        _store[index].remove(*pair);
        _currentSize -= 1;
    }

    void clear()
    {
        for (auto &list : _store)
        {
            list.clear();
        }
        _currentSize = 0;
    }

    int bucket_count()
    {
        return _bucketCount;
    }

    float load_factor()
    {
        return -1;
    }

private:
    vector<list<pair<K, V>>> _store;
    int _currentSize;
    int _bucketCount;

    pair<K, V> *find(const K &key, int index)
    {
        for (auto &pair : _store[index])
        {
            if (pair.first == key)
            {
                return &pair;
            }
        }
        return nullptr;
    }

    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int hash(const K &key)
    {
        return key % _bucketCount;
    }
};

#endif //__CHAINING_HASH_H
