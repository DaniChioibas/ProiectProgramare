#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>
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
    if (argc != 7)
    {
        cout << "Argument invalid. Foloseste ./app2 programare_nou <data> <ora> <numePersoana> <numarOferte> <idOferte>\n";
        cout << "Ex <data>: \"30.07.2023\"\n";
        cout << "Ex <ora>: \"10:30\"\n";
        cout << "Ex <numePersoana>: \"Nume Prenume\" sau \"Prenume\"\n";
        cout << "Ex <numarOferte>: \"3\"";
        cout << "Ex <idOferte>: \"1 3 4\" sau \"2\"";
        return;
    }
    string data = argv[2];
    regex pattern("\\d{1,2}\\.\\d{1,2}\\.\\d{4}");
    if (!regex_match(data, pattern))
    {
        cout << "Argument invalid. Foloseste ./app2 programare_nou <data> <ora> <numePersoana> <numarOferte> <idOferte>\n";
        cout << "Ai introdus o data gresita | Ex <data>=12.12.2012";
        return;
    }
    Data A(data);
    if (A.getZi() > 31 || A.getLuna() > 12)
    {
        cout << "Argument invalid. Foloseste ./app2 programare_nou <data> <ora> <numePersoana> <numarOferte> <idOferte>\n";
        cout << "Ai introdus o data gresita | Ex <data>=12.12.2012";
        return;
    }
    if (A.getNumeZi() == "Sambata" || A.getNumeZi() == "Duminica")
    {
        cout << "Argument invalid. Foloseste ./app2 programare_nou <data> <ora> <numePersoana> <numarOferte> <idOferte>\n";
        cout << "Frizeria este deschisa Luni-Vineri.\n";
        cout << "Pentru data aleasa, ziua este: " << A.getNumeZi() << "!\n";
        return;
    }

    string ora = argv[3];
    regex pattern2("\\d{1,2}\\:\\d{1,2}");
    if (!regex_match(ora, pattern2))
    {
        cout << "Argument invalid. Foloseste ./app2 programare_nou <data> <ora> <numePersoana> <numarOferte> <idOferte>\n";
        cout << "Ai introdus o ora gresita | Ex <ora> = 10:30";
        return;
    }
    Ora B(ora);
    if (B.getOra() < 10 || B.getOra() > 20)
    {
        cout << "Argument invalid. Foloseste ./app2 programare_nou <data> <ora> <numePersoana> <numarOferte> <idOferte>\n";
        cout << "Frizeria este deschisa in intervalul 10:00 - 21:00\n";
        cout << "Ora aleasa: " << B << endl;
        return;
    }
    if (B.getMinute() != 0 && B.getMinute() != 15 && B.getMinute() != 30 && B.getMinute() != 45)
    {
        cout << "Argument invalid. Foloseste ./app2 programare_nou <data> <ora> <numePersoana> <numarOferte> <idOferte>\n";
        cout << "Programarile pot fi facute doar din 15 in 15 minute (x:00 | x:15 | x:30 | x:45);";
        return;
    }
    string nume = argv[4];
    string nrOferte = argv[5];
    if (nrOferte.size() != 1)
    {
        cout << "Argument invalid. Foloseste ./app2 programare_nou <data> <ora> <numePersoana> <numarOferte> <idOferte>\n";
        cout << "Numarul de oferte ar trebui sa fie o singura cifra!";
        return;
    }
    char digit = nrOferte[0];
    if (!isdigit(digit))
    {
        cout << "Argument invalid. Foloseste ./app2 programare_nou <data> <ora> <numePersoana> <numarOferte> <idOferte>\n";
        cout << "Numarul de oferte ar trebui sa fie o singura cifra!";
        return;
    }
    if (digit == 0)
    {
        cout << "Argument invalid. Foloseste ./app2 programare_nou <data> <ora> <numePersoana> <numarOferte> <idOferte>\n";
        cout << "Numarul de oferte ar trebui sa fie o singura cifra, nu 0!";
        return;
    }
    string idOferte = argv[6];
    regex pattern3("^(\\d+\\s){" + std::to_string(stoi(nrOferte) - 1) + "}\\d+$");
    if (!regex_match(idOferte, pattern3))
    {
        cout << "Argument invalid. Foloseste ./app2 programare_nou <data> <ora> <numePersoana> <numarOferte> <idOferte>\n";
        cout << "Id-ul de oferte trebuie sa fie sub forma \"1 2 3\"\n";
        cout << "Numarul de oferte trebuie sa coincida cu cel specificat!\n";
        return;
    }
    int idOf[stoi(nrOferte)];
    istringstream iss(idOferte);
    for (int i = 0; i < stoi(nrOferte); i++)
        iss >> idOf[i];
    vector<Oferta *> listOferte;
    vector<Oferta *> listOferteIesire;
    ifstream input;
    input.open("../Shared/Files/oferte.txt");
    if (!input.is_open())
        return;
    string linie;
    int nr;
    input >> nr;
    getline(input, linie);
    for (int i = 0; i < nr; i++)
    {
        getline(input, linie);
        Oferta *tmp = new Oferta(linie);
        listOferte.push_back(tmp);
    }
    int i = 0, ok = 0;
    while (i != stoi(nrOferte))
    {
        ok = 0;
        for (auto it : listOferte)
        {
            if (it->getId() == idOf[i])
            {
                listOferteIesire.push_back(it);
                i++;
                ok = 1;
            }
        }
        if (ok == 0)
            break;
    }
    if (ok == 0)
    {
        cout << "Argument invalid. Foloseste ./app2 programare_nou <data> <ora> <numePersoana> <numarOferte> <idOferte>\n";
        cout << "Unul sau mai multe id-uri de oferte nu exista!";
        return;
    }
    int ok2 = 0;
    vector<Programare *> listaProgramari;
    ifstream input2;
    input2.open("../Shared/Files/programari.txt");
    string linie2;
    do
    {
        string data2;
        getline(input2, data2);
        if (input2.eof())
            break;
        Data AA(data2);
        string ora2;
        getline(input2, ora2);
        Ora BB(ora2);
        string nume2;
        getline(input2, nume2);
        string status2;
        getline(input2, status2);
        string nr2;
        getline(input2, nr2);
        int nrOferte2 = stoi(nr2);
        Programare *tmp2 = new Programare(nume2, status2, AA, BB, nrOferte2);
        for (int i = 0; i < nrOferte2; i++)
        {
            string l;
            getline(input2, l);
            Oferta *tmp = new Oferta(l);
            tmp2->adaugaOferta(tmp);
        }
        listaProgramari.push_back(tmp2);

    } while (getline(input2, linie2));

    for (auto it : listaProgramari)
    {
        if (it->getData() == A && it->getOra() == B)
        {
            cout << "Argument invalid. Foloseste ./app2 programare_nou <data> <ora> <numePersoana> <numarOferte> <idOferte>\n";
            cout << "Exista deja o programare in data " << A << " la ora " << B;
            return;
        }
    }
    ofstream output;
    output.open("../Shared/Files/programari.txt", ios::app);
    output << data << endl;
    output << ora << endl;
    output << nume << endl;
    output << "Pending" << endl;
    output << nrOferte << endl;
    for (auto it : listOferteIesire)
    {
        output << *it << endl;
    }
    output << "---" << endl;
}
void programari(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Argument invalid. Foloseste ./app2 programari <data>";
        cout << " |Ex <data>=12.12.2012";
        return;
    }
    vector<Programare *> Programari;
    string data = argv[2];
    regex pattern("\\d{1,2}\\.\\d{1,2}\\.\\d{4}");
    if (!regex_match(data, pattern))
    {
        cout << "Argument invalid. Nu ai introdus o data valida. Foloseste ./app2 programari <data>";
        cout << " |Ex <data>=12.12.2012";
        return;
    }

    ifstream input;
    input.open("../Shared/Files/programari.txt");
    Data A(data);
    if (A.getZi() > 31 || A.getLuna() > 12)
    {
        cout << "Argument invalid. Nu ai introdus o data valida. Foloseste ./app2 programari <data>";
        cout << " |Ex <data>=12.12.2012";
        return;
    }
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
    cout << "Programarile dupa data <" << data << "> sunt: \n";
    for (auto et : Programari)
    {
        if (data < et->getData())
        {
            et->afisare();
            cout << endl;
        }
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
    vector<string> Oferte;
    vector<Programare *> Programari;
    cout << "Acestea sunt toate programarile: \n";
    input.open("../Shared/Files/programari.txt");
    if (!input.is_open())
        return;
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