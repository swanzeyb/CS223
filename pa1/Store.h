#pragma once

#include <string>
#include "List.h"

using std::to_string;

template <typename Key, typename Value>
class Store {
  private:
    List<Key> keys;
    List<Value> values;

  public:
    Store() {};
    ~Store() {};

    Value get(Key key) {
      return keys[key];
    }

    void set(Key key, Value value) {
      keys.push(key);
      values.push(value);
    }
};
