#ifndef contact_h
#define contact_h

#include <iostream>
#include <string>
using namespace std;
class Contact{
    int id;
    string name;
    string phoneNumber;
    string gmail;
    string address;
    public:
        Contact();
        Contact(int id, string name,string phoneNumber,string gmail,string address);

        void setId(int id);
        void setName(string name);
        void setPhoneNumber(string name);
        void setGmail(string gmail);
        void setAddress(string address);

        int getId();
        string getName();
        string getPhoneNumber();
        string getGmail();
        string getAddress();
        
        static vector<Contact> getData(string filename, vector<Contact>& contacts);
        static void display(string filename, vector<Contact>& contacts);
        static vector<Contact> add(vector<Contact>& contacts);
        static void search(vector<Contact>& contacts);
        static void update(vector<Contact>& contacts);
        static void remove(vector<Contact>& contacts);
        static void statistics(vector<Contact>& contacts);
        static void backup(vector<Contact>& contacts);
        static void restore(vector<Contact>& contacts);
};
#endif