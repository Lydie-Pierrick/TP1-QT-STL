#ifndef PATIENT_H
#define PATIENT_H

class PATIENT_H
{
private:
    string name;
    string firstname;
    string address;
    string street;
    string commentsSickness;
    int telephone;
    int postalCode;
    int durationConsultation;
    int priority;

    vector<int> idRessource;

public:
    patient();
}

#endif // PATIENT_H
