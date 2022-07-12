/* Sarah Caruthers
2350081
caruthers@chapman.edu
CPSC 406-01
Course Project
*/

/* This class is adapted from my FileReader class used
for my RPNCalc assignment from Data Structures */

#ifndef FileReader_H
#define FileReader_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class FileReader{
public:
  FileReader();
  ~FileReader();

  void ProcessNFAFile(string inFile);

  string getQ();
  string getSigma();
  string getQo();
  string getF();
  string getDelta();

  void setDelta(string delta);

  string Q;
  string sigma;
  string qo;
  string F;
  string delta;

};
#endif
