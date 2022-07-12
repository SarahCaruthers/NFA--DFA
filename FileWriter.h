/* Sarah Caruthers
2350081
caruthers@chapman.edu
CPSC 406-01
Course Project
*/

#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <iostream>
#include <fstream>
using namespace std;

class FileWriter{
public:
  FileWriter();
  ~FileWriter();

  void WriteToFile(string str);
};

#endif
