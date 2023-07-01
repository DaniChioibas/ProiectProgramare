#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "data.h"
#include "ora.h"
#include "oferta.h"
using namespace std;

class Programare
{
    string nume;
    string status;
    Data data;
    Ora ora;
    int nrOferte;
    vector<Oferta *> oferte;

public:
    Data getData()
    {
        return this->data;
    }
    void adaugaOferta(Oferta *tmp)
    {
        this->oferte.push_back(tmp);
    }
    Programare(string, string, Data, Ora, int);
    void afisare()
    {
        cout << this->data << endl;
        cout << this->ora << endl;
        cout << this->nume << endl;
        cout << this->status << endl;
        cout << this->nrOferte << endl;
        for (auto et : oferte)
        {
            et->afisare();
            cout << endl;
        }
    }
};
Programare::Programare(string nume, string status, Data data, Ora ora, int nrOferte)
{
    this->nume = nume;
    this->status = status;
    this->data = data;
    this->ora = ora;
    this->nrOferte = nrOferte;
}