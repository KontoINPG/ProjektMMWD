#include"AlgorytmPszczeli.hpp"
#include"produkt.hpp"

extern std::vector<Produkt> BazaProduktow;
extern std::vector<Sklep> BazaSklepow;
extern std::vector<ElementZamawiany> ListaZamowienia;

using std::cout;
using std::cin;
using std::endl;

// http://zsi.ii.us.edu.pl/~mboryczka/IntStad/sr_abc.php

void algorytm_pszczeli_testy()
{

    //Losowanie pocz¹tkowych rozwi¹zañ:

    int ilFurazerek = 5;
    std::vector< std::vector<int>> rozwiazaniePoczatkowe;

    for (int furazerka = 0; furazerka<ilFurazerek; furazerka++)
    {
        std::vector<int> rozwiazanie;
        for( element : ListaZamowienia)
        {
            int wylosowanySklepID;
            std::vector<int> dostawcy;
            int ilDostawcow;

            dostawcy = element.get_listaDostawcow();
            ilDostawcow = dostawcy.size();
            wylosowanySklepID = dostawcy[rand()%ilDostawcow];//-------------SPRAWDZIÆ, CZY TO JEST DOBRZE-------------//
            cout<<"WSID: "<<wylosowanySklepID<<endl;
            rozwiazanie.push_back(wylosowanySklepID);
        }
        rozwiazaniePoczatkowe.push_back(rozwiazanie);
        for(lA:rozwiazanie)
            cout<<BazaSklepow[lA].get_nazwa();
        cout<<"------------------"<<endl;

    }




}


