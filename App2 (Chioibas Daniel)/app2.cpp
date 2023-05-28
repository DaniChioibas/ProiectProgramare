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
void catalog_oferte();
void programari_toate();
int main(int argc, char *argv[])
{
    if (argc <= 1)
        optiuni();
    else if (argc == 2)
    {
        string optiune = argv[1];
        if (optiune == "catalog_oferte")
            catalog_oferte();
        else if (optiune == "programari_toate")
            programari_toate();
        else
            optiuni();
    }
    else if (argc == 3)
    {
        // data x.y.z
        string data = argv[2];
    }
}

void optiuni()
{
    cout << "Ai introdus o optiune invalida. Foloseste: \n";
    cout << "   catalog_oferte\n";
    cout << "   programari <data>\n";
    cout << "   programari_toate\n";
    cout << "   programare_nou <data> <ora> <numePersoana> <oferta>";
}
void catalog_oferte()
{
    cout << "Acesta este catalogul cu oferte: ";
}
void programari_toate()
{
    ifstream input;
    cout << "Acestea sunt toate programarile: \n";
    input.open("../Shared/Files/programari.txt");
    if (!input.is_open())
        return;
    string line;
    vector<string> L;
    int ok = 0;
    while (!input.eof())
    {
        if (line == "---")
        {
            vector<string>::iterator it;
            for (it = L.begin(); it != L.end(); it++)
                cout << *it << endl;
            L.clear();
        }
        getline(input, line);
        L.push_back(line);
    }
    input.close();
}