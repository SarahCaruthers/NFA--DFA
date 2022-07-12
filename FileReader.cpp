/* Sarah Caruthers
2350081
caruthers@chapman.edu
CPSC 406-01
Course Project
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "FileReader.h"

using namespace std;

// default constructor
FileReader::FileReader(){
  string Q;
  string sigma;
  string qo;
  string F;
  string delta;
}

// default destructor
FileReader::~FileReader(){

}

/* processDNAFile()
creates an output file and prints the complement or reverse complement of a DNA sequnce from an input file
takes in the name of the input file, output file, and a string of input from the user to tell the program which method from class DNAComplement to call
*/
void FileReader::ProcessNFAFile(string inFile){
  ifstream inFS;
  // http://www.cplusplus.com/forum/beginner/121597/
  inFS.open(inFile);
  getline(inFS, Q, '\n');
  getline(inFS, sigma, '\n');
  getline(inFS, qo, '\n');
  getline(inFS, F, '\n');
  while (!inFS.eof()){
    string subDelt;
    getline(inFS, subDelt);
    delta += subDelt;
    delta +='\n';
  }
  inFS.close();
}

string FileReader::getQ(){
  return Q;
}

string FileReader::getSigma(){
  return sigma;
}

string FileReader::getQo(){
  return qo;
}

string FileReader::getF(){
  return F;
}

string FileReader::getDelta(){
  return delta;
}
