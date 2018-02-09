#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include<iostream>
#include "client.h"

using namespace std;
class Affichage
{
private:
    ostream &os;
    int priorityAverage;
    int counter;
    int prioritySum;
public:
    Affichage(ostream &out);
    void operator ()(Client client);
};

#endif // AFFICHAGE_H
