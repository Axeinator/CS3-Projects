#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
    string name;
    char choice = ' ';
    Tree t;
    while (choice != '4') {
        cout << "Menu:" << endl;
        cout << "1. Add a person" << endl;
        cout << "2. Print all persons" << endl;
        cout << "3. Print details of a specific person" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == '1') {
            cout << "Enter the name of the person to add: ";
            cin >> name;
            t.addPerson(name);
        } else if (choice == '2') {
            cout << "Printing all persons:" << endl;
            t.printAll();
        } else if (choice == '3') {
            cout << "Enter the name of the person to print details: ";
            cin >> name;
            Person* person = t.findPerson(name);
            if (person != nullptr) {
                cout << "Details of person " << name << ":" << endl;
                cout << "Children: ";
                for (auto child : person->getChildren()) {
                    cout << child->name << ", ";
                }
                cout << endl << "Lover: ";
                if (person->getPartner() != nullptr) {
                    cout << person->getPartner()->name;
                } else {
                    cout << "";
                }
                cout << endl << "Parents: ";
                for (auto parent : person->getParents()) {
                    cout << parent->name << ", ";
                }
                cout << endl;
            } else {
                cout << "Person not found." << endl;
            }
        } else if (choice == '4') {
            cout << "Exiting..." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

