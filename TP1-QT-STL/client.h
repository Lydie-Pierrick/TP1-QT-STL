#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Client
{
private:
    string lastName;
    string firstName;
    string addr;
    string city;
    string comments;
    int telephone;
    int postalCode;
    int duration;
    int priority;
    vector <int> idRes;
public:
    Client(string lastName, string firstName, string addr, string city, string comments, int telephone,
                   int postalCode, int duration, int priority);
    string getAddr() const;
    void setAddr(const string &value);
    string getLastName() const;
    void setLastName(const string &value);
    string getFirstName() const;
    void setFirstName(const string &value);
    string getCity() const;
    void setCity(const string &value);
    string getComments() const;
    void setComments(const string &value);
    int getTelephone() const;
    void setTelephone(int value);
    int getPostalCode() const;
    void setPostalCode(int value);
    int getDuration() const;
    void setDuration(int value);
    int getPriority() const;
    void setPriority(int value);
    vector<int> getIdRes() const;
    void setIdRes(const vector<int> &value);
};

#endif // PATIENT_H
