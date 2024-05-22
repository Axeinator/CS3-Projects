#include "program.h"

void program::raceFinder(map<string, stuct>& m, map<string, string>& races) {
  // Open the file for reading
  myReader.open("testingDataSet-1.csv");
  if (!myReader.is_open()) {
    cout << "Reader failed. " << endl;
  }

  // Variables for storing data
  string line, lname, race;
  int space, x;
  int ld = 0;

  // Iterate through each line in the file
  while (getline(myReader, line)) {
    // Find the position of the first space and the first comma in the line
    space = line.find(' ') + 1;
    x = line.find(',');

    // Extract the last name from the line
    lname = line.substr(space, x - space);
    string elname;

    // Remove spaces and convert to uppercase
    int i = 0;
    while (i < lname.length()) {
      if (!(lname[i] == ' ')) {
        elname += toupper(lname[i]);
      }
      i++;
    }

    // store based on full name, not just last name
    if (races.find(elname) != races.end()) {
      m[line.substr(0, x)].race = races[elname];
    }
    else {
      m[line.substr(0, x)].race = "unknown";
    }
    ld++;
    if(ld % 50000 == 0) cout << "Race Finder: " << ld << endl;
  }
  myReader.close();
}

void program::compFinder(map<string, stuct>& m) {
  // Open the file for reading
  myReader.open("testingDataSet-1.csv");

  // Variables for storing data
  string line, name;
  int date = 0;
  vector<int> v;
  int ld = 0;

  // Iterate through each line in the file
  try { 
  while (getline(myReader, line)) {
    int commaCount = 0;
    int comma = 0;
    for (int i = 0; i < line.length(); ++i) {
        if (line[i] == ',') {
            commaCount++;
            if (commaCount == 36) {
                comma = i;
                break; // Return the position of the 36th comma
            }
        }
    }  
    date = stoi(line.substr(comma + 1, 4));
    // Extract the name from the line
    int x = line.find(',');
    name = line.substr(0, x);

      // Update the number of competitions and store dates for the same name
    m[name].comp++;
    m[name].dates.push_back(date);

    ld++;
    if (ld % 50000 == 0) cout << "Competition Counter: " << ld << endl;
  }
}


void program::generateCsv(map<string, stuct>& m) {
  // Open the file for reading
  ifstream mReader;
  mReader.open("testingDataSet-1.csv");
  if (!mReader.is_open()) {
    cout << "Reader failed.";
  }

  // Open a file for writing
  myWriter.open("newFile.csv");
  if (!myWriter.is_open()) {
    cout << "Writer failed.";
  }
  string line;
  int ld = 0;
  while(getline(mReader, line)) {
    int x = line.find(',');
    string name = line.substr(0, x);
    myWriter << line;
    // find the details associated with the name
    stuct s = m.at(name);
    int minDate = 3000;
    int maxDate = 0;
    for (int i = 0; i < s.dates.size(); i++) {
      if (s.dates[i] < minDate) minDate = s.dates[i];
      if (s.dates[i] > maxDate) maxDate = s.dates[i];
    }
    int years = maxDate - minDate + 1;
    myWriter << "," << s.race << "," << s.comp << "," << years << endl;
    ld++;
    if (ld % 50000 == 0) cout << "CSV Generator: " << ld << endl;
  }
}
