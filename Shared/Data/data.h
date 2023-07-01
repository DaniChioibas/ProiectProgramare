#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
using namespace std;

class Data
{
    int zi;
    int luna;
    int an;
    string numeZi;

public:
    Data(string);
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
    Data &operator=(const Data &other)
    {
        if (this != &other)
        {
            this->zi = other.zi;
            this->luna = other.luna;
            this->an = other.an;
            this->numeZi = other.numeZi;
        }
        return *this;
    }
};
Data::Data(string dateString)
{
    istringstream iss(dateString);
    char dot;
    int zi, luna, an;
    iss >> zi >> dot >> luna >> dot >> an;
    this->zi = zi;
    this->an = an;
    this->luna = luna;
    tm date = {0, 0, 0, this->zi, this->luna - 1, this->an - 1900};
    char bufferr[20];
    mktime(&date);
    strftime(bufferr, sizeof(bufferr), "%A", &date);
    string buffer = bufferr;
    if (buffer == "Monday")
        this->numeZi = "Luni";
    else if (buffer == "Tuesday")
        this->numeZi = "Marti";
    else if (buffer == "Wednesday")
        this->numeZi = "Miercuri";
    else if (buffer == "Thursday")
        this->numeZi = "Joi";
    else if (buffer == "Friday")
        this->numeZi = "Vineri";
    else if (buffer == "Saturday")
        this->numeZi = "Sambata";
    else if (buffer == "Sunday")
        this->numeZi = "Duminica";
}
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