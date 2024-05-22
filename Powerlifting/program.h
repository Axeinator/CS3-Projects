#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <cctype>

using namespace std;
struct stuct {
  string race;
  int comp, yer;
  vector<int> dates;
};
class program {
public:
  ifstream myReader;
  ofstream myWriter;
  void raceFinder(map<string, stuct>&, map<string, string>&);
  void compFinder(map<string, stuct>&);
  void generateCsv(map<string,stuct>&);
};



