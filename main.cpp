/* Sarah Caruthers
2350081
caruthers@chapman.edu
CPSC 406-01
Course Project
*/

#include "FileReader.h"
#include "Converter.h"
#include <map>
#include <string>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[]){
  FileReader fr;
  FileWriter fw;
  Converter C;

  C.fr.ProcessNFAFile(argv[1]); //Nick M (don't know his last name) helped me with this
  C.ParseSigma();
  C.EPSClosureStates();
  string set = C.FindSet();
  C.PowerSet(set);
  string pow =  C.getPowerSet();
  string powF = C.Format(pow);
  fw.WriteToFile(powF);
  string sigma = C.getSigma();
  fw.WriteToFile(sigma);
  string qo = C.getDFAqo();
  string qoF = C.Format(qo);
  fw.WriteToFile(qoF);
  C.FindAcceptStates();
  string F = C.getDFAF();
  string FF = C.Format(F);
  fw.WriteToFile(FF);
  C.StateTransitions();
  C.CreateTransitionsA();
  string compA = C.DeltaOnA();
  fw.WriteToFile(compA);
  cout << "A " <<compA << endl;
  C.CreateTransitionsB();
  string compB = C.DeltaOnB();
  cout << "B " <<compB << endl;
  fw.WriteToFile(compB);






}
