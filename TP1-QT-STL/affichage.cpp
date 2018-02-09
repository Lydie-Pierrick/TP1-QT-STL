#include "affichage.h"


Affichage::Affichage(ostream &out) : os(out), counter(0), priorityAverage(0), prioritySum(0)
{

}

void Affichage::operator()(Client client)
{

    counter ++;
    prioritySum += client.getPriority();
    priorityAverage = prioritySum / counter;

     os << client.getFirstName() << "\t" << client.getLastName() << "\t" << client.getAddr() << "\t" << client.getPriority()<< endl;
     os << "Average Priority = " << priorityAverage << endl;
}
