#pragma once
#include <iostream>
#include <string>
#include "data.h"
#include "ora.h"
using namespace std;

class Oferta
{
    string nume;
    int id;
    int durata;
    double pret;

public:
    Oferta(string &inputString)
    {
        istringstream iss(inputString);
        iss >> id >> nume >> durata >> pret;
    }
    void afisare()
    {
        cout << this->id << " " << this->nume << " " << this->durata << " " << this->pret;
    }
    string getNume() const
    {
        return nume;
    }

    void setNume(const string &newNume)
    {
        nume = newNume;
    }

    int getId() const
    {
        return id;
    }

    void setId(int newId)
    {
        id = newId;
    }

    int getDurata() const
    {
        return durata;
    }

    void setDurata(int newDurata)
    {
        durata = newDurata;
    }

    double getPret() const
    {
        return pret;
    }

    void setPret(double newPret)
    {
        pret = newPret;
    }
};