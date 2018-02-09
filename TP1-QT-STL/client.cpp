#include "client.h"

Client::Client(string lastName, string firstName, string addr, string city, string comments, int telephone,
               int postalCode, int duration, int priority):
    lastName(lastName), firstName(firstName), addr(addr), city(city), comments(comments),
    telephone(telephone), postalCode(postalCode), duration(duration), priority(priority)
{

}

string Client::getAddr() const
{
    return addr;
}

void Client::setAddr(const string &value)
{
    addr = value;
}

string Client::getLastName() const
{
    return lastName;
}

void Client::setLastName(const string &value)
{
    lastName = value;
}

string Client::getFirstName() const
{
    return firstName;
}

void Client::setFirstName(const string &value)
{
    firstName = value;
}

string Client::getCity() const
{
    return city;
}

void Client::setCity(const string &value)
{
    city = value;
}

string Client::getComments() const
{
    return comments;
}

void Client::setComments(const string &value)
{
    comments = value;
}

int Client::getTelephone() const
{
    return telephone;
}

void Client::setTelephone(int value)
{
    telephone = value;
}

int Client::getPostalCode() const
{
    return postalCode;
}

void Client::setPostalCode(int value)
{
    postalCode = value;
}

int Client::getDuration() const
{
    return duration;
}

void Client::setDuration(int value)
{
    duration = value;
}

int Client::getPriority() const
{
    return priority;
}

void Client::setPriority(int value)
{
    priority = value;
}

vector<int> Client::getIdRes() const
{
    return idRes;
}

void Client::setIdRes(const vector<int> &value)
{
    idRes = value;
}




