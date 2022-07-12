/* Sarah Caruthers
2350081
caruthers@chapman.edu
CPSC 406-01
Course Project
*/

#include "Converter.h"
#include "FileReader.h"
#include "FileWriter.h"
#include <map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;


Converter::Converter(){
  string DFAqo;
  string DFASigma;
  string DFAQ;
  string DFAF;
  string epsStates;
  string set;
  int setSize;
  string powerSet;
  map<char, char> hashMapA;
  map<char, char> hashMapB;
  string ATrans;
  string BTrans;
  string deltaA;
  string deltaB;
  string completeA;
  string completeB;
  string Nsigma;
}

Converter::~Converter(){

}

string Converter::getDFAqo(){
  return DFAqo;
}

string Converter::getDFAQ(){
  return DFAQ;
}

string Converter::getDFAF(){
  return DFAF;
}

string Converter::getSigma(){
  DFASigma = fr.getSigma();
  return DFASigma;
}

string Converter::getPowerSet(){
  return powerSet;
}

string Converter::getATrans(){
  return ATrans;
}

string Converter::getBTrans(){
  return BTrans;
}

void Converter::CreateNewState(string state){
  AddNewState(state);
}

void Converter::AddNewState(string state){
  DFAQ = "{" + state + "}";
  DFAQ += '\t';
}

//https://stackoverflow.com/questions/13172158/c-split-string-by-line = stringstream functions
//https://www.cplusplus.com/reference/string/string/find/ = find function
void Converter::ParseSigma(){
  string sig = fr.getSigma();
  for (int i=0; i<sig.size(); ++i){
    if (isdigit(sig.at(i)) || isalpha(sig.at(i))){
      Nsigma.push_back(sig.at(i));
    }
  }
}

void Converter::EPSClosureStates(){
  string eps = "";
  string delta = fr.getDelta();
  stringstream ss(delta);
  string currLine;
  while(getline(ss, currLine)){
    size_t found = currLine.find("EPS");
    if (found != string::npos){
      for (int i=0; i<currLine.size(); ++i){
        if (isdigit(currLine.at(i))){
          eps.push_back(currLine.at(i));
        }
      }
      CreateNewState(eps);
    }
   }
   DFAqo += eps;
}

string Converter::FindSet(){
  string states = fr.getQ();
  for (int i=0; i<states.size(); ++i){
    if (isdigit(states.at(i))){
      set.push_back(states.at(i));
    }
  }
  return set;
}

//https://www.geeksforgeeks.org/recursive-program-to-generate-power-set/
void Converter::PowerSet(string set, int index, string curr){
  int n = set.length();
  if (index == n){
    powerSet += curr;
    powerSet += '\t';
    return;
  }
  PowerSet(set, index+1, curr+set[index]);
  PowerSet(set, index+1, curr);
}

void Converter::FindAcceptStates(){
  string accept = fr.getF();
  stringstream ss(powerSet);
  string currLine;
  while(getline(ss, currLine, '\t')){
    for (int i=0; i<currLine.size(); ++i){
      if (isdigit(currLine.at(i))){
        if (accept.find(currLine.at(i)) != string::npos){
          DFAF += currLine;
          DFAF += '\t';
        }
      }
    }
  }
}

void Converter::StateTransitions(){
  string delta = fr.getDelta();
  stringstream ss(delta);
  string currLine;
  while (getline(ss, currLine)){
    if (currLine.find("a") != string::npos || currLine.find("0") != string::npos){
      ATrans += currLine;
      ATrans += '\n';
    }
    else if (currLine.find("b") != string::npos || currLine.find("1") != string::npos){
      BTrans += currLine;
      BTrans += '\n';
    }
  }
}

void Converter::CreateTransitionsA(){
  stringstream ss(ATrans);
  string currLine;
  while (getline(ss, currLine, '\n')){
    for (int i=0; i<currLine.size(); ++i){
      char a = currLine.at(1);
      char b = currLine.at(currLine.size()-2);
      hashMapA.insert(make_pair(a,b));
    }
  }
}

void Converter::CreateTransitionsB(){
  stringstream ss(BTrans);
  string currLine;
  while (getline(ss, currLine)){
    char a = currLine[1];
    char b = currLine[currLine.size()-2];
    hashMapB.insert(make_pair(a,b)); //https://thispointer.com/stdmap-tutorial-part-1-usage-detail-with-examples/
  }
}

string Converter::DeltaOnA(){
  string completeA;
  stringstream ss(powerSet);
  string currLine;
  char c;
  char found;
  char a = Nsigma.at(0);
  while (getline(ss, currLine, '\t')){
    string deltaA = "";
    for (int i=0; i<currLine.size(); ++i){
      c = currLine.at(i);
      found = hashMapA[c];
      deltaA.push_back(found);
    }
     completeA += "{";
     completeA += currLine;
     completeA += "}";
     completeA += ", ";
     completeA.push_back(a);
     completeA += " = {";
     completeA += deltaA;
     completeA += "}";
     completeA +='\n';
  }
  return completeA;
}

string Converter::DeltaOnB(){
  string completeAB;
  stringstream ss(powerSet);
  string currLine;
  char b = Nsigma.at(1);
  while (getline(ss, currLine, '\t')){
    string deltaB = "";
    for (int i=0; i<currLine.size(); ++i){
      char c = currLine.at(i);
      char found = hashMapB[c];
      deltaB.push_back(found);
    }
     completeB += "{";
     completeB += currLine;
     completeB += "}";
     completeB += ", ";
     completeB.push_back(b);
     completeB += " = {";
     completeB += deltaB;
     completeB += "}";
     completeB +='\n';
  }
  return completeB;
}

string Converter::Format(string str){
  string format = "";
  stringstream ss(str);
  string currLine;
  while (getline(ss, currLine, '\t')){
    format += "{";
    format += currLine;
    format += "}";
    format += '\t';
  }
  return format;
}
