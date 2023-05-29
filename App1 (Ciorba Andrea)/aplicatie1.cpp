#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../Shared/Data/data.h"
#include "../Shared/Data/ora.h"
#include "../Shared/Data/oferta.h"
#include "../Shared/Data/programare.h"
using namespace std;
void optiuni();
int main(int argc, char *argv[])
{
    if (argc <= 1)
        optiuni();
    else
        cout << "Ai introdus " << argc << " argumente";
}

void optiuni()
{
    cout << "Ai introdus o optiune invalida. Foloseste: \n";
    cout << "   catalog_oferte\n";
    cout << "   programari <data>\n";
    cout << "   programari_toate\n";
    cout << "   programare_nou <data> <ora> <numePersoana> <oferta>";
}