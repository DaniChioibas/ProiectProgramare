#pragma once
#include <iostream>
#include <string>
using namespace std;

class Data
{
    int zi;
    int luna;
    int an;
    string numeZi;

public:
    Data();
    Data(int, int, int, string);
    int getZi();
    int getLuna();
    int getAn();
    string getNumeZi();
    void setZi(int);
    void setLuna(int);
    void setAn(int);
    void setNumeZi(string);
    friend ostream &operator<<(ostream &, const Data &);
};
Data::Data()
{
    this->zi = 0;
    this->luna = 0;
    this->an = 0;
    this->numeZi = "";
}
Data::Data(int zi, int luna, int an, string numeZi)
{
    this->zi = zi;
    this->luna = luna;
    this->an = an;
    this->numeZi = numeZi;
}
int Data::getAn()
{
    return this->an;
}
int Data::getLuna()
{
    return this->luna;
}
int Data::getZi()
{
    return this->zi;
}
string Data::getNumeZi()
{
    return this->numeZi;
}
void Data::setZi(int x)
{
    this->zi = x;
}
void Data::setLuna(int x)
{
    this->luna = x;
}
void Data::setAn(int x)
{
    this->an = x;
}
void Data::setNumeZi(string x)
{
    this->numeZi = x;
}
ostream &operator<<(ostream &out, const Data &x)
{
    out << x.zi << "." << x.luna << "." << x.an << " " << x.numeZi;
    return out;
}