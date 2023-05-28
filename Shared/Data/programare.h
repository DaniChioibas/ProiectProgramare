#include <iostream>
#include <string>
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
    Oferta **oferte;
};