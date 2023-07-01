#pragma once
#include <iostream>
using namespace std;

class Ora
{
    int ora;
    int minute;

public:
    Ora(string);
    Ora();
    Ora(int, int);
    int getOra();
    int getMinute();
    void setMinute(int x);
    void setOra(int x);
    friend ostream &operator<<(ostream &, const Ora &);
    Ora &operator=(const Ora &other)
    {
        if (this != &other)
        {
            this->ora = other.ora;
            this->minute = other.minute;
        }
        return *this;
    }
    friend bool operator==(const Ora &, const Ora &);
};
bool operator==(const Ora &lhs, const Ora &rhs)
{
    return lhs.ora == rhs.ora && lhs.minute == rhs.minute;
}
Ora::Ora(string timp)
{
    size_t colonPos = timp.find(':');

    string hourString = timp.substr(0, colonPos);
    this->ora = stoi(hourString);

    string minuteString = timp.substr(colonPos + 1);
    this->minute = stoi(minuteString);
}
Ora::Ora()
{
    this->ora = 0;
    this->minute = 0;
}
Ora::Ora(int ora, int minute)
{
    this->ora = ora;
    this->minute = minute;
}
int Ora::getOra()
{
    return this->ora;
}
int Ora::getMinute()
{
    return this->minute;
}
void Ora::setMinute(int x)
{
    this->minute = x;
}
void Ora::setOra(int x)
{
    this->ora = x;
}
ostream &operator<<(ostream &out, const Ora &x)
{
    out << x.ora << ":" << x.minute;
    return out;
}