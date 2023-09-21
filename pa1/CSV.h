#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

enum Status
{
  CSV_DATA,
  CSV_NEWLINE,
  CSV_EOF,
  CSV_ERROR,
};

class CSV
{
private:
  fstream _file;
  string _path;
  char _delimeter;
  char _word;
  string _data;

public:
  CSV(string path, char delimeter = ',', char word = '\"') : _path(path), _delimeter(delimeter), _word(word){};

  ~CSV()
  {
    if (_file.is_open())
    {
      _file.close();
    }
  };

  bool load(std::ios_base::openmode mode = ios::in)
  {
    _file.open(_path, mode);
    return _file.is_open();
  }

  string read()
  {
    // Don't read if the file is not open or at the end of the file
    if (!_file.is_open() || _file.eof())
    {
      _file.close();
      return "";
    }

    _data = "";
    char c = '\0';
    while (_file.get(c))
    {
      // We don't care about new lines, space, or carraige returns
      if (c == '\n' || c == '\r' || c == ' ')
      {
        continue;
      }

      // If we find a word, we need to read until the next word
      if (c == _word)
      {
        // Read until the next word
        while (_file.get(c))
        {
          if (c == _word)
          {
            // We found a word, so we can return the data

            // Skip the delimeter
            if (_file.peek() == _delimeter)
            {
              _file.get();
            }

            return _data;
          }

          _data += c;
        }
      }

      // Otherwise, we need to read until the next delimeter
      if (c == _delimeter)
      {
        // We found a delimeter, so we can return the data
        return _data;
      }
      else
      {
        _data += c;
      }
    }

    return "";
  }

  void skip(int num)
  {
    for (int i = 0; i < num; i++)
    {
      read();
    }
  }

  bool write(bool newline, string data)
  {
    // Can't write to closed file
    if (!_file.is_open())
    {
      return false;
    }

    if ((data.find(_delimeter) || data.find(' ')) != string::npos)
    {
      // Has a character we need to escape
      data = _word + data + _word;
    }

    if (newline)
    {
      data += '\n';
    }
    else
    {
      data += _delimeter;
    }

    _file << data;
    return true;
  }

  void close()
  {
    if (_file.is_open())
    {
      _file.close();
    }
  }
};
