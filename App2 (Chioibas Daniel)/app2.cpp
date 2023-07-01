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
void catalog_oferte(int, char *[]);
void programari_toate(int, char *[]);
void programare_nou(int, char *[]);
void programari(int, char *[]);
int main(int argc, char *argv[])
{
    if (argc <= 1)
        optiuni();
    else
    {
        string x = argv[1];
        if (x == "programari")
            programari(argc, argv);
        else if (x == "programari_toate")
            programari_toate(argc, argv);
        else if (x == "programare_nou")
            programare_nou(argc, argv);
        else if (x == "catalog_oferte")
            catalog_oferte(argc, argv);
        else
            optiuni();
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
void programare_nou(int argc, char *argv[])
{
    if (argc != 6)
    {
        cout << "Argument invalid. Foloseste ./app2 programare_nou <data> <ora> <numePersoana> <oferta>";
        cout << "<data>: ab.cd.abcd\n";
        cout << "<ora>: ab:ab\n";
        cout << "<numePersoana> \"Ex Nume\"\n";
        cout << "<oferta>: idOferta ";
        return;
    }
}
void programari(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Argument invalid. Foloseste ./app2 programari <data>";
        cout << " Ex <data>";
        return;
    }
    vector<Programare *> Programari;
    string data = argv[2];
    ifstream input;
    input.open("../Shared/Files/programari.txt");
    Data A(data);
    vector<string> Oferte;
    string linie;
    ///
    do
    {
        string dataa;
        getline(input, dataa);
        if (input.eof())
            break;
        Data A(dataa);
        string ora;
        getline(input, ora);
        Ora B(ora);
        string nume;
        getline(input, nume);
        string status;
        getline(input, status);
        string nr;
        getline(input, nr);
        int nrOferte = stoi(nr);
        Programare *tmp2 = new Programare(nume, status, A, B, nrOferte);
        for (int i = 0; i < nrOferte; i++)
        {
            string l;
            getline(input, l);
            Oferta *tmp = new Oferta(l);
            tmp2->adaugaOferta(tmp);
        }
        Programari.push_back(tmp2);
    } while (getline(input, linie));
    for (auto et : Programari)
    {
        et->afisare();
        cout << endl;
    }
}
void catalog_oferte(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Argument invalid. Foloseste ./app2 catalog_oferte";
        return;
    }
    cout << "--(Acesta este catalogul cu oferte)-- \n";
    ifstream input;
    input.open("../Shared/Files/oferte.txt");
    if (!input.is_open())
        return;
    string linie;
    getline(input, linie);
    cout << "Exista " << linie << " oferte diferite:\n";
    while (getline(input, linie))
        cout << linie << "\n";
}
void programari_toate(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Argument invalid. Foloseste ./app2 programari_toate";
        return;
    }
    ifstream input;
    cout << "Acestea sunt toate programarile: \n";
    input.open("../Shared/Files/programari.txt");
    if (!input.is_open())
        return;
    string linie;
    while (getline(input, linie))
        cout << linie << "\n";
}