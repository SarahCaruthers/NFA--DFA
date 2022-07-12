/* Sarah Caruthers
2350081
caruthers@chapman.edu
CPSC 406-01
Course Project
*/

#ifndef Converter_H
#define Converter_H

#include "FileReader.h"
#include "FileWriter.h"
#include <string>
#include <sstream>
#include <iostream>
#include <math.h>
#include <map>

using namespace std;

class Converter{
public:
  Converter();
  ~Converter();

  void EPSClosureStates();
  void CreateNewState();
  void AddNewState(string state);
  void CreateNewState(string state);
  string StripDelta(string s);
  string FindSet();
  void PowerSet(string set, int index=0, string curr="");
  void FindAcceptStates();
  void StateTransitions();
  void CreateTransitionsA();
  void CreateTransitionsB();
  string DeltaOnA();
  string DeltaOnB();
  string Format(string str);
  void ParseSigma();

  string getSigma();
  string getDFAqo();
  string getDFAF();
  string getDFAQ();
  string getPowerSet();
  string getATrans();
  string getBTrans();

  string Nsigma;
  string DFAqo;
  string DFASigma;
  string DFAQ;
  string epsStates;
  string set;
  string powerSet;
  int setSize;
  string DFAF;
  string powerSetStates;
  string ATrans;
  string BTrans;
  string deltaA;
  string deltaB;
  string completeA;
  string completeB;

  FileReader fr;
  FileWriter fw;

  map<char, char> hashMapA;
  map<char, char> hashMapB;





};

#endif
