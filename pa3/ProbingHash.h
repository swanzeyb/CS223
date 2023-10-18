#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>

#include "Hash.h"

using std::pair;
using std::vector;

// Can be used for tracking lazy deletion for each element in your table
enum EntryState
{
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};

template <typename K, typename V>
class ProbingHash : public Hash<K, V>
{ // derived from Hash
private:
    // Needs a table and a size.
    // Table should be a vector of std::pairs for lazy deletion
    vector<pair<K, V>> _store;
    vector<EntryState> _status;
    int _currentSize;

public:
    ProbingHash(int n = 11)
    {
        int buckets = findNextPrime(n);
        _store.resize(buckets);
        _status.resize(buckets);
        std::fill(_status.begin(), _status.end(), EMPTY);
        _currentSize = 0;
    }

    ~ProbingHash()
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
        int start = index;

        do
        {
            if (_store[index].first == key)
            {
                return _store[index].second;
            }
            index = (index + 1) % _store.size();
        } while (index != start); // Loop until we've checked every item

        throw std::out_of_range("Key not found");
    }

    bool insert(const std::pair<K, V> &pair)
    {
        int index = hash(pair.first);
        while (_status[index] == VALID)
        {
            index = (index + 1) % _store.size();
        }

        if ((size_t)index >= _store.size() - 1)
        {
            return false;
        }

        _store[index] = pair;
        _status[index] = VALID;
        _currentSize += 1;

        if (load_factor() >= 0.75)
        {
            rehash();
        }

        return true;
    }

    void erase(const K &key)
    {
        int index = hash(key);
        int start = index;

        do
        {
            if (_store[index].first == key)
            {
                _status[index] = DELETED;
                _currentSize -= 1;
                return;
            }
            index = (index + 1) % _store.size();
        } while (index != start); // Loop until we've checked every item
    }

    void clear()
    {
        _store.clear();
        _status.clear();
        _currentSize = 0;
    }

    int bucket_count()
    {
        return _store.size();
    }

    float load_factor()
    {
        return (float)_currentSize / _store.size();
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

    int hash(const K &key)
    {
        return key % _store.size();
    }

    void rehash()
    {
        int buckets = findNextPrime(_store.size() * 2);
        vector<pair<K, V>> store(buckets);
        vector<EntryState> status(buckets);
        std::fill(status.begin(), status.end(), EMPTY);
        _currentSize = 0;

        for (size_t i = 0; i < _store.size(); i++)
        {
            if (_status[i] == VALID) // Find all valid entries and rehash them
            {
                pair<K, V> pair = _store[i];
                int index = pair.first % buckets;
                while (status[index] == VALID)
                {
                    index = (index + 1) % store.size();
                }

                store[index] = pair;
                status[index] = VALID;
                _currentSize += 1;
            }
        }

        _store = store;
        _status = status;
    }
};

#endif //__PROBING_HASH_H
