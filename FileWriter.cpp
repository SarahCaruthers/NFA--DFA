/* Sarah Caruthers
2350081
caruthers@chapman.edu
CPSC 406-01
Course Project
*/

#include <iostream>
#include <fstream>
#include "FileWriter.h"

using namespace std;

FileWriter::FileWriter(){

}

FileWriter::~FileWriter(){

}

void FileWriter::WriteToFile(string str){
  ofstream outFS;
  outFS.open("NFAtoDFA4.txt.DFA", ios_base::app);

  if (!outFS.is_open()) {
     cout << "Could not open file: " << endl;
     return;
  }

  outFS << str << endl;

  outFS.close();
}
