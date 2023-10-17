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
using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//
template<typename K, typename V>
class ChainingHash : public Hash<K,V> {
private:

public:
    ChainingHash(int n = 11) {
    }

    ~ChainingHash() {
        this->clear();
    }

    int size() {
        return -1;
    }

    V operator[](const K& key) {
        return -1;
    }

    bool insert(const std::pair<K, V>& pair) {
        return true;
    }

    void erase(const K& key) {
    }

    void clear() {
    }

    int bucket_count() {
        return -1;
    }

    float load_factor() {
        return -1;
    }

private:
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

    int hash(const K& key) {
        return 0;       
    }

};

#endif //__CHAINING_HASH_H
