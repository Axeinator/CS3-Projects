#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Person {
public:
  vector<Person *> parents;
  vector<Person *> children;
  Person *partner;
  string name;
  Person(string name);
  vector<Person *> getParents();
  vector<Person *> getChildren();
  Person *getPartner();
  void print(Person *);
};
