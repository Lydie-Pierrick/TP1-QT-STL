#include "patient.h"

// Default constructor
patient::patient()
{
}

// Comfort constructor
patient::patient(string name, string firstname, string address, string street, string comments, string Sickness, int telephone, int postalCode, int durationConsultation, int priority, vector<int> idRessource)
{
    this.name = name;
    this.firstname = firstname;
    this.address = address;
    this.street = street;
    this.commentsSickness = commentsSickness;
    this.telephone = telephone;
    this.postalCode = postalCode;
    this.durationConsultation = durationConsultation;
    this.priority = priority;

    this.idRessource = nullptr;
}
