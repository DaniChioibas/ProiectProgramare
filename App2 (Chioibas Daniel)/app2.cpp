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
}
void catalog_oferte(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Argument invalid. Foloseste ./app2 catalog_oferte";
        return;
    }
    cout << "Acesta este catalogul cu oferte: ";
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