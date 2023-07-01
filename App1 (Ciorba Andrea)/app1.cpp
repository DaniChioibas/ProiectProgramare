#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include <iomanip>
#include "../Shared/Data/data.h"
#include "../Shared/Data/ora.h"
#include "../Shared/Data/oferta.h"
#include "../Shared/Data/programare.h"
using namespace std;

vector<Oferta> catalog;
void optiuni();
void catalog_oferte(int, char *[]);
void adaugare_oferta(int, char *[]);
void modifica_oferta(int, char *[]);
void programari_pending(int ,char *[]);
void programare_accept(int , char *[]);
int main(int argc, char* argv[]) {

    if (argc <= 1)
        optiuni();
    else {
        string optiune = argv[1];
        if (optiune == "adaugare_oferta") {
            adaugare_oferta(argc, argv);
        } else if (optiune == "catalog_oferte") {
            catalog_oferte(argc, argv);
        }
        else if (optiune == "modifica_oferta")
            modifica_oferta(argc, argv);
        else if (optiune == "programari_pending")
            programari_pending(argc, argv);
        else if (optiune == "programare_accept")
            programare_accept(argc, argv);
        else optiuni();
    }

    return 0;
}

void optiuni()
{
    cout << "Ai introdus o optiune invalida. Foloseste: \n";
    cout << "   catalog_oferte\n";
    cout << "   adaugare_oferte\n";
    cout << "   modificare_oferte\n";
    cout << "   stergere_oferte\n";
    cout << "   acceptare_programari";
}

void catalog_oferte(int argc, char *argv[]){
    if (argc!=2)
    { cout<<"Use ./app1 catalog_oferte";return;}
    cout<<"Catalog oferte\n";
    ifstream input;
    input.open("../Shared/Files/oferte.txt");
    if (!input.is_open())
        return;
    string linie;
    getline(input, linie);
    while (getline(input,linie))
        cout<<linie<<"\n";
}

void programari_pending(int argc, char*argv[]){
    if (argc!=2)
    {cout<<"Use ./app1 programari_pending";return;}
    cout<<"Programari in asteptare:\n";
ifstream input;
input.open("../Shared/Files/programari.txt");
if (!input.is_open())
    return;
string linie;
getline(input, linie);
while (getline(input,linie))
    cout<<linie<<"\n";

}

void adaugare_oferta(int argc, char *argv[]){
    if (argc!=4)
    {cout<<"Use ./app1 adaugare_oferta <nume> <durata> <pret>";return;}

}

void modifica_oferta(int argc, char *argv[]){
    if (argc != 5)
    {cout<<"Use ./app1 modifica_oferta <id> <nume> <durata> <pret>";return;}
}

void programare_accept(int argc, char *argv[]){
    if (argc!=3)
    {cout<<"Use ./app1 programare_accept <data> <ora>";return;}
}


