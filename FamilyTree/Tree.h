#include "Person.h"

class Tree {
  private:
    Person* root;
  public:
    Tree();
    void setRoot(Person*);
    Person* getRoot();
    void printAll();
    void addPerson(string name);
    Person* findPerson(string& name);
};


