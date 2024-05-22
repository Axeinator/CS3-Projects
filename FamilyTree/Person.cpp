#include "Person.h"

Person::Person(string name) {
  this->name = name;
}

vector<Person*> Person::getParents() {
  return parents;
}
vector<Person*> Person::getChildren() {
  return children;
}
Person* Person::getPartner() {
  return partner;
}

void Person::print(Person* p) {
  cout << "Name: " << p->name << endl;
  cout << "Parents: ";
  for (int i = 0; i < p->parents.size(); i++) {
    cout << p->parents[i]->name << ", ";
  }
  cout << endl << "Children: ";
  for (int i = 0; i < p->children.size(); i++) {
    cout << p->children[i]->name << ", ";
  }
  cout << endl << "Partner: " << p->partner;
}

