#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "contact.h"
using namespace std;

vector<Contact>Contact::getData(string filename, vector<Contact>& contacts) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Failed to open file for reading." << endl;
        return vector<Contact>();
    }
    string id, name, phoneNumber, gmail, address;
    while (getline(inputFile, id, ',') &&
           getline(inputFile, name, ',') &&
           getline(inputFile, phoneNumber, ',') &&
           getline(inputFile, gmail, ',') &&
           getline(inputFile, address)) {
        Contact contact(stoi(id), name, phoneNumber, gmail, address);
        contacts.push_back(contact);
    }
    inputFile.close();
    return contacts;
}
void Contact::display(string filename, vector<Contact>& contacts) {
    for(auto& contact : contacts) {
        cout << "ID:" << contact.getId() << endl;
        cout << "Name:" << contact.getName() << endl;
        cout << "Phone:" << contact.getPhoneNumber() << endl;
        cout << "Gmail:" << contact.getGmail() << endl;
        cout << "Address:" << contact.getAddress() << endl;
        cout << "-------------------" << endl;
    }
}
vector<Contact>Contact::add(vector<Contact>& contacts) {
    int id;
    string name, phoneNumber, gmail, address;
    cout << "Enter ID: ";
    cin >> id;
    cin.ignore(); 
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter phoneNumber: ";
    getline(cin, phoneNumber);
    cout << "Enter Gmail: ";
    getline(cin, gmail);
    cout << "Enter Address: ";
    getline(cin, address);

    Contact contact(id, name, phoneNumber, gmail, address);
    contacts.push_back(contact);
    ofstream fileOut("danhba.csv",ios::app);
    fileOut << contact.getId() << "," << contact.getName() << "," << contact.getPhoneNumber() << "," << contact.getGmail() << "," << contact.getAddress() << endl;
    fileOut.close();
    return contacts;
}
void Contact::search(vector<Contact>& contacts) {
    string name;
    cout << "Enter name to search: ";
    cin.ignore();
    getline(cin, name);
    for(auto& contact : contacts) {
        if(contact.getName() == name) {
            cout <<"ID:" << contact.getId() << endl;
            cout <<"Name:" << contact.getName() << endl;
            cout <<"Phone:" << contact.getPhoneNumber() << endl;
            cout <<"Gmail:" << contact.getGmail() << endl;
            cout <<"Address:" << contact.getAddress() << endl;
        }
    }
}
void Contact::update(vector<Contact>& contacts) {
    int id;
    string name, phoneNumber, gmail, address;
    cout << "Enter ID to update: ";
    cin >> id;
    cin.ignore(); 
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter phoneNumber: ";
    getline(cin, phoneNumber);
    cout << "Enter Gmail: ";
    getline(cin, gmail);
    cout << "Enter Address: ";
    getline(cin, address);
    for(auto& contact : contacts) {
        if(contact.getId() == id) {
            contact.setName(name);
            contact.setPhoneNumber(phoneNumber);
            contact.setGmail(gmail);
            contact.setAddress(address);
        }
    }
    ofstream fileOut("danhba.csv");
    for(auto& contact : contacts) {
        fileOut << contact.getId() << "," << contact.getName() << "," << contact.getPhoneNumber() << "," << contact.getGmail() << "," << contact.getAddress() << endl;
    }
    fileOut.close();
}
void Contact::remove(vector<Contact>& contacts) {
    int id;
    cout << "Enter ID to remove: ";
    cin >> id;
    for(auto it = contacts.begin(); it != contacts.end(); it++) {
        if(it->getId() == id) {
            contacts.erase(it);
            break;
        }
    }
    ofstream fileOut("danhba.csv");
    for(auto& contact : contacts) {
        fileOut << contact.getId() << "," << contact.getName() << "," << contact.getPhoneNumber() << "," << contact.getGmail() << "," << contact.getAddress() << endl;
    }
    fileOut.close();
}
void Contact::statistics(vector<Contact>& contacts) {
    cout << "Total contacts: " << contacts.size() << endl;
}
void Contact::backup(vector<Contact>& contacts) {
    ofstream fileOut("danhba_backup.csv");
    for(auto& contact : contacts) {
        fileOut << contact.getId() << "," << contact.getName() << "," << contact.getPhoneNumber() << "," << contact.getGmail() << "," << contact.getAddress() << endl;
    }
    fileOut.close();
}
void Contact::restore(vector<Contact>& contacts) {
    contacts = getData("danhba_backup.csv", contacts);
    ofstream fileOut("danhba.csv");
    for(auto& contact : contacts) {
        fileOut << contact.getId() << "," << contact.getName() << "," << contact.getPhoneNumber() << "," << contact.getGmail() << "," << contact.getAddress() << endl;
    }
    fileOut.close();
}
