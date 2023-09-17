#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

enum Status {
  CSV_DATA,
  CSV_NEWLINE,
  CSV_EOF,
  CSV_ERROR,
};

class CSV {
  private:
    fstream _file;
    string _path;
    char _delimeter;
    char _word;
    string _data;

  public:
    CSV(string path, char delimeter = ',', char word = '\"'): _path(path), _delimeter(delimeter), _word(word) {};

    ~CSV() {
      if (_file.is_open()) {
        _file.close();
      }
    };

    bool load() {
      _file.open(_path, ios::in);
      return _file.is_open();
    }

    string read() {
      // Don't read if the file is not open or at the end of the file
      if (!_file.is_open() || _file.eof()) {
        return "";
      }

      string line;
      getline(_file, line, _delimeter);

      // Check for many words in one cell
      size_t start = line.find_first_of(_word) + 1; // Skip the first quote
      size_t end = line.find_first_of(_word, start);
      if (start != end) {
        line = line.substr(start, end - start);
      }

      return line;
    }
};
