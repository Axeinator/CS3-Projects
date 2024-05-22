#include "Tree.h"

Tree::Tree() {
  root = nullptr;
}
void Tree::setRoot(Person* person) {
  root = person;
}

Person* Tree::getRoot() {
  return root;
}

void Tree::printAll() {
    if (root == nullptr) {
      cout << "Tree is empty" << endl; 
      return;
    }
    queue<Person*> personQueue;
    personQueue.push(root);
    set<Person*> visited;
    while (!personQueue.empty()) {
        Person* currentPerson = personQueue.front();
        personQueue.pop();
        if (visited.find(currentPerson) != visited.end()) {
            continue;
        }
        cout << currentPerson->name << endl;
        for (int i = 0; i < currentPerson->parents.size(); i++) {
            personQueue.push(currentPerson->parents[i]);
        }
        if (currentPerson->partner) {
            personQueue.push(currentPerson->partner);
        }
        for (int i = 0; i < currentPerson->children.size(); i++) {
            personQueue.push(currentPerson->children[i]);
        }
        visited.insert(currentPerson);
    }
}

Person* Tree::findPerson(string& name) {
  if (root == nullptr) {
    return nullptr;
  }
  queue<Person*> personQueue;
  personQueue.push(root);
  while (!personQueue.empty()) {
    Person* currentPerson = personQueue.front();
    personQueue.pop();
    if (currentPerson->name == name) {
      return currentPerson;
    }
    for (int i = 0; i < currentPerson->parents.size(); i++) {
      personQueue.push(currentPerson->parents[i]);
    }
    for (int i = 0; i < currentPerson->children.size(); i++) {
      personQueue.push(currentPerson->children[i]);
    }
    if (currentPerson->partner) {
      personQueue.push(currentPerson->partner);
    }
  }
  return nullptr;
}
void Tree::addPerson(string name) {
  Person* b = new Person(name);
  if (Tree::getRoot() == nullptr) {
    Tree::setRoot(b);
  } else {
    string selection;
    char relation;
    while (selection != "exit") {
      cout << "What connections does this person have? (list to see everyone in the tree, exit to stop)";
      cin >> selection;
      if (selection == "list") {
        printAll();
      } else if (selection != "exit") {
        cout << "What is the relationship to the new person? (p for parent, c for child, l for lover)";
        cin >> relation;
        if (relation == 'p') {
          Person* p = findPerson(selection);
          if (p != nullptr) {
            p->children.push_back(b);
            b->parents.push_back(p);
            cout << "Successfully added" << endl;
          } else {
            cout << "Not found" << endl;
          }
        } else if (relation == 'c') {
          Person* c = findPerson(selection);
          if (c != nullptr) {
            b->parents.push_back(c);
            c->children.push_back(b);
            cout << "Successfully added" << endl;
          } else {
            cout << "Not found" << endl;
          }
        }
        else if (relation == 'l') {
          Person* l = findPerson(selection);
          if (l != nullptr) {
            l->partner = b;
            b->partner = l;
            cout << "Successfully added" << endl;
          }
          else {
            cout << "Not found" << endl;
          }
        }
      }
    }
  }
}

