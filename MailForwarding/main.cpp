#include <map>
#include <fstream>
#include <sstream>
#include "util.h"

// Enter your code here
struct node {
    string email;
    node* next;
};

void addEmail(string e, node* &head) {
    node* n = new node;
    n->email = e;
    n->next = nullptr;
    node* temp = head;
    if (head == nullptr) {
        head = n;
    }
    else {
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = n;
    }

    
}

void removeEmail(string e, node* &head) {
    if(!head) {
        cout << "Not found.";
        return;
    }
    if(head->email == e) {
        head = head->next;
        return;
    }
    node* temp = head;
    while(temp->next) {
        if(temp->next->email == e) {
            temp->next = temp->next->next;
            return;
        }
    }
    cout << "Not found. ";
    
}

string forwardingAddress(string name, string email, map<string, node*> &people) {
    if (people.find(name) != people.end()) {
        node* head = people[name];
        node* temp = head;
        while (temp != nullptr) {
            if (temp->email == email) {
                if (temp->next != nullptr) {
                    return temp->next->email;
                } else {
                    return "No Valid Email";
                }
            }
            temp = temp->next;
        }
    }
    return "Name not found.";
}


int main() {
    map<string, node*> people;
    ifstream file("initial.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, email;
        getline(ss, name, ',');
        getline(ss, email, ',');
        
        node* head = nullptr;
        addEmail(email, head);
        
        if(people.find(name) != people.end()) {
            node* temp = people[name];
            while(temp->next) {
                temp = temp->next;
            }
            temp->next = head;
        }
        else {
            people[name] = head;
        }
    }
    file.close();
    int choice;
    string name, email;
    while (choice != 4) {
        cout << "\nPlease select an option:\n"
                "1 - Add a new email\n"
                "2 - Remove an email\n"
                "3 - Find forwarding email address\n"
                "4 - Exit\n"
                "";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            cout << "Please enter the name: ";
            getline(cin, name);
            cout << "Please enter the email address: ";
            cin >> email;
            addEmail(email, people[name]);
            cout << email << " has been added.\n";
        } else if (choice == 2) {
            cout << "Please enter the name: ";
            getline(cin, name);
            cout << "Please enter the email address: ";
            cin >> email;
            removeEmail(email, people[name]);
            cout << email << " has been removed.\n";
        } else if (choice == 3) {
            cout << "Please enter the name: ";
            getline(cin, name);
            cout << "Please enter the email address: ";
            cin >> email;
            cout << "Verified - Send email to " << forwardingAddress(name, email, people) << endl;
        } else if (choice == 4) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    
    return 0;
}
