#include<iostream>
#include "program.h"
using namespace std;
map<string, string> createLastNameMap() {
  map<string, string> lastNameMap;
  ifstream lastNameFile("last_nameRaceProbs.csv");
  string line;
  getline(lastNameFile, line);
  while (getline(lastNameFile, line)) {
    int comma1 = line.find(',');
    int comma2 = line.find(',', comma1 + 1);
    int comma3 = line.find(',', comma2 + 1);
    int comma4 = line.find(',', comma3 + 1);
    int comma5 = line.find(',', comma4 + 1);
    double probWhite, probBlack, probHispanic, probAsian, probOther;

    string lastName = line.substr(0, comma1);
    probWhite = stod(line.substr(comma1 + 1, comma2 - comma1 - 1));
    probBlack = stod(line.substr(comma2 + 1, comma3 - comma2 - 1));
    probHispanic = stod(line.substr(comma3 + 1, comma4 - comma3 - 1));
    probAsian = stod(line.substr(comma4 + 1, comma5 - comma4 - 1));
    probOther = stod(line.substr(comma5 + 1));


    double biggest = probWhite;
    string race = "white";
    if (probBlack > biggest) {race = "black"; biggest = probBlack;}
    if (probHispanic > biggest) {race = "hispanic"; biggest = probHispanic;}
    if (probAsian > biggest) {race = "asian"; biggest = probAsian;}
    if (probOther > biggest) {race = "other"; biggest = probOther;}

    lastNameMap[lastName] = race;
  }
  return lastNameMap;
}


int main() {
  program b;
  map<string, stuct> l;
  map<string, string> races = createLastNameMap();
  b.raceFinder(l, races);
  b.compFinder(l);
  b.generateCsv(l);
  
  return 0;
}  
