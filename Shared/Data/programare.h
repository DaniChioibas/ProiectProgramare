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
    Oferta *oferte;

public:
    Programare(vector<string>);
    Programare(string, string, Data, Ora, int);
    ~Programare();
};
Programare::Programare(string nume, string status, Data data, Ora ora, int nrOferte)
{
    this->nume = nume;
    this->status = status;
    this->data.setAn(data.getAn());
    this->data.setLuna(data.getLuna());
    this->data.setZi(data.getZi());
    this->data.setNumeZi(data.getNumeZi());
    this->ora.setMinute(ora.getMinute());
    this->ora.setOra(ora.getOra());
    this->nrOferte = nrOferte;
    this->oferte = new Oferta[nrOferte];
}
Programare::Programare(vector<string> P)
{
    this->nume = nume;
    this->status = status;
    this->data.setAn(data.getAn());
    this->data.setLuna(data.getLuna());
    this->data.setZi(data.getZi());
    this->data.setNumeZi(data.getNumeZi());
    this->ora.setMinute(ora.getMinute());
    this->ora.setOra(ora.getOra());
    this->nrOferte = nrOferte;
    this->oferte = new Oferta[nrOferte];
}
Programare::~Programare()
{
    delete[] this->oferte;
}